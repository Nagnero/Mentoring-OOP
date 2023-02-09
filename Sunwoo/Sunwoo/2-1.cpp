#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <cstring>
using namespace std;

class Student_info // ���� �⺻ ���� class
{
private:
	char name[10];
	int age = 0;
	char university[100];
	char major[100];

public:
	Student_info(char* name, int age, char* univ, char* major);
	bool find(char* name);
	void print(); 
	void change(char* name, int age, char* univ, char* major);
};

Student_info::Student_info(char* name, int age, char* univ, char* major)
{ // �Է¹��� ���� �� ��ü ����� ����
	strcpy(this->name, name); 
	this->age = age;
	strcpy(this->university, univ);
	strcpy(this->major, major);
}
bool Student_info::find(char* name)
{ // �� ��ü���� �̸� ����� ���Ͽ� ������ 1 ��ȯ, �ƴϸ� 0 ��ȯ
	if (strcmp(this->name, name) == 0)
		return 1;
	else
		return 0;
}
void Student_info::print()
{ // �� ��ü�� ����� ��� �����͵��� ���
	cout << "Name : " << this->name << endl;
	cout << "Age : " << this->age << endl;
	cout << "University : " << this->university << endl;
	cout << "Major : " << this->major << endl;
	cout << "-------------------------" << endl;
}
void Student_info::change(char* name, int age, char* univ, char* major)
{ // �Է¹��� ���� �ش� ��ü ����� ����, Student_info �����ڿ� ���� ��� ����
	strcpy(this->name, name);
	this->age = age;
	strcpy(this->university, univ);
	strcpy(this->major, major);
}

int main(void)
{
	char command[10] = "", temp_name[10], name[10], univ[100], major[100];
	int i, age, cnt = 0;
	Student_info* student[10]; // ���� ������ �迭 ��ü ����

	while (1)
	{
		cout << "Please Enter Command(insert, find, change, print, exit) :";
		cin >> command;

		if (strcmp(command, "insert") == 0)
		{ // command�� insert�̸� �̸� ���� 
			cin >> name >> age >> univ >> major;
			student[cnt] = new Student_info(name, age, univ, major);
			cnt++;
		}
		else if (strcmp(command, "find") == 0)
		{ // command�� find�̸� ����� ��ü���� find ��� �Լ� ȣ��
			cout << "----------find----------" << endl;
			cin >> name;
			for (i = 0; i < cnt; i++)
			{
				if (student[i]->find(name)) // ������ �̸��� ã����
					student[i]->print(); // print ����Լ��� ���
			}
		}
		else if (strcmp(command, "change") == 0)
		{ // command�� change�� ���������� ��ü�鿡 �����Ͽ�
			cin >> temp_name >> name >> age >> univ >> major;
			for (i = 0; i < cnt; i++)
				if (student[i]->find(temp_name))
				{ // find ����Լ��� ���� ���� name�� ���� ��ü�� Ȯ���Ͽ� ������ ����
					student[i]->change(name, age, univ, major);
					break;
				}			
		}
		else if (strcmp(command, "print") == 0)
		{ // command�� print�̸� for������ print����Լ��� �ݺ�ȣ���Ͽ� ������ ���
			cout << "----------print----------" << endl;
			for (i = 0; i < cnt; i++)
			{
				student[i]->print();
			}
			cout << "-------------------------" << endl;
		}
		else if (strcmp(command, "exit") == 0) // command�� exit�̸� ���ѹݺ����� ����
			break;
		else // � ��쿡�� �ش���� ������ �ݺ��� �����
			continue;
	}
	
	for (i = 0; i < cnt; i++) // �����Ҵ� ����
		delete[] student[i];

	cout << "-------------------------" << endl;

	return 0;
}