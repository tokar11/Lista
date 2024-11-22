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
		Clear();
	}
	  void AddAtBeg(int value) {
		  Node* newNode = new Node(value);
		  if (!head) {
			  head = tail = newNode;
		  }
		  else {
			  newNode->next = head;
			  head->prev = newNode;
			  head = newNode;
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
	std::cout << "\nMenu:\n";
	std::cout << "1. Add item at the beginning of the list.\n";
	std::cout << "2. Add item at the end of the list.\n";
	std::cout << "3. Add item at a specified index.\n";
	std::cout << "4. Delete item from the beginning of the list.\n";
	std::cout << "5. Delete item from the end of the list.\n";
	std::cout << "6. Delete item from a specified index.\n";
	std::cout << "7. Display list\n";
	std::cout << "8. Display reversed list.\n";
	std::cout << "9. Clear list.\n";
	std::cout << "0. Exit.\n";
	std::cout << "Your choice: ";
}

int main()
{
	DoublyLinkedList list;
	int choice, value, index;

	do {
		menu();
		std::cin >> choice;
		switch (choice) {
		case 1:
			std::cout << "Enter value: ";
			std::cin >> value;
			list.AddAtBeg(value);
			break;
		case 2:
			std::cout << "Enter value: ";
			std::cin >> value;
			list.AddAtEnd(value);
			break;
		case 3:
			std::cout << "Enter index: ";
			std::cin >> index;
			std::cout << "Enter value: ";
			std::cin >> value;
			list.AddAtIndex(index, value);
			break;
		case 4:
			list.RemoveFromBeg();
			break;
		case 5:
			list.RemoveFromEnd();
			break;
		case 6:
			std::cout << "Enter index: ";
			std::cin >> index;
			list.RemoveAtIndex(index);
			break;
		case 7:
			std::cout << "List status: ";
			list.display();
			break;
		case 8:
			std::cout << "The list is in reverse order: ";
			list.DisplayReverse();
			break;
		case 9:
			list.Clear();
			std::cout << "List has been cleared\n";
			break;
		case 0:
			std::cout << "You left the program!\n";
			break;
		default:
			std::cout << "Incorrect case selection!\n";
		}
	} while (choice != 0);
	return 0;
}


