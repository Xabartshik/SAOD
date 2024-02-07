//Сделано Ошлаковым, ИВТ-22

#include "pseudoVector.h"

//Проверка на работоспособность подпрограмм
void test()
{
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
}