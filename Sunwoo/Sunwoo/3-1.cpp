#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <cstring>
using namespace std;

// Node Ŭ���� ����
class Node
{
private:
	int ID;
	string name;
	Node* prev;
	Node* next;
public:
	Node() // Node �ʱ�ȭ
	{
		this->ID = 0;
		this->name = "";
		this->prev = NULL;
		this->next = NULL;
	}
	void setValue(int input, string name) { this->ID = input; this->name = name; } // ID�� �̸� ����
	int getID() { return this->ID; } // ID getter
	string getName() { return this->name; } // �̸� getter
	void setPrev(Node* prevNode) { this->prev = prevNode; } // ���� ���� ����
	void setNext(Node* nextNode) { this->next = nextNode; } // ���� ���� ����
	Node* getPrev() { return this->prev; } // ���� ��� ��������
	Node* getNext() { return this->next; } // ���� ��� ��������
};

// List Ŭ���� ����
class List
{
private:
	Node* head;
	Node* tail;
	int size;
public:
	List() // List �ʱ�ȭ
	{
		this->head = NULL;
		this->tail = NULL;
		this->size = 0;
	}
	~List() // List �Ҹ���
	{
		Node* curNode = head;
		Node* delNode = NULL;
		while (curNode != NULL) // ���� ������ ���������� ����
		{
			delNode = curNode;
			curNode = curNode->getNext();
			delete delNode;
		}
		delNode = NULL;
	}
	Node* FIND(int input); // input�� ��忡 ����� ID�� ������ �ش� ��� ��ȯ
	void INSERT(int input, string name); // ID�� �̸��� ��ũ�� ����Ʈ�� ����
	void PRINT(); // ���
	void PRINT_REVERSE(); // �������� ���
	void SORT_NAME(); // �̸����� ����
	void SORT_ID(); // ID�� ����
	void DEL(int input); // input�� ������ ID�� ���� ��带 ����
};

Node* List::FIND(int input)
{
	Node* curNode = head;

	while (curNode != NULL) // ��� ��带 Ȯ���ϴ� �ݺ���
	{
		if (curNode->getID() == input) // input�� ��忡 ����� ID�� ������
			return curNode; // �ش� ��� ��ȯ
		curNode = curNode->getNext(); // ��� ��带 Ȯ���ϴ� �ݺ���
	}
}

void List::INSERT(int input, string name)
{
	Node* curNode = head;

	if (FIND(input)!=NULL) // �ߺ��Ǵ� ID�� ������
		return; // �ش� �޼��� Ż��

	Node* newNode = new Node;
	newNode->setValue(input, name);

	if (head == NULL) // ����� ��尡 �ϳ��� ������
	{
		tail = head = newNode; // ���ο� ��带 head���� tail�� ����
		this->size++; // ����� ���� 1 ����
	}
	else // �̹� ����� ��尡 �ϳ��� ������
	{
		while (curNode != NULL) // ��� ��带 Ȯ���ϴ� �ݺ���
		{
			if (curNode->getID() > input) // ��忡 ����� ID�� input���� ũ��
			{
				if (curNode == head) // �ش� ��尡 head�̸� �� �տ� �߰��ϰ� size 1 ����
				{
					newNode->setNext(curNode);
					curNode->setPrev(newNode);
					head = newNode;
					this->size++;
					return;
				}
				else // �ش� ��尡 head�� �ƴϸ� ���ο� ��带 �߰�
				{ // �߰��� ���ο� ��带 �յڷ� next, prev ��� ����
					curNode->getPrev()->setNext(newNode);
					newNode->setPrev(curNode->getPrev());
					newNode->setNext(curNode);
					curNode->setPrev(newNode);
					this->size++; // size 1 ����
					return;
				}
			}
			curNode = curNode->getNext();
		}

		// ��忡 ����� ID�� input���� ū ��尡 ������ �� �ڿ� ��� �߰�
		tail->setNext(newNode); 
		newNode->setPrev(tail);
		tail = tail->getNext();
		this->size++;
	}
}

void List::PRINT()
{
	Node* curNode = head;

	while (curNode != NULL) // ��� ��忡 �����Ͽ� getNext �޼���� �ϳ��� ���
	{
		cout << curNode->getID() << " " << curNode->getName() << endl;
		curNode = curNode->getNext();
	}
}

void List::PRINT_REVERSE()
{
	Node* curNode = tail;

	while (curNode != NULL) // ��� ��忡 �����Ͽ� getPrev �޼���� �ϳ��� ���
	{
		cout << curNode->getID() << " " << curNode->getName() << endl;
		curNode = curNode->getPrev();
	}
}

void List::SORT_NAME()
{
	int temp_ID; // �ӽ� ID ��
	string temp_name; // �ӽ� �̸� ����
	Node* curNode = head;
	Node* lastNode = tail;

	// ���� ���� ����
	while (head != lastNode) // ������ ��尡 head�� �ƴϸ� ��� �ݺ�
	{
		curNode = head;
		while (curNode != lastNode) // ������ ��尡 ���� ��尡 �ƴϸ� �ݺ�
		{
			if (curNode->getName() > curNode->getNext()->getName()) // ���� ��忡 ����� �̸��� ���� ��忡 ����� �̸� ��
			{ // ���� ��忡 ����� �̸��� �� ũ�� �������� ������ ���� ����
				temp_ID = curNode->getID();
				temp_name = curNode->getName();
				curNode->setValue(curNode->getNext()->getID(), curNode->getNext()->getName());
				curNode->getNext()->setValue(temp_ID, temp_name);
			}
			curNode = curNode->getNext();
		}
		lastNode = lastNode->getPrev(); // ������ ��带 getPrev �޼���� �� ��徿 ������ �̵�
	}

	PRINT(); // ���ĵ� ��� ���
}

void List::SORT_ID()
{
	int temp_ID; // �ӽ� ID ��
	string temp_name; // �ӽ� �̸� ����
	Node* curNode = head;
	Node* lastNode = tail;

	//���� ���� ���� SORT_NAME �޼��忡�� �̸� ��� ID�� ���Ѵٴ� �� ���� ����
	while (head != lastNode)
	{
		curNode = head;
		while (curNode != lastNode)
		{
			if (curNode->getID() > curNode->getNext()->getID())
			{
				temp_ID = curNode->getID();
				temp_name = curNode->getName();
				curNode->setValue(curNode->getNext()->getID(), curNode->getNext()->getName());
				curNode->getNext()->setValue(temp_ID, temp_name);
			}
			curNode = curNode->getNext();
		}
		lastNode = lastNode->getPrev();
	}
}

void List::DEL(int input) 
{
	Node* curNode = FIND(input);
		
	if (curNode == head) // �����ϴ°� ù��° ����� ���
	{
		if (curNode->getNext() == NULL) // ù��° ��� �ϳ��ۿ� ���� ���
		{
			delete head; // �޸� ���� ����
			head = NULL; // ���� ����, ���� ����
		}
		else // ù��° ��带 �����ϸ鼭 ��尡 �������� ���
		{
			head = curNode->getNext(); // head�� ���� ���� ���� ��
			delete curNode; // �޸𸮿� ���� ����
			curNode = NULL;
		}
		this->size--; // size 1 ����
	}
	else if (curNode == tail) // �����ϴ� �� ������ ����� ���
	{
		tail = curNode->getPrev(); // tail�� �����Ϸ��� ��� �� ���� ����
		delete curNode; // �޸𸮿� ���� ����
		curNode = NULL;
		this->size--; // size 1 ����
	}
	else // �߰� ����
	{
		curNode->getPrev()->setNext(curNode->getNext()); // ���� ��带 �������� �� �� ��峢�� ����
		curNode->getNext()->setPrev(curNode->getPrev());
		delete curNode; // ���� ��� ����
		curNode = NULL;
		this->size--;
	}
}

int main()
{
	int command = 0, input;
	string name;
	List* Linked_List = new List;

	// command�� ���� �ٸ� �޼��� ȣ��
	while (command != 7)
	{
		cout << "Please Enter Command (1:insert, 2:print, 3:print_reverse, 4:sort_by_name, 5:sort_by_ID, 6:delete, 7:exit) :";
		cin >> command;
		if (command == 1)
		{
			cin >> input >> name;
			Linked_List->INSERT(input, name);
		}
		else if (command == 2)
		{
			Linked_List->PRINT();
		}
		else if (command == 3)
		{
			Linked_List->PRINT_REVERSE();
		}
		else if (command == 4)
		{
			Linked_List->SORT_NAME();
		}
		else if (command == 5)
		{
			Linked_List->SORT_ID();
		}
		else if (command == 6)
		{
			cin >> input;
			Linked_List->DEL(input);
		}
		else if (command == 7)
		{
			break;
		}
		else
			continue;
	}

	// �����Ҵ� ����
	delete Linked_List;

	return 0;
}