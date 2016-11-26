#include <iostream>
using namespace std;

float harmonicmean(int x, int y) {
	return 2.0 * x * y / (x + y);
}
void main() 
{
	int x, y;
	do
	{
		cout << "Enter two numbers\n";
		cin >> x;cin >> y;
		cout << harmonicmean(x, y) << endl;
		Sleep(1000);
		system("CLS");
	} while (x!= 0 || y!= 0);

}