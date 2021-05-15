#ifndef USER_HEADER
#define USER_HEADER

#include "account.h"

/**
 * type of an account
 * only uses 2 types of accounts for testing
 */
typedef enum account_type_enum {
  CHECKING = 0,
  SAVING = 1,
} account_type_t;

/**
 * user structure
 */
typedef struct user_struct {
  int pin;
  int card;
  account_t *checking;
  account_t *saving;
} user_t;

// user acces functions
extern user_t *user_create(int pin, int card_num);
extern int user_authenticate(user_t *user, int pin);
extern int user_get_balance(user_t *user, account_type_t atype);
extern int user_deposit(user_t *user, account_type_t atype, int amount);
extern int user_withdraw(user_t *user, account_type_t atype, int amount);

#endif