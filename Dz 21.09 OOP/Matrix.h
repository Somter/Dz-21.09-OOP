#pragma once
#include <iostream>	
using namespace std;

template<class T>		
class Matrix{
private:
	int columns;		
	int rows;			
	T** ptr;		
public:
	Matrix() = default;		
	Matrix(int r, int c);	
	void Print();	
	T GetElem(int row, int col);	
	Matrix<T> SumNumber(int number);	
	Matrix<T> SumMatrix(Matrix<T> obj);		
	Matrix<T> MinusNumber(int number);		
	Matrix<T> MinusMatrix(Matrix<T> obj);
	Matrix<T> MultiplyNumber(int number);		
	Matrix<T> MultiplyMatrix(Matrix<T> obj);				
		
	 //~Matrix();							
};
	
template<class T>
inline Matrix<T>::Matrix(int r, int c)
{
	rows = r;	
	columns = c;
	ptr = new T* [rows];	
	for (int i = 0; i < rows; i++) 
	{
		ptr[i] = new T[columns];	
	}
	for (int i = 0; i < rows; i++) 
	{
		for (int j = 0; j < columns; j++)	
		{
			ptr[i][j] = rand() % 30;
		}
	}
}

template<class T>
inline void Matrix<T>::Print()
{
	for (int i = 0; i < rows; i++)	
	{
		for (int j = 0; j < columns; j++)	
		{
			cout << ptr[i][j] << '\t';		
		}	
		cout << endl;
	}
}

template<class T>
inline T Matrix<T>::GetElem(int row, int col)	
{	
	if (row >= 0 && row < rows && col >= 0 && col < columns) {	
		return ptr[row][col];	
	}	
}

template<class T>
inline Matrix<T> Matrix<T>::SumNumber(int number)
{
	//Matrix + number
	Matrix rez;
	rez.rows = rows;	
	rez.columns = columns;	
	rez.ptr = new T*[rows];	

	for (int i = 0; i < rows; i++)	{
		rez.ptr[i] = new T[columns];	
	}
	for (int i = 0; i < rows; i++) {
		for (int j = 0; j < columns; j++){
			rez.ptr[i][j] = ptr[i][j];	
		}	
	}	
	for (int i = 0; i < rows; i++){
		for (int j = 0; j < columns; j++)	{
			rez.ptr[i][j] = rez.ptr[i][j] + number;	
		}		
	}
	cout << "+ " << number << " to matrix elements!\n";	
	return rez;	
}

template<class T>
inline Matrix<T> Matrix<T>::SumMatrix(Matrix<T> obj)
{
	//A + B	
	if (rows == obj.rows && columns == obj.columns){
		Matrix rezult;
		rezult.rows = rows;
		rezult.columns = columns;	
		rezult.ptr = new T * [rows];

		for (int i = 0; i < rows; i++) {
			rezult.ptr[i] = new T[columns];	
		}
		for (int i = 0; i < rows; i++) {
			for (int j = 0; j < columns; j++){
				rezult.ptr[i][j] = ptr[i][j];	
			}
		}
		for (int i = 0; i < rows; i++){
			for (int j = 0; j < columns; j++){
				rezult.ptr[i][j] = rezult.ptr[i][j] + obj.ptr[i][j];	
			}
		}
		cout << "Matrix C: " << endl;		
		return rezult;	
	}
	else {
		cout << "The matrix sizes must be equal!\n";	
		return  Matrix<T>();	
	}
}
template<class T>
inline Matrix<T> Matrix<T>::MinusNumber(int number)	
{
	//Matrix - number
	Matrix rez;
	rez.rows = rows;
	rez.columns = columns;
	rez.ptr = new T * [rows];

	for (int i = 0; i < rows; i++) {
		rez.ptr[i] = new T[columns];
	}
	for (int i = 0; i < rows; i++) {
		for (int j = 0; j < columns; j++) {
			rez.ptr[i][j] = ptr[i][j];
		}
	}
	for (int i = 0; i < rows; i++) {
		for (int j = 0; j < columns; j++) {
			rez.ptr[i][j] = rez.ptr[i][j] - number;
		}
	}
	cout << "- " << number << " to matrix elements!\n";
	return rez;
}
template<class T>
inline Matrix<T> Matrix<T>::MinusMatrix(Matrix<T> obj)
{
	//A - B	
	if (rows == obj.rows && columns == obj.columns) {
		Matrix rezult;
		rezult.rows = rows;
		rezult.columns = columns;
		rezult.ptr = new T * [rows];

		for (int i = 0; i < rows; i++) {
			rezult.ptr[i] = new T[columns];
		}
		for (int i = 0; i < rows; i++) {
			for (int j = 0; j < columns; j++) {
				rezult.ptr[i][j] = ptr[i][j];
			}
		}
		for (int i = 0; i < rows; i++) {
			for (int j = 0; j < columns; j++) {
				rezult.ptr[i][j] = rezult.ptr[i][j] - obj.ptr[i][j];
			}
		}
		cout << "Matrix C: " << endl;	
		return rezult;
	}
	else {
		cout << "The matrix sizes must be equal!\n";
		return  Matrix<T>();	
	}
}
template<class T>
inline Matrix<T> Matrix<T>::MultiplyNumber(int number)
{
	// Matrix * number
	Matrix rez;
	rez.rows = rows;	
	rez.columns = columns;	
	rez.ptr = new T * [rows];

	for (int i = 0; i < rows; i++) {
		rez.ptr[i] = new T[columns];
	}
	for (int i = 0; i < rows; i++) {	
		for (int j = 0; j < columns; j++) {	
			rez.ptr[i][j] = ptr[i][j];	
		}
	}
	for (int i = 0; i < rows; i++) {	
		for (int j = 0; j < columns; j++) {	
			rez.ptr[i][j] = rez.ptr[i][j] * number;	
		}
	}
	cout << "* " << number << " to matrix elements!\n";
	return rez;
}
template<class T>
inline Matrix<T> Matrix<T>::MultiplyMatrix(Matrix<T> obj)	
{	
	// Matrix * Matrix
	if (columns == obj.rows) {	
		Matrix<T> result(rows, obj.columns);	

		for (int i = 0; i < rows; i++) {
			for (int j = 0; j < obj.columns; j++) {
				T sum = 0;
				for (int k = 0; k < columns; k++) {
					sum = sum + ptr[i][k] * obj.ptr[k][j];
				}
				result.ptr[i][j] = sum;
			}
		}
		cout << "Matrix C: " << endl;
		return result;
	}
	else {
		cout << "Matrix dimensions are not compatible for multiplication!\n";
		return Matrix<T>();
	}
}
//
//template<class T>
//inline Matrix<T>::~Matrix()
//{
//	cout << "Destructor\n";	
//	for (int i = 0; i < rows; i++) 
//	{
//		delete[] ptr[i];	
//	}
//	delete[] ptr;		
//	ptr = nullptr;	
//}