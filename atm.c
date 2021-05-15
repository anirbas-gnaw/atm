#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <assert.h>
#include "atm.h"

/**
 * creates a new ATM
 * starting state is WAITING for a card to be inserted
 */
atm_t *atm_create(void) {
  atm_t *atm;

  atm = malloc(sizeof(atm_t));
  atm->state = WAITING;
  atm->user = 0;
  atm->bank = bank_get();
  atm->cashbin = cashbin_get();

  return atm;
}

/**
 * free atm when done testing
 */
void atm_destroy(atm_t *atm) {
  free(atm);
}

/**
 * tracks states and responds to valid commands from each state
 */
void atm_action(atm_t *atm, char *cmd, char *num) {
  account_type_t atype;

  switch (atm->state) {
    case WAITING:
      if (strcmp(cmd, "cardin") == 0) {
        atm->user = bank_get_user(atm->bank, atoi(num));
        if(atm->user != 0) {
          atm->state = CARDIN;
        }
      } else {
        printf("invalid cmd: %s\n", cmd);
      }
      break;
    case CARDIN:
      if (strcmp(cmd, "verify") == 0) {
        assert(atm->user != 0);
        if (user_authenticate(atm->user, atoi(num))) {
          atm->state = LOGGEDIN;
        } else {
          printf("invalid pin\n");
        }
      } else if (strcmp(cmd, "cardout") == 0) {
        atm->user = 0;
        atm->state = WAITING;
      } else {
        printf("invalid cmd: %s\n", cmd);
      }
      break;
    case LOGGEDIN:
      if (strcmp(cmd, "checking") == 0) {
        assert(atm->user != 0);
        atm->state = INCHECKING;
      } else if (strcmp(cmd, "saving") == 0) {
        assert(atm->user != 0);
        atm->state = INSAVING;
      } else if (strcmp(cmd, "cardout") == 0) {
        atm->user = 0;
        atm->state = WAITING;
      } else {
        printf("invalid cmd: %s\n", cmd);
      }
      break;
    case INCHECKING:
    case INSAVING:
      atype = atm->state == INCHECKING ? CHECKING : SAVING;
      if (strcmp(cmd, "balance") == 0) {
        printf("Balance: %d\n", user_get_balance(atm->user, atype));
      } else if (strcmp(cmd, "deposit") == 0) {
        printf("New balance: %d\n", 
                user_deposit(atm->user, atype, atoi(num)));
        cashbin_deposit(atm->cashbin, atoi(num));
      } else if (strcmp(cmd, "withdraw") == 0) {
        if(cashbin_get_amount(atm->cashbin) < atoi(num)) {
          printf("Not enough money in cashbin\n");
        } else {
          printf("New balance: %d\n",
                  user_withdraw(atm->user, atype, atoi(num)));
          cashbin_withdraw(atm->cashbin, atoi(num));
        }
      } else if (strcmp(cmd, "done") == 0) {
        atm->state = LOGGEDIN;
      } else if (strcmp(cmd, "cardout") == 0) {
        atm->user = 0;
        atm->state = WAITING;
      } else {
        printf("invalid cmd: %s\n", cmd);
      }
      break;
  }
}