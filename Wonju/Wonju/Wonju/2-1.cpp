#include <iostream>
using namespace std;
class Student_info{
private:
	char name[10];
	int age = 0;
	char university[100];
	char major[100];

public: // ���� �Է¹޾Ƽ� private�� ����
	Student_info(char* name, int age, char* univ, char* major)
	{

	};
	bool find(char* name);
	void print()  //private�� ����� �� ���
	{
		cout << "----------print----------";
		cout << "Name : " << name << endl;
		cout << "Age : " << age << endl;
		cout << "University : " << university << endl;
		cout << "Major : " << major << endl;
		cout << "-------------------------"<< endl;
	};
	void change(char* name, int age, char* univ, char* major); //set�Լ��� ���ؼ� �ٲٱ�
};
int main(void)
{
	char input[10]; // Ŀ�ǵ� ����
		// Ŭ���� �޼ҵ忡 ������ ���� ����
	char name1[10];
	int age1;
	char univ1[100];
	char major1[100];
	int i = 0;
	Student_info* array[10]; // ������ �Է��� �迭 ����
	while (1) // ���� �ݺ�
	{
		cout << "Please Enter Command(Insert, find, change, print, exit) : "; 
		cin >> input; // Ŀ�ǵ带 �Է¹���
		if (input == "insert" && " Insert") // insert�� ���
		{
			cin >> name1 >> age1 >> univ1 >> major1; // ������ ��� �Է¹���.
			//array[i].Student_info(name1, age1, univ1, major1); //�Է¹��� ������ �������� ��ȹ
			i++; // ���� �����
		}
	}