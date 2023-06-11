#pragma once
#include<string>
#include<iostream>
#include "Account.h"
using namespace std;

class Account
{
private:
	string accno; // 계좌번호
	string owner; // 예금주
	int balance; // 잔액
	string password; // 비밀번호

public:
	Account(string no, string own, int bal, string password);
	int deposit(int amount);
	int withdraw(int amount, string password);
	int transfer(Account* acc, int amount, string password);
	int show(string password);
	void info();
	string getAccno();
	string getOwner();
};

Account::Account(string no, string own, int bal, string pass)
{
	accno = no;
	owner = own;
	balance = bal;
	password = pass;
}

int Account::deposit(int amount)
{
	if (amount < 0)
	{
		cout << "유효하지 않은 금액입니다. 입금 실패." << endl;
		return 0;
	}

	balance += amount;
	cout << amount << " 원이 계좌에 입금되었습니다." << endl;
	return balance;	
}

int Account::withdraw(int amount, string pass)
{
	if (pass != password)
	{
		cout << "유효하지 않은 비밀번호입니다. 출금 실패." << endl;
		return 0;
	}

	if (amount < 0)
	{
		cout << "유효하지 않은 금액입니다. 출금 실패." << endl;
		return 0;
	}

	if (balance < amount)
	{
		cout << amount << "원이 계좌에서 출금되었습니다." << endl;
		return balance;
	}
}

	int Account::transfer(Account * acc, int amount, string pass)
	{
		if (pass != password)
		{
			cout << "유효하지 않은 비밀번호입니다. 이체 실패. " << endl;
			return 0;
		}

		if (amount < 0)
		{
			cout << "유효하지 않은 금액입니다. 이체 실패. " << endl;
			return 0;
		}

		if (balance < amount)
		{
			cout << "잔액이 부족합니다. 이체 실패. " << endl;
			return 0;
		}
		
		balance -= amount;
		acc->balance += amount;
		cout << amount << "원이 계좌로 이체되었습니다. " << endl;
		return balance;
	}

	int Account::show(string pass)
	{
		if (pass != password)
		{
			cout << "유효하지 않은 비밀번호. 조회 실패." << endl;
			return 0;
		}

		cout << "계좌번호: " << accno << endl;
		cout << "예금주: " << owner << endl;
		cout << "잔액: " << balance << "원" << endl;
		return balance;
	}

	void Account::info()
	{
		cout << "계좌번호 : " << endl;
		cout << "예금주 : " << endl;
		cout << "잔액 : " << balance << "원" << endl;
	}

	string Account::getAccno()
	{
		return accno;
	}

	string Account::getOwner()
	{
		return owner;
	}