#include <iostream>
#include <string>
#include <cstddef>
using namespace std;

bool containsAlphabetical(string pw)
{
	size_t alphabetical = pw.find_first_of("abcdefghijklmnopqrstuvwxyz");
	if (alphabetical != string::npos)
		return true;

	return false;
}

bool containsCapital(string pw)
{
	size_t capital = pw.find_first_of("ABCDEFGHIJKLMNOPQRSTUVWXYZ");
	if (capital != string::npos)
		return true;

	return false;
}

bool containsNumber(string pw)
{
	size_t number = pw.find_first_of("0123456789");
	if (number != string::npos)
		return true;

	return false;
}

bool containsSpecial(string pw)
{
	size_t special = pw.find_first_of("!@#$_");
	if (special != string::npos)
		return true;

	return false;
}


bool isStrong(string pw)
{
	if (sizeof(pw) > 5 && containsAlphabetical(pw) && containsCapital(pw) && containsNumber(pw) && containsSpecial(pw))
		return true;

	return false;

}



int main()
{
	
	string password;
	cin >> password;

	if (isStrong(password))
		cout << "Password is strong" << endl;
	else
		cout << "Password is weak" << endl;


	return 0;

}