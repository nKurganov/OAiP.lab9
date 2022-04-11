#pragma once
#include <iostream>

const int MAX_SIZE = 30;//максимальный размер вектора

class Vector
{
	int size;//текущий размер
	int* beg;//указатель на начало динамического массива
public:
	Vector() { size = 0; beg = 0; }//конструктор без параметров
	Vector(int s);//конструктор с параметром
	Vector(int s, int* mas);//конструктор с параметром
	Vector(const Vector& v);//конструктор копирования
	~Vector();//деструктор
	const Vector& operator=(const Vector& v);//операция присваивания

	int& operator[](int i);//доступ по индексу
	int operator()();
	const Vector& operator+(int a);//добавление к элементам
	const Vector& operator-(int n);//удалить n элементов
	//дружественные функции ввода-вывода
	friend std::ostream& operator<<(std::ostream& out, const Vector& v);
	friend std::istream& operator>>(std::istream& in, Vector& v);
};

