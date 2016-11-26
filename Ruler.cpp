#include <iostream>
using namespace std;

void subdivide(char ar[], int low, int high, int level);

int main()
{
	int Divs = 6;
	int Len = 2;
	cout << "Enter the length of the scale\n";
	cin >> Len;
	char* ruler;
	ruler = new char[Len];
	cout << "Enter the number of divisions\n";
	cin >> Divs;
	int i;
	for (i = 1; i < Len - 2; i++)
		ruler[i] = ' ';
	ruler[Len - 1] = '\0';
	int max = Len - 2;
	int min = 0;
	ruler[min] = ruler[max] = '|';
	std::cout << ruler << std::endl;
	for (i = 1; i <= Divs; i++)
	{
		subdivide(ruler, min, max, i);
		std::cout << ruler << std::endl;
		for (int j = 1; j < Len - 2; j++)		// from lowest index to highest index
			ruler[j] = ' '; // reset to blank ruler
	}
	system("pause");
}
void subdivide(char ar[], int low, int high, int level)
{
	if (level == 0)
		return;
	int mid = (high + low) / 2;
	ar[mid] = '|';
 	subdivide(ar, low, mid, level - 1);
	subdivide(ar, mid, high, level - 1);
}