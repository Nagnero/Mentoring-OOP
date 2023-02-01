#define _CRT_SECURE_NO_WARNINGS
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
	Student_info(char* name, int age, char* univ, char* major)
	{
		strcpy(this->name, name);
		strcpy(this->university, univ);
		strcpy(this->major, major);
		this->age = age;
	};
	bool find(char* name)
	{
		if (strcmp(this->name, name) == 0)
			return 0;
		else
			return 1;
	};
	void print()  //private�� ����� �� ���
	{
		cout << "----------print----------";
		cout << "Name : " << this->name << endl;
		cout << "Age : " << this->age << endl;
		cout << "University : " << this->university << endl;
		cout << "Major : " << this->major << endl;
		cout << "-------------------------" << endl;
	};
	void change(char* name, int age, char* univ, char* major)
	{
		if (strcmp(this->name, name) == 0)
		{
			strcpy(this->name, name);
			strcpy(this->university, univ);
			strcpy(this->major, major);
			this->age = age;
		}
	};
	~Student_info() {
	};
	};
	int main (void)
	{
		Student_info* Student[10] = {0};
		char input[10] ={0}; // Ŀ�ǵ� ����
			// Ŭ���� �޼ҵ忡 ������ ���� ����
		char mainname[10] = { 0 };
		int mainage = 0;
		char mainuniv[100] = { 0 };
		char mainmajor[100] = { 0 };
		char findname[10] = { 0 };
		int i = 0;
		
		while (1) // ���� �ݺ�
		{
			cout << "Please Enter Command(Insert, find, change, print, exit) : ";
			cin >> input; // Ŀ�ǵ带 �Է¹���
			if (strcmp(input,"insert")==0) // insert�� ���
			{	
				cin >> mainname >> mainage >> mainuniv >> mainmajor;
				Student[i] = new Student_info(mainname, mainage, mainuniv, mainmajor); 
				i++; // ���� �����
			}
			else if (strcmp(input, "find") == 0)
			{
				cin >> findname;
				for (int j = 0; j < 10; j++) {
					if (Student[i]->find(findname) == 0)
						Student[i]->print();
				}
			}
			else if (strcmp(input, "change"))
			{
				for (int l = 0; l < 10; l++)
				{
					Student[l]->change(findname, mainage, mainuniv, mainmajor);
				}
			}
			else if (strcmp(input, "print") == 0)
			{
				for(int k=0;k<10;k++)
					Student[i]->print();
			}
			else if (i > 9 || strcmp(input, "exit"))
				break;

			else
			{
				cout << "Please Enter Command(insert, find, change, print, exit) : ";
				cin >> input; // Ŀ�ǵ带 �Է¹���
			}
		}
		delete Student;
		return 0;
	}
