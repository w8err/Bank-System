#pragma once
#include<string>
#include<iostream>
#include "Account.h"
using namespace std;

class Account
{
private:
	string accno; // ���¹�ȣ
	string owner; // ������
	int balance; // �ܾ�
	string password; // ��й�ȣ

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
		cout << "��ȿ���� ���� �ݾ��Դϴ�. �Ա� ����." << endl;
		return 0;
	}

	balance += amount;
	cout << amount << " ���� ���¿� �ԱݵǾ����ϴ�." << endl;
	return balance;	
}

int Account::withdraw(int amount, string pass)
{
	if (pass != password)
	{
		cout << "��ȿ���� ���� ��й�ȣ�Դϴ�. ��� ����." << endl;
		return 0;
	}

	if (amount < 0)
	{
		cout << "��ȿ���� ���� �ݾ��Դϴ�. ��� ����." << endl;
		return 0;
	}

	if (balance < amount)
	{
		cout << amount << "���� ���¿��� ��ݵǾ����ϴ�." << endl;
		return balance;
	}
}

	int Account::transfer(Account * acc, int amount, string pass)
	{
		if (pass != password)
		{
			cout << "��ȿ���� ���� ��й�ȣ�Դϴ�. ��ü ����. " << endl;
			return 0;
		}

		if (amount < 0)
		{
			cout << "��ȿ���� ���� �ݾ��Դϴ�. ��ü ����. " << endl;
			return 0;
		}

		if (balance < amount)
		{
			cout << "�ܾ��� �����մϴ�. ��ü ����. " << endl;
			return 0;
		}
		
		balance -= amount;
		acc->balance += amount;
		cout << amount << "���� ���·� ��ü�Ǿ����ϴ�. " << endl;
		return balance;
	}

	int Account::show(string pass)
	{
		if (pass != password)
		{
			cout << "��ȿ���� ���� ��й�ȣ. ��ȸ ����." << endl;
			return 0;
		}

		cout << "���¹�ȣ: " << accno << endl;
		cout << "������: " << owner << endl;
		cout << "�ܾ�: " << balance << "��" << endl;
		return balance;
	}

	void Account::info()
	{
		cout << "���¹�ȣ : " << endl;
		cout << "������ : " << endl;
		cout << "�ܾ� : " << balance << "��" << endl;
	}

	string Account::getAccno()
	{
		return accno;
	}

	string Account::getOwner()
	{
		return owner;
	}