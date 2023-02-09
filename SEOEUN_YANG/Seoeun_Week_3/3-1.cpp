#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
using namespace std;

class Node {//��� Ŭ���� ����
private:
	int ID;
	char name[100];
	Node* next;  // ���� ��带 ����Ű�� ������
public:
	Node() {//������
		ID = 0;//�ʱ�ȭ
		strcpy(this->name, "");
		this->next = NULL;//�ʱ�ȭ
	}
	void setID(int ID) { this->ID = ID; }//������ ����
	int getID() { return this->ID; }//������ �ҷ���
	void setname(char* name) { strcpy(this->name, name); }
	char* getname() { return this->name; }
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
	void INSERT(int ID,char* name);
	void PRINT();
	void FIND(int value);
	void DELETE(int value);
};

void List::INSERT(int ID, char* name) {
	Node* curNode = head;
	Node* newNode = new Node;
	newNode->setID(ID);
	newNode->setname(name);//��� ������ ����

	if (head == NULL) {
		tail = head = newNode;
		this->size++;
	}

	else {
		tail->setNext(newNode);
		tail = tail->getNext();
		this->size++;
	}
}

void List::PRINT() {
	Node* curNode = head;//ù��° ������ ���ʷ� ���

	while (curNode != NULL) {
		cout << curNode->getID() << " " << curNode->getname() << endl;
		curNode = curNode->getNext();
	}
}

int main(void) {
	int command;
	int ID = 0;
	char name[100];

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
			//cin >> num;
			//valueList->DELETE(num);
		}

		else if (command == 4) {
			valueList->PRINT();
		}

		else if (command == 5) {
			valueList->PRINT();
		}

		else if (command == 6) {
			valueList->PRINT();
		}

		else if (command == 7)
			break;

		else
			continue;
	}
	return 0;
}