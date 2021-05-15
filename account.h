#ifndef ACCOUNT_HEADER
#define ACCOUNT_HEADER

/**
 * account structure to represent a user's account
 * only tracks balance
 * used to test ATM
 */
typedef struct account_struct {
  int balance;
} account_t;

// account access functions
extern account_t *account_create(int init_amount);
extern int account_get_balance(account_t *accout);
extern int account_deposit(account_t *accout, int amount);
extern int account_withdraw(account_t *accout, int amount);

#endif