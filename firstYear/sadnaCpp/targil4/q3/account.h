#ifndef __ACCOUNT_H
#define __ACCOUNT_H
#include<iostream>
using namespace std;
class Account {
private:
	//private fields
	int accountNumber;
	int code;
	float balance;
	//static fields
	static float _sumWithdraw;
	static float _sumDeposit;
public:
	//getters for the static fields
	static float getSumWithdraw();
	static float getSumDeposit();
	//constructor
	Account(int aNumber = 0, int code = 0, float balance = 0);
	//distructer
	~Account();
	//functions
	float getBalance();//get the balance of the account(the private field)
	void setBalance(float b);//setter for the private field balance
	int getAccountNumber();//getter for the AccountNumber(the private field)
	int getCode();//getter for the Code(the private field)
	float withdraw(float nis);//this function does the withdraw
	void deposit(float cheque);//this function does the deposit
	//operator
	friend istream& operator >> (istream& in, Account & account);
	
};
istream& operator >> (istream& in, Account & account);
#endif // !__ACCOUNT_H
