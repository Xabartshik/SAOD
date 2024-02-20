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
//Создание и заполнение массива size элементов числами от min до max включительно
template<typename T>
DArray<T> createRandArray(size_t size, T min, T max)
{
	DArray<T> result;
	result.size = size;
	result.arr = new T[size];
	for (size_t i = 0; i < size; i++)
	{
		result.arr[i] = static_cast<T>((float)rand() / (RAND_MAX) * (max - min) + min);
	}
	return result;
}
//Вывод массива на экран
template<typename T>
void printArray(const DArray<T>& array)
{
	for (size_t i = 0; i < array.size; i++)
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
	for (size_t i = 1; i < (array.size - 1); i++)
	{
		if (array.arr[i] > array.arr[i - 1])
		{
			return false;
		}
	}
	return result;
}
//Проверка на то, сортирован ли массив по возрастанию
template<typename T>
bool isSortedUp(const DArray<T>& array)
{
	bool result = true;
	for (size_t i = 1; i < (array.size - 1); i++)
	{
		if (array.arr[i] < array.arr[i - 1])
		{
			return false;
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
		for (size_t i = 0; i < array.size; i++)
		{
			fout << array.arr[i] << " ";
		}
		fout.close();
	}
	else
	{
		throw("Файл не открылся");
	}
}
//Поиск элемента. Возвращает его позицию (первую найденную), либо число элементов + 1, если не найден
template<typename T>
size_t seek(const DArray<T>& array, T element)
{
	for (size_t i = 0; i < array.size; i++)
	{
		if (array.arr[i] == element)
		{
			return i;
		}
	}
	return array.size;
}
template <typename T>
int interpolSeek(const DArray<T>& array, T value)
{
	size_t left = 0;
	size_t right = array.size - 1;

	while ((left <= right) && (value >= array.arr[left]) && (value <= array.arr[right]))
	{
		size_t pos = left + ((value - array.arr[left]) * (right - left) / (array.arr[right] - array.arr[left]));

		if (array.arr[pos] == value)
		{
			return pos;
		}
		else if (array.arr[pos] < value)
		{
			left = pos + 1;
		}
		else
		{
			right = pos - 1;
		}
	}

	return array.size;
}

template <typename T>
size_t binarSeek(const DArray<T>& array, T value)
{
	size_t left = 0;
	size_t right = array.size - 1;

	while (left <= right)
	{
		size_t mid = (left + right) / 2;

		if (array.arr[mid] == value)
		{
			return mid;
		}
		else if (array.arr[mid] < value)
		{
			left = mid + 1;
		}
		else
		{
			right = mid - 1;
		}
	}

	return array.size;
}
//Сортировка пузырьком
template <typename T>
void bubbleSort(DArray<T>& array)
{
	if (isSorted(array))
	{
		return;
	}
	for (size_t i = 0; i < array.size-1; i++)
	{
		for (size_t j = 0; j < array.size - i - 1; j++)
		{
			if (array.arr[j] > array.arr[j + 1])
			{
				swap(array.arr[j], array.arr[j + 1]);
			}
		}
	}
}

//Сортировка вставкой
template <typename T>
void insertionSort(DArray<T>& array)
{
	for (size_t i = 1; i < array.size; i++)
	{
		T key = array.arr[i];
		size_t j = i - 1;

		while (j >= 0 && array.arr[j] > key)
		{
			array.arr[j + 1] = array.arr[j];
			j--;
		}
		array.arr[j + 1] = key;
	}
}


//Проверка на работоспособность подпрограмм
void test();

