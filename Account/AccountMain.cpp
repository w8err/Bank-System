#include <iostream>
#include "Account.h" // Account 클래스를 포함한 헤더 파일을 include

int main()
{
	int system = 1;
	Account* account = nullptr; // 계좌 객체를 동적으로 생성할 포인터를 선언

	while (system)
	{
		int choice = 0;

		std::cout << "작업 종류를 선택하세요: " << std::endl;
		std::cout << "1. 계좌 생성\n2. 계좌 입금\n3. 계좌에서 출금\n4. 송금\n5. 계좌 정보 조회\n0. 종료" << std::endl;
		std::cin >> choice;

		switch (choice)
		{
		case 1:
		{
			std::string accno, owner, password;
			int balance;

			std::cout << "계좌번호: ";
			std::cin >> accno;
			std::cout << "예금주: ";
			std::cin >> owner;
			std::cout << "잔액: ";
			std::cin >> balance;
			std::cout << "비밀번호: ";
			std::cin >> password;

			// Account 객체를 동적으로 생성
			account = new Account(accno, owner, balance, password);
			std::cout << "계좌가 생성되었습니다." << std::endl;
			break;
		}
		case 2:
		{
			int amount;
			std::cout << "입금할 금액: ";
			std::cin >> amount;

			if (account != nullptr)
			{
				account->deposit(amount);
			}
			else
			{
				std::cout << "계좌가 생성되지 않았습니다. 먼저 계좌를 생성해주세요." << std::endl;
			}
			break;
		}
		case 3:
		{
			int amount;
			std::string password;
			std::cout << "출금할 금액: ";
			std::cin >> amount;
			std::cout << "비밀번호: ";
			std::cin >> password;

			if (account != nullptr)
			{
				account->withdraw(amount, password);
			}
			else
			{
				std::cout << "계좌가 생성되지 않았습니다. 먼저 계좌를 생성해주세요." << std::endl;
			}
			break;
		}
		case 4:
		{
			int amount;
			std::string accno, password;
			std::cout << "송금할 계좌번호: ";
			std::cin >> accno;
			std::cout << "송금할 금액: ";
			std::cin >> amount;
			std::cout << "비밀번호: ";
			std::cin >> password;

			if (account != nullptr)
			{
				Account* targetAccount = new Account(accno, "", 0, ""); // 대상 계좌 생성
				account->transfer(targetAccount, amount, password);
				delete targetAccount; // 대상 계좌 삭제
			}
			else
			{
				std::cout << "계좌가 생성되지 않았습니다. 먼저 계좌를 생성해주세요." << std::endl;
			}
			break;
		}
		case 5:
		{
			std::string password;
			std::cout << "비밀번호: ";
			std::cin >> password;

			if (account != nullptr)
			{
				account->show(password);
			}
			else
			{
				std::cout << "계좌가 생성되지 않았습니다. 먼저 계좌를 생성해주세요." << std::endl;
			}
			break;
		}
		case 0:
			system = 0;
			break;
		default:
			std::cout << "유효하지 않은 선택입니다. 다시 선택해주세요." << std::endl;
			break;
		}
	}

	delete account; // 동적으로 생성한 계좌 객체를 삭제합니다.

	return 0;
}