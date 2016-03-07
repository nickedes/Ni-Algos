/*
Problem : https://www.hackerrank.com/challenges/time-conversion
*/

#include <iostream>
using namespace std;

int main()
{
	int h,m,s;
	char format[2],c;

	cin >> h >> c >> m >> c >> s >> format[0] >> format[1];
	if(format[0] == 'P'){
		if(h==12)
			h = 0;
		cout << h+12 << ":";
		if(m < 10)
			cout << "0" << m << ":";
		else
			cout << m << ":" ;
		if(s < 10)
			cout << "0" << s;
		else
			cout << s;
	}
	else
	{
		if(h==12)
			h = 0;
		if(h < 10)
			cout << "0" << h << ":";
		else
			cout << h << ":";
		if(m < 10)
			cout << "0" << m << ":";
		else
			cout << m << ":" ;
		if(s < 10)
			cout << "0" << s;
		else
			cout << s;	
	}
	return 0;
}