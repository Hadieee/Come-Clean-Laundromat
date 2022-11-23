#include <iostream>
using namespace std;



int main(){
	int a = 20221103;
	int year = a/10000;
	int month = a/100 - a/10000 * 100;
	int day = a - a/100 * 100;
	
	
	cout << year << "/" << month << "/";
	if(day - 10 > 0){
		cout << day ;
	}
	else{
		cout << "0" << day;
	}
}
