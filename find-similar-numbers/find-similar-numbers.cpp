// find-similar-numbers.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include "vector"
#include "iostream"
#include <map>
using namespace std;

/**********************************************/

int partition(int arr[], int low, int high)
{
	// pivot (Element to be placed at right position)
	int pivot = arr[high];
	int i = (low - 1);  // Index of smaller element
	for (int j = low; j <= high - 1; j++)
	{
		// If current element is smaller than the pivot
		if (arr[j] < pivot)
		{
			i++;    // increment index of smaller element
			swap(arr[i], arr[j]);
		}
	}
	swap(arr[i + 1], arr[high]);
	return (i + 1);
}

void quickSort(int arr[], int low, int high)
{
	if (low < high)
	{
		/* pi is partitioning index, arr[pi] is now
		at right place */
		int pi = partition(arr, low, high);
		quickSort(arr, low, pi - 1);  // Before pi
		quickSort(arr, pi + 1, high); // After pi
	}
}

/***************************************************/

int _tmain(int argc, _TCHAR* argv[])
{
	int size = 0;
	int *a = NULL;

	cout << "Enter total number of elements: ";
	cin >> size;
	cout << endl;

	a = new int[size];

	// Store number entered by the user
	for (int i = 0; i < size; ++i) {
		cout << "Enter Number " << i + 1 << " : ";
		cin >> a[i];
	}

	quickSort(a, 0, size - 1);

	cout <<endl<< "numbers after sorting:" << endl;
	for (int i = 0; i < size; ++i) {
		printf("%d\n", a[i]);
	}

	/**********************************/	

	map <int, int>mp;

	for (int i = 0; i<size; i++) 
		mp[a[i]]++;

	cout << endl << "Repeated element is  " << endl;
	for (auto it = mp.begin(); it != mp.end(); it++)
	{
		if (it->second != 1) 
			cout << it->first << ", it appears " << it->second << " times"<<endl;
	}

	delete[] a;
	system("pause");
	return 0;
}

