#include "FillRand.h"
#include "TemplatedArrayFunctions.h"
#include "TemplatedArrayFunctions.cpp"

void main()
{
	setlocale(LC_ALL, "");
	const int n = 10;
	int arr[n] = { 0,1,2,3,4,5,6,7,8,9 };

	Print(arr, n);
	Sort(arr, n);
	Print(arr, n);
	cout << "Sum of array elements: " << Sum(arr, n) << endl;
	cout << "Avg of array elements: " << Avg(arr, n) << endl;
	cout << "Min value in the array: " << MinValueIn(arr, n) << endl;
	cout << "Max value in the array: " << MaxValueIn(arr, n) << endl;

	const int SIZE = 8;
	int brr[SIZE];
	FillRand(brr, SIZE);
	Print(brr, SIZE);
	Sort(brr, SIZE);
	Print(brr, SIZE);
	cout << "Sum of array elements: " << Sum(brr, SIZE) << endl;
	cout << "Avg of array elements: " << Avg(brr, SIZE) << endl;
	cout << "Min value in the array: " << MinValueIn(brr, SIZE) << endl;
	cout << "Max value in the array: " << MaxValueIn(brr, SIZE) << endl;

	Print(arr, n);
	cout << delimiter << endl;


	int i_arr_2[ROWS][COLS] =
	{
		{3,5,8},
		{13,21,34},
		{55,89,144},
	};

	FillRand(i_arr_2, ROWS, COLS);
	Print(i_arr_2, ROWS, COLS);
	cout << "Sum of array elements: " << Sum(i_arr_2, ROWS, COLS) << endl;
	cout << "Avg of array elements:  " << Avg(i_arr_2, ROWS, COLS) << endl;
	cout << "Min value in the array:  " << MinValueIn(i_arr_2, ROWS, COLS) << endl;
	cout << "Max value in the array:  " << MaxValueIn(i_arr_2, ROWS, COLS) << endl;
	Sort(i_arr_2, ROWS, COLS);
	Print(i_arr_2, ROWS, COLS);

}