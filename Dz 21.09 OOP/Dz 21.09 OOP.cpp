// Dz 21.09 OOP.cpp : This file contains the 'main' function. Program execution begins and ends there.
//
//
//����: �������
//�������
//�������� ��������� ����� �������.���������� ����������� ������������ ��������� ������, ������� ������, 
//���������� ������� � ����������, ���������� ���������� ����������, ����������� �������, �������������� �������� � ������� ������������� ����������(+, -, *, / ), 
//����� ������������� � ������������ ��������.
//����������� ����������� ����� �(� ������������), � ������������ � ������� ������.
#include <iostream>
#include "Matrix.h"
using namespace std;

class C {
    int x;
public:
    C() = default;
    C(int numb) : x(numb) {}
    int GetElem(int row, int col) const {
        return x;
    }
    C& operator=(int a) {
        x = a;
        return *this;
    }
    C operator+(int number) {
        return C(x + number);
    }
    C operator+(const C& obj) {
        return C(x + obj.x);
    }
    C operator-(int number) {
        return C(x - number);
    }
    C operator-(const C& obj) {
        return C(x - obj.x);
    }
    C operator*(int number) {
        return C(x * number);
    }
    C operator*(const C& obj) {
        return C(x * obj.x);
    }
};

ostream& operator<<(ostream& os, const C& obj) {
    os << obj.GetElem(0, 0);
    return os;
}
C operator*(int number, const C& obj) { 
    return C(number * obj.GetElem(0, 0));
}   

int main() {
    int rows = 5;
    int columns = 5;
    int choise1, choise2, choise3, choise4, choise5;
    cout << "How to fill out the matrix? \n";
    cout << "1 - random values\n";
    cout << "2 - Fill the matrix from the keyboard\n";
    cout << "Youre choice: ";
    cin >> choise1;
    switch (choise1) {
    case 1:
        Matrix<C> A_matrix(rows, columns);
        cout << "The matrix 'A' is filled!\n";

        Matrix<C> B_matrix(rows, columns);
        cout << "The matrix 'B' is filled!\n";

        cout << "What do you want?\n";
        cout << "1 - '+'\n";
        cout << "2 - '-'\n";
        cout << "3 - '*'\n";
        cout << "4 - '/'\n";
        cout << "5 - Print matrix\n";
        cout << "Your choice: ";
        cin >> choise2;
        switch (choise2) {
        case 1:
            cout << "1 - Matrix + number\n";
            cout << "2 - A + B\n";
            cout << "Your choice: ";
            cin >> choise3;
            switch (choise3) {
            case 1:
                //A
                int plus_numberA, plus_numberB;
                cout << "Enter number for 'A' matrix: ";
                cin >> plus_numberA;
                cout << "A: ";
                Matrix<C> MatrixPlusNumberA = A_matrix.SumNumber(plus_numberA);
                A_matrix = move(MatrixPlusNumberA);

                // B
                cout << "Enter number for 'B' matrix: ";
                cin >> plus_numberB;
                cout << "B: ";
                Matrix<C> MatrixPlusNumberB = B_matrix.SumNumber(plus_numberB);
                B_matrix = move(MatrixPlusNumberB);
                break;
            case 2:
                // C
                cout << "Matrix A: " << endl;
                A_matrix.Print();
                cout << "\n";
                cout << "\t\t+" << endl;
                cout << "\n";
                cout << "Matrix B: " << endl;
                B_matrix.Print();
                cout << "\n";
                cout << "\t\t=" << endl;
                cout << "\n";
                Matrix<C> MatrixPlusMatrix = A_matrix.SumMatrix(B_matrix);
                MatrixPlusMatrix.Print();
                break;
            }
            break;
        case 2:
            cout << "1 - Matrix - number\n";
            cout << "2 - A - B\n";
            cout << "Your choice: ";
            cin >> choise4;
            switch (choise4) {
            case 1:
                // A
                int minus_numberA, minus_numberB;
                cout << "Enter number for 'A' matrix: ";
                cin >> minus_numberA;
                cout << "A: ";
                Matrix<C> MatrixMinusNumberA = A_matrix.MinusNumber(minus_numberA);
                A_matrix = move(MatrixMinusNumberA);

                //B
                cout << "Enter number for 'B' matrix: ";
                cin >> minus_numberB;
                cout << "B: ";
                Matrix<C> MatrixMinusNumberB = B_matrix.MinusNumber(minus_numberB);
                B_matrix = move(MatrixMinusNumberB);
                break;
            case 2:
                // C
                cout << "Matrix A: " << endl;
                A_matrix.Print();
                cout << "\n";
                cout << "\t\t-" << endl;
                cout << "\n";
                cout << "Matrix B: " << endl;
                B_matrix.Print();
                cout << "\n";
                cout << "\t\t=" << endl;
                cout << "\n";
                Matrix<C> MatrixMinusMatrix = A_matrix.MinusMatrix(B_matrix);
                MatrixMinusMatrix.Print();
                break;
            }
            break;
        case 3:
            cout << "1 - Matrix * number\n";
            cout << "2 - A * B\n";
            cout << "Your choice: ";
            cin >> choise5;
            switch (choise5) {
            case 1:
                //A
                int multiply_numberA, multiply_numberB;
                cout << "Enter number for 'A' matrix: ";
                cin >> multiply_numberA;
                cout << "A: ";
                Matrix<C> MatrixMultiplyNumberA = A_matrix.MultiplyNumber(multiply_numberA);
                A_matrix = move(MatrixMultiplyNumberA);

                //B
                cout << "Enter number for 'B' matrix: ";
                cin >> multiply_numberB;
                cout << "B: ";
                Matrix<C> MatrixMultiplyNumberB = B_matrix.MultiplyNumber(multiply_numberB);
                B_matrix = move(MatrixMultiplyNumberB);
                break;
            case 2:
                cout << "Matrix A: " << endl;
                A_matrix.Print();
                cout << "\n";
                cout << "\t\t*" << endl;
                cout << "\n";
                cout << "Matrix B: " << endl;
                B_matrix.Print();
                cout << "\n";
                cout << "\t\t=" << endl;
                cout << "\n";
                Matrix<C> MatrixMultiplyMatrix = A_matrix.MultiplyMatrix(B_matrix);
                MatrixMultiplyMatrix.Print();
            }
            break;
        }
    }
    return 0;
}

// Run program: Ctrl + F5 or Debug > Start Without Debugging menu
// Debug program: F5 or Debug > Start Debugging menu

// Tips for Getting Started: 
//   1. Use the Solution Explorer window to add/manage files
//   2. Use the Team Explorer window to connect to source control
//   3. Use the Output window to see build output and other messages
//   4. Use the Error List window to view errors
//   5. Go to Project > Add New Item to create new code files, or Project > Add Existing Item to add existing code files to the project
//   6. In the future, to open this project again, go to File > Open > Project and select the .sln file