#include <assert.h>
#include <stdlib.h>
#include "account.h"

/**
 * creates new account with inital balance set to `amount`
 */
account_t *account_create(int amount) {
  account_t *account;

  account = malloc(sizeof(account_t));
  account->balance = amount;

  return account;
}

/**
 * returns the balance of `account`
 */
int account_get_balance(account_t *account) {
  assert(account != 0);
  return account->balance;
}

/**
 * deposits `amount` into `account`
 */
int account_deposit(account_t *account, int amount) {
  assert(account != 0);
  account->balance += amount;
  return account->balance;
}

/**
 * withdraw `amount` from `account`
 * allow negative balance
 */
int account_withdraw(account_t *account, int amount) {
  assert(account != 0);
  account->balance -= amount;
  return account->balance;
}