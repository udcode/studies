#include <iostream>
#include "clock.h"
#include "account.h"

using namespace std;

enum Action {
   STOP,
   BALANCE,
   DEPOSIT,
   WITHDRAW, 
   SUM_DEPOSIT,
   SUM_WITHDRAW
};

Action menu() {//function that return a menu enum
   cout << "enter 1 to get account balance" << endl;
   cout << "enter 2 to deposit money" << endl;
   cout << "enter 3 to withdraw money" << endl;
   cout << "enter 4 to see the sum of all Deposits" << endl;
   cout << "enter 5 to see the sum of all withdraws" << endl;
   cout << "enter 0 to stop" << endl;
   int x;
   cin >> x; 
   return (Action)x;//casting the x to the enum equivalent to the number inputed by user
}
//a function which  find the account given by user and returning the index of the account in the bank array
//@ param - Account* - array of accounts , int size- number of accounts
int findAccount(Account* bank, int size) {
   unsigned int number, code;
   cout << "please enter account number: ";
   cin >> number;
   int i = 0;
   while (i < size && bank[i].getAccountNumber() != number) { i++; if (i >= size)throw "ERROR: no such account number!\n"; }//if the account was not found
   cout << "please enter the code: ";
   cin >> code;
   if (bank[i].getCode() == code){ return i; }//if every thing is o.k. return the index of the account in the bank array
   else {throw "ERROR: wrong code!\n"; }

}

void printTransaction(Account a, Action ac, Clock &c) {//this function printing the acction made by user
   cout << c << "\t";//printing the time after the transaction was made
   switch (ac) {//using the Acction menu enum
   case BALANCE:
	   try {
		   cout << "Account #: " << a.getAccountNumber() << "\t";
		   cout << "balance: " << a.getBalance() << endl;
	   }
	   catch (const char * error) {
		   throw error;
	   }
	  break;
   case DEPOSIT:
	   cout << "Account #: " << a.getAccountNumber()<< "\t";
	   cout << "new balance: " << a.getBalance() << endl;
	   break;
   case WITHDRAW:
      cout << "Account #: " << a.getAccountNumber() << "\t";
      cout << "new balance: " << a.getBalance() << endl;
      break;
   case SUM_DEPOSIT:
      cout << "Sum of all deposits: " << Account::getSumDeposit() << endl;
      break;
   case SUM_WITHDRAW:
      cout << "Sum of all withdraws: " << Account::getSumWithdraw() << endl;
      break;
   }
}

//this function get the balance of a specific account
void getBalance(Account* bank, int size, Clock &c) {
   c += 20;//increasing the time by 20 seconds(the time takes to get the balance
   try {
	   printTransaction(bank[findAccount(bank, size)], BALANCE, c);//surrounded by try and catch for the findAccount function wich throws an exception if needed
   }
   catch (const char * error) { throw error; }//if an exception was thrown by the function throw the error to the main program
   }
//this function does the deposit
void cashDeposit(Account* bank, int size, Clock &c) {
	int i;
	try {
		i = findAccount(bank, size);//getting the index of the bank to act on
	}
	catch (const char* error) { cout << c; throw error; }//if an exception was thrown by the function throw the error to the main program
   float amount;
   c += 29;//changed from 30 with dan permision to make scense in using the ++ operator on clock
   cout << "enter the amount of the check: ";
   cin >> amount;
   try { bank[i].deposit(amount); }//trying to do the deposit
   catch (const char * error) {//if the deposit failed
	   throw error;}//throw the error to the main program
   printTransaction(bank[i], DEPOSIT, c);//if everithing went well print the action

   }
//this function does the withdraw
void cashWithdraw(Account* bank, int size, Clock &c) {
	int i;
	try {
		i = findAccount(bank, size);//getting the index of the bank to act on
	}
	catch (const char * error) { throw  error; }//if an exception was thrown by the function throw the error to the main program
   float amount;
   c += 49;//changed from 50 with dan permision to make scense in using the ++ operator on clock
   cout << "enter the amount of money to withdraw: ";
   cin >> amount;
   try {
	   bank[i].withdraw(amount);//trying to do the withdraw
   }
   catch (const char * error) {//if the withdraw failed
	  throw error;//throw the error to the main program
   }
	  printTransaction(bank[i], WITHDRAW, c);//if everithing went well print the action
}

int main() {
   Clock clock(8);//initializing the clock to 8 am
   Account bank[10];//intializing 10 accounts
   cout << "enter account number and code for 10 accounts:\n";//asking the user to input 10 accounts
   for (int i = 0; i < 10; i++) {
      try {
         cin >> bank[i];
         for (int j = 0; j < i; j++)
            if (bank[i].getAccountNumber() == bank[j].getAccountNumber())
               throw "ERROR: account number must be unique!\n";
      }
      catch (const char* msg) {//if the function throwed an exception
         cout << clock << '\t' << msg;
         i--;
      }
   }
   Action ac = menu();
   while (ac) {
      switch (ac) {
      case BALANCE:
		  try {
			  getBalance(bank, 10, clock);//getting the balance
		  }
		  catch (const char * error) { cout << error << "can't show balance\n"; }//if the function throwed an exception
		 break;
      case DEPOSIT:
		  try {
			  cashDeposit(bank, 10,++clock);//depositing money
		  }
		  catch (const char * error) { cout << error << "cannot deposit\n"; }//if the function throwed an exception
         break;
      case WITHDRAW:
		  try {
         cashWithdraw(bank, 10, ++clock);//withdrawing from the account
		  }
		  catch (const char * error) { cout << error << "cannot withdraw\n"; }//if the function throwed an exception
		  break;
      case SUM_DEPOSIT:
         clock += 60;
         printTransaction(bank[0], SUM_DEPOSIT, clock);//using the static fields to print the sum of deposit
         break;
      case SUM_WITHDRAW:
         clock += 60;
         printTransaction(bank[0], SUM_WITHDRAW, clock);//using the static fields to print the sum of withdrow
         break;
      }
      ac = menu();
   }
   
   return 0;
}
