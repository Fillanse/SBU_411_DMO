#include <iostream>

using std::cout;
using std::cin;
using std::endl;

#define tab "\t"

void FillRand(int* arr, const int n);
void FillRand(int** arr, const int rows, const int cols);

template<typename T> void Print(T* arr, const int n);
template<typename T> void Print(T** arr, const int rows, const int cols);

template<typename T> void Increase_size(T*& arr, int size);
template<typename T> void Push_back(T*& arr, const T value, int size);
template<typename T> void Push_front(T*& arr, const T value, int size);
template<typename T> void Erase(T*& arr, const int index, int size);
template<typename T> void Insert(T*& arr, const T value, const int index, int size);
template<typename T> void Pop_back(T*& arr, int size);
template<typename T> void Pop_front(T*& arr, int size);

template<typename T> void Push_row_back(T**& arr, int rows, const int cols, const T* values);
template<typename T> void Pop_row_back(T**& arr, int rows);
template<typename T> void Pop_row_front(T**& arr, int rows);
template<typename T> void Erase_row(T**& arr, int rows, const int cols, const int index);
template<typename T> void Pop_col_back(T**& arr, const int rows, int cols);
template<typename T> void Pop_col_front(T**& arr, const int rows, int cols);
template<typename T> void Erase_col(T**& arr, const int rows, int cols, const int index);

//#define DYNAMIC_MEMORY_1
//#define DYNAMIC_MEMORY_2

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
#ifdef DYNAMIC_MEMORY_2
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
#endif // DYNAMOC_MEMORY_2



}

void FillRand(int** arr, const int rows, const int cols)
{
	for (int i = 0; i < rows; i++) {
		for (int j = 0; j < cols; j++)
		{
			arr[i][j] = rand() % 100;
		}
	}

}

void FillRand(int* arr, const int n)
{
	for (int i = 0; i < n; i++)
	{
		arr[i] = rand() % 100;
	}
}

template<typename T>
void Print(T** arr, const int rows, const int cols)
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

template<typename T>
void Print(T* arr, const int n)
{
	for (int i = 0; i < n; i++)
	{
		cout << arr[i] << tab;
	}
	cout << endl;
}

template<typename T>
void Increase_size(T*& arr, int size) {
	T* temp = new T[size + 1];
	for (int i = 0; i < size; i++) {
		temp[i] = arr[i];
	}
	delete[] arr;
	arr = temp;
	size++;
}

template<typename T>
void Push_back(T*& arr, const T value, int size) {
	Increase_size(arr, size);
	arr[size] = value;
}

template<typename T>
void Push_front(T*& arr, const T value, int size) {
	T* temp = new T[size + 1];
	temp[0] = value;
	for (int i = 1; i < size; i++) {
		temp[i] = arr[i];
	}
	delete[] arr;
	arr = temp;
	size++;
}

template<typename T>
void Erase(T*& arr, const int index, int size) {
	if (index < 0 || index >= size) {
		cout << "Invalid index" << endl;
		return;
	}
	for (int i = index; i < size - 1; i++) {
		arr[i] = arr[i + 1];
	}
	size--;
}

template<typename T>
void Insert(T*& arr, const T value, const int index, int size) {
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

template<typename T>
void Pop_back(T*& arr, int size) {
	if (size > 0) {
		T* temp = new T[--size];
		for (int i = 0; i < size - 1; ++i) {
			temp[i] = arr[i];
		}		
		delete[] arr;
		arr = temp;
	}
}


template<typename T>
void Pop_front(T*& arr, int size) {
	if (size > 0) {
		T* temp = new T[size - 1];
		for (int i = 1; i < size; i++) {
			temp[i] = arr[i];
		}
		delete[] arr;
		arr = temp;
		size--;
	}
}

template<typename T>
T** Allocate(const int rows, const int cols) {
	T** arr = new T* [rows];

	for (int i = 0; i < rows; i++) {
		arr[i] = new T[cols];
	}

	return arr;
}

template<typename T>
void Clear(T**& arr, const int rows, const int cols) {
	for (int i = 0; i < rows; i++) {
		delete arr[i];
	}
	delete[] arr;
}

template<typename T>
void Push_row_back(T**& arr, int rows, const int cols, const T* values) {
	T** temp = new T* [rows + 1];

	for (int i = 0; i < rows; ++i) {
		temp[i] = arr[i];
	}

	temp[rows] = new T[cols];
	for (int j = 0; j < cols; ++j) {
		temp[rows][j] = values[j];
	}

	Clear(arr, rows, cols);
	arr = temp;
	rows++;
}

template<typename T>
void Push_row_front(T**& arr, int rows, const int cols, const T* values) {
	int** temp = new int* [rows + 1];

	temp[0] = new T[cols];
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

template<typename T>
void Insert_row(T**& arr, int rows, const int cols, const int index, const T* values) {
	if (index > 0 && index < rows) {
		T** temp = new T* [rows + 1];

		for (int i = 0; i < index; i++) {
			temp[i] = arr[i];
		}

		temp[index] = new T[cols];
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

template<typename T>
void Push_col_back(T**& arr, const int rows, int cols, const T* values) {
	for (int i = 0; i < rows; i++) {
		T* temp = new T[cols + 1];

		for (int j = 0; j < cols; j++) {
			temp[j] = arr[i][j];
		}

		temp[cols] = values[i];
		delete[] arr;
		arr[i] = temp;
	}
	cols++;
}

template<typename T>
void Push_col_front(T**& arr, const int rows, int cols, const T* values) {
	for (int i = 0; i < rows; i++) {
		T* temp = new T[cols + 1];

		for (int j = 1; j < cols; j++) {
			temp[j] = arr[i][j];
		}

		temp[0] = values[i];
		delete[] arr;
		arr[i] = temp;
	}
	cols++;
}

template<typename T>
void Insert_col(T**& arr, const int rows, int cols, const int index, const T* values) {
	if (index > 0 && index < cols) {
		for (int i = 0; i < rows; i++) {
			T* temp = new T[cols + 1];

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

template<typename T>
void Pop_row_back(T**& arr, int rows) {
	if (rows > 0) {
		delete[] arr[--rows];

		T** temp = new T* [rows];
		for (int i = 0; i < rows; i++) {
			temp[i] = arr[i];
		}

		delete[] arr;
		arr = temp;
	}
}

template<typename T>
void Pop_row_front(T**& arr, int rows) {
	if (rows > 0) {
		delete[] arr[0];

		for (int i = 1; i < rows; i++) {
			arr[i - 1] = arr[i];
		}

		T** temp = new T* [--rows];
		for (int i = 0; i < rows; i++) {
			temp[i] = arr[i];
		}


		delete[] arr;
		arr = temp;
	}
}

template<typename T>
void Erase_row(T**& arr, int rows, const int cols, const int index) {
	if (index > 0 && index < cols) {
		delete[] arr[index];

		for (int i = 1; i < rows; i++) {
			arr[i - 1] = arr[i];
		}

		T** temp = new T* [--rows];
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

template<typename T>
void Pop_col_back(T**& arr, const int rows, int cols) {
	if (cols > 0) {
		for (int i = 0; i < rows; i++) {
			T* temp = new T[--cols];
			for (int j = 0; j < cols; j++) {
				temp[j] = arr[i][j];
			}

			delete[] arr[i];
			arr[i] = temp;
		}
	}
}

template<typename T>
void Pop_col_front(T**& arr, const int rows, int cols) {
	if (cols > 0) {
		for (int i = 0; i < rows; i++) {

			T* temp = new T[--cols];
			for (int j = 0; j < cols; j++) {
				temp[j] = arr[i][j + 1];
			}

			delete[] arr[i];
			arr[i] = temp;
		}
	}
}

template<typename T>
void Erase_col(T**& arr, const int rows, int cols, const int index) {
	if (index > 0 && index < cols) {
		for (int i = 0; i < rows; i++) {
			delete[] arr[index];

			T* temp = new T[--cols];
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