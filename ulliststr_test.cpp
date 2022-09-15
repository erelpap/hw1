/* Write your test code for the ULListStr in this file */
#include <iostream>
#include "ulliststr.h"
using namespace std;


int main(int argc, char* argv[])
{
ULListStr* trial = new ULListStr();
cout << endl;

// tests all three conditions in the push_back function:
// when the list is empty, when it is filled and when 
// it needs to create a new Item in the list (26 > ARRSIZE)
// and the usual case

cout << "PUSH_BACK 3 MAIN CONDITIONS" << endl;

for(int i = 0; i < 26; i++){
	trial->push_back(to_string(i));
} 

for(int i = 0; i < trial->size(); i++){
	cout << trial->get(i) << " ";
}

trial->clear();
cout << endl;

// tests all three conditions in the push_front function:
// when the list is empty, when it is filled and when 
// it needs to create a new Item in the list (26 > ARRSIZE) 
// and the usual case

cout << "PUSH_FRONT 3 MAIN CONDITIONS" << endl;

for(int i = 0; i < 26; i++){
	trial->push_front(to_string(i));
} 

for(int i = 0; i < trial->size(); i++){
	cout << trial->get(i) << " ";
}

trial->clear();
cout << endl;
// show it can correctly push_back after a push_front 
// which means a new Item must be created

cout << "PUSH_BACK AFTER PUSH_FRONT" << endl;

trial->push_front("a");
trial->push_back("b");
for(int i = 0; i < trial->size(); i++){
	cout << trial->get(i) << " ";
}

trial->clear();
cout << endl;

// show it can correctly push_front after a push_back 
// which means a new Item must be created

cout << "PUSH_FRONT AFTER PUSH_BACK" << endl;

trial->push_back("a");
trial->push_front("b");
for(int i = 0; i < trial->size(); i++){
	cout << trial->get(i) << " ";
}

trial->clear();
cout << endl;



// tests all three conditions in the pop_back function:
// when the list is filled, when it is filled and when 
// it needs to delete an item and traverse to the next Item and 
// when there are no items (trial->size() + 10 > trial->size())

cout << "POP_BACK 3 MAIN CONDITIONS" << endl;

for(int i = 0; i < 26; i++){
	trial->push_back(to_string(i));
} 
int initialSize = trial->size();
for(int i = 0; i < initialSize + 10; i++){
	trial->pop_back();
}

cout << "size: " << trial->size() << endl;

trial->clear();

// tests all three conditions in the pop_front function:
// when the list is filled, when it is filled and when 
// it needs to delete an Item and traverse to the next Item and 
// when there are no items (trial->size() + 10 > trial->size())

cout << "POP_FRONT 3 MAIN CONDITIONS" << endl;

for(int i = 0; i < 26; i++){
	trial->push_back(to_string(i));
} 
initialSize = trial->size();
for(int i = 0; i < initialSize + 10; i++){
	trial->pop_front();
}

cout << "size: " << trial->size() << endl;

trial->clear();

//tests pop_back works when there is one element left in the
// middle of the array of a single Item

cout << "POP_BACK WHEN LAST ELEMENT IN THE MIDDLE OF AN ARRAY" << endl;
for(int i = 0; i < 10; i++){
	trial->push_back(to_string(i)); // trial has 10 elements
} 

for(int i = 0; i < 5; i++){
	trial->pop_back(); // 5 are gone
}

for(int i = 0; i < 4; i++){
	trial->pop_front(); // 4 are gone
}
cout << "size: " << trial->size() << endl;
cout << "element: " << trial->front() << endl;
cout << "element: " << trial->back() << endl;

trial->pop_back();

cout << "size: " << trial->size() << endl;
// below statements abort and it should as there are no more elements

// cout << "element: " << trial->front() << endl;
// cout << "element: " << trial->back() << endl;


//tests pop_front works when there is one element left in the
// middle of the array of a single Item

cout << "POP_FRONT WHEN LAST ELEMENT IN THE MIDDLE OF AN ARRAY" << endl;

for(int i = 0; i < 10; i++){
	trial->push_back(to_string(i)); // trial has 10 elements
} 

for(int i = 0; i < 5; i++){
	trial->pop_back(); // 5 are gone
}

for(int i = 0; i < 4; i++){
	trial->pop_front(); // 4 are gone
}
cout << "size: " << trial->size() << endl;
cout << "element: " << trial->front() << endl;
cout << "element: " << trial->back() << endl;

trial->pop_front();

cout << "size: " << trial->size() << endl;
// below statements abort and it should as there are no more elements

// cout << "element: " << trial->front() << endl;
// cout << "element: " << trial->back() << endl;

// tests front() after push back and push front

cout << "FRONT AFTER PUSH BACK AND PUSH FRONT" << endl;

for(int i = 0; i < 26; i++){
	trial->push_back(to_string(i));
} 

cout << trial->front() << endl;

trial->clear();

for(int i = 0; i < 26; i++){
	trial->push_front(to_string(i));
} 

cout << trial->front() << endl;


// tests back() after push back and push front

cout << "BACK AFTER PUSH BACK AND PUSH FRONT" << endl;

for(int i = 0; i < 26; i++){
	trial->push_back(to_string(i));
} 

cout << trial->back() << endl;

trial->clear();

for(int i = 0; i < 26; i++){
	trial->push_front(to_string(i));
} 

cout << trial->back() << endl;

delete trial;
return 0;
}
