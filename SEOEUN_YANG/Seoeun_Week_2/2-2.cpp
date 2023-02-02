#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
using namespace std;

class animal {
private:
	char name[10];
	int year = 0;
	char species[100];

public:
	animal(char* name, int year, char* species);//������
	char* get_name() { return this->name; }//�̸� ����
	int get_year() { return this->year; }//���� ����
	char* get_species() { return this->species; }//�� ����
};

class zoo {
private:
	class animal* animal_list[100];//���� �Ҵ� (�ִ� ���� 100���� ���� ����)
	int size = 0;//���� ����

public:
	void save(char* name, int year, char* species) {//���� �Լ�
		animal_list[size] = new animal(name, year, species);//��ü �� �����Ҵ�
		size++;//��ü �� ���� ����
	}
	void size_setter(int size) { this->size = size; }//���� �� ����
	int size_getter() { return this->size; }//���� �� �˷���

	void print(int i);//���� ���� ���
	int find(char* species_i,int cnt);//���� �� �˻�
	
	~zoo() {//�Ҹ���
		delete[]animal_list;//�����Ҵ� ����
	}
};

animal::animal(char* name, int year, char* species) {//���� ���� ����
	strcpy(this->name, name);
	this->year = year;
	strcpy(this->species, species);
}

void zoo::print(int i) {//���
	cout << "----------" << i << "----------" << endl;
	cout << "Name : " << animal_list[i]->get_name() << endl;
	cout << "Year : " << animal_list[i]->get_year() << endl;
	cout << "Species : " << animal_list[i]->get_species() << endl;
	cout << "---------------------" << endl;
}

int zoo::find(char* species_i,int cnt) {//���� �� �˻�
	int size = size_getter();
	for (int i = 0; i < size; i++) {
		if (strcmp(animal_list[i]->get_species(), species_i) == 0) {//���� ���ٸ�
			print(i);//���
			cnt++;//������++
		}
	}
	return cnt;
}

int main() {
	zoo* Zoo = new zoo;//zoo ��ü ����
	char input[100]={};//command �Է�
	char name_i[10];
	int year_i;
	char species_i[100];
	int size;

	while (1) {
		cout << "Please Enter Command(new_animal,print_all,print_species,exit) :";
		cin >> input;

		if (strcmp(input, "new_animal") == 0) {
			cin >> name_i >> year_i >> species_i;
			Zoo->save(name_i, year_i, species_i);//���� ���� ����
		}

		else if (strcmp(input, "print_all") == 0) {
			size=Zoo->size_getter();//����Ǿ� �ִ� ���� ������ �ҷ���
			cout << "------print_all------" << endl;
			for (int i = 0; i < size; i++) {//���� ��������ŭ �ݺ� (��� ���)
				Zoo->print(i);
			}
			cout << "---------------------" << endl;
		}

		else if (strcmp(input, "print_species") == 0) {
			int cnt = 0;//���� �� ���� ����
			cin >> species_i;
			cout << "------print_species------" << endl;
			cnt=Zoo->find(species_i,cnt);
			cout << "Number of species is :" << cnt << endl;
			cout << "---------------------" << endl;
		}

		else if (strcmp(input, "exit") == 0)//exit �Է�
			break;//���ѷ��� Ż��

		else//�߸� �Է�
			continue;//����
	}

	delete Zoo;//�����Ҵ� ����
	return 0;
}