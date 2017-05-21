#pragma once
#include <iostream>
class BidirectionalLists {

private:
	struct Elem {
		int date;
		Elem *next;
		Elem *last;
	};
	Elem *first;
public:
	void creteElem() {
		first = nullptr;
		int i;
		Elem *a;
		a = new Elem;
		std::cin >> i;
		a->date = i;
		a->next = NULL;
		a->last = NULL;
		first = a;
		Elem *p;
		Elem *f = first;
		while (f != NULL) {
			if (f->next == NULL) {
				std::cin >> i;
				if (!i) break;
				p = new Elem;
				p->date = i;
				p->next = NULL;
				p->last = f;
				f->next = p;
			}
			f = f->next;
		}

	}

	void outElem() {
		Elem *p;
		int k = 0;
		p = first;
		std::cout << "p\tp->date\tp->last\tp->next" << std::endl;
		while (p != NULL) { //k != count
			std::cout << p << "\t" << p->date << "\t" << p->last << "\t" << p->next << std::endl;
			p = p->next;
			k++;
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
				p->last = f;
				f->next = p;
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
		p->last = nullptr;
		first->last = p;
		first = p;
	}

	void addElemMidIndex(int number, int index) {
		Elem *f = first;
		int k = 1;
		while (f != 0) {
			if (k == index) {
				Elem *p;
				p = new Elem;
				p->date = number;
				p->next = f->next;
				p->last = f;
				f->next->last = p;
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
				p->last = f;
				f->next->last = p;
				f->next = p;
			}
			f = f->next;
		}
	}

	void deleteElemHead() {
		Elem *f = first;
		first = f->next;
		first->last = nullptr;
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
		while (f != nullptr) {
			if (k == index) {
				Elem *tmp = f->next;
				f->next = f->next->next;
				f->next->last = f;
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
