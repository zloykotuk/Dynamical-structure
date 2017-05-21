// DS.cpp: определяет точку входа для консольного приложения.
//

#include "stdafx.h"
#include "UnidirectionalLists.h"
#include "UnidirectionalLinkedLists.h"
#include "BidirectionalLists.h"
#include "BidirectionalLinkedLists.h"
#include <iostream>
#include <conio.h>

using namespace std;

void createUnidirectionalLists() {
	UnidirectionalLists UL;
	UL.createElem();
	UL.outElem();
	while (true){
		int i;
		do {
			cout << "1.Добавити в початок 2.Добавити в кінець" << endl;
			cout << "4.Видалити з початоку 5.Видалити з кінця" << endl;
			cout << "Введіть число: ";
			cin >> i;
		} while (!cin);
		if (i == 1) {
			cout << "Яке число добавити:";
			int j;
			cin >> j;
			UL.addElemHead(j);
			UL.outElem();
		} else if (i == 2) {
			cout << "Яке число добавити:";
			int j;
			cin >> j;
			UL.addElemEnd(j);
			UL.outElem();
		} else if (i == 4) {
			UL.deleteElemHead();
			UL.outElem();
		} else if (i == 5) {
			UL.deleteElemEnd();
			UL.outElem();
		} else {
			cout << "Неправильний ввод" << endl;
		}
	}

}

void createUnidirectionalLinkedLists() {
	UnidirectionalLinkedLists ULL;
	cout << "true";
}

void createBidirectionalLists() {
	BidirectionalLists BL;
	cout << "true";
}

void createBidirectionalLinkedLists() {
	BidirectionalLinkedLists BLL;
	cout << "true";
}

int main() {
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);
	while (!kbhit()) {
		cout << "Виберіть тип списку:" << endl << "1.Однонаправлений" << endl << "2.Однонаправлений звязаний" << endl << "3.Двонаправлений" << endl << "4.Двонаправлений звязаний" << endl;
		int i;
		do {
				cout << "Введіть число: ";
				cin >> i;
		} while (!cin);
		if (i == 1) {
			createUnidirectionalLists();
		}
		else if (i == 2) {
			createUnidirectionalLinkedLists();
		}
		else if (i == 3) {
			createBidirectionalLists();
		}
		else if (i == 3) {
			createBidirectionalLinkedLists();
		}
		else {
			cout << "Неправильно введені дані ведіть ще раз" << endl;
		}
	}
    return 0;
}
