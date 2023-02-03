#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <cstring>
using namespace std;

class animal {
private:
	char name[10];
	int year = 0;
	char species[100];
public:
	animal() {};
	void save(char* name, int age, char* species);
	char* getName();
	int getAge();
	char* getSpecies();
};

// ���� ���� ����޼���; �̸��� ���� ���� ������ ��ü�� ������
void animal::save(char* name, int age, char* species)
{
	strcpy(this->name, name);
	this->year = age;
	strcpy(this->species, species);
}
// �̸� getter; ��ü�� ����� �̸��� ��ȯ��
char* animal::getName()
{
	return this->name;
}
// ���� getter; ��ü�� ����� ���̸� ��ȯ��
int animal::getAge()
{
	return this->year;
}
// �� getter; ��ü�� ����� ���� ��ȯ��
char* animal::getSpecies()
{
	return this->species;
}


class zoo {
private:
	class animal* animal_list[100];
	int size = 0;
public:
	void save(char* name, int age, char* species);
	void print(int i);
	bool find(int i, char* species);
	~zoo();
};

// zoo ��ü���� animal ��ü�� �����Ҵ�
void zoo::save(char* name, int age, char* species)
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
bool zoo::find(int i, char* species)
{
	if (strcmp(animal_list[i]->getSpecies(), species) == 0)
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
	char command[20], name[10], species[100];
	int age, i, cnt = 0;
	zoo* Zoo = new zoo;

	while (1)
	{
		cout << "Please Enter Any Command(new_animal,print_all,print_species,exit) :";
		cin >> command;
		if (strcmp(command, "new_animal") == 0) // command�� new_animal�̸�
		{
			cin >> name >> age >> species;
			// ������ ���� ����Լ� ȣ��; name, age, species ����
			Zoo->save(name, age, species);
			cnt++;
		}
		else if (strcmp(command, "print_all") == 0) // command�� print_all�̸�
		{
			cout << "------print_all------" << endl;
			for (i = 0; i < cnt; i++) // ������ ��ü�� �����Ͽ� zooŬ������ print�޼��� ȣ��
				Zoo->print(i);
			cout << "---------------------" << endl;
		}
		else if (strcmp(command, "print_species") == 0) // command�� print_species�̸�
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
		else if (strcmp(command, "exit") == 0) // command�� exit�̸� ���ѹݺ��� Ż��
			break;
		else // ��� �͵� �ش���� ������ �ݺ�
			continue;
	}

	delete Zoo; // �޸� ����

	return 0;
}