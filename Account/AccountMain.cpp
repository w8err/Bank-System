#include <iostream>
#include "Account.h" // Account Ŭ������ ������ ��� ������ include

int main()
{
	int system = 1;
	Account* account = nullptr; // ���� ��ü�� �������� ������ �����͸� ����

	while (system)
	{
		int choice = 0;

		std::cout << "�۾� ������ �����ϼ���: " << std::endl;
		std::cout << "1. ���� ����\n2. ���� �Ա�\n3. ���¿��� ���\n4. �۱�\n5. ���� ���� ��ȸ\n0. ����" << std::endl;
		std::cin >> choice;

		switch (choice)
		{
		case 1:
		{
			std::string accno, owner, password;
			int balance;

			std::cout << "���¹�ȣ: ";
			std::cin >> accno;
			std::cout << "������: ";
			std::cin >> owner;
			std::cout << "�ܾ�: ";
			std::cin >> balance;
			std::cout << "��й�ȣ: ";
			std::cin >> password;

			// Account ��ü�� �������� ����
			account = new Account(accno, owner, balance, password);
			std::cout << "���°� �����Ǿ����ϴ�." << std::endl;
			break;
		}
		case 2:
		{
			int amount;
			std::cout << "�Ա��� �ݾ�: ";
			std::cin >> amount;

			if (account != nullptr)
			{
				account->deposit(amount);
			}
			else
			{
				std::cout << "���°� �������� �ʾҽ��ϴ�. ���� ���¸� �������ּ���." << std::endl;
			}
			break;
		}
		case 3:
		{
			int amount;
			std::string password;
			std::cout << "����� �ݾ�: ";
			std::cin >> amount;
			std::cout << "��й�ȣ: ";
			std::cin >> password;

			if (account != nullptr)
			{
				account->withdraw(amount, password);
			}
			else
			{
				std::cout << "���°� �������� �ʾҽ��ϴ�. ���� ���¸� �������ּ���." << std::endl;
			}
			break;
		}
		case 4:
		{
			int amount;
			std::string accno, password;
			std::cout << "�۱��� ���¹�ȣ: ";
			std::cin >> accno;
			std::cout << "�۱��� �ݾ�: ";
			std::cin >> amount;
			std::cout << "��й�ȣ: ";
			std::cin >> password;

			if (account != nullptr)
			{
				Account* targetAccount = new Account(accno, "", 0, ""); // ��� ���� ����
				account->transfer(targetAccount, amount, password);
				delete targetAccount; // ��� ���� ����
			}
			else
			{
				std::cout << "���°� �������� �ʾҽ��ϴ�. ���� ���¸� �������ּ���." << std::endl;
			}
			break;
		}
		case 5:
		{
			std::string password;
			std::cout << "��й�ȣ: ";
			std::cin >> password;

			if (account != nullptr)
			{
				account->show(password);
			}
			else
			{
				std::cout << "���°� �������� �ʾҽ��ϴ�. ���� ���¸� �������ּ���." << std::endl;
			}
			break;
		}
		case 0:
			system = 0;
			break;
		default:
			std::cout << "��ȿ���� ���� �����Դϴ�. �ٽ� �������ּ���." << std::endl;
			break;
		}
	}

	delete account; // �������� ������ ���� ��ü�� �����մϴ�.

	return 0;
}