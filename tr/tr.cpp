// tr.cpp: определяет точку входа для консольного приложения.
//

#include "stdafx.h"
#include <iostream>
using namespace std;
/*! Методом быстрой сортировки сортирует массив ar.
 * \param [in] ar − указатель на массив
 * \param [in] firs − первый элемент
 * \param [in] n − последний элемент
 */

void sortarr(int *ar, int firs, int las)
{
	int buf,start,x,y;//!<Буфер, опорная переменная, 2 переменные для индексации
	x=firs;
	y=las;
	start=ar[(x+y) / 2];
	do
	{
		while (ar[x]<start)
		{
			x++;
		}
		while (ar[y]>start)
		{
			y--;
		}
		if (x<=y) 
		{
			buf=ar[x];
			ar[x]=ar[y];
			ar[y]=buf;
			x++;
			y--;
		}
	} while (x<y);
	if (firs<y) sortarr(ar, firs, y);
	if (x<las) sortarr(ar, x, las);
}
//!Функция main

int main()
{
	int n, first, last;//!<Кол-во элементов, первый и последний элементы
	cout<<"n="; cin>>n;
	first=0; 
	last=n-1;
	int *arr=new int[n];//!<Массив целых чисел
	cout<<"arr:\n";
	for (int i=0; i<n; i++)
	{
		cin>>arr[i];
	}
	sortarr(arr, first, last);
	cout<<"after sort:\n";
	for (int i=0; i<n; i++) 
	{
		cout<<arr[i]<<" ";
	}
	delete []arr;
	system("pause");
	return 0;
}
