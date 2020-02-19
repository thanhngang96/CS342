#include "TimeSpan.h"
int main()
{
	cout << endl << "Constructors and operator<< tests:" << endl;
	TimeSpan ddb(1.7, 2.1, 3.5), dms (1, 2), ds(4);
	cout << ddb << endl << dms << endl << ds << endl;
	cout << endl << "Convertion tests:" << endl;
	TimeSpan d1(-100, -100, 100); cout << d1<< endl;
	TimeSpan d2(-100, -100, -100); cout << d2 << endl;
	TimeSpan d3(100, 100, -100); cout << d3 << endl;
	TimeSpan d4(100, -100, 100); cout << d4 << endl;
	TimeSpan d5(-3.4, 75.8, 129.6); cout << d5 << endl;
	TimeSpan d6(5.4, 0, -229.2); cout << d6 << endl;
	cout << endl << "getter test:" << endl;
	TimeSpan d7(2, 4, 6);
	cout <<"Before: " << d7 << endl;
	d7.setTime(1, 2, 3);
	cout <<"After:  " << d7 << endl;
	cout << endl << "operator>> test:" << endl;
	TimeSpan duration;
	cin >> duration;
	cout << duration << endl;
	cout << endl << "operator= test:" << endl;
	TimeSpan da(10), db(-20), dc;
	da = 15;
	cout << da << endl;
	da = db;
	cout << da << endl;
	cout << endl << "operator+= test:" << endl;
	da = 10; db = -20;
	da += db;
	cout << da << endl;
	cout << endl << "operator-= test:" << endl;
	da = 10; db = -20;
	da -= db;
	cout << da << endl;
	cout << endl << "operator+ test:" << endl;
	da = 10; db = -20;
	dc = da + db;
	cout << dc << endl;
	cout << endl << "operator- test:" << endl;
	da = 10; db = -20; dc = 0;
	dc = da - db;
	cout << dc << endl;
	cout << endl << "unary negation test:" << endl;
	da = 10; db = -20;
	da = -db;
	cout << da << endl;
	cout << endl << "operator!= test:" << endl;
	da = 10; db = -20;
	if (da != db)
	{
		cout << "Durations are different." << endl;
	}
	else
	{
		cout << "Durations are the same" << endl;
	}

	cout << endl << "operator== test:" << endl;
	if (da == db)
	{
		cout << "Durations are the same." << endl;
	}
	else
	{
		cout << "Durations are different." << endl;
	}

	system("pause");
	return 0;
}