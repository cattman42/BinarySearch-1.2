// BinarySearch (Project 1).cpp : This file contains the 'main' function. Program execution begins and ends there.
//
// Caleb Catt, 4/10/2019, CMSC 270, Binary Search in Pointer Format

#include <iostream>
using namespace std;

int* binSearch(int *list, int target, int *first, int *last)
{
	int length = (*first + *last) / 2;
	int * middle = first;
	while (*middle < length)
		middle++;
	cout << "Entering binSearch: \n\tfirstptr: " << first << " contains " << *first << "\n"
		<< "\tlastptr: " << last << " contains " << *last << "\n" << "\tmidptr: " << middle << " contains " << *middle << "\n";
	if (*first > *last)
		return NULL;
	else if (target == *middle)
		return middle;
	else if (target < *middle)
		return binSearch(list, target, first, middle - 1);
	else
		return binSearch(list, target, middle + 1, last);
}

int main()
{
	int list[10];
	int * startptr;
	int * ptr;
	int * endptr;
	startptr = list;
	ptr = list;
	
	int length = sizeof(list) / sizeof(*ptr);
	
	cout << "This list is ";
	for (int i = 0; i < length; i++)
	{
		*ptr = (2 * i + 1);
		cout << *ptr << " ";
		ptr++;
	}
	endptr = ptr-1;
	

	cout << "\n";

	cout << "Enter a key: ";
	int key;
	cin >> key;

	int* index = binSearch(list, key, startptr, endptr);
	ptr = startptr;
	int counter = 0;
	while (ptr != index)
	{
		ptr++;
		counter++;
	}
	if (index != NULL)
		cout << "The key is found at zero-based index: " << counter;
	else
		cout << "The key is not found in the list.";
		
}



// Run program: Ctrl + F5 or Debug > Start Without Debugging menu
// Debug program: F5 or Debug > Start Debugging menu

// Tips for Getting Started: 
//   1. Use the Solution Explorer window to add/manage files
//   2. Use the Team Explorer window to connect to source control
//   3. Use the Output window to see build output and other messages
//   4. Use the Error List window to view errors
//   5. Go to Project > Add New Item to create new code files, or Project > Add Existing Item to add existing code files to the project
//   6. In the future, to open this project again, go to File > Open > Project and select the .sln file
