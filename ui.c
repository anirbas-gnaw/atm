#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include "atm.h"

/**
 * main routine for testing the ATM with simple commandline input
 */
int main(void) {
  size_t size;
  char *buf;
  size_t inSize;
  char *cmd;
  char* num;
  atm_t *atm;

  buf = 0;

  atm = atm_create();

  while (1) {
    printf("ATM> ");
    inSize = getline(&buf, &size, stdin);
    buf[inSize - 1] = 0;

    cmd = strtok(buf, " ");
    num = strtok(NULL, " ");

    if (strcmp (cmd, "quit") == 0) {
      break;
    }

    atm_action(atm, cmd, num);
  }

  atm_destroy(atm);

  return 0;
}
