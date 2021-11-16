#include <iostream>
#include <iomanip>
#include <time.h>

using namespace std;

void Create(int** t, const int n, const int Low, const int High);
void Print(int** t, const int n);
void Transpose(int** t, const int n);

int main()
{
	srand((unsigned)time(NULL));

	int Low = -15;
	int High = 15;

	int n;
	cout << "n = "; cin >> n;

	int** t = new int* [n];
	for (int i = 0; i < n; i++)
		t[i] = new int[n];

	Create(t, n, Low, High);
	Print(t, n);

	Transpose(t, n);
	Print(t, n);

	for (int i = 0; i < n; i++)
		delete[] t[i];
	delete[] t;

	return 0;
}

void Create(int** t, const int n, const int Low, const int High)
{
	for (int i = 0; i < n; i++)
		for (int j = 0; j < n; j++)
			t[i][j] = Low + rand() % (High - Low + 1);
}

void Print(int** t, const int n)
{
	cout << endl;
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < n; j++)
			cout << setw(4) << t[i][j];
		cout << endl;
	}
	cout << endl;
}


void Transpose(int** t, const int n)
{
	int tmp;
	for (int i = 0; i < n; ++i)
	{
		for (int j = 0; j < i; ++j)
		{
			tmp = t[i][j];
			t[i][j] = t[j][i];
			t[j][i] = tmp;  
		}
	}
}
