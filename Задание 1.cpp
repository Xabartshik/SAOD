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
	double time_sum = 0, time_sum1 = 0, time_sum2 = 0, time_sum3 = 0, time_sum4 = 0;
	//Счетчик итерации с текущим размером
	unsigned cur_it = 0;

	while (cend != '0')
	{
		cur_it++;
		cout << "Iteration №" << i << "; Size == " << size << endl;
		//Первый замер
		auto t0 = steady_clock::now();
		//Проверка работоспособности
		test();
		//Второй замер
		auto t1 = steady_clock::now();
		//Вычисление и преобразование в мс
		auto delta = duration_cast<milliseconds>(t1 - t0);
		//Увеличение суммы всех времен затраченных на выполнение
		time_sum += delta.count();
		//time_sum / cur_it -- вычисление среднего времени на генерацию
		cout << "Assert time " << delta.count() << " " << "Medium this iteration " << time_sum / cur_it << endl;


		//Инициализация рандомайзера
		srand(time(0));
		//Первый замер
		t0 = steady_clock::now();
		//Создание массива случайных чисел
		DArray<int> arr = createRandArray(size, 5, 20);
		//Второй замер
		t1 = steady_clock::now();
		//Вычисление и преобразование в мс
		delta = duration_cast<milliseconds>(t1 - t0);
		time_sum1 += delta.count();
		cout << "Randomising time " << delta.count() << " " << "Medium this iteration " << time_sum1 / cur_it << endl;


		t0 = steady_clock::now();
		//Проверка, сортирован ли массив
		cout << "Sorted: " << isSorted(arr) << endl;

		t1 = steady_clock::now();
		delta = duration_cast<milliseconds>(t1 - t0);

		time_sum2 += delta.count();
		cout << "Sorted check time " << delta.count() << " " << "Medium this iteration " << time_sum2 / cur_it << endl;



		t0 = steady_clock::now();
		//Сохранение массива
		saveFile(arr, "output.txt");

		t1 = steady_clock::now();
		delta = duration_cast<milliseconds>(t1 - t0);
		time_sum3 += delta.count();
		cout << "Save time " << delta.count() << " "  << "Medium this iteration " << time_sum3 / cur_it << endl;



		t0 = steady_clock::now();
		//Поиск числа в массиве
		cout << seek(arr, 21) << endl;
		t1 = steady_clock::now();
		delta = duration_cast<milliseconds>(t1 - t0);
		time_sum4 += delta.count();
		cout << "Seek time " << delta.count() << " " << "Medium this iteration " << time_sum4 / cur_it << endl;

		cout << "0 == end | + == continue | * == size*10 | / == size/10 " << endl;
		//Проверка, достигнута ли очередная, сотая итерация. Использовалась для вычисления средних времязатрат и сброса соответсвующих параметров. 
		//* увеличивает размер массива в 10 раз, / -- уменьшает в 10 раз
		if (i % 100 == 0)
		{
			cin >> cend;
			if (cend == '*')
			{
				size *= 10;
				cur_it = 0;
				time_sum = 0;
				time_sum1 = 0;
				time_sum2 = 0;
				time_sum3 = 0;
				time_sum4 = 0;
			}
			if (cend == '/')
			{
				size /= 10;
				cur_it = 0;
				time_sum = 0;
				time_sum = 0;
				time_sum1 = 0;
				time_sum2 = 0;
				time_sum3 = 0;
				time_sum4 = 0;
			}
		}
		//Увеличение счетчика итерации
		i++;
	}

}

