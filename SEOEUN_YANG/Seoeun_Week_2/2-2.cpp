#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
using namespace std;

class animal {
private:
	char name[10];
	int year = 0;
	char species[100];

public:
	
	animal(char* name, int year, char* species);//�ڵ�������
};

class zoo {
private:
	class animal* animal_list[100];//�ִ� ���� 100���� ���� ����
	int size = 0;//���� ����

public:
	void save(char* name, int year, char* species) {
		animal_list[size] = new animal(name, year, species);
		size++;
	}




	void size_setter(int size) { this->size = size; }
	void size_getter() { this->size; }
	void animal_setter() {
		size_getter();
		this->animal_list[size];
	}
	//zoo(animal_list[]);

	
};

animal::animal(char* name, int year, char* species) {
	strcpy(this->name, name);
	this->year = year;
	strcpy(this->species, species);
	
}



int main() {
	zoo* Zoo = new zoo;
	char input[100]={};
	char name_i[10];
	int year_i;
	char species_i[100];

	while (1) {
		cout << "Please Enter Command(new_animal,print_all,print_species,exit) :";
		cin >> input;

		if (strcmp(input, "new_animal") == 0) {
			cin >> name_i >> year_i >> species_i;

			
		}

		else if (strcmp(input, "print_all") == 0) {
			//d
		}

		else if (strcmp(input, "print_species") == 0) {
			//d
		}

		else if (strcmp(input, "exit") == 0)//exit �Է�
			break;//���ѷ��� Ż��

		else//�߸� �Է�
			continue;//����
	}

	//���� �Ҵ� ����
	return 0;
}


//zoo->animal->name,year,species