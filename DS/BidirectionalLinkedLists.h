#pragma once
#include <iostream>
using namespace std;
class BidirectionalLinkedLists{
private:
	struct Elem {
		int date;
		Elem *next;
		Elem *last;
	};
	Elem *first;
	int count;

public:
	void creteElem() {
		first = nullptr;
		int i;
		Elem *a;
		a = new Elem;
		cin >> i;
		a->date = i;
		first = a;
		a->next = first;
		a->last = NULL;
		count = 1;
		Elem *p;
		Elem *f = first;
		while (true) {
			if (f->next == first) {
				cin >> i;
				if (!i) {
					first->last = f;
					break;
				}
				p = new Elem;
				p->date = i;
				p->next = first;
				p->last = f;
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
		cout << "p\tp->date\tp->last\tp->next" << endl;
		while (k != count) { //k != count
			cout << p << "\t" << p->date << "\t" << p->last << "\t" << p->next << endl;
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
				p->last = f;
				first->last = p;
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
		first->last = p;
		first = p;
		count++;
		f = f->next;
		while (f != first) {
			if (f->next == first->next) {
				f->next = first;
				first->last = f;
				break;
			}
			f = f->next;
		}
	}

	void addElemMidIndex(int number, int index) {
		Elem *f = first;
		f = f->next;
		int k = 1;
		while (f != first) {
			if (k == index) {
				Elem *p;
				p = new Elem;
				p->date = number;
				p->next = f->next;
				p->last = f;
				f->next->last = p;
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
				p->last = f;
				f->next->last = p;
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
				first->last = f;
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
		f = f->next;
		while (f != first) {
			if (k == index) {
				Elem *tmp = f->next;
				f->next = f->next->next;
				f->next->last = f;
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
				first->last = f;
				count--;
				return;
			}
			f = f->next;
		}
	}


};

