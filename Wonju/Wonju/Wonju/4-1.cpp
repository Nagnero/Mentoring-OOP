#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <cstring>
using namespace std;

class Node {
private:
	int value;
	Node* LeftChild;
	Node* RightChild;
	Node* Parent;

public:
	Node() {
		this->value = 0;
		this->LeftChild = NULL;
		this->RightChild = NULL;
		this->Parent = NULL;
	}
	void setValue(int data) { this->value = data; }
	int getValue() { return this->value; }

	void setLeftChild(Node* LeftChild) { this->LeftChild = LeftChild; }
	Node* getLeftChild() { return this->LeftChild; }

	void setRightChild(Node* RightChild) { this->RightChild = RightChild; }
	Node* getRightChild() { return this->RightChild; }
	
	void setParent(Node* Parent) { this->Parent = Parent; }
	Node* getParent() { return this->Parent; }

};

class Tree {
private:
	int size;
	Node* root;
	Node* Parent;
	Node* curNode;
public:
	Tree() {
		size = 0;
		root = NULL;
		Parent = NULL;
		curNode = NULL;
	}
	~Tree() {
		allocate(root);
	}
	Node* getRoot(){return root; }
	void INSERT(Node* curNode, int integer);
	void DELETE(int integer);
	void FIND(int integer);
	void PrintPreorder(Node* curNode);
	void PrintInorder(Node* curNode);
	void PrintPostorder(Node* curNode);
	void PrintLeafnode(Node* curNode);
	void allocate(Node* curNode);
};
void Tree::INSERT(Node* curNode, int integer) { // ��Ʈ ��尡 ���� ���
	if (root == NULL)
	{
		Node* newNode = new Node;
		newNode->setValue(integer);
		root = newNode;
		curNode = root;
		this->size++;
	}
	else if (curNode->getValue() > integer) { //���ο� ����� ���� �� ���� ���
		if (curNode->getLeftChild() == NULL) {
			Node* newNode = new Node;
			newNode->setValue(integer);
			curNode->setLeftChild(newNode);
			this->size++;
		}
		else { //���� �ڽ��� �ִ� ���
			if (curNode->getLeftChild()->getValue() == integer)
				return;
			INSERT(curNode->getLeftChild(), integer);
		}
	}
	else if (curNode->getValue() < integer) // ���� ��忡 ����� ������ ū ���
	{
		if (curNode->getRightChild() == NULL) { //������ �ڽ��� �ִ� ���
			Node* newNode = new Node;
			newNode->setValue(integer);
			curNode->setRightChild(newNode);
			this->size++;
		}
		else {
			if (curNode->getRightChild()->getValue() == integer)
				return;
			INSERT(curNode->getRightChild(), integer);
		}
	}
}
void Tree::PrintPreorder(Node* curNode) { // ������ȸ ���¿�
	if (curNode == nullptr)
		return;
	cout << curNode->getValue() << " ";
	PrintPreorder(curNode->getLeftChild()); 
	PrintPreorder(curNode->getRightChild());
}

void Tree::PrintInorder(Node* curNode) { // ������ȸ �����
	if (curNode == nullptr)
		return;
	PrintInorder(curNode->getLeftChild());
	cout << curNode->getValue() << " ";
	PrintInorder(curNode->getRightChild());
}

void Tree::PrintPostorder(Node* curNode) { // ������ȸ �¿���
	if (curNode == nullptr)
		return;
	PrintPostorder(curNode->getLeftChild());
	PrintPostorder(curNode->getRightChild());
	cout << curNode->getValue() << " ";
}

int main(void) {
	Tree* tree = new Tree;
	int Command = 0;
	int integer = 0;

	while (1)
	{
		cout << "Enter Any Command(1: Insert, 2:Delete, 3:Find, 4:Preorder, 5:Inorder, 6:Postorder, 7:Leaf node, 8:Exit) : ";
		cin >> Command;
		if (Command == 1)
		{
			cin >> integer;
			tree->INSERT(tree->getRoot(), integer);
		}
		else if (Command == 2)
		{

		}
		else if (Command == 3)
		{

		}
		else if (Command == 4)
		{
			tree->PrintPreorder(tree->getRoot());
			cout << endl;
		}
		else if (Command == 5)
		{
			tree->PrintInorder(tree->getRoot());
			cout << endl;
		}
		else if (Command == 6)
		{
			tree->PrintPostorder(tree->getRoot());
			cout << endl;
		}
		else if (Command == 7)
		{

		}
		else if (Command == 8)
		{
			break;
		}
		else
			cout << "���� ������ ���ڸ� �������ּ���";
	}
	
}