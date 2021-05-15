# ATM Controller

This prject simulates a simple ATM controller that allows for the flow:
Insert Card => PIN number => Select Account => See Balance/Deposit/Withdraw

Also included are simple Bank, User, Account, and Cashbox APIs as well as a command line UI for testing purposes.


## Dowloading and compiling:
pull from github
run navigate to the directory and run `make` to compile.


## Files:
atm.c: Implementation of the ATM controller.  atm tracks the state of an ATM. For each state there is a set of commands that can change the state.  The states and commands are:
- WAITING: the ATM is waiting for a card to be inserted
  - `cardin card_num` inserts a card with number `card_num` and changes to state to CARDIN
- CARDIN: a card has been inserted
  - `verify pin_num` verifies the `pin_num` matches the account and changes the state to LOGGEDIN
  - `cardout` takes the card out and the state returns to WAITING
- LOGGEDIN: the account has been verified
  - `checking` changes state to INCHECKING
  - `saving` changes state to INSAVING
  - `cardout` takes the card out and returns the state to WAITING
- INCHECKING: further actions are taken on the user's checking account
  - `balance` prints the balance of the checking account.  State remains unchanged
  - `deposit amount` deposits `amount` into the checking account.  State remains unchanged
  - `withdraw amount` withdraws `amount` from the checking account.  State remains unchanged
  - `done` changes the state back to LOGGEDIN
  - `cardout` takes the card out and returns the state to WAITING
- INSAVING: further actions are taken on the user's checking account
  - `balance` prints the balance of the checking account.  State remains unchanged
  - `deposit amount` deposits `amount` into the checking account.  State remains unchanged
  - `withdraw amount` withdraws `amount` from the checking account.  State remains unchanged
  - `done` changes the state back to LOGGEDIN
  - `cardout` takes the card out and returns the state to WAITING

bank.c: simple bank API for testing.  A bank is a collection of multiple users.  The bank can have at max 10 users.  This can be changed in the bank struct in bank.h.  Currently, creating a bank will create a 2 user bank with:
  - user card number 101      password 11
  - user card number 102      password 22  
with all accounts initialized to 0.  This can be changed by changing the `bank_get` function.

user.c: simple API represnting a user for testing purposes.  A user has a card number, a checking account, and a savings account.  

account.c: Simple API for an account (ie a checking account, or a savings account).  An account currenlty consists sololy of an account balance.

cashbin.c: Simple cashbin API for testing.  The cashbin is intialized to having $100 and cannot go below 0.

ui.c: console UI for testing.  This contains the main control flow for using the ATM.


## Testing: 
To test the ATM using the APIs provided, run `make run` from the console.  This will open up an ATM to the waiting state.  Type `quit` at any point to close

### Example test 1:
ATM> cardin 101
ATM> verify 11
ATM> checking
ATM> balance
Balance: 0
ATM> deposit 10
New balance: 10
ATM> done
ATM> saving
ATM> balance
Balance: 0
ATM> cardout
ATM> quit