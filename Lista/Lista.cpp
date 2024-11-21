#include <iostream>

class DoublyLinkedList {
private:
	struct Node {
		int data;
		Node* prev;
		Node* next;
		Node(int val) : data(val), prev(nullptr), next(nullptr) {}
	};
	Node* head;
	Node* tail;

public: DoublyLinkedList() : head(nullptr), tail(nullptr) {}
	  ~DoublyLinkedList() {
		  clear();
	  }
	  void AddAtBeg(int value) {
		  Node* newNode = new Node(value);
		  if (!tail) {
			  head = tail = newNode;
		  }
		  else {
			  newNode->prev = tail;
			  tail->next = newNode;
			  tail = newNode;
		  }
	  }
	  void AddAtEnd(int value) {
		  Node* newNode = new Node(value);
		  if (!tail) {
			  head = tail = newNode;
		  }
		  else {
			  newNode->prev = tail;
			  tail->next = newNode;
			  tail = newNode;
		  }
	  }
	  void AddAtIndex(int index, int value) {
		  if (index == 0) {
			  AddAtBeg(value);
			  return;
		  }
		  Node* newNode = new Node(value);
		  Node* current = head;
		  int count = 0;
		  while (current && count < index - 1) {
			  current = current->next;
			  count++;
		  }
		  if (!current) {
			  std::cout << "Index out of range.\n";
			  delete newNode;
			  return;
		  }
		  newNode->next = current->next;
		  newNode->prev = current;
		  if (current->next) {
			  current->next->prev = newNode;
		  }
		  else {
			  tail = newNode;
		  }
		  current->next = newNode;
	  }
	  void RemoveFromBeg() {
		  if (!head) {
			  std::cout << "The list is empyt.\n";
			  return;
		  }
		  Node* temp = head;
		  head = head->next;
		  if (head) {
			  head->prev = nullptr;
		  }
		  else {
			  tail = nullptr;
		  }
		  delete temp;
	  }
};

int main()
{
   
}


