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

class Queue {

	private : 

		Node* head;
		Node* tail;
		int count;

	public:

		Queue(int deger) {
			Node* node = new Node(deger);
			head = node;
			tail = node;
			count = 1;
		}

		~Queue() {

			Node* temp = head;

			while (head != NULL) {

				head = head->next;
				delete temp;
				temp = head;
			}
		}

		void printAll() {

			Node* temp = head;

			while (temp != NULL) {

				cout << temp->deger << " , ";
				temp = temp->next;

			}
		}

		int getHeadValue() {

			if (count > 0) {

				Node* temp = head;
				return temp->deger;
			}
			else
				return INT_MIN;
		}

		int getTailValue() {

			if (count > 0) {

				Node* temp = tail;
				return temp->deger;
			}
			else
				return INT_MIN;
		}
		int getCount() {

			return count;
		}

		void appendQueue(int deger) {

			Node* node = new Node(deger);

			if (count == 0) {

				head = node;
				tail = node;
				node->next = NULL;
				count++;
			}
			else {

				tail->next = node;
				tail = node;
				count++;
			}
		}


		int deQueue() {

			if (count == 0)
				return INT_MIN;

			Node* temp = head;

			if (count == 1) {
				count--;
				return temp->deger;

			}
			else {
				head = head->next;
				count--;
				return temp->deger;
			}
			delete temp;
			
		}

		bool isEmpty() {

			if (count > 0) {
				
				return true;
			}
			else
				return false;
		}

};



int main() {

	Queue* queue = new Queue(12);

	queue->appendQueue(1);
	queue->appendQueue(4);
	queue->appendQueue(77);

	cout << "deQueue is : " << queue->deQueue() << endl;
	cout << "Count is : " << queue->getCount() << endl;
	cout << "Head is " << queue->getHeadValue() << endl;
	cout << "Tail is " << queue->getTailValue()<< endl;
	
	queue->printAll();





	delete queue;
}