#include <iostream>
using namespace std;

/*
class Node {
	public:
		int deger;
		Node* next;

		Node(int deger) {
			this->deger = deger;
			next = NULL;
		}
};

class DoubleEven {
	private:
		Node* head;
		Node* tail;
		int count;

	public:
		DoubleEven(int deger) {

			Node* node = new Node(deger);
			head = node;
			tail = node;
			count = 1;
		}
		~DoubleEven() {

			Node* tmp = head;
			while (head != NULL) {
				head = head->next;
				delete tmp;
				tmp = head;
			}
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

		void doubleEvens() {

			Node* temp = head;
			while (temp != NULL) {
				if (temp->deger % 2 == 0)
				{
					temp->deger = (temp->deger * 2);
					cout << temp->deger << " , ";
					temp = temp->next;
				}
				else
				{
					cout << temp->deger << " , ";
					temp = temp->next;
				}
				
			}

		}

		void printAll() {

			Node* temp = head;
			while (temp != NULL) {
				cout << temp->deger << " , ";
				temp = temp->next;
			}

		}


};


int main() {

	DoubleEven* doubleeven = new DoubleEven(1);
	doubleeven->appendList(2);
	doubleeven->appendList(3);
	doubleeven->appendList(4);
	doubleeven->appendList(5);
	doubleeven->appendList(6);
	doubleeven->appendList(7);
	doubleeven->appendList(8);
	doubleeven->appendList(9);

	doubleeven->printAll();
	cout << endl;
	doubleeven->doubleEvens();


}
*/


/*class Node {

	public:
		int deger;
		Node* next;

		Node(int deger) 
		{
			this->deger = deger;
			next = NULL;
		}
};

class sumPositiveElements {

	private:
		Node* head;
		Node* tail;
		int count=0;

	public:

		sumPositiveElements(int deger) {

			Node* node = new Node(deger);
			head = node;
			tail = node;
			count=1;
		}

		void addValue(int deger) {

			Node* node = new Node(deger);

			if (count == 0) 
			{
				head = node;
				tail = node;
				count++;
			}

			else 
			{
				tail->next = node;
				tail = node;
				count++;
			}

		}
		void printAll() {


			Node* temp = head;

			if (count == 0)
				return;

			while(temp!=NULL)
			{
				cout << temp->deger << " , ";
				temp = temp->next;
				count++;
		}
	}

		int sumAll() {
			Node* temp = head;
			int toplam = 0;

			while (temp != NULL) { // Liste sonuna kadar devam et.
				if (temp->deger > 0) { // Sadece pozitif deðerleri topla.
					toplam += temp->deger;
				}
				temp = temp->next; // Her durumda düðümü ilerlet.
			}
			return toplam; // Döngüden sonra toplamý döndür.
		}
};

int main() {

	sumPositiveElements *sumpositiveelements = new sumPositiveElements(12);

	sumpositiveelements->addValue(1);
	sumpositiveelements->addValue(2);
	sumpositiveelements->addValue(4);
	sumpositiveelements->addValue(-1);

	cout << "Listedeki pozitif sayilarin toplami : " << sumpositiveelements->sumAll()<<endl;

	sumpositiveelements->printAll();

}



*/

/*

class Node {

	public:
		Node* next;
		int deger;

		Node(int deger) 
		{
			this->deger = deger;
			next = NULL;
		}
};

class LinkedStack {

	private:
		Node* top;
		int count;

	public:
		LinkedStack(int deger) 
		{
			Node* node = new Node(deger);
			top = node;
			count++;
		}

		void push(int deger) {

			Node* node = new Node(deger);

			if (count == 0) 
			{
				top = node;
				count++;
			}
			else 
			{
				node->next = top;
				top = node;
				count++;
			}
		}

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

		void printAll() {

			Node* temp = top;
			while (temp != NULL) {

				cout << temp->deger << " , ";
				temp = temp->next;
			}



		}


};

int main() {

	LinkedStack* linkedstack = new LinkedStack(12);

	linkedstack->push(1);
	linkedstack->push(2);
	linkedstack->push(3);
	linkedstack->push(4);
	linkedstack->push(5);
	cout << "Pop edilen eleman : "<<linkedstack->pop();
	cout << endl;
	linkedstack->printAll();
	
        
}

*/

/*
class Node {

	public:
		Node* left;
		Node* right;
		int deger;

		Node(int deger) {

			this->deger = deger;
			left = NULL;
			right= NULL;
		}

};
class OddCount {

	public:
		Node* root;
		int count;
		int toplam;

		OddCount() {

			root = NULL;	
		}

		bool insertNode(int deger) {

			Node* node = new Node(deger);

			if (root == NULL) {

				root = node;
				return true;
			}
			Node* temp = root;

			while (true) {
				if (node->deger == temp->deger)
				{
					cout << "Tree de olan deger tekrardan eklenmeye calisiyor " << endl;
					return false;
				}

				if (node->deger < temp->deger) {

					if (temp->left == NULL) {

						temp->left = node;
						return true;
					}
					temp = temp->left;
				}

				else {

					if (temp->right == NULL) {

						temp->right = node;
						return true;
					}
					temp = temp->right;

				}
			}
		}

		void DFSPreOrderPrintAll(Node* node) {

			cout << node->deger << " , ";
			if (node->left)
			{
				if (node->deger % 2 == 1)
					toplam++;
				DFSPreOrderPrintAll(node->left);
			}
			if (node->right != NULL)
			{
				if (node->deger %2==1)
					toplam++;
				DFSPreOrderPrintAll(node->right);
			}
		}



};

int main() {

	OddCount* oddcount = new OddCount();

	oddcount->insertNode(1);
	oddcount->insertNode(21);
	oddcount->insertNode(123);
	oddcount->insertNode(3);
	oddcount->insertNode(12);
	oddcount->insertNode(11);

	oddcount->DFSPreOrderPrintAll(oddcount->root);
	cout << endl;
	cout << oddcount->toplam;
	

}
*/


/*
class Node {

	public: 
		int deger;
		Node* next;

		Node(int deger) {

			this->deger = deger;
			next = NULL;
		}
};

class DeleteNth {

	public:
		Node* head;
		Node* tail;
		int count;
		int index;

	

		DeleteNth(int deger) {

			Node* node = new Node(deger);
			head = node;
			tail = node;
			count++;
		}
		
		void insertNode(int deger) {

			Node* node = new Node(deger);
			if (count == 0) {
				head = node;
				tail = node;
				count++;
			}

			else
			{
				tail->next = node;
				tail = node;
				count++;
			}
		}

		void printAll() {

			Node* temp = head;
			if (count == 0)
				return;
			else {
				while (temp != NULL) 
				{
					cout << temp->deger << " , ";
					temp = temp->next;
				}
			}
		}


		void SearchAll(int index) {
			Node* temp = head;
			if (count == 0)
				return;
			else {
				while (temp != NULL)
				{
					if (temp->deger == index) {
						temp = temp->next;
					}
					else {
						cout << temp->deger << " , ";
						temp = temp->next;
					}
				}
			}
		}

};

int main() {

	DeleteNth* deleteNth = new DeleteNth(1);

	deleteNth->insertNode(2);
	deleteNth->insertNode(3);
	deleteNth->insertNode(4);
	deleteNth->insertNode(5);
	deleteNth->printAll();

	cout << "\nLutfen silmek istediginiz sayiyi secin : ";
	cin >> deleteNth->index;

	deleteNth->SearchAll(deleteNth->index);



}

*/



class Node {

public:
	Node* next;
	int deger;

	Node(int deger) {

		this->deger = deger;
		next = NULL;
	}
};

class ExchangeNode {

private:
	Node* head;
	Node* tail;
	int count;

public:

	ExchangeNode(int deger)
	{
		Node* node = new Node(deger);
		head = node;
		tail = node;
		count = 1;
	}

	void printAll() {

		Node* temp = head;
		while (temp != NULL) {

			cout << temp->deger << " , ";
			temp = temp->next;
		}
	}

	void insertNode(int deger) {

		Node* node = new Node(deger);
		if (count == 0)  // Düzeltme: == kullanýldý
		{
			head = node;
			tail = node;
			count++;
		}

		else
		{
			tail->next = node;
			tail = node;
			count++;
		}
	}

	Node* findNodeByValue(int value) {
		Node* current = head;
		while (current) {
			if (current->deger == value) {
				return current;
			}
			current = current->next;
		}
		return nullptr;
	}

	bool swapValues(int value1, int value2) {

		if (value1 == value2 || count <= 1) // Ayný deðerler veya tek elemanlý liste
			return false;

		Node* node1 = findNodeByValue(value1);
		Node* node2 = findNodeByValue(value2);

		if (node1 && node2) {
			int temp = node1->deger;
			node1->deger = node2->deger;
			node2->deger = temp;
			return true;
		}

		return false;
	}

};

int main() {

	ExchangeNode* exchangenode = new ExchangeNode(1);

	exchangenode->insertNode(2);
	exchangenode->insertNode(3);
	exchangenode->insertNode(4);

	exchangenode->printAll();
	cout << endl;

	if (exchangenode->swapValues(1,3)) {
		cout << "Swap successful!" << endl;
	}
	else {
		cout << "Swap failed!" << endl;
	}

	exchangenode->printAll();

	delete exchangenode; // Hafýza temizliði

	return 0;
}
