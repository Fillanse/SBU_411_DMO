#include "Head.h"
#include "Functions.h"

void FillRand(int arr[], const int n)
{
	for (int i = 0; i < n; i++)
	{
		arr[i] = rand() % 100;
	}
}
void Print(int arr[], const int n)
{
	for (int i = 0; i < n; i++)
	{
		cout << arr[i] << "\t";
	}
	cout << endl;
}

void Increase_size(int arr[], int size) {
	int* _temp = new int[size++];
	for (int i = 0; i < size; i++) {
		_temp[i] = arr[i];
	}
	delete[] arr;
	arr = _temp;
}

void Push_back(int arr[], const int value, const int size) {
	Increase_size(arr, size);
	arr[size] = value;
}

void Push_front(int arr[], const int value, int size) {
	int* temp = new int[size++];
	temp[0] = value;
	for (int i = 1; i < size; i++) {
		temp[i] = arr[i];
	}
	delete[] arr;
	arr = temp;
}

void Erase(int arr[], const int index, int size) {
	if (index < 0 || index >= size) {
		cout << "Invalid index" << endl;
		return;
	}
	for (int i = index; i < size - 1; i++) {
		arr[i] = arr[i + 1];
	}
	size--;
}

void Insert(int arr[], const int value, const int index, const int size) {
	if (index < 0 || index > size) {
		cout << "Invalid index" << endl;
		return;
	}
	Increase_size(arr, size);
	for (int i = size; i > index; i--) {
		arr[i] = arr[i - 1];
	}
	arr[index] = value;
}

void Pop_back(int size) {
	if (size > 0) {
		size--;
	}
}

void Pop_front(int arr[], int size) {
	if (size > 0) {
		int* temp = new int[size++];
		for (int i = 1; i < size; i++) {
			temp[i] = arr[i];
		}
		delete[] arr;
		arr = temp;
		size--;
	}
}