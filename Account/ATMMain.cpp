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
//			return i; //�߰��ϸ� i�� ����
//		}
//	}
//	return -1;
//}
//
//void userDisplay(Account * pAcc[], int cnt, Account * user)
//{
//	cout << "ȯ���մϴ�. " << user->getOwner() << "��" << endl;
//	int sel = 0;
//	int amnt, idx;
//	string no, pw;
//	while (sel != 5)
//	{
//		cout << "1.�Ա�  2.���  3.�۱�  4.��ȸ  5.�α׾ƿ� : "; cin >> sel;
//		switch (sel)
//		{
//		case 1: 
//			cout << "�Աݾ� : "; cin >> amnt;
//			if (user->deposit(amnt))
//			{
//				cout << "�ԱݵǾ����ϴ�" << endl;
//			}
//			else
//			{
//				cout << "�Աݽ����Ͽ����ϴ�" << endl;
//			}
//			
//			break;
//		case 2: 
//			cout << "��ݾ� : "; cin >> amnt;
//			cout << "��й�ȣ : "; cin >> pw;
//			if (user->withdraw(amnt, pw))
//			{
//				cout << "��ݵǾ����ϴ�" << endl;
//			}
//
//			break;
//		case 3:
//			//���� ���¸� �Է¹�����
//			cout << "�۱ݰ��¹�ȣ : "; cin >> no;
//			cout << "�۱ݾ� : "; cin >> amnt;
//			cout << "��й�ȣ : "; cin >> pw;
//			// pAcc �迭�� �ִ��� ��ȸ(����� idx�� Ȯ��)
//			idx = findIndex(pAcc, cnt, no);
//			if (idx < 0)
//			{
//				cout << "��ϵ��� ���� �����Դϴ�." << endl;
//			}
//			else
//			{
//				if (user->transfer(pAcc[idx], amnt, pw))
//				{
//					cout << pAcc[idx]->getOwner() << "�Կ��� �۱ݵǾ����ϴ�" << endl;
//				}
//			}
//
//
//			// ��ϵ� ������ ��츸 transfer(pAcc[idx], ?, ?) ���·� ȣ��.
//
//			
//			break;
//		case 4: 
//			cout << "��й�ȣ : "; cin >> pw;
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
//	Account* pAcc[100]; //������ ������ ���¸� ������ �����͹迭
//	
//	pAcc[0] = new Account("1234-1234", "�����", 100000, "1234");
//	pAcc[1] = new Account("4321-4321", "ȫ�浿", 200000, "4321");
//	
//	int cnt = 2; //��ϵ� �����Ǽ��� �����ϴ� ����.
//	
//				 //UI�����
//	int sel=0, bal, del, result;
//	string no, own, pw;
//	while (sel != 5)
//	{
//		cout << "1.���µ���ϱ�  2.��ϰ��º���  3.���»����ϱ�  4.�α���  5.����  : ";
//		cin >> sel;
//		switch (sel)
//		{
//		case 1:
//			cout << "���ó��" << endl;
//			cout << "���¹�ȣ : "; cin >> no;
//			cout << "������ : "; cin >> own;
//			cout << "�ܾ� : "; cin >> bal;
//			cout << "��й�ȣ : "; cin >> pw;
//			pAcc[cnt++] = new Account(no, own, bal, pw);
//			cout << "��ϵǾ����ϴ�" << endl;
//			break;
//		case 2:
//			cout << "���º���" << endl;
//			for (int i = 0; i < cnt; i++)
//			{
//				pAcc[i]->info();
//			}
//
//
//			break;
//		case 3:
//			cout << "���»���" << endl;
//			cout << "������ ���¹�ȣ :"; cin >> no;
//			del = findIndex(pAcc, cnt, no);
//			if (del < 0)
//			{
//				cout << "���������ʴ� ����" << endl;
//			}
//			else
//			{
//				delete pAcc[del];
//				for (int i = del; i < cnt - 1; i++)
//				{
//					pAcc[i] = pAcc[i + 1];
//				}
//				cnt--;
//				cout << "�����Ǿ����ϴ�" << endl;
//			}
//
//
//
//			break;
//		case 4 : 
//			cout << "���¹�ȣ : "; cin >> no;
//			result = findIndex(pAcc, cnt, no);
//			if (result < 0)
//			{
//				cout << "��ϵ��� ���� �����Դϴ�." << endl;
//			}
//			else
//			{
//				userDisplay(pAcc, cnt, pAcc[result]);
//				//�����ȭ��.
//			}
//
//			break;
//
//		case 5:
//			cout << "����" << endl;
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