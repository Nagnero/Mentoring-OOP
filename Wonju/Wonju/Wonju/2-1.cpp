#include <iostream>
#include <cstring>

using namespace std;
class Student_info {
private:
	char name[10];
	int age = 0;
	char university[100];
	char major[100];

public: // ���� �Է¹޾Ƽ� private�� ����
	Student_info() {};
	Student_info(char* name, int age, char* univ, char* major)
	{
		name = new char[10];
		strcpy(this->name, name);
		univ = new char[100];
		strcpy(this->university, univ);
		major = new char[100];
		strcpy(this->major, major);
		this->age = age;
	};
	bool find(char* name)
	{

	};
	void print()  //private�� ����� �� ���
	{
		cout << "----------print----------";
		cout << "Name : " << name << endl;
		cout << "Age : " << age << endl;
		cout << "University : " << university << endl;
		cout << "Major : " << major << endl;
		cout << "-------------------------" << endl;
	};
	void change(char* name, int age, char* univ, char* major)
	{

	};
	~Student_info() {};

	int main (void)
	{
		Student_info* Student[10] = {};
		char input[10]; // Ŀ�ǵ� ����
			// Ŭ���� �޼ҵ忡 ������ ���� ����
		char name1[10];
		int age1;
		char univ1[100];
		char major1[100];
		int i = 0;
		
		while (1) // ���� �ݺ�
		{
			cout << "Please Enter Command(Insert, find, change, print, exit) : ";
			cin >> input; // Ŀ�ǵ带 �Է¹���
			if (input == "insert") // insert�� ���
			{
				cin >> name1 >> age1 >> univ1 >> major1; // ������ ��� �Է¹���.
				Student[i] = new Student_info(name1,age1, univ1, major1);
				i++; // ���� �����
			}
			else if (input == "find")
			{

			}
			else if (input == "print")
			{

			}
			else if (input == "exit")
			{
				break;
			}
			else
			{
				cout << "Please Enter Command(insert, find, change, print, exit) : ";
				cin >> input; // Ŀ�ǵ带 �Է¹���
			}
		}
	}
	};