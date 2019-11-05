#include "../std_lib_facilities.h"

int main(int argc, char **argv)
{
	cout << "int: " << argc << '\n';
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
