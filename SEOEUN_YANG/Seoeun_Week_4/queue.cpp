#include <iostream>
using namespace std;

class Node {//��� Ŭ���� ����
private:
	int value;//�����Ͱ�
	Node* next;//�� ��� ������
	Node* prev;//���� ��� ������

public:
	Node() {//�ڵ�������
		this->value = 0;//�ʱ�ȭ
		this->next = NULL;
		this->prev = NULL;
	}
	void setValue(int data) { this->value = data; }
	int getValue() { return this->value; }
	void setNext(Node* nextNode) { this->next = nextNode; }
	Node* getNext() { return this->next; }
	void setPrev(Node* prevNode) { this->prev = prevNode; }
	Node* getPrev() { return this->prev; }
};

class Queue {//ť Ŭ���� ����
private:
	Node* front;//��
	Node* rear;//��
	int size;//ť ����
public:
	Queue() {//�ڵ�������
		this->front = NULL;//�ʱ�ȭ
		this->rear = NULL;
		this->size = 0;
	}
	bool isEmpty();//������ ���� ���� Ȯ��
	void enqueue(int data);//����
	void dequeue();//����
	void printQueue();//���
};

bool Queue::isEmpty() {
	if (this->size == 0)
		return true;
	else
		return false;
}

void Queue::enqueue(int data) {
	Node* newNode = new Node;
	newNode->setValue(data);

	if (isEmpty()) {
		front = rear = newNode;
		this->size++;
	}
	else {
		newNode->setNext(rear);//rear �ڿ� ����� ����
		rear->setPrev(newNode);//����� ����
		rear = newNode;//�� ��� rear�� ����
		Node* curNode = rear;
		while (curNode != NULL)
			curNode = curNode->getNext();//front ã��
		curNode = front;
		this->size++;
	}
}

void Queue::dequeue() {
	if (isEmpty()) {//������ ���� X
		cout << "queue underflow";
	}
	else {
		if (this->size == 1) {
			delete rear;
			rear = NULL;//�����Ⱚ ����
			front = NULL;
			this->size--;
			cout << "queue underflow";//���� ������ ����
			return;
		}
		Node* dequeueNode = front;
		front = front->getPrev();//front ��� �̵� (�� ĭ �ڷ�)
		delete dequeueNode;
		front->setNext(NULL);//�����Ⱚ ���� (�ʱ�ȭ)
		this->size--;
	}
}

void Queue::printQueue() {
	Node* curNode = rear;

	while (curNode != NULL) {//rear���� ��� �̵��ϸ鼭 ���
		cout << curNode->getValue() << "    ";
		curNode = curNode->getNext();
	}
	cout << endl << "Data count: " << this->size << endl;
}

int main(void) {

	string command;
	int data = 0;
	Queue* queue = new Queue;//ť ���� �Ҵ�

	while (1) {
		cout << "Please Enter Command(enqueue, dequeue): ";
		cin >> command;

		if (command == "enqueue") {
			cin >> data;
			queue->enqueue(data);
			queue->printQueue();
		}

		else if (command == "dequeue") {
			queue->dequeue();
			queue->printQueue();
		}
	}

	delete queue;//���� �Ҵ� ����

	return 0;
}