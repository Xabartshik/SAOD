//Сделано Ошлаковым, ИВТ-22

#include "pseudoVector.h"


int main()
{
	//Счетчик итераций
	int i = 1;
	//Размер массива
	int size = 10E1;
	//Символ для продолжения/остановки итерации
	char cend = 1;
	//Счетчики времени
	double time_sum = 0, time_sum1 = 0, time_sum2 = 0, time_sum3 = 0, time_sum4 = 0, time_sum5 = 0;
	//Счетчик итерации с текущим размером
	unsigned cur_it = 0;
	//Проверка работоспособности
	test();

	while (cend != '0')
	{
		cur_it++;
		cout << "Iteration №" << i << "; Size == " << size << endl;


		//Инициализация рандомайзера
		srand(time(0));
		//Первый замер
		DArray<int> arr = createRandArray(size, 5, 20);
		auto t0 = steady_clock::now();
		//Сортировка массива пузырьком
		bubbleSort(arr);
		//Второй замер
		auto t1 = steady_clock::now();
		//Вычисление и преобразование в мс
		auto delta = duration_cast<microseconds>(t1 - t0);
		time_sum1 += delta.count();
		cout << "Buble sort time " << delta.count() << " " << "Medium this iteration " << time_sum1 / cur_it << endl;



		arr = createRandArray(size, 5, 20);
		t0 = steady_clock::now();
		insertionSort(arr);
		t1 = steady_clock::now();
		delta = duration_cast<microseconds>(t1 - t0);

		time_sum5 += delta.count();
		cout << "Insertion sort time " << delta.count() << " " << "Medium this iteration " << time_sum5 / cur_it << endl;


		t0 = steady_clock::now();
		//Поиск элемента бинарный
		cout << binarSeek(arr, 21) << endl;
		t1 = steady_clock::now();
		delta = duration_cast<microseconds>(t1 - t0);

		time_sum2 += delta.count();
		cout << "Seek binary " << delta.count() << " " << "Medium this iteration " << time_sum2 / cur_it << endl;



		t0 = steady_clock::now();
		//Поиск элемента по интерполяционному методу
		cout << interpolSeek(arr, 21) << endl;

		t1 = steady_clock::now();
		delta = duration_cast<microseconds>(t1 - t0);
		time_sum3 += delta.count();
		cout << "Seek interpolation " << delta.count() << " "  << "Medium this iteration " << time_sum3 / cur_it << endl;



		t0 = steady_clock::now();
		//Поиск числа в массиве
		cout << seek(arr, 21) << endl;
		t1 = steady_clock::now();
		delta = duration_cast<microseconds>(t1 - t0);
		time_sum4 += delta.count();
		cout << "Seek element default time " << delta.count() << " " << "Medium this iteration " << time_sum4 / cur_it << endl;

		cout << "0 == end | + == continue | * == size*10 | / == size/10 " << endl;
		//Проверка, достигнута ли очередная, сотая итерация. Использовалась для вычисления средних времязатрат и сброса соответсвующих параметров. 
		//* увеличивает размер массива в 10 раз, / -- уменьшает в 10 раз
		if (i % 10 == 0)
		{
			cin >> cend;
			if (cend == '*')
			{
				size *= 10;
				cur_it = 0;
				time_sum1 = 0;
				time_sum2 = 0;
				time_sum3 = 0;
				time_sum4 = 0;
				time_sum5 = 0;
			}
			if (cend == '/')
			{
				size /= 10;
				cur_it = 0;
				time_sum1 = 0;
				time_sum2 = 0;
				time_sum3 = 0;
				time_sum4 = 0;
				time_sum5 = 0;
			}
		}
		//Увеличение счетчика итерации
		i++;
	}

}

