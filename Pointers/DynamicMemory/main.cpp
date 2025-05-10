#include <iostream>

using namespace std;

void FillRand(int arr[], const int n);
void Print(int arr[], const int n);

void main()
{
	setlocale(LC_ALL, "");
	const int n = 10;
	int arr[n];
	FillRand(arr, n);
	Print(arr, n);


	int even_count = 0;
	int odd_count = 0;
	for (int i = 0; i < n; i++)
	{
		if (arr[i] % 2 == 0)even_count++;
		else odd_count++;
	}

	int* even_arr = new int[even_count];
	int* odd_arr = new int[odd_count];

	for (int i = 0, j = 0, k = 0; i < n; i++)
	{
		if (arr[i] % 2 == 0)even_arr[j++] = arr[i];
		else odd_arr[k++] = arr[i];
	}


	Print(even_arr, even_count);
	Print(odd_arr, odd_count);


	delete[] odd_arr;
	delete[] even_arr;
}

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