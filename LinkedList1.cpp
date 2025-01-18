#include <iostream>
using namespace std;

class Node {
	public:
		int deger;
		Node* next;

		Node(int deger) {
			this->deger = deger;
			next = NULL;
		}
};

class LinkedList {
	private:
		Node* head;
		Node* tail;
		int count;
	
	public:
		LinkedList(int deger) {

			Node* node = new Node(deger);
			head = node;
			tail = node;
			count = 1;
		}
		~LinkedList() {

			Node* tmp = head;
			while (head != NULL) {
				head = head->next;
				delete tmp;
				tmp = head;
			}
		}
		void printHead() {

			if (head != NULL)
				cout << "Head is : " << head->deger << endl;
		}
		void printTail() {

			if (tail != NULL)
				cout <<"Tail is : "<< tail->deger<<endl;
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
			}
			else {
				tail->next = node;
				tail = node;
			}
			count++;
		}

		void printList() {
			Node* tmp = head;
			while (tmp != NULL) {

				cout << tmp->deger << " , ";
				tmp = tmp->next;

			}
			cout << endl;
		}

		void deleteLastNode() {
			Node* tmp1=head;
			Node* tmp2=head;
			if (count == 0)
				return;
			while (tmp1->next) {

				tmp2 = tmp1;
				tmp1 = tmp1->next;
			}
			tail = tmp2;
			tail->next = NULL;
			count--;
			if (count == 0) {
				head = NULL;
				tail = NULL;
			}
			delete tmp1;

		}

		void addFirst(int deger1) {

			Node* newNode = new Node(deger1);
			if (count == 0) {

				head = newNode;
				tail = newNode;
			}
			else {
				newNode->next = head;
				head = newNode;
			}
			count++;
		}
		void deleteFirstNode() {

			Node* tmp3 = head;
			if (count == 1) {
				head = NULL;
				tail = NULL;
			}
			else if (count == 0)
				return;
			else{
				head = head->next;
			}
			delete tmp3;
			count--;

		}

		Node* getIndex(int tmp5) {

			if (tmp5 < 0 || tmp5 >= count)
				return NULL;

			Node* tmp4 = head;
			for (int i = 0;i < tmp5;++i) {
				tmp4 = tmp4->next;
			}
			return tmp4;
		}

		bool setValue(int index, int yeni_deger) {

			Node* temp = getIndex(index);

			if (temp != NULL) {

				temp->deger = yeni_deger;
				return true;
			}
			return false;
		}

		bool insertNode(int index, int deger) {

			if (index<0 || index>count) {

				return false;
			}

			if (index == 0) {

				addFirst(deger);
				return true;
			}

			if (index == count) {

				appendList(deger);
				return true;
			}
			Node* yeninode = new Node(deger);
			Node* temp = getIndex(index-1);
			yeninode->next = temp->next;
			temp->next = yeninode;
			count++;
			return true;
		}


		void deleteNodeIndex(int index) {
			if (index >= 0 && index < count) {

				if (index == 0)
					deleteFirstNode();

				else if (index == count - 1)
					deleteLastNode();

				else {

					Node* del = getIndex(index);
					Node* temp = getIndex(index - 1);
					temp->next = del->next;
					delete del;
					count--;
				}
			}
		}
};

int main() {

	LinkedList* linkedlist1 = new LinkedList(12);
	linkedlist1->appendList(5);
	linkedlist1->appendList(21);
	linkedlist1->appendList(64);
	linkedlist1->appendList(2);

	linkedlist1->printHead();
	linkedlist1->printTail();
	linkedlist1->getCount();

	linkedlist1->deleteLastNode();
	cout << "Son Node un silinmesiyle olusan liste : ";
	linkedlist1->printList();
	
	linkedlist1->addFirst(123);
	cout << "Basa istedigimiz degeri atadýktan sonra olusan liste : ";
	linkedlist1->printList();

	linkedlist1->deleteFirstNode();
	cout << "Ilk Node un silinmesiyle olusan liste : ";
	linkedlist1->printList();

	cout << linkedlist1->getIndex(3)->deger << endl;

	linkedlist1->setValue(2, 1535);
	cout << "2. indexin degerinin degismesiyle olusan liste : ";
	linkedlist1->printList();

	linkedlist1->insertNode(3, 214);
	cout << "2. indexten sonraki index 3 oldugu için yeni degerimiz 214 ile olusan liste : ";
	linkedlist1->printList();

	linkedlist1->deleteNodeIndex(3);
	cout << "3. indexin silindikten sonra olusan liste : ";
	linkedlist1->printList();

	delete linkedlist1;  
}

