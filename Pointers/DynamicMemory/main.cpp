#include <iostream>

using std::cout;
using std::cin;
using std::endl;

#define tab "\t"

void FillRand(double* arr, const int n);
void FillRand(double** arr, const int rows, const int cols);

void Print(int* arr, const int n);
void Print(int** arr, const int rows, const int cols);

void Increase_size(int*& arr, int size);
void Push_back(int*& arr, const int value, int size);
void Push_front(int*& arr, const int value, int size);
void Erase(int*& arr, const int index, int size);
void Insert(int*& arr, const int value, const int index, int size);
void Pop_back(int& size);
void Pop_front(int*& arr, int size);

void Push_row_back(int**& arr, int rows, const int cols, const int* values);
void Pop_row_back(int**& arr, int rows);

//#define DYNAMIC_MEMORY_1
#define DYNAMIC_MEMORY_2

void main()
{
#ifdef DYNAMIC_MEMORY_1
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
#endif // DYNAMIC_MEMORY_1

	int rows;
	int cols;

	cout << "Enter amount of rows: "; cin >> rows;
	cout << "Enter amount of columns: "; cin >> cols;

	int** arr = new int* [rows];

	for (int i = 0; i < rows; i++) {
		arr[i] = new int[cols];
	}

	FillRand(arr, rows, cols);
	Print(arr, rows, cols);

	Pop_row_back(arr, rows);
	Print(arr, rows, cols);

	for (int i = 0; i < rows; i++) {
		delete arr[i];
	}
	delete[] arr;
}

void FillRand(double** arr, const int rows, const int cols)
{
	for (int i = 0; i < rows; i++) {
		for (int j = 0; j < cols; j++)
		{
			arr[i][j] = rand() % 100;
		}
	}

}

void FillRand(double* arr, const int n)
{
	for (int i = 0; i < n; i++)
	{
		arr[i] = rand() % 100;
	}
}

void Print(int** arr, const int rows, const int cols)
{
	for (int i = 0; i < rows; i++) {
		for (int j = 0; j < cols; j++)
		{
			cout << arr[i][j] << tab;
		}
		cout << endl;
	}
	cout << endl;
}

void Print(int* arr, const int n)
{
	for (int i = 0; i < n; i++)
	{
		cout << arr[i] << tab;
	}
	cout << endl;
}

void Increase_size(int*& arr, int size) {
	int* temp = new int[size + 1];
	for (int i = 0; i < size; i++) {
		temp[i] = arr[i];
	}
	delete[] arr;
	arr = temp;
	size++;
}

void Push_back(int*& arr, const int value, int size) {
	Increase_size(arr, size);
	arr[size] = value;
}

void Push_front(int*& arr, const int value, int size) {
	int* temp = new int[size + 1];
	temp[0] = value;
	for (int i = 1; i < size; i++) {
		temp[i] = arr[i];
	}
	delete[] arr;
	arr = temp;
	size++;
}

void Erase(int*& arr, const int index, int size) {
	if (index < 0 || index >= size) {
		cout << "Invalid index" << endl;
		return;
	}
	for (int i = index; i < size - 1; i++) {
		arr[i] = arr[i + 1];
	}
	size--;
}

void Insert(int*& arr, const int value, const int index, int size) {
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

void Pop_back(int& size) {
	if (size > 0) {
		size--;
	}
}

void Pop_front(int*& arr, int size) {
	if (size > 0) {
		int* temp = new int[size - 1];
		for (int i = 1; i < size; i++) {
			temp[i] = arr[i];
		}
		delete[] arr;
		arr = temp;
		size--;
	}
}

int** Allocate(const int rows, const int cols) {
	int** arr = new int* [rows];

	for (int i = 0; i < rows; i++) {
		arr[i] = new int[cols];
	}

	return arr;
}

void Clear(int**& arr, const int rows, const int cols) {
	for (int i = 0; i < rows; i++) {
		delete arr[i];
	}
	delete[] arr;
}

void Push_row_back(int**& arr, int rows, const int cols, const int* values) {
	int** temp = new int* [rows + 1];

	for (int i = 0; i < rows; ++i) {
		temp[i] = arr[i];
	}

	temp[rows] = new int[cols];
	for (int j = 0; j < cols; ++j) {
		temp[rows][j] = values[j];
	}

	Clear(arr, rows, cols);
	arr = temp;
	rows++;
}


void Push_row_front(int**& arr, int rows, const int cols, const int* values) {
	int** temp = new int* [rows + 1];

	temp[0] = new int[cols];
	for (int j = 0; j < cols; ++j) {
		temp[0][j] = values[j];
	}

	for (int i = 0; i < rows; ++i) {
		temp[i + 1] = arr[i];
	}

	delete[] arr;
	arr = temp;
	rows++;
}

void Insert_row(int**& arr, int rows, const int cols, const int index, const int* values) {
	if (index > 0 && index < rows) {
		int** temp = new int* [rows + 1];

		for (int i = 0; i < index; i++) {
			temp[i] = arr[i];
		}

		temp[index] = new int[cols];
		for (int j = 0; j < cols; j++) {
			temp[index][j] = values[j];
		}

		for (int i = index; i < rows; i++) {
			temp[i + 1] = arr[i];
		}

		delete[] arr;
		arr = temp;
		rows++;
	}
}

void Push_col_back(int**& arr, const int rows, int cols, const int* values) {
	for (int i = 0; i < rows; i++) {
		int* temp = new int[cols + 1];

		for (int j = 0; j < cols; j++) {
			temp[j] = arr[i][j];
		}

		temp[cols] = values[i];
		delete[] arr;
		arr[i] = temp;
	}
	cols++;
}

void Push_col_front(int**& arr, const int rows, int cols, const int* values) {
	for (int i = 0; i < rows; i++) {
		int* temp = new int[cols + 1];

		for (int j = 1; j < cols; j++) {
			temp[j] = arr[i][j];
		}

		temp[0] = values[i];
		delete[] arr;
		arr[i] = temp;
	}
	cols++;
}

void Insert_col(int**& arr, const int rows, int cols, const int index, const int* values) {
	if (index > 0 && index < cols) {
		for (int i = 0; i < rows; i++) {
			int* temp = new int[cols + 1];

			for (int j = 0; j < index; j++) {
				temp[j] = arr[i][j];
			}

			temp[index] = values[i];
			for (int j = index; j < cols; j++) {
				temp[j + 1] = arr[i][j];
			}

			delete[] arr[i];
			arr[i] = temp;
		}
		cols++;
	}
}

void Pop_row_back(int**& arr, int rows) {
	if (rows > 0) {
		delete[] arr[--rows];

		int** temp = new int* [rows];
		for (int i = 0; i < rows; i++) {
			temp[i] = arr[i];
		}

		delete[] arr;
		arr = temp;
	}
}

void Pop_row_front(int**& arr, int rows) {
	if (rows > 0) {
		delete[] arr[0];

		for (int i = 1; i < rows; i++) {
			arr[i - 1] = arr[i];
		}

		int** temp = new int* [--rows];
		for (int i = 0; i < rows; i++) {
			temp[i] = arr[i];
		}


		delete[] arr;
		arr = temp;
	}
}

void Erase_row(int**& arr, int rows, const int cols, const int index) {
	if (index > 0 && index < cols) {
		delete[] arr[index];

		for (int i = 1; i < rows; i++) {
			arr[i - 1] = arr[i];
		}

		int** temp = new int* [--rows];
		for (int i = 0; i < index; i++) {
			temp[i] = arr[i];
		}

		for (int i = index + 1; i < rows; i++) {
			temp[i] = arr[i];
		}

		delete[] arr;
		arr = temp;
	}
}

void Pop_col_back(int**& arr, const int rows, int cols) {
	if (cols > 0) {
		for (int i = 0; i < rows; i++) {
			int* temp = new int[--cols];
			for (int j = 0; j < cols; j++) {
				temp[j] = arr[i][j];
			}

			delete[] arr[i];
			arr[i] = temp;
		}
	}
}

void Pop_col_front(int**& arr, const int rows, int cols) {
	if (cols > 0) {
		for (int i = 0; i < rows; i++) {

			int* temp = new int[--cols];
			for (int j = 0; j < cols; j++) {
				temp[j] = arr[i][j + 1];
			}

			delete[] arr[i];
			arr[i] = temp;
		}
	}
}

void Erase_col(int**& arr, const int rows, int cols, const int index) {
	if (index > 0 && index < cols) {
		for (int i = 0; i < rows; i++) {
			delete[] arr[index];

			int* temp = new int[--cols];
			for (int j = 0; j < index; j++) {
				temp[j] = arr[i][j];
			}

			for (int j = index + 1; i < rows; i++) {
				temp[j] = arr[i][j];
			}

			delete[] arr[i];
			arr[i] = temp;
		}
	}
}