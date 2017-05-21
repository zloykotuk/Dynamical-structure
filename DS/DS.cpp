// DS.cpp: ���������� ����� ����� ��� ����������� ����������.
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
			cout << "1.�������� � ������� 2.�������� � �����" << endl;
			cout << "4.�������� � �������� 5.�������� � ����" << endl;
			cout << "������ �����: ";
			cin >> i;
		} while (!cin);
		if (i == 1) {
			cout << "��� ����� ��������:";
			int j;
			cin >> j;
			UL.addElemHead(j);
			UL.outElem();
		} else if (i == 2) {
			cout << "��� ����� ��������:";
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
			cout << "������������ ����" << endl;
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
		cout << "������� ��� ������:" << endl << "1.���������������" << endl << "2.��������������� ��������" << endl << "3.��������������" << endl << "4.�������������� ��������" << endl;
		int i;
		do {
				cout << "������ �����: ";
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
			cout << "����������� ������ ��� ����� �� ���" << endl;
		}
	}
    return 0;
}
