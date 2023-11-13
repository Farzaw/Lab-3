#include <iostream>

using namespace std;

void sort(int plate_array[], int n);

int main()
{
	int n;
	int Plant_Array[32];
	int First, Second;

	cin >> n;
	
	for (int i = 0; i < n; i++)
		cin >> Plant_Array[i];

	sort(Plant_Array, n);
	
	First = Plant_Array[n - 1];
	Second = Plant_Array[n - 2];
	int y = n - 3;

	while (Second < First and not(y<0)) //O(n-2)
	{
		
		Second += Plant_Array[y];
		y--;
	}

	if (y >= 0) 
	{
		bool b = true;
		for (int i = y; i >= 0; i--) //O(n-2)
		{
			if (First < Second)
				b = true;
			else
				b = false;
			if (b)
			{
				b = false;
				First += Plant_Array[i];
			}
			else
			{
				b = true;
				Second += Plant_Array[i];
			}

		}
	}


	cout << abs(First - Second);

	return 0;
}

//Приблизительная ассимптотика алгоритма равна O(n^2) + 2*O(n-2)

//----------------------------------------------------------------------------------------------------------------------------------------

void sort(int plate_array[], int n) // В худшем случае n^2, в лучшем n
{
	for (int i = 0; i < n; i++)
	{
		int a = 0;
		for (int j = i; j < n; j++)
		{
			if (plate_array[i] > plate_array[j])
			{
				a = plate_array[j];
				plate_array[j] = plate_array[i];
				plate_array[i] = a;
			}
				
		}
	}
}