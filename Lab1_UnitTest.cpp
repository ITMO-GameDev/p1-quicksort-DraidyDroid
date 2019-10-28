﻿#include "pch.h"
#include "CppUnitTest.h"
#include "D:\Учёба\Итмо\Алгоритмы_лабы\Проги\Lab1\Lab1\Lab1_Functions.h"


using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace Lab1UnitTest
{
	TEST_CLASS(Lab1UnitTest)
	{
	public:
		
		// Тестирование функций, используемых в функциях sort и q_sort 
		TEST_METHOD(Test_get_index) //Тестирование функции get_index
		{
			int a[3] = {1,2,3};

			Assert::AreEqual(2, get_index(a, a + 2)); // Проверяем индекс последнего элемента
			Assert::AreEqual(1, get_index(a, a + 1)); // Проверяем индекс второго элемента
			Assert::AreEqual(0, get_index(a, a)); // Проверяем индекс первого элемента
			
		}

		TEST_METHOD(Test_count_elem) //Тестирование функции count_elem
		{
			int a[3] = { 1, 2, 3 };

			Assert::AreEqual(3, count_elem(a)); // Проверяем количество элементов в массиве
		}

		TEST_METHOD(Test_Find_median) // Тестирование функции Find_median
		{
			int a[5] = { 1, 2, 3, 4, 5 };

			Assert::AreEqual(a[2], *Find_median(a,a+4, [](int a, int b) {return a < b; })); // Проверяем, является ли число 3 медианой

		}
		//===================================================================================
		// тестирование функций сортировки

		TEST_METHOD(Test_sort)
		{
			int a[5] = { 3, 5, 4, 1, 2 }; // неотсортированный массив. Отсортированный выглядит так: {1, 2, 3, 4, 5}

			
			bool t = true; // контрольная переменная

			sort(a, a + 4); // сортируем массив вставками

			for (int i = 1; i<count_elem(a);i++) // проверяем массив на предмет отсортированности
			{
				if (a[i-1] > a[i]) { t = false; break; } // если какой-то элемент больше следующего, то значит массив не отсортирован
			}

			Assert::IsTrue(t); // проверка контрольной переменной 

		}

		TEST_METHOD(Test_q_sort) // Тест показал, что для массивов, которые содержат в себе 10 элементов и меньше метод q_sort выполняется очень долго
								 // поэтому массив, который содержит в себе 10 элементов и меньше сортируется методом вставками
		{

			int a[9] = { 3, 5, 2, 4, 1, 3, 5, 2 }; // неотсортированный массив. Отсортированный выглядит так: {1, 2, 3, 4, 5}

			//int a[100];
			//// Заполнение массива случайными числами
			//for (int i = 0; i <= 99; i++)
			//	a[i] = rand() % 201 - 100;


			bool t = true; // контрольная переменная

			q_sort(a, a+8, [](int a, int b) {return a < b; }); // сортируем массив алгоритмом быстрой сортировки

			for (int i = 1; i < count_elem(a); i++) // проверяем массив на предмет отсортированности
			{
				if (a[i-1] > a[i]) { t = false; break; } // если какой-то элемент больше следующего, то значит массив не отсортирован
			}

			Assert::IsTrue(t); // проверка контрольной переменной 

		}
	};
}
