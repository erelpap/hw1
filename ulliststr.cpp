#include <cstddef>
#include <stdexcept>
#include "ulliststr.h"
#include <iostream>
using namespace std;

ULListStr::ULListStr()
{
  head_ = NULL;
  tail_ = NULL;
  size_ = 0;
}

ULListStr::~ULListStr()
{
  clear();
}

bool ULListStr::empty() const
{
  return size_ == 0;
}

size_t ULListStr::size() const
{
  return size_;
}

// WRITE YOUR CODE HERE

void ULListStr::push_back(const std::string& val){
	if(empty()){
		// an item is created. Since it is the first item both tail and head are the same
		Item* latest  = new Item;
		tail_ = latest;
		head_ = latest;
		tail_->first = 0;
		tail_->last = 1;
		tail_->val[tail_->first] = val; //val is put at the back of the item
		size_++;	
	}

	else if(tail_->last == ARRSIZE){ // the condition is valid if a new item is needed for a push back
		Item* latest  = new Item;
		Item* temp; 
		temp = tail_; // old tail is saved to manipulate the prev's and next's
		tail_ = latest;
		tail_->first = 0;
		tail_->last = 0;
		temp->next = tail_; //old tail's next is now tail
		tail_->prev = temp; //old tail is now tail->prev
		tail_->next = nullptr;
		tail_->val[tail_->last] = val;
		tail_->last++;
		size_++;
	}

	else{ // the condition when the list is not empty and we do not need a new item
		tail_->val[tail_->last] = val;
		tail_->last++;
		size_++;
	}
	
}

void ULListStr::pop_back(){
if(empty()){ // nothing to pop_back
	return;
}

else if(size_ == 1){ // if there is one element than the list can be deleted fully
	clear();
}

else if(tail_->last == 1){ // when the tail has one element
	Item* temp;
	temp = tail_;
	delete tail_; //old tail deleted to prevent memory leak
	tail_ = temp->prev; //new tail is old tail's prev
	tail_->next = nullptr;
	size_--;
}

else{ //normal pop_back where the item is still the same after pop_back
	tail_->last--;
	size_--;
}
}

void ULListStr::push_front(const std::string& val){

	if(empty()){
		// an item is created. Since it is the first item both tail and head are the same
		Item* latest  = new Item;
		tail_ = latest;
		head_ = latest;
		head_->first = 9;
		head_->last = 10;
		head_->val[head_->first] = val; //val is put at the front of the item
		size_++;
	}
	else if(head_->first == 0){  // the condition is valid if a new item is needed for a push front
		Item* latest = new Item;
		Item* temp;
		temp = head_; // old head is saved to manipulate the prev's and next's
		head_ = latest;
		head_->first = 9;
		head_->last = 10;
		head_->prev = nullptr;
		head_->next = temp; // old head is now head->next
		temp->prev = head_; //head is the prev of old head
		head_->val[head_->first] = val; //in the first of the new head val is assigned
		size_++;
	}
else{ // normal push front is done without any edge case situations
	head_->first--;
	head_->val[head_->first] = val;
	size_++;
}

}

void ULListStr::pop_front(){
	
if(empty()){
	return; //nothing to pop front
}

else if(size_ == 1){  //if there is one element than the list can be deleted fully
	clear();
}

else if(head_->first == 9){ // when the head has one element
	Item* temp;
	temp = head_;
	delete head_; // old head is deleted to prevent memory leak
	head_ = temp->next;  //new head is old head's next
	head_->prev = nullptr;


	size_--;
}
else{
	head_->first++;
	size_--;
}
}

std::string const & ULListStr::back() const{
if(empty()){
	return nullptr;
}
else{	
	return tail_->val[tail_->last - 1]; // since last is one bigger than last index 1 is subtracted
}
}

std::string const & ULListStr::front() const{
	if(empty()){
		return nullptr;
	}
	else{
		return head_->val[head_->first];
	}

}

std::string* ULListStr::getValAtLoc(size_t loc) const{
	if(loc >= size_ || loc < 0){ // the given conditions are invalid locs.
	// loc can not be bigger than size and cannot be less than 0
		return nullptr;
	}
	else{ 

		loc = loc + head_->first; //first may be greater than 0. To calculate the loc head->first is added to loc
		int atNode = loc/10; // since it item holds 10 values this gives the item that corresponds to loc
		int atArray = loc % 10; //loc mod 10 gives the index of the loc in the calculated item
		Item* temp = head_;
		for (int i = 0; i < atNode; i++){
			temp = temp->next;
		} // in the for loop we traverse until the calculated item
		return &temp->val[atArray]; //in that item the value at the calculated index is returned
	}
	
}


void ULListStr::set(size_t loc, const std::string& val)
{
  std::string* ptr = getValAtLoc(loc);
  if(ptr == NULL){
    throw std::invalid_argument("Bad location");
  }
  *ptr = val;
}

std::string& ULListStr::get(size_t loc)
{
  std::string* ptr = getValAtLoc(loc);
  if(ptr == NULL){
    throw std::invalid_argument("Bad location");
  }
  return *ptr;
}

std::string const & ULListStr::get(size_t loc) const
{
  std::string* ptr = getValAtLoc(loc);
  if(ptr == NULL){
    throw std::invalid_argument("Bad location");
  }
  return *ptr;
}

void ULListStr::clear()
{
  while(head_ != NULL){
    Item *temp = head_->next;
    delete head_;
    head_ = temp;
  }
  tail_ = NULL;
  size_ = 0;
}
