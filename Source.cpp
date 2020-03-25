#include<iostream>
#include<stdlib.h>
#include<time.h>
using namespace std;

void showArr(int arr[][6], const int  SIZE_ROW, const int SIZE_COL);
void fillArr(int arr[][6], const int  SIZE_ROW, const int SIZE_COL);
void searchMax(int arr[][6], const int  SIZE_ROW, const int SIZE_COL, int *maxNumber, int *maxIndexForRow, int *maxIndexForCol);
void searchMin(int arr[][6], const int  SIZE_ROW, const int SIZE_COL, int *pminNumber, int* pminIndexForRow, int *pminIndexForCol);
int main()
{
	setlocale(LC_ALL, "ru");
	srand(time(0));
	cout << "1.2. написать программу, которая находит максимальный и минимальный элементы\n"
		" двумерном массиве и меняет местами строки с этими элементами. \n"
		"Если максимальный и минимальный находятся в одной строке - выводится соответствующее уведомление. \n\n";
	const int SIZE_ROW = 5;
	const int SIZE_COL = 6;
	int arr[SIZE_ROW][SIZE_COL];
	
	const int SIZE_BUFER_COL = 6;
	int buferArr[SIZE_BUFER_COL];
	int maxIndexForCol = 0, minIndexForRow = 0, maxIndexForRow = 0, minIndexForCol = 0, maxNumber = 0, minNumber = 0;
	
	
	int*pminIndexForCol = &minIndexForCol;
	int*pminIndexForRow = &minIndexForRow;
	int*pminNumber = &minNumber;
	int* pmaxIndexForCol = &maxIndexForCol;
	int* pmaxIndexForRow = &maxIndexForRow;
	int* pmaxNumber = &maxNumber;
	fillArr(arr, SIZE_ROW, SIZE_COL);
	showArr(arr, SIZE_ROW, SIZE_COL);
	
	
	
	searchMax(arr, SIZE_ROW, SIZE_COL, &maxNumber, &maxIndexForRow, &maxIndexForCol);
	cout << " Indecs MAX = " << *pmaxIndexForRow << "|" << *pmaxIndexForCol << endl
		 << " MAX =  " << maxNumber << endl<<endl;
	*pminNumber =arr[0][0];
	searchMin(arr, SIZE_ROW, SIZE_COL, &minNumber,&minIndexForRow,&minIndexForCol);
	cout << " Indecs MIN = " << minIndexForRow << "|" << minIndexForCol << endl
		 << " MIN =  " << minNumber << endl<<endl;

	if (minIndexForRow != maxIndexForRow)
	{
		for (int i = 0; i < SIZE_ROW; i++)
		{
			if (i == minIndexForRow)
			{
				for (int j = 0; j < SIZE_COL; j++)
				{
					buferArr[j] = arr[i][j];
					
				}
				cout << "+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++" << endl<< endl
					<< "\t\t String with MAX element :" << endl;
				cout << " Indecs string with MAX : " << *pmaxIndexForRow  << endl;
			}
		}
		for (int i = 0; i < SIZE_ROW; i++)
		{
			if (i == maxIndexForRow)
			{
				for (int j = 0; j < SIZE_COL; j++)
				{
					arr[minIndexForRow][j] = arr[i][j];
					cout << "\t" << arr[minIndexForRow][j] ;
				}
				cout << "\n\n+++++++++++++++++++++++++++++++++++++++++++++++++++++++++" << endl
					<< "\t\t String with MIN element :" << endl;
				cout << " Indecs string with MIN :" << minIndexForRow << endl;
					
			}
		}
		for (int i = 0; i < SIZE_ROW; i++)
		{
			if (i == minIndexForRow)
			{
				for (int j = 0; j < SIZE_COL; j++)
				{
					arr[maxIndexForRow][j] = buferArr[j];
					cout << "\t" << arr[maxIndexForRow][j] ;
				}
				cout << "\n\n+++++++++++++++++++++++++++++++++++++++++++++++++++++++++" << endl
					<< "Swap strings in arr :"<<endl;
					
			}
		}
	
		showArr(arr, SIZE_ROW, SIZE_COL);
	
	
	}
	else
	{
		cout << "MAX and MIN in a one string!" << endl;
	}
	
	
	system("pause");
	return 0;
}
	
void showArr(int arr[][6], const int  SIZE_ROW, const int SIZE_COL)
{
	for (int i = 0; i < SIZE_ROW; i++)
	{
		for (int j = 0; j < SIZE_COL; j++)
		{
			cout << arr[i][j] << "\t";
		}
		cout << endl<< endl;
	}
}
void fillArr(int arr[][6], const int  SIZE_ROW, const int SIZE_COL)
{
		for (int i = 0; i < SIZE_ROW; i++)
		{
			for (int j = 0; j < SIZE_COL; j++)
			{
				arr[i][j] = rand() % 50;

			}
		}
}
void searchMin(int arr[][6], const int  SIZE_ROW, const int SIZE_COL,  int *pminNumber, int *pminIndexForRow , int *pminIndexForCol)
{
	
	for (int i = 0; i < SIZE_ROW; i++) 
	{
		for (int j = 0; j < SIZE_COL; j++)
		{
			
			if (arr[i][j] < *pminNumber)
			{
				*pminNumber = arr[i][j];
				*pminIndexForRow = i;
				*pminIndexForCol = j;
			}
		}
	}
     
	
}
void searchMax(int arr[][6], const int  SIZE_ROW, const int SIZE_COL, int *pmaxNumber, int *pmaxIndexForRow, int *pmaxIndexForCol)
{
	*pmaxNumber = arr[0][0];
	for (int i = 0; i < SIZE_ROW; i++) 
	{
		for (int j = 0; j < SIZE_COL; j++)
		{
			if (arr[i][j] >*pmaxNumber)
			{
				*pmaxNumber = arr[i][j];
				*pmaxIndexForRow = i;
				*pmaxIndexForCol = j;
			}
		}
	}
	
}