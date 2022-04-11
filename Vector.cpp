#pragma once
#include "Vector.h"
using namespace std;
 
Vector::Vector(int s)
{
	//если текущий размер больше максимального, то генерируется исключение
	if (s > MAX_SIZE)
		throw 1;

	size = s;
	beg = new int[s];
	for (int i = 0; i < size; i++)
		beg[i] = 0;
}

Vector::Vector(const Vector& v)
{
	size = v.size;
	beg = new int[size];
	for (int i = 0; i < size; i++)
		beg[i] = v.beg[i];
}

Vector::~Vector()
{
	if (beg != 0)
		delete[] beg;
}

Vector::Vector(int s, int* mas)
{
	//если текущий размер больше максимального, то генерируется исключение
	if (s > MAX_SIZE)
		throw 1;

	size = s;
	beg = new int[size];
	for (int i = 0; i < size; i++)
		beg[i] = mas[i];
}

const Vector& Vector::operator=(const Vector& v)
{
	if (this == &v)
		return *this;
	if (beg != 0)
		delete[] beg;

	size = v.size;
	beg = new int[size];
	for (int i = 0; i < size; i++)
		beg[i] = v.beg[i];
	return *this;
}

ostream& operator<<(ostream& out, const Vector& v)
{
	if (v.size == 0) out << "Empty\n";
	else
	{
		for (int i = 0; i < v.size; i++)
			out << v.beg[i] << " ";
		out << endl;
	}
	return out;
}

istream& operator >>(istream& in, Vector& v)
{
	for (int i = 0; i < v.size; i++)
	{
		cout << ">";
		in >> v.beg[i];
	}
	return in;
}

int& Vector::operator[](int i)
{
	if (i < 0) throw 2;//если индекс отрицательный, то генерируется исключение
	//если индекс больше размер вектора, то генерируется исключение
	if (i >= size) throw 3;
	return beg[i];
}

int Vector::operator()()
{
	return size;
}

const Vector& Vector::operator+(int a)
{
	for (int i = 0; i < size; ++i)
		beg[i] += a;
	return *this;
}

const Vector& Vector::operator-(int n)
{
	if (n < 0) throw 4;
	if (size < n) throw 5;

	if (size == n)//если в вектор один элемент
	{
		size = 0;
		delete[] beg;
		beg = 0;
	} else {
		int* temp = new int[size - n];
		size -= n;
		for (int i = 0; i < size; ++i)
			temp[i] = beg[i];
		delete[] beg;
		beg = temp;
	}

	return *this;
}