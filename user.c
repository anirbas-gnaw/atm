#include <stdlib.h>
#include <stdio.h>
#include <assert.h>
#include "user.h"

/**
 * creates a new user with an access pin and a unique card number
 * each user has exactly 2 accounts
 * account balance initiated to 0
 */
user_t *user_create(int pin, int card_num){
  user_t *user;

  user = malloc(sizeof(user_t));
  user->pin = pin;
  user->card = card_num;
  user->checking = account_create(0);
  user->saving = account_create(0);

  return user;
}

/**
 * returns 1 if `pin` matches the `user`s pin, 0 otherwise
 */
int user_authenticate(user_t *user, int pin) {
  return (user->pin == pin);
}

/**
 * returns the `user`s balance for the `atype` account
 */
int user_get_balance(user_t *user, account_type_t atype) {
  switch (atype) {
    case CHECKING:
      return account_get_balance(user->checking);
    case SAVING:
      return account_get_balance(user->saving);
  } 
  assert(0);
  return 0;
}

/**
 * deposits `amount` into `user`s `atype` account
 */
int user_deposit(user_t *user, account_type_t atype, int amount) {
  switch (atype) {
    case CHECKING:
      return account_deposit(user->checking, amount);
    case SAVING:
      return account_deposit(user->saving, amount);
  }
  assert(0);
  return 0;
}

/**
 * withdraws `amount` from `user`s `atype` account
 */
int user_withdraw(user_t *user, account_type_t atype, int amount) {
  switch (atype) {
    case CHECKING :
      return account_withdraw(user->checking, amount);
    case SAVING :
      return account_withdraw(user->saving, amount);
  }
  assert(0);
  return 0;
}
