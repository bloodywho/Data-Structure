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

class Stack {

	private:
		Node* top;
		int count;
	public:
		Stack(int deger) {

			Node* node = new Node(deger);
			top = node;
			count = 1;
		}

		~Stack() {

			Node* temp = top;
			while (top != NULL) {

				top = top->next;
				delete temp;
				temp = top;
			}
		}

		void printAll() {

			Node* temp = top;
			while (temp != NULL) {

				cout << temp->deger << " , ";
				temp = temp->next;
			}
		}

		void printTop() {
			if (count > 0) {
				cout << "Top deger : " << top->deger << endl;
			}
			else
				return;
		}

		void getCount() {

			cout << "Stack eleman sayisi : " << count << endl;
		}

		void push(int deger) {

			Node* node = new Node(deger);
			node->next = top;
			top = node;
			count++;
		};

		int pop() {

			if (count == 0)
				return -1;

			Node* temp = top;
			int deger = top->deger;
			top = top->next;
			delete temp;
			count--;
			return deger;
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

	Stack* stack = new Stack(12);
	stack->push(11);
	stack->push(5);

	cout << "Pop edilen eleman : " << stack->pop() << endl;
	stack->printTop();
	stack->getCount();
	cout << "Stackte ki elemanlar :  ";
	stack->printAll();
	

	delete stack;

}