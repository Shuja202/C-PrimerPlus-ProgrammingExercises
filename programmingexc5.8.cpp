#include<iostream>
#include<conio.h>
#include<cstring>

using namespace std;

void main()
{
	int counter = 0, check = 0;
	char words[100];
	cout << "Enter the words\nEnter \"done\" to stop\n";
	
	cin.getline(words, 100);
	do
	{
		for (int i = 0; i < 100; i++)
		{
			if (words[i] == ' ')
			{
				counter++;
				if (words[i + 1] == ' ')
				{
					i += 1;
					
				}
				if (words[i + 1] == 'd')
				{
					if (words[i + 2] == 'o')
					{
						if (words[i + 3] == 'n')
						{
							if (words[i + 4] == 'e')
							{
								check = 1;
							}
						}
					}
				}
			}
		}
	} while (check != 1);

	cout << "You entered " << counter << " words\n";
	system("pause");
}