#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include<memory>

using namespace std;

int chooseorder();

struct Review {
	int price;
	string title;
	int rating;
};

bool operator<(const shared_ptr<Review> r1, const shared_ptr<Review> r2);
bool worseThan(const shared_ptr<Review> r1, const shared_ptr<Review> r2);
bool cheaper(const shared_ptr<Review> r1, const shared_ptr<Review> r2);
bool FillReview(Review & rr);
void ShowReview(shared_ptr<Review>  rr);

int main()
{
	vector<Review> books;
	Review temp;
	while (FillReview(temp))
		books.push_back(temp);


	vector< shared_ptr<Review> > booksptr(books.size());
	for (int i = 0; i < (int)books.size(); i++)
	{
		booksptr[i] = (shared_ptr<Review>)(new Review(books[i]));
	}

	if (books.size() > 0)
	{
		cout << "\nThank you. You entered the following "
			<< books.size() << " ratings:\n\n"
			<< "Rating\t\tBook\t\tPrices\n";
		for (auto x : booksptr) ShowReview(x);

		string choice;		// choice of order
		int order = 0;
		cout << "Enter your choice of order : \n";
		cout << "A) Alphabetical Order\nB) Ratings\nC) Prices\n(quit) to Exit.\n";
		while (true)
		{
			cin >> choice;
			cin.clear();
			while (cin.get() != '\n')
				continue;

			if (choice == "A" || choice == "a")
			{
				sort(booksptr.begin(), booksptr.end());
				order = chooseorder();
				cout << "Sorted by title:\nRating\t\tBook\t\tPrices\n";
				if (order == 1)
					for_each(booksptr.begin(), booksptr.end(), ShowReview);
				else
					for_each(booksptr.rbegin(), booksptr.rend(), ShowReview);
			}
			else
				if (choice == "B" || choice == "b")
				{
					sort(booksptr.begin(), booksptr.end(), worseThan);
					order = chooseorder();
					cout << "Sorted by rating:\nRating\t\tBook\t\tPrices\n";
					if (order == 1)
						for_each(booksptr.begin(), booksptr.end(), ShowReview);
					else
						for_each(booksptr.rbegin(), booksptr.rend(), ShowReview);
				}
				else
					if (choice == "C" || choice == "c")
					{
						sort(booksptr.begin(), booksptr.end(), cheaper);
						order = chooseorder();
						cout << "Sorted by rating:\nRating\t\tBook\t\tPrices\n";
						if (order == 1)
							for_each(booksptr.begin(), booksptr.end(), ShowReview);
						else
							for_each(booksptr.rbegin(), booksptr.rend(), ShowReview);
					}
					else
						if (choice == "quit" || choice == "QUIT")
							break;
						else
							cout << "Please Enter a valid option\n\a";
			// if everything goes well then display this menu
			cout << "\nEnter your choice of order : \n";
			cout << "A) Alphabetical Order\nB) Ratings\nC) Prices\n(quit) to Exit.\n";
		}
	}
	else
		cout << "No entries. ";
	cout << "Bye.\n";
	cin.get();
	return 0;
}
int chooseorder()
{
	cout << "\nAscending order ? 1\nDescending order ? 2\n";
	int order = 0;			// choice of ascending / descending
	cin >> order;
	cin.clear();
	while (cin.get() != '\n')
		continue;
	while (order != 1 && order != 2)
	{
		cout << "Please Enter a valid option\a\n";
		cin >> order;
		cin.clear();
		while (cin.get() != '\n')
			continue;
	}
	return order;
}
bool operator<(const shared_ptr<Review> r1, const shared_ptr<Review> r2)
{
	if (r1->title < r2->title)
		return true;
	else if (r1->title == r2->title && r1->rating < r2->rating)
		return true;
	else
		if (r1->title == r2->title && r1->rating == r2->rating && r1->price < r2->price)
			return true;
		else
			return false;
}
bool cheaper(const shared_ptr<Review> r1, const shared_ptr<Review> r2)
{
	if (r1->price < r2->price)
		return true;
	else
		return false;
}
bool worseThan(const shared_ptr<Review> r1, const shared_ptr<Review> r2)
{
	if (r1->rating < r2->rating)
		return true;
	else
		return false;
}
bool FillReview(Review & rr)
{
	cout << "Enter book title (quit to quit): ";
	getline(cin, rr.title);
	if (rr.title == "quit")
		return false;
	cout << "Enter book rating: ";
	cin >> rr.rating;
	if (!cin) 
	{
		cin.clear();
		while (cin.get() != '\n')
			continue;
		return false;
	}
	cout << "Enter book price: ";
	cin >> rr.price;
	if (!cin)
	{
		cin.clear();
		while (cin.get() != '\n')
			continue;
		return false;
	}
	// get rid of rest of input line
	while (cin.get() != '\n')
		continue;
	return true;
}

void ShowReview(shared_ptr<Review> rr)
{
	std::cout << rr->rating << "\t\t" << rr->title << "\t\t" << rr->price << std::endl;
}