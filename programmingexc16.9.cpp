#include<iostream>
#include<list>
#include<vector>
#include<time.h>
#include<algorithm>
int main()
{
	using namespace std;
	time_t srand(time(NULL));
	int len = rand() % 10000001 + 10000000;
	vector<int> vec1;
	for (int i = 0; i < len; i++)			// first vector of random size
		vec1.push_back(rand());

	cout << "Created large vector and lsit objects(size : 10 to 20 million)\n";
	cout << "in this run the  size is : " << vec1.size() << "\nand initialized to same random values\n\n";

	vector<int> vec2(vec1);				// second vector copy of first vector

	list<int> li(len);				// list of same length uninitialized
	copy(vec1.begin(), vec1.end(), li.begin());				// copying vector values to list

	// if you wannna display the containers,mind it, it will take a lot of time 
	/*
	cout << "Vector 1 : " << endl;		//took more than one hour to display one vector
	for (auto x : vec1) cout << x << ", ";
	cout << endl << endl;
	
	cout << "Vector 2 : " << endl;
	for (auto x : vec2) cout << x << ", ";
	cout << endl << endl;

	cout << "List : " << endl;
	for (auto x : li) cout << x << ", ";
	cout << endl << endl;*/
	
	clock_t start = clock();
	sort(vec1.begin(), vec1.end());			// time taken to sort vector
	clock_t end = clock();

	cout << "TIME TAKEN TO SORT THE VECTOR OBJECT BY SORT STL ALGORITHM\n";
	cout << (double)(end - start) / CLOCKS_PER_SEC << endl << endl;

	start = clock();
	li.sort();				// sorting list by it's class method
	end = clock();

	cout << "TIME TAKEN TO SORT THE LIST OBJECT BY SORT METHOD\n";
	cout << (double)(end - start) / CLOCKS_PER_SEC << endl << endl;

	copy(vec2.begin(), vec2.end(), li.begin());			// resetting list to original un-sorted random	
								// by vec2 because vec1 is sorted now
	start = clock();
	copy(li.begin(), li.end(), vec1.begin());		//copying list to vector	
	sort(vec1.begin(), vec1.end());				// sorting that vector
	copy(vec1.begin(), vec1.end(), li.begin());		// copying vector back to list
	end = clock();
	cout << "TIME TAKEN TO DO THESE THREE STEPS : \n1)COPYING LIST TO VECTOR\n2)SORTING VECTOR\n";
	cout << "3)COPYING LIST BACK FROM SORTED VECTOR\n\n";
	cout << (double)(end - start) / CLOCKS_PER_SEC << endl << endl;
	cout << "The end of program reached\nPress enter. . . ";
	cin.get();
	return 0;
}