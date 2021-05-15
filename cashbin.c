#include <stdlib.h>
#include "cashbin.h"

/**
 * Initializes cash bin to 100 for testing
 */
cashbin_t *cashbin_get(void) {
  cashbin_t *cashbin;

  cashbin = malloc(sizeof(cashbin_t));
  cashbin->cash = 100;

  return cashbin;
}

/**
 * returns the amount in the cash bin
 */
int cashbin_get_amount(cashbin_t *bin) {
  return bin->cash;
}

/**
 * adds the deposit `amount` to the cash bin
 * no max for testing
 */
void cashbin_deposit(cashbin_t *bin, int amount) {
  bin->cash += amount;
}

/**
 * withdraws `amount` from cashbin
 * no negative allowed
 * but assume caller checks that cashbin has enough cash before withdrawing
 */
void cashbin_withdraw(cashbin_t *bin, int amount) {
  bin->cash -= amount;
}