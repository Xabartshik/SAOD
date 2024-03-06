//Сделано Ошлаковым, ИВТ-22

#include "pseudoVector.h"
#include <iostream>
#include <random>
#include <cassert>

//Проверка на работоспособность подпрограмм
void test()
{
    //Проверки работы функций на проверку сортированности
    DArray<int> arr;
    arr.arr = new int[5] { 1, 2, 3, 4, 5 };
    arr.size = 5;
    assert(isSortedUp(arr) == 1);
    assert(isSorted(arr) == 1);
    assert(isSortedDown(arr) == 0);

    arr.arr = new int[5] {3, 2, 1};
    assert(isSorted(arr) == 1);
    assert(isSortedUp(arr) == 0);
    assert(isSortedDown(arr) == 1);

    arr.arr = new int[5] {5, 2, 7};
    assert(isSorted(arr) == 0);
    assert(isSortedUp(arr) == 0);
    assert(isSortedDown(arr) == 0);


    //Проверка поиска элемента бинарно и интерполяционно
    DArray<double> arr3;
    arr3.arr = new double[5] { 1.1, 3.0, 5.0, 7.1, 9.12 };
    arr3.size = 5;
    insertionSort(arr3);
    assert(binarSeek(arr3, 5.0) == 2);
    assert(binarSeek(arr3, 8.0) == 5);

    assert(binarSeek(arr3, 1.1) == 0);
    assert(binarSeek(arr3, 9.12) == 4);

    assert(interpolSeek(arr3, 5.0) == 2);
    assert(interpolSeek(arr3, 8.0) == 5);

    assert(interpolSeek(arr3, 1.1) == 0);
    assert(interpolSeek(arr3, 9.12) == 4);

    assert(seek(arr3, 5.0) == 2);
    assert(seek(arr3, 8.0) == 5);

    assert(seek(arr3, 9.12) == 4);
    assert(seek(arr3, 1.1) == 0);
    testMergeSort();
    testBubbleSort();
    testQuickSort();
    testShellSort();
    testInsertionSort();
}

//Тестирование bubbleSort
void testBubbleSort() {
    // Тестирование сортировки для разных случаев

    // Лучший случай (уже отсортирован)
    DArray<int> bestCase;
    int* arr = new int[5] {1, 2, 3, 4, 5};
    bestCase.arr = arr;
    bestCase.size = 5;
    bubbleSort(bestCase);
    isSortedUp(bestCase);

    // Худший случай (отсортирован в обратном порядке)
    DArray<int> worstCase;
    worstCase.arr = new int[5] {5, 4, 3, 2, 1};
    worstCase.size = 5;

    bubbleSort(worstCase);
    isSortedUp(worstCase);
    // Средний случай
    DArray<int> averageCase;
    averageCase.arr = new int[5] {2, 4, 1, 5, 3};
    averageCase.size = 5;
    bubbleSort(averageCase);
    isSortedUp(averageCase);

    // Средний случай с большим количеством повторений
    DArray<int> averageCaseRepeat;
    arr = new int[100];
    averageCaseRepeat.arr = arr;
    averageCaseRepeat.size = 100;
    for (size_t i = 0; i < 100; i++) {
        averageCaseRepeat.arr[i] = (rand() % 5) + 1;
    }
    bubbleSort(averageCaseRepeat);
    isSortedUp(averageCaseRepeat);

}
//Тестирование insertionSort
void testInsertionSort() {
    // Тестирование сортировки для разных случаев

    // Лучший случай (уже отсортирован)
    DArray<int> bestCase;
    int* arr = new int[5] {1, 2, 3, 4, 5};
    bestCase.arr = arr;
    bestCase.size = 5;
    insertionSort(bestCase);
    isSortedUp(bestCase);

    // Худший случай (отсортирован в обратном порядке)
    DArray<int> worstCase;
    worstCase.arr = new int[5] {5, 4, 3, 2, 1};
    worstCase.size = 5;

    insertionSort(worstCase);
    isSortedUp(worstCase);
    // Средний случай
    DArray<int> averageCase;
    averageCase.arr = new int[5] {2, 4, 1, 5, 3};
    averageCase.size = 5;
    insertionSort(averageCase);
    isSortedUp(averageCase);

    // Средний случай с большим количеством повторений
    DArray<int> averageCaseRepeat;
    arr = new int[100];
    averageCaseRepeat.arr = arr;
    averageCaseRepeat.size = 100;
    for (size_t i = 0; i < 100; i++) {
        averageCaseRepeat.arr[i] = (rand() % 5) + 1;
    }
    insertionSort(averageCaseRepeat);
    isSortedUp(averageCaseRepeat);

}

//Тестирование shellSort
void testShellSort() {
    // Тестирование сортировки для разных случаев

    // Лучший случай (уже отсортирован)
    DArray<int> bestCase;
    int* arr = new int[5] {1, 2, 3, 4, 5};
    bestCase.arr = arr;
    bestCase.size = 5;
    shellSort(bestCase);
    isSortedUp(bestCase);

    // Худший случай (отсортирован в обратном порядке)
    DArray<int> worstCase;
    worstCase.arr = new int[5] {5, 4, 3, 2, 1};
    worstCase.size = 5;

    shellSort(worstCase);
    isSortedUp(worstCase);
    // Средний случай
    DArray<int> averageCase;
    averageCase.arr = new int[5] {2, 4, 1, 5, 3};
    averageCase.size = 5;
    shellSort(averageCase);
    isSortedUp(averageCase);

    // Средний случай с большим количеством повторений
    DArray<int> averageCaseRepeat;
    arr = new int[100];
    averageCaseRepeat.arr = arr;
    averageCaseRepeat.size = 100;
    for (size_t i = 0; i < 100; i++) {
        averageCaseRepeat.arr[i] = (rand() % 5) + 1;
    }
    shellSort(averageCaseRepeat);
    isSortedUp(averageCaseRepeat);

}


//Тестирование mergeSort
void testMergeSort() {
    // Тестирование сортировки для разных случаев

    // Лучший случай (уже отсортирован)
    DArray<int> bestCase;
    int* arr = new int[5] {1, 2, 3, 4, 5};
    bestCase.arr = arr;
    bestCase.size = 5;
    mergeSort(bestCase, 0, bestCase.size - 1);
    isSortedUp(bestCase);

    // Худший случай (отсортирован в обратном порядке)
    DArray<int> worstCase;
    worstCase.arr = new int[5] {5, 4, 3, 2, 1};
    worstCase.size = 5;

    mergeSort(worstCase, 0, worstCase.size - 1);
    isSortedUp(worstCase);
    // Средний случай
    DArray<int> averageCase;
    averageCase.arr = new int[5] {2, 4, 1, 5, 3};
    averageCase.size = 5;
    mergeSort(averageCase, 0, averageCase.size - 1);
    isSortedUp(averageCase);

    // Средний случай с большим количеством повторений
    DArray<int> averageCaseRepeat;
    arr = new int[100];
    averageCaseRepeat.arr = arr;
    averageCaseRepeat.size = 100;
    for (size_t i = 0; i < 100; i++) {
        averageCaseRepeat.arr[i] = (rand() % 5) + 1;
    }
    mergeSort(averageCaseRepeat, 0, averageCaseRepeat.size - 1);
    isSortedUp(averageCaseRepeat);


}

//Тестирование quickSort
void testQuickSort() {
    // Тестирование сортировки для разных случаев

    // Лучший случай (уже отсортирован)
    DArray<int> bestCase;
    int* arr = new int[5] {1, 2, 3, 4, 5};
    bestCase.arr = arr;
    bestCase.size = 5;
    quickSort(bestCase, 0, bestCase.size - 1);
    isSortedUp(bestCase);

    // Худший случай (отсортирован в обратном порядке)
    DArray<int> worstCase;
    worstCase.arr = new int[5] {5, 4, 3, 2, 1};
    worstCase.size = 5;

    quickSort(worstCase, 0, worstCase.size - 1);
    isSortedUp(worstCase);
    // Средний случай
    DArray<int> averageCase;
    averageCase.arr = new int[5] {2, 4, 1, 5, 3};
    averageCase.size = 5;
    quickSort(averageCase, 0, averageCase.size - 1);
    isSortedUp(averageCase);

    // Средний случай с большим количеством повторений
    DArray<int> averageCaseRepeat;
    arr = new int[100];
    averageCaseRepeat.arr = arr;
    averageCaseRepeat.size = 100;
    for (size_t i = 0; i < 100; i++) {
        averageCaseRepeat.arr[i] = (rand() % 5) + 1;
    }
    quickSort(averageCaseRepeat, 0, averageCaseRepeat.size - 1);
    isSortedUp(averageCaseRepeat);


}