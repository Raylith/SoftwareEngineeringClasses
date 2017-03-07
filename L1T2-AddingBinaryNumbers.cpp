#include <iostream>
#include <string>
using namespace std;

string addBinary(string first, string second)
{
	int carry = 0;
	string result = "";

	int length1 = first.length();
	int length2 = second.length();

	if (length1 > length2)
	{
		for (int i = 0; i < length1 - length2; i++)
			second = '0' + second;
	}
	else if(length1 < length2)
	{
		for (int i = 0; i < length2 - length1; i++)
			first = '0' + first;
	}


	for (int i = first.length() - 1; i >= 0; i--)
	{
		int first_bit = first[i] - '0'; //same as first_bit = first.at(i)-48;
		int second_bit = second[i] - '0';

		int bit_sum = (first_bit ^ second_bit ^ carry) + '0';
		result = (char)bit_sum + result;
		carry = (first_bit & second_bit) | (second_bit & carry) | (first_bit & carry) ;
	}

	if (carry)
		result = '1' + result;
	


	return result;

}

bool isValid(string str)
{
	for (int i = 0; i < str.length(); i++)
	{
		
		if ((str.at(i) != '0') && (str.at(i) != '1'))
		{
			cout << "Invalid string, enter another." << endl;
			return false;
		}	
	}
	return true;


}




int main()
{

	string first_binary, second_binary;

	do
		cin >> first_binary;
	while(!isValid(first_binary));
	
	do
		cin >> second_binary;
	while (!isValid(second_binary));


	cout << addBinary(first_binary, second_binary);

	return 0;

}
