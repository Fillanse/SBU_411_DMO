#include <iostream>

using namespace std;

void main() {
	int n;
	cout << "Введите размер массива: "; cin >> n;
	int* arr = new int[n];
	for (int i = 0; i < n; i++) {
		arr[i] = rand() % 100;
	}
	for (int i = 0; i < n; i++) {
		cout << arr[i] << "\t";
	}
	cout << endl;
	delete[] arr;
}