#include <iostream>
#include<queue>
using namespace std;


class Node {

	public:
		
		int deger;
		Node* left;
		Node* right;

		Node(int deger) {

			this->deger = deger;
			left = NULL;
			right = NULL;
		}
};
class BinarySearchTree {

	public:
		Node* root;

		BinarySearchTree() {

			root = NULL;
		}

		~BinarySearchTree() 
		{

			deleteAllNodes(root);
		}

		void deleteAllNodes(Node* node)
		{
			if (node == NULL)
				return;
			if (node->left != NULL)
			{
				deleteAllNodes(node->left);
			}
			if (node->right != NULL)
			{
				deleteAllNodes(node->right);
			}
			delete node;
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
			if(node->left)
			{
				DFSPreOrderPrintAll(node->left);
			}
			if (node->right != NULL) 
			{
				DFSPreOrderPrintAll(node->right);
			}
		}

		Node* DFSPreOrderSearch(Node* node, int aranan_deger) {

			if (node == NULL || node->deger == aranan_deger)
			{
				return node;
			}
			if (aranan_deger < node->deger)
			{
				return DFSPreOrderSearch(node->left, aranan_deger);
			}
			else {
				return DFSPreOrderSearch(node->right, aranan_deger);
			}
		}

		void DFSPostOrderPrintAll(Node* node) {

			if (node->left)
			{
				DFSPreOrderPrintAll(node->left);
			}
			if (node->right != NULL)
			{
				DFSPreOrderPrintAll(node->right);
			}
			cout << node->deger << " , ";
		}

		void DFSInOrderPrintAll(Node* node) {

			if (node->left)
			{
				DFSInOrderPrintAll(node->left);	
			}

			cout << node->deger << " , ";

			if (node->right != NULL)
			{
				DFSInOrderPrintAll(node->right);
			}
		
		}

		void BreadthFirstSearch() {

			queue<Node*> queue1;
			queue1.push(root);

			while (queue1.size() > 0) 
			{
				Node* temp = queue1.front();
				queue1.pop();
				cout << temp->deger << " , ";

				if (temp->left != NULL)
				{
					queue1.push(temp->left);
					
				}
				if (temp->right != NULL)
				{
					queue1.push(temp->right);
				}
			}
		}


};

int main() {

	BinarySearchTree* bst = new BinarySearchTree();


	bst->insertNode(52);
	bst->insertNode(27);
	bst->insertNode(15);
	bst->insertNode(30);
	bst->insertNode(78);
	bst->insertNode(65);
	bst->insertNode(53);
	
	bst->DFSPreOrderPrintAll(bst->root);  // DFS PRE ORDER ROOTTAN AÞAÐI ÖNCE SOL TARAFTAKÝLERÝ YAZDIRIR
	Node * ptr = bst->DFSPreOrderSearch(bst->root,78);
	if (ptr != NULL)
	{
		cout << "\nAradiginiz sonuc bulundu : " << ptr->deger << endl;
	}
	else 
	{
		cout << "\nAradiginiz sonuc BST icinde degildir" << endl;
	}

	bst->DFSPostOrderPrintAll(bst->root); // DFS POST ORDER EN AÞAÐIDAN YUKARI DOÐRU YAZAR!!!
	cout << endl;
	bst->DFSInOrderPrintAll(bst->root); // DFS IN ORDER 

	cout << endl;

	bst->BreadthFirstSearch(); // BFS QUEUE YAZILIÞI

}


/*


					52
			      /    \
				27		 78
			  /  \      /
			15    30   65
					 /
				   53


*/