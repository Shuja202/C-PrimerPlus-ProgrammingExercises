#include<iostream>
#include<conio.h>
#include<string>
#include<string.h>
#include<cstring>

using namespace std;
void main()
{

	int counter = 0;
	int check = 0;
	string words;
	cout << "Enter the words\nEnter \"done\" to stop\n";

	getline(cin, words);
	
	for (unsigned int i = 0; i < (words.length()-3); i++)
	{
		if (words.at(i) == ' ')
		{
			counter++;
			if (words.at(i + 1) == ' ')
			{
				i += 1;

			}if (words.at(i + 1) == 'd')
			{
				if (words.at(i + 2) == 'o')
				{
					if (words.at(i + 3) == 'n')
					{
						if (words.at(i + 4) == 'e')
						{
							check = 1;
						}
					}
				}
			}
		}
		if (check == 1)
		{
			break;
		}
	}

	cout << "You entered " << counter << " words\n";



	system("pause");
}