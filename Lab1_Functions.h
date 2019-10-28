
#include <iostream>
#include <stdio.h>
#include <algorithm>
#include <cstdlib>
#include <iterator>
#include <numeric>

using namespace std;

template <typename T>
bool comp(const T& a, const T& b);

template <typename T>
int get_index(T* first, T* current) // функция возвращает индекс элемента, по его указателю и указателю на первый элемент. first* - указатель на первый элемент массива
{
	return current - first;
}

template <typename T, size_t N>
int count_elem(T (&first)[N]) // функция возвращает количество элементов в массиве
{
	size_t count = N;
	return count;
	
}


template <typename T>
void sort(T* first, T* last) // сортировка вставками на интервале от первого и до последнего элемента
{
	int last_indx = get_index(first, last);

	for (int i = 0; i <= last_indx; i++)
	{
		int j = get_index(first, &first[i]) - 1;
		T key = first[i];

		while ((first[j] > key) && (j >= 0))
		{
			first[j + 1] = first[j];
			j--;
		}
		first[j + 1] = key;

	}

}

template <typename T, typename Compare>
T* Find_median(T* first, T* last, Compare comp) // функция находит медиану среди первого, последнего и среднего элемента массива
											    //comp это - a < b
{
	int i = get_index(first, last) / 2; // индекс среднего элемента массива

	if ((comp(*first, *last) && (*first >= first[i])) || (!comp(*first, *last) && (*first < first[i])))
		return first;

	if ((comp(*last, *first) && (*last >= first[i])) || (!comp(*last, *first) && (*last < first[i])))
		return last;

	if (((first[i] < *last) && (first[i] >= *first)) || ((first[i] >= *last) && (first[i] < *first)))
		return first + i;

	return NULL;
}

template <typename T, typename Compare>
void q_sort(T* first, T* last, Compare comp) // comp возвращает true, если a < b и false в противном случае
{
	T* opor = Find_median(first, last, comp); // находим опорный элемент с помощью функции Find_median

	T* f = first;
	T* l = last;
	if (opor != nullptr)
	{
		do { 								       // выполняем сортировку для текущей итерации
			while ((f <= last) && comp(*f, *opor))   // ищем элемент, который меньше опорного
				f++;
			while ((l >= first) && comp(*opor, *l))  // ищем элемент, который больше опорного
				l--;

			if (f < l)
			{
				swap(*f, *l);					   // меняем найденные элементы местами
				++f;
				--l;
			}
		} while (f <= l);

	}
		// Если индекс опорного элемента меньше, допустим индекса середины, 
		// то выполняем сортировку вставками на интервале от первого до опорного элемента.
		// Если нет, то выполняем сортировку рекурсивно от первого до опорного элемента 

		if (l > first)
			if (get_index(first, last) - get_index(first, opor) < get_index(first, last) / 2)
			{
				sort(first, l);
			}
			else
			{
				q_sort(first, l, comp);
			}

		if (last > f)
			if (get_index(first, last) - get_index(first, opor) < get_index(first, last) / 2)
			{
				sort(f, last);
			}
			else
			{
				q_sort(f, last, comp);
			}
}


