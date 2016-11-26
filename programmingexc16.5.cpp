#include<iostream>
#include<string>
#include<algorithm>

using namespace std;

template<class t> 
int reduce(t arr[], int length);

const int len = 5;

int main()
{

	string array[len]{ "wert","asga7","dfghdfgh","asgads","asga7" };
	cout << "Original Array : " << endl;
	for (int i = 0; i < len; i++)
		cout << array[i] << " ";
	cout << endl;
	int reduction = reduce(array, len);
	cout << endl << "Sorted and shorted array : " << endl;
	for (int i = 0; i < reduction; i++)
		cout << array[i] << " ";
	cout << endl;
	cout << "And the index returned by the function is : " << reduction << endl;

	cin.get();
	return 0;
}

template<class t>
int reduce(t arr[], int length)
{
	t temp;
	int end = length - 1;
	for (int i = 0; i < length; i++)
	{
		for (int j = i + 1; j <= end; j++)
		{
			if (arr[i] == arr[j])
			{
				temp = arr[j];
				arr[j] = arr[end];
				arr[end] = temp;
				end--;
			}
		}
	}
	if (end < length - 1)
	{
		sort(arr, arr + end + 1);
		return end + 1;
	}
	else
	{
		sort(arr, arr + length);
		return length;
	}
}