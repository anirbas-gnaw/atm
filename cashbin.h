#ifndef CASHBIN_HEADER
#define CASHBIN_HEADER

/**
 * Cashbin structure for testing ATM
 */
typedef struct cashbin_struct {
  int cash;
} cashbin_t;

// cashbin access functions
extern cashbin_t *cashbin_get(void);
extern int cashbin_get_amount(cashbin_t *bin);
extern void cashbin_deposit(cashbin_t *bin, int num);
extern void cashbin_withdraw(cashbin_t *bin, int num);

#endif