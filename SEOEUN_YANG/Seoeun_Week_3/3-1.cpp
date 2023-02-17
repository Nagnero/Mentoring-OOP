#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
using namespace std;

class Node {//��� Ŭ���� ����
private:
	int ID;//���̵�
	string name;//�̸�
	Node* prev;//���� ��� ����Ŵ
	Node* next;//���� ��� ����Ŵ
public:
	Node() {//������
		ID = 0;//�ʱ�ȭ
		name = "";
		this->next = NULL;//������ �ʱ�ȭ
		this->prev = NULL;
	}
	void setID(int ID) { this->ID = ID; }//������ ����
	int getID() { return this->ID; }//������ �ҷ���
	void setname(string name) { this->name=name; }
	string getname() { return this->name; }

	void setPrev(Node* prevNode) { this->prev = prevNode; }//���� ��� ������ ����
	Node* getPrev() { return this->prev; }//��� ������ �̵�
	void setNext(Node* nextNode) { this->next = nextNode; }//���� ��� ������ ����
	Node* getNext() { return this->next; }//���� ��� ������ �ҷ��� (��� �̵�)
};

class List {//����Ʈ Ŭ���� ����
private:
	Node* head;//head ���
	int size;//����Ʈ ����(ũ��)
	Node* tail;//tail ���
public:
	List() {//������ (�ʱ�ȭ)
		this->head = NULL;
		this->tail = NULL;
		size = 0;
	}
	~List() {//�Ҹ��� (�����Ҵ� ����)
		Node* curNode = head;//ù��° ���
		Node* delNode = NULL;//�ʱ�ȭ
		while (curNode != NULL) {
			delNode = curNode;//�ش� ��� ������ ���� ����
			curNode = curNode->getNext();//curNode ���� ���� �̵�
			//���� �ٲ�� �ȵ�
			delete delNode;//��� ����
		}
	}

	bool FIND(int ID);//�ߺ� �˻�
	void INSERT(int ID,string name);//����
	void PRINT();//���
	void PRINT_REV();//�����
	void SORT_NAME();//�̸� �������� ����
	void SORT_ID();//���̵� �������� ����
	void DELETE(int ID);//����
};

bool List::FIND(int ID) {//�ߺ� �˻�
	Node* curNode = head;//ó������ Ž��
	while (curNode != NULL) {//�����Ͱ� �ִ� ���ȸ�
		if (curNode->getID() == ID) {//ã�� ���� ���� ��
			return true;
		}
		curNode = curNode->getNext();//ã�� �� �ƴϸ� ���� ���� �̵�
	}
	return false;
}

void List::INSERT(int ID, string name) {
	Node* curNode = head;
	Node* newNode = new Node;//�� ��� ����
	newNode->setID(ID);
	newNode->setname(name);//��� ������ ����

	if (FIND(ID) == true) {//�ߺ� ����
		return;//�ߺ��̶�� INSERT �Լ� ����
	}

	if (head == NULL) {//ó��
		tail = head = newNode;
		this->size++;
		return;
	}

	else {//����Ʈ ����
		while (curNode != NULL) {//������ ��ġ ã��
			if (curNode->getID() > ID) {//��ġ ã��
				if (curNode == head) {//head �տ� �����ؾ� �� ���
					newNode->setNext(curNode);//�� ��� ������ ����
					curNode->setPrev(newNode);//������ ����
					head = newNode;//head �缳��
					this->size++;
					return;//INSERT ��
				}
				else {//����Ʈ �߰� ���� //curNode �տ� newNode ����
					//curNode �� ���� newNode ����
					curNode->getPrev()->setNext(newNode);//curNode�� ������� next ������ new���� ����
					newNode->setPrev(curNode->getPrev());//newNode�� prev, curNode �� ���� ����
					//newNode�� curNode ����
					curNode->setPrev(newNode);
					newNode->setNext(curNode);
					this->size++;
					return;
				}
			}
			curNode = curNode->getNext();//��ġ Ž��
		}
	}

	//������ ����
	tail->setNext(newNode);//�� ��� tail�� ����
	newNode->setPrev(tail);//������ ����
	tail = tail->getNext();//tail �̵�
	this->size++;
}

void List::PRINT() {
	Node* curNode = head;//ù��° ������ ���ʷ� ���

	while (curNode != NULL) {
		cout << curNode->getID() << " " << curNode->getname() << endl;
		curNode = curNode->getNext();
	}
}

void List::PRINT_REV() {
	Node* curNode = tail;//������ ������ ���ʷ� ���

	while (curNode != NULL) {
		cout << curNode->getID() << " " << curNode->getname() << endl;
		curNode = curNode->getPrev();//�� ���� �̵�
	}
}

void List::SORT_NAME() {
	int temp_ID = 0;
	string temp_name = "";
	Node* Node_1 = head;
	Node* Node_2 = tail;

	while (head != Node_2) {//node 2�� �̻�
		Node_1 = head;//�ʱ�ȭ
		while (Node_1 != Node_2) {//ó������ �¾ƾ� �����̸鼭 ����
			if (Node_1->getname() > Node_1->getNext()->getname()) {//�̸� ũ��
				temp_ID = Node_1->getID();//swap
				temp_name = Node_1->getname();
				Node_1->setID(Node_1->getNext()->getID());
				Node_1->setname(Node_1->getNext()->getname());
				Node_1->getNext()->setID(temp_ID);
				Node_1->getNext()->setname(temp_name);
			}
			Node_1 = Node_1->getNext();//���� ���� �̵�
		}
		Node_2 = Node_2->getPrev();//���� while�� �� �� ���� �̸� ���� ū �� �� �������� ����� �׷��� ���� �ٽ� ���ص� ��
	}

	PRINT();
}

void List::SORT_ID() {
	int temp_ID = 0;
	string temp_name = "";
	Node* Node_1 = head;
	Node* Node_2 = tail;

	while (head != Node_2) {//node 2�� �̻�
		Node_1 = head;
		while (Node_1 != Node_2) {
			if (Node_1->getID() > Node_1->getNext()->getID()) {
				temp_ID = Node_1->getID();
				temp_name = Node_1->getname();
				Node_1->setID(Node_1->getNext()->getID());
				Node_1->setname(Node_1->getNext()->getname());
				Node_1->getNext()->setID(temp_ID);
				Node_1->getNext()->setname(temp_name);
			}
			Node_1 = Node_1->getNext();
		}
		Node_2 = Node_2->getPrev();
	}
}

void List::DELETE(int ID) {
	Node* curNode = head;
	//���� ����
	Node* prevNode = NULL;
	Node* delNode = NULL;

	while (curNode != NULL) {//��忡 �����Ͱ� ���� ��
		if (curNode->getID() == ID)//����� ���� ���� �� while�� Ż��
			break;
		prevNode = curNode;//����� ���� ���� �ƴϸ� ��� �̵� (prev�� ���� ��� ����, ������ �ű� �� �̿�)
		curNode = curNode->getNext();
	}

	//while�� Ż�� ����
	if (curNode == head) {//head ����
		if (head->getNext() == NULL) {//head�� ����
			delNode = head;
			delete delNode;
			this->size--;//-> size=0
			head=NULL;
		}
		else {//��� 2�� �̻�
			delNode = head;
			head = head->getNext();//head ���� ��带 head�� ����
			delete delNode;
			this->size--;
		}
	}
	else if (curNode == tail) {//tail ����
		delNode = tail;
		tail = prevNode;//tail �� ��� tail�� ����
		delete delNode;
		tail->setNext(NULL); // ��2 //�����Ⱚ ���� (tail �׻� NULL ����Ŵ)
		this->size--;
	}
	else {//�߰� ����
		delNode = curNode;
		prevNode->setNext(curNode->getNext());//cur��� ���� ��带 cur��� ������ ��带 ����Ű�� ����
		delete delNode;//cur��� ����
		this->size--;
	}
}

int main(void) {
	int command;
	int ID = 0;
	string name;
	List* valueList = new List;//�����Ҵ�
	
	while (1) {
		cout << "Please Enter Command(1 : insert, 2 : print, 3 : print_reverse, 4 : sort_by_name, 5 : sort_by_ID, 6 : delete, 7 : exit) : ";
		cin >> command;

		if (command == 1) {
			cin >> ID >> name;
			valueList->INSERT(ID,name);
		}

		else if (command == 2) {
			valueList->PRINT();
		}

		else if (command == 3) {
			valueList->PRINT_REV();
		}

		else if (command == 4) {
			valueList->SORT_NAME();
		}

		else if (command == 5) {
			valueList->SORT_ID();
		}

		else if (command == 6) {
			cin >> ID;
			valueList->DELETE(ID);
		}

		else if (command == 7)
			break;

		else
			continue;
	}

	delete valueList;//�����Ҵ� ����
	return 0;
}