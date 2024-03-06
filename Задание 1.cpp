//Сделано Ошлаковым, ИВТ-22

#include "pseudoVector.h"
#include <vector>

int main()
{
	//Счетчик итераций
	int i = 1;
	//Символ для продолжения/остановки итерации
	char cend = 1;
	//Счетчики времени
	double time_sum1 = 0;
	//Счетчик итерации с текущим размером
	unsigned cur_it = 0;
	//Проверка работоспособности
	//Служебные массивы:
	vector<size_t> length = { 100, 1'000, 10'000, 50'000, 100'000, 150'000, 200'000,  500000, 1000000, 2000000, 5000000, 10000000 };
	//	vector<size_t> length = { 100, 1'000, 10'000, 50'000, 100'000, 150'000, 200'000,  500000, 1000000, 2000000, 5000000, 10000000 };
	//100, 1000, 10000, 50000, 100000, 150000, 200000 ,  500000, 1000000
	//vector<size_t> iters =  { 1'000, 100, 100,   50,     50,      30,  20};
	vector<size_t> iters = { 100, 100, 100,   100,     100,      100,  100, 100, 100, 100, 100, 100, 100 };
	vector<double> result;
	int k = 0;
	test();
	//Размер массива
	int size = length[k];
	DArray<int> arr = createRandArray(size, 5, 20);
	while (k != length.size())
	{
		cur_it++;


		//Инициализация рандомайзера
		srand(time(NULL));
		//Первый замер
		arr = createRandArray(size, 0, 1000);
		auto t0 = steady_clock::now();
		//Сортировка массива быстро
		mergeSort(arr, 0, arr.size);
		//shellSort(arr);
		//Второй замер
		auto t1 = steady_clock::now();
		//Вычисление и преобразование в seconds
		auto delta = duration_cast<milliseconds>(t1 - t0);
		time_sum1 += delta.count();

		//Проверка, достигнута ли очередная, сотая итерация. Использовалась для вычисления средних времязатрат и сброса соответсвующих параметров. 
		//* увеличивает размер массива в 10 раз, / -- уменьшает в 10 раз
		if (i % iters[k] == 0)
		{
			cout << "Iteration №" << i << "; Size == " << size << endl;
			cout << "0 == end | + == continue | * == size*10 | / == size/10 " << endl;
			result.push_back(time_sum1 / cur_it / 1000);
			cout << "Merge sort time " << delta.count() / 1000 << " " << "Medium this iteration " << time_sum1 / cur_it / 1000 << endl;
			//cin >> cend;
			//if (cend == '*')
			//{
				//size *= 10;
				//cur_it = 0;
				//time_sum1 = 0;
			//}
			//if (cend == '+')
			//{
			k++;
			if (k == length.size())
				break;
			size = length[k];
			cur_it = 0;
			time_sum1 = 0;
			//}
			//if (cend == '/')
			//{
			//	size /= 10;
			//	cur_it = 0;
			//	time_sum1 = 0;
			//}
		}
		//Увеличение счетчика итерации
		i++;
	}
	for (int i = 0; i < result.size(); i++)
	{
		cout << result[i] << ", ";
	}
}

