
#include <iostream>
#include <stdlib.h>
using namespace std;

class Node {
public:
	int data;
	Node* next;
};

class LList {
private:
	Node* first; 

public:
	LList() { first = NULL; }
	LList(int loopNum, int data);
	//~LList();

	void Display();
	void Insert(int index, int x);
	int Length();
};

LList::LList(int loopTimes, int dataOfFirst) {
	Node* last, * t;

	first = new Node;
	first->data = dataOfFirst;
	first->next = NULL;
	last = first;

	for (int i = 1; i < loopTimes; i++) {
		t = new Node;
		t->data = i;
		t->next = NULL;
		last->next = t;
		last = t;
	}
}
//Display LL
void LList::Display() {
	Node* p = first;
	while (p) {
		cout << p->data << " ";
		p = p->next;
	}
	cout << endl;
}
//Lengts of list
int LList::Length() {
	Node* p = first;
	int len = 0;

	while (p) {
		len++;
		p = p->next;
	}
	return len;
}

//Insert in LL at a given position
void LList::Insert(int index, int x) {
	Node* t, * p = first;

	if (index < 0 || index > Length())
		return;
	t = new Node;
	t->data = x;
	t->next = NULL;

	if (index == 0) {
		t->next = first;
		first = t;
	}
	else {
		for (int i = 0; i < index - 1; i++) {
			p = p->next;
		}
		t->next = p->next;
		p->next = t;
	}

}

int main()
{
	int firstNode, howMany, index, newValue;
	cout << "Enter an amount of nodes: \n" << endl;
	cin >> howMany;
	cout << "Enter the value for the first node: \n" << endl;
	cin >> firstNode;
	LList K(howMany, firstNode);
	cout << "\n";
	K.Display();
	cout << "\n" << "If you want to insert a new node, provide index and a new value!" << endl;
	cin >> index;
	cin >> newValue;
	K.Insert(index, newValue);
	cout << "\n";
	K.Display();
}