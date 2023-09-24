// Dz 21.09 OOP.cpp : This file contains the 'main' function. Program execution begins and ends there.
//
//
//Тема: шаблоны
//Задание
//Создайте шаблонный класс матрица.Необходимо реализовать динамическое выделение памяти, очистку памяти, 
//заполнение матрицы с клавиатуры, заполнение случайными значениями, отображение матрицы, арифметические операции с помощью перегруженных операторов(+, -, *, / ), 
//поиск максимального и минимального элемента.
//Реализовать собственный класс А(с перегрузками), и использовать в шаблоне класса.
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
    void SetX(int numb) {   
        x = numb;
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
    C operator/(double number) {
        return C(x / number);       
    }    
    bool operator>(const C& obj) const {
        return x > obj.x;
    }   
    bool operator<(const C& obj) const {
        return x < obj.x;   
    }
    C operator++(int) {
        C temp(*this);
        x++;
        return temp;
    }
};

ostream& operator<<(ostream& os, const C& obj) {
    os << obj.GetElem(0, 0);
    return os;
}
istream& operator>>(istream& is, C& obj)        
{
    int number;      
    is >> number;
    obj.SetX(number);   
    return is;
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

        cout << "number of type C objects: " << Matrix<C>::count << endl;   

        cout << "What do you want?\n";
        cout << "1 - '+'\n";
        cout << "2 - '-'\n";
        cout << "3 - '*'\n";
        cout << "4 - '/'\n";
        cout << "5 - look for max element\n";
        cout << "6 - look for min elemen\n";    
        cout << "7 - Print matrix\n";
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
                break;  
            }
            break;
        case 4:
            // A
            int divide_numberA, divade_numberB;      
            cout << "Enter number for 'A' matrix: ";
            cin >> divide_numberA;  
            cout << "A: ";
            Matrix <C> MatrixDivideNumberA = A_matrix.DivideNumber(divide_numberA);  
            A_matrix = move(MatrixDivideNumberA);   

            // B
            cout << "Enter number for 'B' matrix: ";    
            cin >> divade_numberB;    
            cout << "B: ";  
            Matrix <C> MatrixDivideNumberB = B_matrix.DivideNumber(divade_numberB); 
            B_matrix = move(MatrixDivideNumberB);          
           break;  
        case 5:
            cout << "A:\n";
            A_matrix.Print();
            cout << "Max element: " << A_matrix.FindMaxElem() << "\n\n";

            cout << "B:\n";
            B_matrix.Print();   
            cout << "Max element: " << B_matrix.FindMaxElem() << endl;  
            break;
        case 6:
            cout << "A:\n";
            A_matrix.Print();
            cout << "Min element: " << A_matrix.FindMinElem() << "\n\n";    

            cout << "B:\n";
            B_matrix.Print();   
            cout << "Min element: " << B_matrix.FindMinElem() << endl;      
            break;  
        case 7:
            cout << "Matrix A: \n"; 
            A_matrix.Print();       
            cout << "Matrix B: \n"; 
            B_matrix.Print();       
            break;
        }    
        break;  
        case 2: // 2 - Fill the matrix from the keyboard
            // A
            int rowsA, columnsA;  
            cout << "Enter rows: ";
            cin >> rowsA;
            cout << "Enter columns: ";  
            cin >> columnsA;
            cout << "Matrix A: \n";
            Matrix<C> A_second_matrix(rowsA, columnsA, 0);  
            cout << "The matrix 'A' is filled!\n";  

            //B
            int rowsB, columnsB;
            cout << "Enter rows: ";
            cin >> rowsB;
            cout << "Enter columns: ";
            cin >> columnsB;
            cout << "Matrix B: \n";
            Matrix <C> B_second_matrix(rowsB, columnsB, 0);    
            cout << "The matrix 'B' is filled!\n";  
            cout << Matrix<C>::count << endl;

            cout << "What do you want?\n";
            cout << "1 - '+'\n";
            cout << "2 - '-'\n";
            cout << "3 - '*'\n";
            cout << "4 - '/'\n";
            cout << "5 - look for max element\n";
            cout << "6 - look for min elemen\n";
            cout << "7 - Print matrix\n";
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
                    Matrix<C> MatrixSecondPlusNumberA = A_second_matrix.SumNumber(plus_numberA);
                    A_second_matrix = move(MatrixSecondPlusNumberA);    

                    // B
                    cout << "Enter number for 'B' matrix: ";
                    cin >> plus_numberB;
                    cout << "B: ";
                    Matrix<C> MatrixSecondPlusNumberB = B_second_matrix.SumNumber(plus_numberB);
                    B_second_matrix = move(MatrixSecondPlusNumberB);    
                    break;
                case 2:
                    // C
                    cout << "Matrix A: " << endl;
                    A_second_matrix.Print();
                    cout << "\n";
                    cout << "\t\t+" << endl;
                    cout << "\n";
                    cout << "Matrix B: " << endl;
                    B_second_matrix.Print();
                    cout << "\n";
                    cout << "\t\t=" << endl;
                    cout << "\n";
                    Matrix<C> MatrixSecondPlusMatrix = A_second_matrix.SumMatrix(B_second_matrix);    
                    MatrixSecondPlusMatrix.Print(); 
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
                    Matrix<C> MatrixSecondMinusNumberA = A_second_matrix.MinusNumber(minus_numberA);
                    A_second_matrix = move(MatrixSecondMinusNumberA);   

                    //B
                    cout << "Enter number for 'B' matrix: ";
                    cin >> minus_numberB;
                    cout << "B: ";
                    Matrix<C> MatrixSecondMinusNumberB = B_second_matrix.MinusNumber(minus_numberB);
                    B_second_matrix = move(MatrixSecondMinusNumberB);   
                    break;
                case 2:
                    // C
                    cout << "Matrix A: " << endl;
                    A_second_matrix.Print();
                    cout << "\n";
                    cout << "\t\t-" << endl;
                    cout << "\n";
                    cout << "Matrix B: " << endl;
                    B_second_matrix.Print();
                    cout << "\n";
                    cout << "\t\t=" << endl;
                    cout << "\n";
                    Matrix<C> MatrixSecondMinusMatrix = A_second_matrix.MinusMatrix(B_second_matrix);
                    MatrixSecondMinusMatrix.Print();    
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
                    Matrix<C> MatrixSecondMultiplyNumberA = A_second_matrix.MultiplyNumber(multiply_numberA);
                    A_second_matrix = move(MatrixSecondMultiplyNumberA);    

                    //B
                    cout << "Enter number for 'B' matrix: ";
                    cin >> multiply_numberB;
                    cout << "B: ";
                    Matrix<C> MatrixSecondMultiplyNumberB = B_second_matrix.MultiplyNumber(multiply_numberB);
                    B_second_matrix = move(MatrixSecondMultiplyNumberB);    
                    break;
                case 2:
                    cout << "Matrix A: " << endl;
                    A_second_matrix.Print();
                    cout << "\n";
                    cout << "\t\t*" << endl;
                    cout << "\n";
                    cout << "Matrix B: " << endl;
                    B_second_matrix.Print();
                    cout << "\n";
                    cout << "\t\t=" << endl;
                    cout << "\n";
                    Matrix<C> MatrixSecondMultiplyMatrix = A_second_matrix.MultiplyMatrix(B_second_matrix); 
                    cout << "Matrix C: \n";
                    MatrixSecondMultiplyMatrix.Print(); 
                    break;
                }
                break;
            case 4:
                // A
                int divide_numberA, divade_numberB;
                cout << "Enter number for 'A' matrix: ";
                cin >> divide_numberA;
                cout << "A: ";
                Matrix <C> MatrixSecondDivideNumberA = A_second_matrix.DivideNumber(divide_numberA);
                A_second_matrix = move(MatrixSecondDivideNumberA);  

                // B
                cout << "Enter number for 'B' matrix: ";
                cin >> divade_numberB;
                cout << "B: ";
                Matrix <C> MatrixSecondDivideNumberB = B_second_matrix.DivideNumber(divade_numberB);
                B_second_matrix = move(MatrixSecondDivideNumberB);  
                break;
            case 5:
                cout << "A:\n";
                A_second_matrix.Print();
                cout << "Max element: " << A_second_matrix.FindMaxElem() << "\n\n";

                cout << "B:\n";
                B_second_matrix.Print();
                cout << "Max element: " << B_second_matrix.FindMaxElem() << endl;
                break;
            case 6:
                cout << "A:\n";
                A_second_matrix.Print();
                cout << "Min element: " << A_second_matrix.FindMinElem() << "\n\n";

                cout << "B:\n";
                B_second_matrix.Print();
                cout << "Min element: " << B_second_matrix.FindMinElem() << endl;
                break;
            case 7:
                cout << "Matrix A: \n"; 
                A_second_matrix.Print();    
                cout << "Matrix B: \n";     
                B_second_matrix.Print();    
                break;
            }
            break;
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
