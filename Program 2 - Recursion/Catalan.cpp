#include <iostream>
using namespace std;

int Catalan(int number);

int main(int argc, char* argv[])
{
	int var = 0;
	//converts the first command line to an integer
	var = atoi(argv[1]);

	cout << Catalan(var) << endl;
	system("pause");
	return 0;
}

int Catalan(int number)
{
	int result = 0;

	//base case when number number equals to 0
	if (number == 0)
	{
		return 1;
	}
	//base case when number number equals to 1
	if (number == 1)
	{
		return 1;
	}

	for (int i = 0; i < number; i++)
	{
		result += Catalan(i) * Catalan(number - i - 1);
	}
	return result;
}
