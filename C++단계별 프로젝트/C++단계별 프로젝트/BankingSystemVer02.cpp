/*
Banking System Ver.02
made by taetinn
contents: degine 'Account' class, apply object pointer array
*/
#include<iostream>
#include<cstring>
#pragma warning (disable:4996)

const int NAME_LEN = 100;
using namespace std;

void showMenu(void);
void makeAccount(void);
void Deposit(void);
void Withdrawal(void);
void showAllAcc(void);

enum { MAKE = 1, DEPOSIT, WITHDRAW, INQUIRE, EXIT };
class Account {
private:
	int accID;
	int balance;
	char* cusName;

public:
	Account(int ID, int money, char* name): accID(ID), balance(money) {
		//int len = strlen(name)+1;
		cusName = new char[strlen(name)+1];
		strcpy(cusName, name);
	}
	int getAccID() { return accID; }
	void deposit(int money) {
		balance += money;
	}
	bool withdraw(int money) {
		if (balance < money) {
			cout << "�ܾ� ����" << endl;
			return 0;
		}
		balance -= money;
		return true;
	}
	void showAccInfo() {
		cout << "����ID : " << accID << endl;
		cout << "�̸� : " << &cusName << endl;
		cout << "�ܾ� : " << balance << endl;
		cout << "==============================" << endl;

	}
	~Account() {
		delete[]cusName;
	}
};

Account* accArr[100]; //obj pointer arr
int accNum = 0;

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
	char name[NAME_LEN];
	int money;

	cout << "[���°���]" << endl;
	cout << "����ID : "; cin >> id;
	cout << "�̸� : "; cin >> name;
	cout << "�Աݾ� : "; cin >> money;
	cout << endl;

	accArr[accNum++] = new Account(id, money, name);
}
void Deposit(void) {
	int id, money;

	cout << "[��	��]" << endl;
	cout << "����ID : "; cin >> id;
	cout << "�Աݾ� : "; cin >> money;

	for (int i = 0; i < accNum; i++) {
		if (accArr[i]->getAccID() == id) {
			accArr[i]->deposit(money);
			cout << "�ԱݿϷ�" << endl;
			
		}
		cout << "�������� �ʴ� �����Դϴ�." << endl;
	}
}

void Withdrawal(void) {
	int id, money;
	bool check;

	cout << "[��	��]" << endl;
	cout << "����ID : "; cin >> id;
	cout << "��ݾ� : "; cin >> money;
	cout << endl;
	for (int i = 0; i < accNum; i++) {
		if (accArr[i]->getAccID() == id) {
			 check = accArr[i]->withdraw(money);
			 if (check == true) { cout << "��ݿϷ�" << endl; }
		}
		cout << "�������� �ʴ� �����Դϴ�." << endl;
	}
	
}

void showAllAcc(void) {
	for (int i = 0; i < accNum; i++) {
		accArr[i]->showAccInfo();
		break;
	}
}

int main(void) {
	int choice;

	while (1) {
		showMenu();
		cout << "���� : ";
		cin >> choice;
		cout << endl;

		switch (choice) {
		case MAKE:
			makeAccount();
			break;
		case DEPOSIT:
			Deposit();
			break;
		case WITHDRAW:
			Withdrawal();
			break;
		case INQUIRE:
			showAllAcc();
			break;
		case EXIT:
			for (int i = 0; i < accNum; i++) { delete accArr[i]; }
			return 0;
		default:
			cout << "Illegal Selection" << endl;
		}
	}
	return 0;
}