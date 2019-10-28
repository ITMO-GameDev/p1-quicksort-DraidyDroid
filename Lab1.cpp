// Lab1.cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.
//

#include <iostream>
#include <stdio.h>
#include <algorithm>
#include <cstdlib>
#include <iterator>
#include <numeric>
#include "Lab1_Functions.h"


using namespace std;


	

	int main()
	{
		const int n = 100;
		int a[n];
		// Заполнение массива случайными числами
		for (int i = 0; i <= n - 1; i++)
			a[i] = rand() % 201 - 100;
		// Вывод элементов массива до сортировки
		for (int i = 0; i <= n - 1; i++)
			printf("%4d ", a[i]);
		printf("\n");


		if (count_elem(a) > 10) // Модульный тест "Test_q_sort" показал, что для массива, в котормо меньше 10-ти элементов программа выполняется очень долгло 
						        // Поэтому что бы избежать черезмерного ожидания, массив в котором 10 элементов и меньше сортируется вставками
		{
			q_sort(a, a + (n - 1), [](int a, int b) {return a < b; });
		}	
		else sort(a, a + (n - 1));

		printf("\n");
		printf("\n");

		for (int i = 0; i <= n - 1; i++)
			printf("%4d ", a[i]);
		printf("\n");
	}

