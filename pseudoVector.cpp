//Сделано Ошлаковым, ИВТ-22

#include "pseudoVector.h"

//Проверка на работоспособность подпрограмм
void test()
{
    //Проверки работы функций на проверку сортированности
	DArray<int> arr;
	arr.arr = new int[] { 1, 2, 3, 4, 5 };
	arr.size = 5;
	assert(isSortedUp(arr) == 1);
	assert(isSorted(arr) == 1);
	assert(isSortedDown(arr) == 0);

	arr.arr = new int[] {3, 2, 1};
	assert(isSorted(arr) == 1);
	assert(isSortedUp(arr) == 0);
	assert(isSortedDown(arr) == 1);

	arr.arr = new int[] {5, 2, 7};
	assert(isSorted(arr) == 0);
	assert(isSortedUp(arr) == 0);
	assert(isSortedDown(arr) == 0);
    //Проверка сортировки пузырьком
    DArray<int> arr1;
    arr1.arr = new int[] { 1, 2, 3, 4, 5 };
    arr1.size = 5;
    bubbleSort(arr1);
    assert(isSortedUp(arr1) == true);
    //Проверка сортировки вставкой
    DArray<int> arr2;
    arr2.arr = new int[] { 5, 4, 3, 2, 1 };
    arr2.size = 5;
    insertionSort(arr2);
    assert(isSortedUp(arr2) == true);

    //Проверка поиска элемента бинарно и интерполяционно
    DArray<double> arr3;
    arr3.arr = new double[] { 1.1, 3.0, 5.0, 7.1, 9.12 };
    arr3.size = 5;
    insertionSort(arr3);
    assert(binarSeek(arr3, 5.0) == 2);
    assert(binarSeek(arr3, 8.0) == 5);
    assert(interpolSeek(arr3, 5.0) == 2);
    assert(interpolSeek(arr3, 8.0) == 5);

    DArray<int> arr4;
    arr4.arr = new int[] { 5, 2, 7, 1, 9 };
    arr4.size = 5;
    bubbleSort(arr4);
    assert(arr4.arr[0] == 1);
    assert(arr4.arr[4] == 9);


}