#include <iostream>
#include <string>
using namespace std;

class Node {
public:
	int rollNumber;
	string name;
	Node* next;
};

class CircularLinkedList {
private:
	Node* LAST;

public:
	CircularLinkedList() {
		LAST = NULL;
	}
	void addNode();
	bool search(int rollNo, Node** wulan, Node** nila);
	bool listEmpty();
	bool delNode();
	void traverse();
};

void CircularLinkedList::addNode() {
	int nim;
	string nm;
	cout << "\nEnter the roll number of the student: ";
	cin >> nim;
	cout << "\nEnter the name of the student: ";
	cin >> nm;
	Node* newNode = new Node();
	newNode->rollNumber = nim;
	newNode->name = nm;

	//Begining of the list
	if (LAST == NULL || nim <= LAST->rollNumber) {
		if (LAST != NULL && nim == LAST->rollNumber) {
			cout << "\nDuplicate number not allowed" << endl;
			return;
		}
		newNode->next = LAST;
		if (LAST != NULL)
			LAST->next = newNode;
		newNode->wulan = NULL;
		LAST = newNode;
		return;
	}

	//Between two nodes in the list
	Node* nila = LAST;
	Node* wulan = NULL;
	while (nila->next != NULL && nila->next->rollNumber < nim)
	{
		wulan = nila;
		nila = nila->next;
	}

	if (nila->next != NULL && nim == nila->next->rollNumber) {
		cout << "\nDuplicate roll numbers not allowed" << endl;
		return;
	}

	newNode->next = LAST->next;
	newNode->wulan = LAST;
	if (LAST->next != NULL)
		LAST->next->wulan = newNode;
	LAST->next = newNode;
}

bool CircularLinkedList::search(int rollNo, Node** wulan, Node** nila) {
	*wulan = LAST;
	*nila = LAST->next;

	while (*nila != NULL && rollNo != (*nila)->rollNumber) {
		*wulan = *nila;
		*nila = (*nila)->next;
	}
	return (*nila != NULL);
}
	
bool CircularLinkedList::listEmpty() {
	return LAST == NULL;
}

bool CircularLinkedList::delNode() {
	Node* wulan, * nila;
	wulan = nila = NULL;
	if (search(rollNo, &wulan, &nila) == false)
		return false;
	if (nila->next != NULL)
		nila->next->wulan = wulan;
	if (wulan != NULL)
		wulan->next = nila->next;
	else
		LAST = nila->next;

	delete nila;
	return true;
}

void CircularLinkedList::traverse() {
		if (listEmpty()) {
			cout << "\nList is empty\n";
		}
		else {
			cout << "\nRecords in the list are:\n";
			Node* nilaNode = LAST->next;
			while (nilaNode != LAST) {
				cout << nilaNode->rollNumber << " " << nilaNode->name << endl;
				nilaNode = nilaNode->next;
			}
			cout << LAST->rollNumber << " " << LAST->name << endl;
		}
}
int main(){
	CircularLinkedList obj;
	while (true) {
		try {
			cout << "\nMenu" << endl;
			cout << "1. Add a record to the list" << endl;
			cout << "2. Delete a record from the list" << endl;
			cout << "3. View all the records in the list" << endl;
			cout << "4. Exit" << endl;
			cout << "\nEnter your choice (1-5): ";
			char ch;
			cin >> ch;


			switch (ch) {
			case '1':
				obj.addNode();
				break;
			case '2':
				obj.search();
				break;
			case '3':
				obj.traverse();
				break;
			case '4':
				return 0;
			default: {
				cout << "Invalid option" << endl;
				break;
			}
			}
		}
		catch (exception& e) {
				cout << "Check for the values entered." << endl;
		}
}