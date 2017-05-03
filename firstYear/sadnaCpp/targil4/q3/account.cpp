#include "account.h"
float Account::_sumDeposit =0;//initializing the static fields
float Account::_sumWithdraw =0;//initializing the static fields

float Account::getSumWithdraw()//get the static field of _sumwithdraw
{
	return _sumWithdraw;
}

float Account::getSumDeposit()//get the static field of _sumdeposet
{
	return _sumDeposit;
}

Account::Account(int aNumber, int code, float balance):accountNumber(aNumber),code(code),balance(balance){
	//if (code > 9999 || code < 1000)throw "ERROR: code must be of 4 digits!";/////why do we need two constructors??????it says to initial to 0!!!!!!!
	this->accountNumber = aNumber;
	this->code = code;
	this->balance = balance;
}
//dtor
Account::~Account()
{
}

float Account::getBalance()//getter for the balance field
{
	return this->balance;
}

void Account::setBalance(float b)//setter for the balance field
{
	this->balance = b;
}
int Account::getAccountNumber()//getter for the accountNumber field
{
	return this->accountNumber;
}
int Account::getCode()//getter for the code field
{
	return this->code;
}
//this function withdoraw the mooney from the account
float Account::withdraw(float nis)
{
	
	if (nis < 2501) {//if the amount is valid
		if (this->balance - nis > -6000)//and the balance after withdraw will be valid
		{
			this->balance -= nis;//take the money out of the account
			_sumWithdraw += nis;//tell the static field that a withdraw occurred
			return nis;
		}
		else
		{
			throw "ERROR: cannot have less than - 6000 NIS!\n";//if the balance after withdraw will not be valid
		}
	}
	else {
		throw "ERROR: cannot withdraw more than 2500 NIS!\n";//if the withdraw is not valid(over then 2500)
	 
	}
}
//this function deposit the cheque to the account
void Account::deposit(float cheque)
{
	if (cheque < 10001 && cheque >= 0) { this->balance += cheque; _sumDeposit += cheque; }//if the cheque is valid
	else if(cheque>10000) { throw "ERROR: cannot deposit more than 10000 NIS!"; }//if the cheque is not valid(over 10000) throw an exception
	else if (cheque<0) { throw "ERROR: cannot deposit a nagative amount!"; }//if the cheque is not valid(nagative amount) throw an exception
}
istream & operator >> (istream& in, Account & account) {//input operator over loading
	int anum, acode;//setting variables for tests
	in >> anum;
	in >> acode;
	if (anum < 0)throw "not a valid acount number\n";//if the account number iputed is not valid throw an exception
	if (acode < 1000 || acode>9999)throw"not a valid code format\n";//if the code iputed is not valid throw an exception
	//if everything is o.k.
	account.accountNumber = anum;
	account.code = acode;
	return in;
}