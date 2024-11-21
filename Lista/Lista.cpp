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

public: 
	DoublyLinkedList() : head(nullptr), tail(nullptr) {}
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
	  void RemoveFromEnd() {
		  if (!tail) {
			  std::cout << "The list is empty.\n";
			  return;
		  }
		  Node* temp = tail;
		  tail = tail->prev;
		  if (tail) {
			  tail->next = nullptr;
		  }
		  else {
			  head = nullptr;
		  }
		  delete temp;
	  }
	  void RemoveAtIndex(int index) {
		  if (index == 0) {
			  RemoveFromBeg();
			  return;
		  }
		  Node* current = head;
		  int count = 0;
		  while (current && count < index) {
			  current = current->next;
			  count++;
		  }
		  if (!current) {
			  std::cout << "Index is out of range.\n";
			  return;
		  }
		  if (current->prev) {
			  current->prev->next = current->next;
		  }
		  if (current->next) {
			  current->next->prev = current->prev;
		  }
		  else {
			  tail = current->prev;
		  }
		  delete current;
	  }
	  void display() const {
		  if (!head) {
			  std::cout << "The list is empty.\n";
			  return;
		  }
		  Node* current = head;
		  while (current) {
			  std::cout << current->data << " ";
			  current = current->next;
		  }
		  std::cout << std::endl;
	  }
	  void DisplayReverse() const {
		  if (!tail) {
			  std::cout << "The list is empty.\n";
			  return;
		  }
		  Node* current = tail;
		  while (current) {
			  std::cout << current->data << " ";
			  current = current->prev;
		  }
		  std::cout << std::endl;
	  }
	  void Clear() {
		  while (head) {
			  RemoveFromBeg();
		  }
	  }
};
void menu() {

}

int main()
{
   
}


