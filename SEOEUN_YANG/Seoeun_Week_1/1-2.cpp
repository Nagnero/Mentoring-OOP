#include <iostream>
#include <cstdlib>
#include <ctime>
using namespace std;

int main(void) {
    int a = 10, b = 10;

    int** mat = new int* [a];//2���� �迭 �����Ҵ�
    for (int i = 0; i < a; i++)
        mat[i] = new int[b];

    int** mat2 = new int* [a];//2���� �迭 �����Ҵ� (�� ����)

    int* SUM = new int[a];//�� �迭 �����Ҵ�
    int* SUM2 = new int[a];//�� �迭 �����Ҵ� (�񱳿�)

    srand((unsigned int)time(NULL));//������ ���� ����

    for (int i = 0; i < a; i++) {
        for (int j = 0; j < b; j++)
            mat[i][j] = rand() % 101;//0~100 ���� ���� �� �迭 ����
    }

    //bubble sort
    int temp;//�� �� �������� ����
    for (int i = 0; i < a; i++) {
        for (int j = 0; j < a; j++) {
            for (int k = 0; k < a - 1; k++) {
                if (mat[i][k] >= mat[i][k + 1]) {
                    temp = mat[i][k];
                    mat[i][k] = mat[i][k + 1];
                    mat[i][k + 1] = temp;
                }
            }
        }
    }

    cout << "Sort by row" << endl;//���
    for (int i = 0; i < a; i++) {
        int sum = 0;
        for (int j = 0; j < b; j++) {
            cout.width(5);
            cout << left << mat[i][j];
            sum += mat[i][j];
        }
        cout << "Sum is " << sum << "(" << &mat[i] << ")";
        SUM[i] = sum;
        cout << endl;
    }

    cout << endl << endl;

    for (int i = 0; i < a; i++)
        SUM2[i] = SUM[i];

    for (int i = 0; i < a; i++) {
        for (int j = 0; j < a - 1; j++) {
            if (SUM[j] >= SUM[j + 1]) {
                int temp = SUM[j];//���� �������� ����
                SUM[j] = SUM[j + 1];
                SUM[j + 1] = temp;
            }
        }
    }

    //compare
    int ord[10];
    for (int i = 0; i < a; i++) {
        for (int j = 0; j < a; j++) {
            if (SUM[i] == SUM2[j]) {
                mat2[i] = mat[j];
                ord[i] = j;
            }
        }
    }

    cout << "Sort by sum" << endl;
    for (int i = 0; i < a; i++) {
        for (int j = 0; j < a; j++) {
            cout.width(5);
            cout << left << mat2[i][j];//���� ����
        }
        cout << "Sum is " << SUM[i] << "(" << &mat[ord[i]] << ")" << endl;
    }

    for (int i = 0; i < a; i++)
        delete[] mat[i];
    delete mat;

    return 0;
}