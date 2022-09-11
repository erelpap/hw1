#include <iostream>
using namespace std;
#include "split.h"

void printLL(Node* LinkedList){
	while ( LinkedList != nullptr){
		cout << LinkedList -> value << " ";
		LinkedList = LinkedList->next;
	}
	cout << endl;
}

int main()
{

// Node n11(8, nullptr);
// Node n10(36, &n11);
// Node n9(35, &n10);
// Node n8(34, &n9);
// Node n7(33, &n8);
// Node n6(32, &n7);
Node* n5 = new Node(104, nullptr);
Node* n4 = new Node(103, n5);
Node* n3 = new Node(18, n4);
Node* n2 = new Node(7, n3);
Node* n1 = new Node(22, n2);

// Node* start = &n1;
Node* e = nullptr;
Node* o = nullptr;

split(n1, o, e);

printLL(n1);
printLL(o);
printLL(e);

while(e != nullptr) {
	Node* temp = e->next;
	delete e;
	e = temp;
}

while(o != nullptr) {
	Node* temp = o->next;
	delete o;
	o = temp;
}




	return 0;
}
