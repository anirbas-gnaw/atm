#ifndef BANK_HEADER
#define BANK_HEADER

#include "user.h"

/**
 * Bank structure for testing ATM
 * this bank stores max 10 users
 */
typedef struct bank_struct {
  int num_users;
  user_t *users[10];
} bank_t;

// bank acces functions
extern bank_t *bank_get(void);
extern user_t *bank_get_user(bank_t *bank, int card);

#endif