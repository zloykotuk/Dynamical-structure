#pragma once
#include <iostream>
#include <windows.h>

class UnidirectionalLinkedLists {
private:
	struct Elem {
		int date;
		Elem *next;
	};
	Elem *first;
	//Elem *end;
	int count;

public:
	void createElem() {
		first = nullptr;
		int i;
		Elem *a;
		a = new Elem;
		std::cin >> i;
		a->date = i;
		first = a;
		a->next = first;
		count = 1;
		Elem *p;
		Elem *f = first;
		while (true) {
			if (f->next == first) {
				std::cin >> i;
				if (!i) break;
				p = new Elem;
				p->date = i;
				p->next = first;
				f->next = p;
				count++;
			}
			f = f->next;
		}

	}

	void outElem() {
		Elem *p;
		int k = 0;
		p = first;
		std::cout << first << std::endl;
		while (k != count) { //k != count
			std::cout << p->date << "\t" << p->next << std::endl;
			p = p->next;
			k++;
		}
	}

	void addElemEnd(int number) {
		Elem *f = first;
		f = f->next;
		Elem *p;
		while (f != first) {
			if (f->next == first) {
				p = new Elem;
				p->date = number;
				p->next = first;
				f->next = p;
				count++;
				break;
			}
			f = f->next;
		}
	}

	void addElemHead(int number) {
		Elem *f = first;
		Elem *p;
		p = new Elem;
		p->date = number;
		p->next = first;
		first = p;
		count++;
		f = f->next;
		while (f != first) {
			if (f->next == first->next) {
				f->next = first;
				break;
			}
			f = f->next;
		}

	}

	void addElemMidIndex(int number, int index) {
		Elem *f = first;
		f = f->next;
		int k = 2;
		while (f != first) {
			if (k == index) {
				Elem *p;
				p = new Elem;
				p->date = number;
				p->next = f->next;
				f->next = p;
				count++;
				break;
			}
			k++;
			f = f->next;
		}
	}

	void addElemMidNumber(int number, int id) {
		Elem *f = first;
		f = f->next;
		while (f != first) {
			if (f->date == id) {
				Elem *p;
				p = new Elem;
				p->date = number;
				p->next = f->next;
				f->next = p;
				count++;
			}
			f = f->next;
		}
	}

	void deleteElemHead() {
		Elem *p = first;
		Elem *k = first;
		first = p->next;
		delete p;
		count--;
		Elem *f = first;
		f = f->next;
		while (f != first) {
			if (f->next == k) {
				f->next = first;
				break;
			}
			f = f->next;
		}
	}

	void deleteElemMidIndex(int index) {
		if (index == 0) {
			deleteElemHead();
			return;
		}
		Elem *f = first;
		//index -= 2;
		int k = 1;
		while (f != nullptr) {
			if (k == index) {
				Elem *tmp = f->next;
				f->next = f->next->next;
				delete tmp;
				count--;
				break;
			}
			k++;
			f = f->next;
		}
	}

	void deleteElemEnd() {
		Elem *f = first;
		f = f->next;
		while (f != first) {
			if (f->next->next == first) {
				delete f->next;
				f->next = first;
				count--;
				return;
			}
			f = f->next;
		}
	}
};
