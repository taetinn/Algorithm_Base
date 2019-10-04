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
			cout << "잔액 부족" << endl;
			return 0;
		}
		balance -= money;
		return true;
	}
	void showAccInfo() {
		cout << "계좌ID : " << accID << endl;
		cout << "이름 : " << &cusName << endl;
		cout << "잔액 : " << balance << endl;
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
	cout << "1. 계좌개설" << endl;
	cout << "2. 입 금" << endl;
	cout << "3. 출 금" << endl;
	cout << "4. 계좌정보 전체 출력" << endl;
	cout << "5. 프로그램 종료 " << endl;
}


void makeAccount(void) {
	int id;
	char name[NAME_LEN];
	int money;

	cout << "[계좌개설]" << endl;
	cout << "계좌ID : "; cin >> id;
	cout << "이름 : "; cin >> name;
	cout << "입금액 : "; cin >> money;
	cout << endl;

	accArr[accNum++] = new Account(id, money, name);
}
void Deposit(void) {
	int id, money;

	cout << "[입	금]" << endl;
	cout << "계좌ID : "; cin >> id;
	cout << "입금액 : "; cin >> money;

	for (int i = 0; i < accNum; i++) {
		if (accArr[i]->getAccID() == id) {
			accArr[i]->deposit(money);
			cout << "입금완료" << endl;
			
		}
		cout << "존재하지 않는 계좌입니다." << endl;
	}
}

void Withdrawal(void) {
	int id, money;
	bool check;

	cout << "[출	금]" << endl;
	cout << "계좌ID : "; cin >> id;
	cout << "출금액 : "; cin >> money;
	cout << endl;
	for (int i = 0; i < accNum; i++) {
		if (accArr[i]->getAccID() == id) {
			 check = accArr[i]->withdraw(money);
			 if (check == true) { cout << "출금완료" << endl; }
		}
		cout << "존재하지 않는 계좌입니다." << endl;
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
		cout << "선택 : ";
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