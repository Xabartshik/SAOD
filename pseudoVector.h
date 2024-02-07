//Сделано Ошлаковым, ИВТ-22

#pragma once
#include <iostream>
#include <fstream>
#include <cassert>
#include <chrono>
#include "pseudoVector.h"

using namespace std;
using namespace chrono;
//Структура массива, состоящая из динамического массива и его размера
template<typename T>
struct DArray
{
	T* arr;
	size_t size;

};
//Создание и заполнение массива size элементов числами от min до max
template<typename T>
DArray<T> createRandArray(size_t size, T min, T max)
{
	DArray<T> result;
	result.size = size;
	result.arr = new T[size];
	for (unsigned i = 0; i < size; i++)
	{
		result.arr[i] = static_cast<T>((float)rand() / (RAND_MAX) * (max - min) + min);
	}
	return result;
}
//Вывод массива на экран
template<typename T>
void printArray(const DArray<T>& array)
{
	for (unsigned i = 0; i < array.size; i++)
	{
		cout << array.arr[i] << " ";
	}
	cout << endl;
}
//Проверка на то, сортирован ли массив по убыванию
template<typename T>
bool isSortedDown(const DArray<T>& array)
{
	bool result = true;
	for (unsigned i = 1; i < (array.size - 1); i++)
	{
		if (array.arr[i] > array.arr[i - 1])
		{
			//return false;
		}
	}
	return result;
}
//Проверка на то, сортирован ли массив по возрастанию
template<typename T>
bool isSortedUp(const DArray<T>& array)
{
	bool result = true;
	for (unsigned i = 1; i < (array.size - 1); i++)
	{
		if (array.arr[i] < array.arr[i - 1])
		{
			//return false;
		}
	}
	return result;
}
//Проверка на то, сортирован ли массив каким-либо образом
template<typename T>
bool isSorted(const DArray<T>& array)
{
	if (isSortedUp(array))
	{
		return true;
	}
	else
	{
		if (isSortedDown(array))
		{
			return true;
		}
	}
	return false;

}

//Процедура сохраняющая массив в файле fileName
template<typename T>
void saveFile(const DArray<T>& array, const string& fileName)
{
	ofstream fout(fileName);
	if (fout.is_open())
	{
		for (unsigned i = 0; i < array.size; i++)
		{
			fout << array.arr[i] << " ";
		}
		fout.close();
	}
	else
	{
		cout << "Файл не открылся" << endl;
	}
}
//Поиск элемента. Возвращает его позицию (первую найденную), либо число элементов + 1, если не найден
template<typename T>
unsigned seek(const DArray<T>& array, T element)
{
	for (unsigned i = 0; i < array.size; i++)
	{
		if (array.arr[i] == element)
		{
			return i;
		}
	}
	return array.size + 1;
}

//Проверка на работоспособность подпрограмм
void test();

