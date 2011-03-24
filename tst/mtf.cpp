#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <time.h>

using namespace std;

int main()
{
	string list, word;
	int counter, index;
	time_t begin, end;
	cout <<"Enter word to perform mtf with ";
	cin >> word;
	int k = 0;
	begin = time(NULL);
	for (; k < 1000; k++)
	{
		for (counter = 0; counter != 256; counter++)
		{
			string list1;
			list1 = char(counter);
			list = list + list1;
		}
		//Comparing character with the string
		for (counter = 0; counter < word.length(); counter++)
		{
			for (index = 0; ; index++)                 //scan the whole array, no need of end condition
			{
				if (word[counter] == list[index]) //till we found it
					break;    //then, break the for
			}
			//Putting found byte in front
			for ( ; index != 0; index--)      //scan from the position of the byte to 0
			{	
				list[index] = list[index-1];  //move all of them to the right
			}
			list[0] = word[counter];                      //update the order 0
		}
		for (counter = 0; counter <= word.length() && k == 0; counter++)
			cout << counter << "\t" << list[counter] << endl;
	}
	end = time(NULL);
	cout <<"Time taken = " <<difftime(end, begin) << endl;
}