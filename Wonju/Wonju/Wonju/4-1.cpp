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

public:
	Tree() {
		size = 0;
		root = NULL;
		Parent = NULL;
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
		if (curNode->getRightChild() == NULL) {
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
int main(void) {
	return 0;
}