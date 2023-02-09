#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
using namespace std;

class Node {//��� Ŭ���� ����
private:
	int ID;
	string name;
	Node* prev;//���� ��� ����Ŵ
	Node* next;//���� ��� ����Ŵ
public:
	Node() {//������
		ID = 0;//�ʱ�ȭ
		name = "";
		this->next = NULL;//�ʱ�ȭ
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

	bool FIND(int ID);
	void INSERT(int ID,string name);
	void PRINT();
	void PRINT_REV();
	void SORT_NAME();
	//void SORT_ID();
	void DELETE(int ID);
};

bool List::FIND(int ID) {
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
	Node* newNode = new Node;
	newNode->setID(ID);
	newNode->setname(name);//��� ������ ����

	if (FIND(ID) == true)//�ߺ� ����
		return;

	if (head == NULL) {//ó��
		tail = head = newNode;
		this->size++;
		return;
	}

	else {//����Ʈ ����
		while (curNode != NULL) {
			if (curNode->getID() > ID) {
				if (curNode == head) {//head �տ� �����ؾ� �� ���
					newNode->setNext(curNode);//head ���� ����
					curNode->setPrev(newNode);//������ ����
					head = newNode;
					this->size++;
					return;//INSERT ��
				}
				else {//����Ʈ �߰� ���� //curNode �տ� newNode ����
					//������ ����
					curNode->getPrev()->setNext(newNode);//curNode�� prev, newNode�� next���� ����
					newNode->setPrev(curNode->getPrev());//newNode�� prev, curNode �� ����� next���� ����
					//������ ����
					curNode->setPrev(newNode);
					newNode->setNext(curNode);
					this->size++;
					return;
				}
			}
			curNode = curNode->getNext();
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
		curNode = curNode->getPrev();
	}
}

void List::SORT_NAME() {
	int temp_ID = 0;
	string temp_name = "";
	Node* Node_1 = head;
	Node* Node_2 = head->getNext();

	for (int i = 0; i < this->size; i++) {
		for (int j = 0; j < (this->size) - 1; j++) {
			if (Node_1->getname() > Node_2->getname()) {
				temp_ID = Node_1->getID();
				temp_name = Node_1->getname();
				Node_1->setID(Node_2->getID());
				Node_1->setname(Node_2->getname());
				Node_2->setID(temp_ID);
				Node_2->setname(temp_name);
			}
			Node_1->getNext();
			Node_2->getNext();
		}

		Node_1 = head;
		Node_2 = head->getNext();
		for (int z = 0; z < i + 1; z++) {
			Node_1->getNext();
			Node_2->getNext();
		}
	}
	PRINT();
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
	if (curNode == head) { // 1. head�� �����ϴ� ���
		if (head->getNext() == NULL) { // list�� head�� �����ϴ� ���
			delNode = head;
			delete head;
			// head = NULL; ��1

			this->size--;//-> size=0
		}
		else { // list�� head �ܿ� �ٸ� ���鵵 �����ϴ� ���
			delNode = head;
			head = head->getNext();//head ���� ��带 head�� ����
			delete delNode;
			this->size--;
		}
	}
	else if (curNode == tail) { // 3. tail�� �����ϴ� ���
		delNode = tail;
		tail = prevNode;//tail �� ��� tail�� ����
		delete delNode;
		tail->setNext(NULL); // ��2 //�����Ⱚ ���� (tail �׻� NULL ����Ŵ)
		this->size--;
	}
	else { // 2. head�� tail�� ������ �ٸ� ������ �����ϴ� ���
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
	List* valueList = new List;
	
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
			valueList->SORT_NAME();//��±���
		}

		else if (command == 5) {
			//valueList->SORT_ID();
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

	delete valueList;
	return 0;
}