#ifndef ATM_HEADER
#define ATM_HEADER

#include "user.h"
#include "bank.h"
#include "cashbin.h"

/**
 * ATM state
 * the atm has several states from which different functions can change the state
 */
typedef enum atm_state {
  WAITING = 0,
  CARDIN = 1,
  LOGGEDIN = 2,
  INCHECKING = 3,
  INSAVING = 4,
} atm_state_t;

/**
 * ATM structure
 */
typedef struct atm_struct {
    user_t *user;
    atm_state_t state;
    bank_t *bank;
    cashbin_t *cashbin;
} atm_t;

// atm access functions
extern atm_t *atm_create(void);
extern void atm_destroy(atm_t *atm);
extern void atm_action(atm_t *atm, char *cmd, char *num);

#endif
