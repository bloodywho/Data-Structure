#include <iostream>
using namespace std;

class Node {
public:
	int deger;
	Node* next;
	Node* prev;

	Node(int deger) {
		this->deger = deger;
		next = NULL;
		prev = NULL;
		 
	}
};

class DoublyLinkedList {

	private:
		Node* head;
		Node* tail;
		int count;

	public:
		DoublyLinkedList(int deger) {

			Node* node = new Node(deger);
			head = node;
			tail = node;
			count = 1;
	}
	void printList() {
		Node* tmp = head;
		while (tmp != NULL) {

			cout << tmp->deger << " , ";
			tmp = tmp->next;

		}
		cout << endl;
	}

	void printHead() {

		if (head != NULL)
			cout << "Head is : " << head->deger << endl;
	}
	void printTail() {

		if (tail != NULL)
			cout << "Tail is : " << tail->deger << endl;
	}
	void getCount() {

		cout << "List Count is : " << this->count << endl;
	}
	void appendList(int deger) {
		Node* node = new Node(deger);

		if (count == 0)
		{
			head = node;
			tail = node;
			count++;
		}
		else {
			tail->next = node;
			node->prev = tail;
			tail = node;
			count++;
		}
		
	}
	void DeleteLastNode(){

		if (count == 0) 
			return;

		Node* temp = tail;

		if (count == 1) {

			head = NULL;
			tail = NULL;
			count--;
		}
		else{
			
			tail = tail->prev;
			tail->next = NULL;
			count--;
		}
		delete temp;
	}
	void AddFirstNode(int deger1) {

		Node* node = new Node(deger1);

		if (count == 0) {

			appendList(deger1);

		}
		else if (count != 0) {

			head->prev = node;
			node->next = head;
			head = node;
			node->prev = NULL;
		}
		count++;
	}

	void deleteFirstNode() {

		Node* temp = head;

		if (count == 0)
			return;

		else if (count == 1) {

			head->next = NULL;
			tail->next = NULL;
			delete temp;
			count++;
		}
		else {

			head = head->next;
			delete temp;
			head->prev = NULL;
			count--;

		}
	}

	Node* getIndex(int tmp5) {

		if (tmp5 < 0 || tmp5 >= count)
			return NULL;

		Node* tmp4 = head;
		if(tmp5<count/2){

			for (int i = 0;i < tmp5;++i) {

				tmp4 = tmp4->next;
			}
		}
		else {
			tmp4 = tail;
			for (int i = count - 1;i >= tmp5;i--) {

				tmp4 = tmp4->prev;
			}
		}
		
		return tmp4;
	}

	bool setNode(int i, int deger) {

		Node* temp = getIndex(i+1);

		if (temp != NULL) {

			temp->deger = deger;
			return true;
		}
		else {
			return false;
		}
	}

	bool insertNode(int index, int deger) {

		if (index >= 0 && index <= count) {

			if (index == 0) {

				AddFirstNode(deger);
				return true;
			}

			if (index == count) {

				appendList(deger);
				return true;
			}
			Node* yeninode = new Node(deger);
			Node* leftNode = getIndex(index - 1);
			Node* rightNode = getIndex(index);
			yeninode->next = rightNode;
			yeninode->prev = leftNode;
			leftNode->next = yeninode;
			rightNode->prev = yeninode;

			count++;
			return true;
		}
		else
			return false;
	}

	void deleteNode(int i) {
		if (i < 0 || i >= count)
			return;

		if (count == 1 && i == 0) {
			Node* temp = head;
			head = NULL;
			tail = NULL;
			delete temp;
			count--;
			return;
		}

		if (i == 0) {
			Node* temp = head;
			head = head->next;
			if (head != NULL)
				head->prev = NULL;
			else
				tail = NULL;
			delete temp;
			count--;
			return;
		}

		Node* temp = getIndex(i);
		Node* leftNode = getIndex(i - 1);
		Node* rightNode = getIndex(i + 1);

		if (leftNode != NULL)
			leftNode->next = rightNode;

		if (rightNode != NULL)
			rightNode->prev = leftNode;

		delete temp;
		count--;
	}

	~DoublyLinkedList() {

		Node* temp = head;
		while (head != NULL) {
			head = head->next;
			delete temp;
			temp = head;
		}

	}

};

int main() {

	DoublyLinkedList* doublylinkedlist1 = new DoublyLinkedList(12);
	doublylinkedlist1->appendList(5);
	doublylinkedlist1->appendList(123);
	doublylinkedlist1->appendList(135);
	doublylinkedlist1->appendList(11);
	doublylinkedlist1->appendList(1234);
	doublylinkedlist1->appendList(2567);


	doublylinkedlist1->AddFirstNode(22);
	doublylinkedlist1->DeleteLastNode();
	doublylinkedlist1->deleteFirstNode();
	doublylinkedlist1->insertNode(1, 1);
	doublylinkedlist1->setNode(4, 13525);
	doublylinkedlist1->deleteNode(1);

	doublylinkedlist1->printHead();
	doublylinkedlist1->printTail();
	doublylinkedlist1->getCount();
	doublylinkedlist1->printList();

	cout << doublylinkedlist1->getIndex(1)->deger;

	delete doublylinkedlist1;
}