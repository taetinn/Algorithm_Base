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
		cout << "선 택 : ";
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
			cout << "다시 선택해 주십시요." << endl;
		}
	}

	return 0;
}

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
	char name[100];
	int money;

	cout << "[계좌개설]" << endl;
	cout << "계좌ID : "; cin >> id;
	cout << "이름 : "; cin >> name;
	cout << "입금액 : "; cin >> money;
	cout << endl;

	mInfo[accNum].account = id;
	strcpy_s(mInfo[accNum].name, name); // string 입력받아서 배열에 저장할 때는 strcpy를 사용한다.
	//mInfo[accNum].name = strcpy(name);
	mInfo[accNum].balance += money;
	accNum++;
}

void Deposit(void) {
	int id, money;

	cout << "[입	금]" << endl;
	cout << "계좌ID : "; cin >> id;
	cout << "입금액 : "; cin >> money;

	for (int i = 0; i < accNum; i++) {
		if (mInfo[i].account == id) {
			mInfo[i].balance += money;
			cout << "입금완료" << endl;
			break;
		}
	}
	cout << "존재하지 않는 계좌입니다.\n";
}

void Withdrawal(void) {

	int id, money;

	cout << "[출	금]" << endl;
	cout << "계좌ID : "; cin >> id;
	cout << "출금액 : "; cin >> money;
	cout << endl;
	for (int i = 0; i < accNum; i++) {
		if (mInfo[i].account == id) {
			if (mInfo[i].balance < money) {
				cout << "잔액부족" << endl;
				return;
			}
			mInfo[i].balance -= money;
			cout << "출금완료" << endl;
			return;
		}
	}
	cout << "존재하지 않는 계좌입니다." << endl;
}

void showAllAcc(void) {

	for (int i = 0; i < accNum; i++) {
		cout << "계좌ID : " << mInfo[i].account << endl;
		cout << "이름 : " << mInfo[i].name << endl;
		cout << "잔액 : " << mInfo[i].balance << endl << endl;
	}
}