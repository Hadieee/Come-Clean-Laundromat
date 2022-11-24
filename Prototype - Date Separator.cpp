#include <iostream>
using namespace std;



int main(){
	
	long long int a = 20221103235901;
	int year = (a % 1000000000000 - a % 10000000000)/10000000000;
	int month = (a % 10000000000 - a % 100000000)/100000000;
	int day = (a % 100000000 - a % 1000000)/1000000;
	int hour = (a % 1000000 - a % 10000)/10000;
	int min = (a % 10000 - a % 100)/100;
	int sec = a % 100;
	
	
	cout << year << "/" << month       << "/";
	cout << (day - 10 > 0 ? "" : "0")  << day  << "   ";
	cout << (hour - 10 > 0 ? "" : "0") << hour << ":";
	cout << (min - 10 > 0 ? "" : "0")  << min  << ":";
	cout << (sec - 10 > 0 ? "" : "0")  << sec  << endl;




}
