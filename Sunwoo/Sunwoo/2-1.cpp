#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <cstring>
using namespace std;

class Student_info
{
private:
	char name[10];
	int age = 0;
	char university[100];
	char major[100];

public:
	//Student_info() {}; // �⺻ ������
	Student_info(char* name, int age, char* univ, char* major)
	{
		strcpy(this->name, name);
		this->age = age;
		strcpy(this->university, univ);
		strcpy(this->major, major);
	};
	bool find(char* name)
	{

	};
	void print() // ��ü�� ����� ���� �ѹ� ���, main���� �ݺ� ȣ��
	{
		cout << "Name : " << this->name << endl;
		cout << "Age : " << this->age << endl;
		cout << "University : " << this->university << endl;
		cout << "Major : " << this->major << endl;
		cout << "-------------------------" << endl;
	};
	void change(char* name, int age, char* univ, char* major);
};

int main(void)
{
	char command[10] = "", name[10], univ[100], major[100];
	int age, cnt = 0;
	Student_info* student[10];

	while (1)
	{
		cout << "Please Enter Command(insert, find, change, print, exit) :";
		cin >> command;
		if (strcmp(command, "insert") == 0)
		{
			cin >> name >> age >> univ >> major;
			student[cnt] = new Student_info(name, age, univ, major);
			cnt++;
		}
		else if (strcmp(command, "find") == 0)
		{

		}
		else if (strcmp(command, "change") == 0)
		{

		}
		else if (strcmp(command, "print") == 0)
		{
			cout << "----------print----------" << endl;
			for (int i = 0; i < cnt; i++)
			{
				student[i]->print();
			}
			cout << "-------------------------" << endl;
		}
		else if (strcmp(command, "exit") == 0)
			return 0;
		else
			continue;
	}
	






	cout << "-------------------------" << endl;
}