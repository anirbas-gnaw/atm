OBJ = atm.o user.o account.o bank.o cashbin.o
CFLAGS = -Werror -Wall -g -O0

atmtest: ui.c $(OBJ)
	gcc $(CFLAGS) -o atmtest ui.c $(OBJ)

account.o: account.h account.c
	gcc $(CFLAGS) -c account.c

user.o: user.c user.h account.h
	gcc $(CFLAGS) -c user.c

bank.o: bank.c bank.h user.h account.h
	gcc $(CFLAGS) -c bank.c

atm.o: atm.c atm.h user.h account.h
	gcc $(CFLAGS) -c atm.c

cashbin.o: cashbin.h cashbin.c
	gcc $(CFLAGS) -c cashbin.c

run: atmtest
	./atmtest

clean:
	rm *.o
