/*
2 Write a program in C++ that converts from miles to kilometers. Your program should have a reasonable prompt for the
user to enter a number of miles. Hint: There are 1.609 kilometers to the mile.
*/
#include "../../../std_lib_facilities.h"

int main()
{
	double km_to_mile = 1.609;
	while (true)
	{
		cout << "Enter miles:\n";
		double mile{0.0};
		if (cin >> mile)
			cout << mile << " == " << mile * km_to_mile << endl;
		else
			break;
	}
	return 0;
}
