#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <cstring>
using namespace std;

class animal {
private:
	string name;
	int year = 0;
	string species;
public:
	void save(string name, int age, string species);
	string getName();
	int getAge();
	string getSpecies();
};

// ���� ���� ����޼���; �̸��� ���� ���� ������ ��ü�� ������
void animal::save(string name, int age, string species)
{
	this->name = name;
	this->year = age;
	this->species = species;
}
// �̸� getter; ��ü�� ����� �̸��� ��ȯ��
string animal::getName()
{
	return this->name;
}
// ���� getter; ��ü�� ����� ���̸� ��ȯ��
int animal::getAge()
{
	return this->year;
}
// �� getter; ��ü�� ����� ���� ��ȯ��
string animal::getSpecies()
{
	return this->species;
}


class zoo {
private:
	class animal* animal_list[100];
	int size = 0;
public:
	void save(string name, int age, string species);
	void print(int i);
	bool find(int i, string species);
	~zoo();
};

// zoo ��ü���� animal ��ü�� �����Ҵ�
void zoo::save(string name, int age, string species)
{
	animal_list[size] = new animal;
	animal_list[size]->save(name, age, species);
	size++;
};
// zooŬ�������� animal Ŭ������ �����Ͽ� ����� ������ �����
void zoo::print(int i)
{
	cout << "----------" << i << "----------" << endl;
	cout << "Name :" << animal_list[i]->getName() << endl;
	cout << "Year :" << animal_list[i]->getAge() << endl;
	cout << "Species :" << animal_list[i]->getSpecies() << endl;
	cout << "---------------------" << endl;
}
// �Է¹��� ���� ����� ���� ������ 1�� ��ȯ�ϴ� �޼���
bool zoo::find(int i, string species)
{
	if (animal_list[i]->getSpecies() == species)
	{
		return 1;
	}
	else
		return 0;
}
// �Ҹ���. ���α׷��� ����� �� ������ �����Ҵ� ����
zoo::~zoo() {
	for (int i = 0; i < this->size; i++)
		delete[] animal_list[i];
}

int main()
{
	string command, name, species;
	int age, i, cnt = 0;
	zoo* Zoo = new zoo;

	while (1)
	{
		cout << "Please Enter Any Command(new_animal,print_all,print_species,exit) :";
		cin >> command;
		if (command == "new_animal") // command�� new_animal�̸�
		{
			cin >> name >> age >> species;
			// ������ ���� ����Լ� ȣ��; name, age, species ����
			Zoo->save(name, age, species);
			cnt++;
		}
		else if (command == "print_all") // command�� print_all�̸�
		{
			cout << "------print_all------" << endl;
			for (i = 0; i < cnt; i++) // ������ ��ü�� �����Ͽ� zooŬ������ print�޼��� ȣ��
				Zoo->print(i);
			cout << "---------------------" << endl;
		}
		else if (command == "print_species") // command�� print_species�̸�
		{
			int same = 0; // ���� ���� ���� ����
			cin >> species;
			cout << "------print_species------" << endl;
			// �� ���� ���� ����Լ� ȣ��, species ����
			for (i = 0; i < cnt; i++)
				if (Zoo->find(i, species))
				{
					Zoo->print(i);
					same++;
				}
			cout << "Number of Species is :" << same << endl;
			cout << "---------------------" << endl;
		}
		else if (command == "exit") // command�� exit�̸� ���ѹݺ��� Ż��
			break;
		else // ��� �͵� �ش���� ������ �ݺ�
			continue;
	}

	delete Zoo; // �޸� ����

	return 0;
}