//#include<iostream>
//#include"Account.h"
//using namespace std;
//
//int findIndex(Account* p[], int cnt, string no)
//{
//	for (int i = 0; i < cnt; i++)
//	{
//		if (p[i]->getAccno() == no)
//		{
//			return i; //발견하면 i를 리턴
//		}
//	}
//	return -1;
//}
//
//void userDisplay(Account * pAcc[], int cnt, Account * user)
//{
//	cout << "환영합니다. " << user->getOwner() << "님" << endl;
//	int sel = 0;
//	int amnt, idx;
//	string no, pw;
//	while (sel != 5)
//	{
//		cout << "1.입금  2.출금  3.송금  4.조회  5.로그아웃 : "; cin >> sel;
//		switch (sel)
//		{
//		case 1: 
//			cout << "입금액 : "; cin >> amnt;
//			if (user->deposit(amnt))
//			{
//				cout << "입금되었습니다" << endl;
//			}
//			else
//			{
//				cout << "입금실패하였습니다" << endl;
//			}
//			
//			break;
//		case 2: 
//			cout << "출금액 : "; cin >> amnt;
//			cout << "비밀번호 : "; cin >> pw;
//			if (user->withdraw(amnt, pw))
//			{
//				cout << "출금되었습니다" << endl;
//			}
//
//			break;
//		case 3:
//			//보낼 계좌를 입력받은후
//			cout << "송금계좌번호 : "; cin >> no;
//			cout << "송금액 : "; cin >> amnt;
//			cout << "비밀번호 : "; cin >> pw;
//			// pAcc 배열에 있는지 조회(결과는 idx로 확인)
//			idx = findIndex(pAcc, cnt, no);
//			if (idx < 0)
//			{
//				cout << "등록되지 않은 계좌입니다." << endl;
//			}
//			else
//			{
//				if (user->transfer(pAcc[idx], amnt, pw))
//				{
//					cout << pAcc[idx]->getOwner() << "님에게 송금되었습니다" << endl;
//				}
//			}
//
//
//			// 등록된 계좌인 경우만 transfer(pAcc[idx], ?, ?) 형태로 호출.
//
//			
//			break;
//		case 4: 
//			cout << "비밀번호 : "; cin >> pw;
//			user->show(pw);
//			break;
//		case 5: break;
//			 
//		}
//	}
//
//}
//
//
//int main()
//{
//	Account* pAcc[100]; //앞으로 생성될 계좌를 저장할 포인터배열
//	
//	pAcc[0] = new Account("1234-1234", "장용훈", 100000, "1234");
//	pAcc[1] = new Account("4321-4321", "홍길동", 200000, "4321");
//	
//	int cnt = 2; //등록된 계좌의수를 관리하는 변수.
//	
//				 //UI만들기
//	int sel=0, bal, del, result;
//	string no, own, pw;
//	while (sel != 5)
//	{
//		cout << "1.계좌등록하기  2.등록계좌보기  3.계좌삭제하기  4.로그인  5.종료  : ";
//		cin >> sel;
//		switch (sel)
//		{
//		case 1:
//			cout << "등록처리" << endl;
//			cout << "계좌번호 : "; cin >> no;
//			cout << "예금주 : "; cin >> own;
//			cout << "잔액 : "; cin >> bal;
//			cout << "비밀번호 : "; cin >> pw;
//			pAcc[cnt++] = new Account(no, own, bal, pw);
//			cout << "등록되었습니다" << endl;
//			break;
//		case 2:
//			cout << "계좌보기" << endl;
//			for (int i = 0; i < cnt; i++)
//			{
//				pAcc[i]->info();
//			}
//
//
//			break;
//		case 3:
//			cout << "계좌삭제" << endl;
//			cout << "삭제할 계좌번호 :"; cin >> no;
//			del = findIndex(pAcc, cnt, no);
//			if (del < 0)
//			{
//				cout << "존재하지않는 계좌" << endl;
//			}
//			else
//			{
//				delete pAcc[del];
//				for (int i = del; i < cnt - 1; i++)
//				{
//					pAcc[i] = pAcc[i + 1];
//				}
//				cnt--;
//				cout << "삭제되었습니다" << endl;
//			}
//
//
//
//			break;
//		case 4 : 
//			cout << "계좌번호 : "; cin >> no;
//			result = findIndex(pAcc, cnt, no);
//			if (result < 0)
//			{
//				cout << "등록되지 않은 계좌입니다." << endl;
//			}
//			else
//			{
//				userDisplay(pAcc, cnt, pAcc[result]);
//				//사용자화면.
//			}
//
//			break;
//
//		case 5:
//			cout << "종료" << endl;
//			break;
//		
//		}
//	}
//
//
//
//
//	return 0;
//}