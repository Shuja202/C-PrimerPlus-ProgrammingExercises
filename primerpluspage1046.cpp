#include<iostream>
#include<string>
#include<array>
#include<vector>
#include<valarray>
#include<algorithm>
#include<cmath>
#include<numeric>
#include<functional>


int main()
{
	using namespace std;
	vector<double> ved1(10), ved2(10), ved3(10);
	array<double, 10> vod1, vod2, vod3;
	valarray<double> vad1(10), vad2(10), vad3(10);

	ved1 = { 1,2,3,4,5,6,7,8,9,10 };
	ved2 = { 1,2,3,4,5,6,7,8,9,10 };
	vod1 = { 1,2,3,4,5,6,7,8,9,10 };
	vod2 = { 1,2,3,4,5,6,7,8,9,10 };
	vad1 = { 1,2,3,4,5,6,7,8,9,10 };
	vad2 = { 5,2,7,4,1,10,3,8,9,6 };
	ved3 = { 0,0,0,0,0,0,0,0,0,0 };
	vod3 = { 0,0,0,0,0,0,0,0,0,0 };
	vad3 = { 0,0,0,0,0,0,0,0,0,0 };
	cout << "ved1 : \n";
	for (int i = 0; i < 10; i++)
		cout << ved1[i] << " ";
	cout << endl;
	cout << "ved2 : \n";
	for (int i = 0; i < 10; i++)
		cout << ved2[i] << " ";
	cout << endl;
	cout << "ved3 : \n";
	for (int i = 0; i < 10; i++)
		cout << ved3[i] << " ";
	cout << endl;
	cout << "vod1 : \n";
	for (int i = 0; i < 10; i++)
		cout << vod1[i] << " ";
	cout << endl;
	cout << "vod2 : \n";
	for (int i = 0; i < 10; i++)
		cout << vod2[i] << " ";
	cout << endl;
	cout << "vod3 : \n";
	for (int i = 0; i < 10; i++)
		cout << vod3[i] << " ";
	cout << endl;
	cout << "vad1 : \n";
	for (int i = 0; i < 10; i++)
		cout << vad1[i] << " ";
	cout << endl;
	cout << "vad2 : \n";
	for (int i = 0; i < 10; i++)
		cout << vad2[i] << " ";
	cout << endl;
	cout << "vad3 : \n";
	for (int i = 0; i < 10; i++)
		cout << vad3[i] << " ";
	cout << endl;
	sort(begin(vad2), end(vad2));
	cout << "vad2 after sorting : \n";
	for (int i = 0; i < 10; i++)
		cout << vad2[i] << " ";
	cout << endl;
	vad3 = 10.0* ((vad1 + vad2) / 2.0 + vad1 * cos(vad2));

	cout << "\nvad3 after entire operation : \n";
	for (int i = 0; i < 10; i++)
		cout << vad3[i] << " ";
	cout << endl;
	
	transform(ved1.begin(), ved1.end(), ved2.begin(), ved3.begin(), plus<double>());
	cout << endl << "ved3 after an operation\n";
	for (int i = 0; i < 10; i++)
		cout << ved3[i] << " ";
	cout << endl;
	transform(ved3.begin(), ved3.end(), ved3.begin(),bind2nd(divides<double>(), 2));
	cout << endl << "ved3 after an operation\n";
	for (int i = 0; i < 10; i++)
		cout << ved3[i] << " ";
	cout << endl;
	transform(ved2.begin(), ved2.end(), ved2.begin(), cosf);
	transform(ved2.begin(), ved2.end(), ved1.begin(), ved2.begin() , multiplies<double>());
	transform(ved3.begin(), ved3.end(), ved2.begin(), ved3.begin(), plus<double>());
	cout << endl << "ved3 after an operation\n";
	for (int i = 0; i < 10; i++)
		cout << ved3[i] << " ";
	cout << endl;
	transform(ved3.begin(), ved3.end(), ved3.begin(), bind2nd(multiplies<double>(), 10.0));

	cout << endl << "\n\nved3 after all operations\n";
	for (int i = 0; i < 10; i++)
		cout << ved3[i] << " ";
	cout << endl;

	cout << "vad1 after using slice : \n";
	vad1[slice(1, 4, 2)] = 50;
	for (int i = 0; i < 10; i++)
		cout << vad1[i] << " ";
	cout << endl;

	return 0;
}