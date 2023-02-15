#include <iostream>
using namespace std;

class Node {//��� Ŭ���� ����
private:
	int data;//�����Ͱ�
	Node* leftChild;
	Node* rightChild;
	Node* parent;

public:
	Node() {//�ڵ�������
		this->data = 0;//�ʱ�ȭ
		this->leftChild = NULL;
		this->rightChild = NULL;
		this->parent = NULL;
	}

	void setData(int data) { this->data = data; }
	int getData() { return this->data; }
	void setParent(Node* nextNode) { this->parent = nextNode; }
	Node* getParent() { return this->parent; }
	void setLeftChild(Node* leftChild) { this->leftChild = leftChild; }
	Node* getLeftChild() { return this->leftChild; }
	void setRightChild(Node* rightChild) { this->rightChild = rightChild; }
	Node* getRightChild() { return this->rightChild; }
};

class Tree {//tree Ŭ���� ����
private:
	Node* root;//�ֻ� ���
	Node* parent;//�θ� ���
	int size;//tree ����
public:
	Tree() {//�ڵ�������
		this->root = NULL;//�ʱ�ȭ
		this->parent = NULL;
		this->size = 0;
	}
	~Tree() {//���� �Ҵ� ���� (��� ����)
		deallocate(root);
	}
	
	Node* getRoot() { return root; }
	void INSERT(Node* curNode, int data);
	//void DELETE(int data);
	//void FIND(int data);
	void PRINT_PRE(Node* curNode);
	void PRINT_IN(Node* curNode);
	void PRINT_POST(Node* curNode);
	void PRINT_LEAF(Node* curNode);//����Ʈ �ϳ� �����鼭 �ڽ� ��� ���� ���� ���
	void deallocate(Node* curNode);
};

void Tree::INSERT(Node* curNode, int data) {//����
	if (root == NULL) {//��Ʈ ��尡 ���� ��� (ù ���� (���� �ߺ� ���ɼ� ����))
		Node* newNode = new Node;
		newNode->setData(data);//����� ������ ����
		root = newNode; //���� ��� = root
		//curNode = root;
		this->size++;
	}
	else if (curNode->getData() > data) {//���� �̵�
		if (curNode->getLeftChild() == NULL) {//���� ���� X -> ���ʿ� ����
			Node* newNode = new Node;
			newNode->setData(data);
			curNode->setLeftChild(newNode);
			this->size++;
		}
		else {//���� ���� 0 -> curNode ���� �ڽ����� �̵��� INSERT �Լ� �ٽ� ����
			if (curNode->getLeftChild()->getData() == data)
				return;//�ߺ� ����
			INSERT(curNode->getLeftChild(), data);//INSERT �Լ� �ٽ� ����
		}
	}
	else if (curNode->getData() < data) {//������ �̵�
		if (curNode->getRightChild() == NULL) {//������ ���� X -> �����ʿ� ����
			Node* newNode = new Node;
			newNode->setData(data);
			curNode->setRightChild(newNode);
			this->size++;
		}
		else {//������ ���� 0 -> curNode ������ �ڽ����� �̵��� INSERT �Լ� �ٽ� ����
			if (curNode->getRightChild()->getData() == data)
				return;//�ߺ� ����
			INSERT(curNode->getRightChild(), data);
		}
	}
}

void Tree::PRINT_PRE(Node* curNode) { // ������ȸ
	if (curNode == nullptr)
		return;
	cout << curNode->getData() << " ";
	PRINT_PRE(curNode->getLeftChild());
	PRINT_PRE(curNode->getRightChild());
}

void Tree::PRINT_IN(Node* curNode) { // ������ȸ
	if (curNode == nullptr)
		return;
	PRINT_IN(curNode->getLeftChild());
	cout << curNode->getData() << " ";
	PRINT_IN(curNode->getRightChild());
}

void Tree::PRINT_POST(Node* curNode) { // ������ȸ
	if (curNode == nullptr)
		return;
	PRINT_POST(curNode->getLeftChild());
	PRINT_POST(curNode->getRightChild());
	cout << curNode->getData() << " ";
}

void Tree::PRINT_LEAF(Node* curNode) {//leaf node ���
	if (curNode == nullptr)
		return;
	PRINT_LEAF(curNode->getLeftChild());
	if(curNode->getLeftChild()==NULL&&curNode->getRightChild()==NULL)
		cout << curNode->getData() << " ";
	PRINT_LEAF(curNode->getRightChild());
}

void Tree::deallocate(Node* curNode) {
	if (curNode == nullptr)
		return;
	deallocate(curNode->getLeftChild());
	deallocate(curNode->getRightChild());
}

int main(void) {
	int command = 0;
	int data = 0;
	Tree* tree = new Tree;

	while (1) {
		cout << "Enter Any Command(1:Insert, 2:Delete, 3:Find, 4:Preorder, 5:Inorder, 6:Postorder, 7:Leaf node, 8:Exit): ";
		cin >> command;

		if (command == 1) {
			cin >> data;
			tree->INSERT(tree->getRoot(), data);
		}

		if (command == 2) {
			//
		}

		if (command == 3) {
			//
		}

		if (command == 4)
			tree->PRINT_PRE(tree->getRoot());

		if (command == 5)
			tree->PRINT_IN(tree->getRoot());

		if (command == 6)
			tree->PRINT_POST(tree->getRoot());

		if (command == 7) {
			//
		}

		if (command == 8)
			break;
	}

	delete tree;
	return 0;
}

//������ ���� �Ƹ���