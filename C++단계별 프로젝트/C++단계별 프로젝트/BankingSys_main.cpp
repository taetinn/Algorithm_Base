/*
Banking System Ver.01
made by taetinn
*/

#include<iostream>
using namespace std;

void showMenu(void);
void makeAccount(void);
void Deposit(void);
void Withdrawal(void);
void showAllAcc(void);

 typedef struct  {
	int account;
	char name[100];
	int balance;
}  Mem;

 Mem mInfo[100];
 int accNum = 0;


int main(void) {
	int choice;

	while (1) {
		showMenu();
		cout << "�� �� : ";
		cin >> choice;
		cout << endl;

		switch (choice)
		{
		case 1:
			makeAccount();
			break;
		case 2:
			Deposit();
			break;
		case 3:
			Withdrawal();
			break;
		case 4 :
			showAllAcc();
			break;
		case 5:
			return 0;
		default:
			cout << "�ٽ� ������ �ֽʽÿ�." << endl;
		}
	}

	return 0;
}

void showMenu(void) {
	cout << "-----MENU-----" << endl;
	cout << "1. ���°���" << endl;
	cout << "2. �� ��" << endl;
	cout << "3. �� ��" << endl;
	cout << "4. �������� ��ü ���" << endl;
	cout << "5. ���α׷� ���� " << endl;
}

void makeAccount(void) {

	int id;
	char name[100];
	int money;

	cout << "[���°���]" << endl;
	cout << "����ID : "; cin >> id;
	cout << "�̸� : "; cin >> name;
	cout << "�Աݾ� : "; cin >> money;
	cout << endl;

	mInfo[accNum].account = id;
	strcpy_s(mInfo[accNum].name, name); // string �Է¹޾Ƽ� �迭�� ������ ���� strcpy�� ����Ѵ�.
	//mInfo[accNum].name = strcpy(name);
	mInfo[accNum].balance += money;
	accNum++;
}

void Deposit(void) {
	int id, money;

	cout << "[��	��]" << endl;
	cout << "����ID : "; cin >> id;
	cout << "�Աݾ� : "; cin >> money;

	for (int i = 0; i < accNum; i++) {
		if (mInfo[i].account == id) {
			mInfo[i].balance += money;
			cout << "�ԱݿϷ�" << endl;
			break;
		}
	}
	cout << "�������� �ʴ� �����Դϴ�.\n";
}

void Withdrawal(void) {

	int id, money;

	cout << "[��	��]" << endl;
	cout << "����ID : "; cin >> id;
	cout << "��ݾ� : "; cin >> money;
	cout << endl;
	for (int i = 0; i < accNum; i++) {
		if (mInfo[i].account == id) {
			if (mInfo[i].balance < money) {
				cout << "�ܾ׺���" << endl;
				return;
			}
			mInfo[i].balance -= money;
			cout << "��ݿϷ�" << endl;
			return;
		}
	}
	cout << "�������� �ʴ� �����Դϴ�." << endl;
}

void showAllAcc(void) {

	for (int i = 0; i < accNum; i++) {
		cout << "����ID : " << mInfo[i].account << endl;
		cout << "�̸� : " << mInfo[i].name << endl;
		cout << "�ܾ� : " << mInfo[i].balance << endl << endl;
	}
}