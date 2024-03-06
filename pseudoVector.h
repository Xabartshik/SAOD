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

// Функция для обмена двух элементов в массиве
template<typename T>
void swap(T* a, T* b) {
	T temp = *a;
	*a = *b;
	*b = temp;
}
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
//Проверка на то, сортирован ли массив каким-либо образом. Средняя сложность - n
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
//Поиск элемента. Возвращает его позицию (первую найденную), либо число элементов + 1, если не найден. Средняя сложность - n
//...в худшем случае О(n)
//...в лучшем случае О(1)
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
//Интерполяционный поиск. Средняя сложность - log(log(n))
//...в худшем случае О(n)
//...в лучшем случае О(1)
template <typename T>
int interpolSeek(const DArray<T>& array, T value)
{
	size_t left = 0;
	size_t right = array.size - 1;
	//if (!isSortedUp(array))
	//{
	//	return array.size;
	//}
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
//Бинарный поиск. Средняя сложность -  log(n)
//...в худшем случае О(log(n))
//...в лучшем случае О(1)
template <typename T>
size_t binarSeek(const DArray<T>& array, T value)
{
	size_t left = 0;
	size_t right = array.size - 1;
	//if (!isSortedUp(array))
	//{
	//	return array.size;
	//}
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
//Сортировка пузырьком по возрастанию. Средняя сложность -- n^2
//...в худшем случае О(n^2)
//...в лучшем случае О(n)
template <typename T>
void bubbleSort(DArray<T>& array)
{
	//if (isSortedUp(array))
	//{
	//	return;
	//}
	for (size_t i = 0; i < array.size - 1; i++)
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

// Сортировка вставкой по возрастанию. Средняя cложность -- n^2
//...в худшем случае О(n^2)
//...в лучшем случае О(n)
template <typename T>
void insertionSort(DArray<T>& array)
{
	//if (isSortedUp(array))
	//{
	//	return;
	//}
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
// Процедура реализации слияния.
/*
* Функция mergeSort принимает массив arr, индекс начала left и индекс конца right.
* Если left меньше right, то массив делится на две равные части, и алгоритм рекурсивно вызывается для каждой части.
* После сортировки подмассивов вызывается функция merge для объединения отсортированных подмассивов в один отсортированный массив.
* * Функция merge принимает массив arr, индекс начала left, индекс середины mid и индекс конца right.
* Она создает временный массив temp для хранения отсортированного массива.
* Функция использует три указателя i, j и k для отслеживания позиций в подмассивах и временном массиве соответственно.
* Она сравнивает элементы из двух подмассивов и добавляет меньший элемент во временный массив.
* После добавления всех элементов из обоих подмассивов во временный массив, временный массив копируется обратно в исходный массив.
*/
template <typename T>
void merge(DArray<T>& arr, size_t left, size_t mid, size_t right) {
	size_t i = left, j = mid + 1, k = 0;
	DArray<T> temp;
	T* tArray = new T[right - left + 1];
	temp.arr = tArray;

	while (i <= mid && j <= right) {
		if (arr.arr[i] <= arr.arr[j]) {
			temp.arr[k++] = arr.arr[i++];
		}
		else {
			temp.arr[k++] = arr.arr[j++];
		}
	}

	while (i <= mid) {
		temp.arr[k++] = arr.arr[i++];
	}

	while (j <= right) {
		temp.arr[k++] = arr.arr[j++];
	}
	//memcpy для копирования массивов (для копирования из временного массива в основной) (куда, откуда, кол-во байт)
	size_t size = sizeof(T) * (right - left + 1);
	//Куда, откуда, размер
	memcpy(arr.arr + left, temp.arr, size);

}

/// Сортировка слиянием по возрастанию. Время работы для всех случаев: NLog(N)

template <typename T>
void mergeSort(DArray<T>& arr, size_t left, size_t right) {
	//if (isSortedUp(arr))
	//{
	//	return;
	//}
	if (left < right) {
		size_t mid = (left + right) / 2;
		mergeSort(arr, left, mid);
		mergeSort(arr, mid + 1, right);
		merge(arr, left, mid, right);
	}
}
// Функция для разбиения массива вокруг опорного элемента. 
// Опорный элемент выбирается случайным образом
/// На флешке и в дебаге может случиться переполнение стэка
template<typename T>
size_t partition(DArray<T>& arr, int low, int high) {
	// Выбор опорного элемента
	int pivot = arr.arr[rand()%arr.size];

	// Индекс последнего элемента, меньшего опорного
	int i = low - 1;

	// Проход по массиву
	for (int j = low; j < high; j++) {
		// Если текущий элемент меньше опорного
		if (arr.arr[j] < pivot) {
			i++;
			swap(&arr.arr[i], &arr.arr[j]);
		}
	}

	// Размещение опорного элемента в правильном месте
	swap(&arr.arr[i + 1], &arr.arr[high]);

	// Возврат индекса опорного элемента
	return i + 1;
}
/// Лучший случай: n log n, средний: n log n, худший: n*n
/// Опорный элемент выбирается случайным образом
// Функция для сортировки массива с помощью алгоритма быстрой сортировки
// На флешке и в дебаге может случиться переполнение стэка
template <typename T>
void quickSort(DArray<T>& arr, int low, int high) {
	// Если массив содержит более одного элемента
	if (low < high) {
		// Разбить массив вокруг опорного элемента
		int pi = partition(arr, low, high);

		// Рекурсивно отсортировать левый и правый подмассивы
		quickSort(arr, low, pi - 1);
		quickSort(arr, pi + 1, high);
	}
}
/// Лучший случай -- n log(n)
/// Средний случай -- (n log(n))^2
/// Худший случай -- (n log(n))^2
/// Сортировка Шелла. Изначальный шаг равен половине размера массива, 
/// затем уменьшается на половину, пока не станет равен 0, тогда все кончается
template<typename T>
void shellSort(DArray<T>& arr) {
	//Если массив отсортирован, то сортировки не будет
	//if (isSortedUp(arr))
	//{
	//	return;
	//}
	//Установка шага
	size_t size = arr.size;
	//Шаг меняется по половина от размера, а затем половина от самого шага
	size_t gap = size / 2;

	//Пока шаг больше 0
	while (gap > 0)
	{
		//Проходимся по массиву
		for (size_t i = gap; i < size; i++)
		{
			//Сохраняем текущий элемент
			T curr = arr.arr[i];
			//Сдвигаем элементы, пока не найдем место для curr
			size_t j = i;
			while (j >= gap && arr.arr[j - gap] > curr)
			{
				arr.arr[j] = arr.arr[j - gap];
				j -= gap;
			}
			//Вставляем элемент в позицию
			arr.arr[j] = curr;
		}
		//Понижение шага
		gap /= 2;
	}

}
//Проверка на работоспособность подпрограмм
void test();
//Тестирование mergeSort
void testMergeSort();
//Тестирование BubbleSort
void testBubbleSort();
//Тестирование QuickSort
void testQuickSort();
//Тестирование ShellSort
void testShellSort();
//Тестирование ShellSort
void testInsertionSort();
