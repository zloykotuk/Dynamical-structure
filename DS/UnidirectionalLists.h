#pragma once
#include <iostream>
#include <conio.h>

class UnidirectionalLists{
private:
	struct Elem{
		int date;
		Elem *next;
	};
	Elem *first;

public:
	void createElem() {
		first = nullptr;
		int i;
		Elem *a;
		a = new Elem;
		std::cin >> i;
		a->date = i;
		a->next = nullptr;
		first = a;
		Elem *p;
		Elem *f = first;
		while (f != nullptr) { 
			if (f->next == nullptr) {
				std::cin >> i;
				if (!i) break;
				p = new Elem;
				p->date = i;
				p->next = nullptr;
				f->next = p;
			}
			f = f->next;
		}
		
}

	void outElem() {
		Elem *p;
		p = first;
		while (p) {
			std::cout << p->date  << "\t" << p->next << std::endl;
			p = p->next;
		}
	}

	void addElemEnd(int number) {
		Elem *f = first;
		Elem *p;
		while (f != nullptr) {
			if (f->next == nullptr) {
				p = new Elem;
				p->date = number;
				p->next = nullptr;
				f->next = p;
				break;
			}
			f = f->next;
		}
	}

	void addElemHead(int number) {
		Elem *f = first;
		while (f != nullptr) {
			Elem *p;
			p = new Elem;
			p->date = number;
			p->next = first;
			first = p;
			break;
		}
	}

	void addElemMidIndex(int number, int index) {
		Elem *f = first;
		int k = 1;
		while (f != 0){
			if (k == index) {
				Elem *p;
				p = new Elem;
				p->date = number;
				p->next = f->next;
				f->next = p;
				break;
			}
			k++;
			f = f->next;
		}
	}

	void addElemMidNumber(int number, int id) {
		Elem *f = first;
		while (f != 0) {
			if (f->date == id) {
				Elem *p;
				p = new Elem;
				p->date = number;
				p->next = f->next;
				f->next = p;
			}
			f = f->next;
		}
	}

	void deleteElemHead() {
		Elem *f = first;
		first = f->next;
		delete f;
	}

	void deleteElemMidIndex(int index) {
		if (index == 0) {
			deleteElemHead();
			return;
		}
		Elem *f = first;
		//index -= 2;
		int k = 1;
		while (f != nullptr){
			if (k == index) {
				Elem *tmp = f->next;
				f->next = f->next->next;
				delete tmp;
				break;
			}
			k++;
			f = f->next;
		}
	}

	void deleteElemEnd() {
		Elem *f = first;
		while (f != nullptr) {
			if (f->next->next == nullptr) {
				delete f->next;
				f->next = nullptr;
				return;
			}
			f = f->next;
		}
	}
};
