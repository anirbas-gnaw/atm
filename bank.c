#include <stdlib.h>
#include <stdio.h>
#include <assert.h>
#include "bank.h"

/**
 * creates a bank with 2 users for tesing purposes
 */
bank_t *bank_get(void) {
  bank_t *bank;

  bank = malloc(sizeof(bank_t));

  bank->num_users = 2;

  bank->users[0] = user_create(11, 101);
  bank->users[1] = user_create(22, 102);

  return bank;
}

/**
 * finds the user with card number `card`
 * returns 0 if no user found
 */
user_t *bank_get_user(bank_t *bank, int card) {
  int i;
  assert(bank != 0);
  for (i = 0; i < bank->num_users; i++) {
    if (bank->users[i]->card == card) {
      return bank->users[i];
    }
  }

  printf("Card invalid: %d\n", card);
  return 0;
}
