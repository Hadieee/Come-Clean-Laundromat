#include <iostream>
#include <conio.h>
#include <string>  //string::pop_back & string::empty
#include <windows.h>
using namespace std;

#define Enter 13
#define Backspace 8

string Censorship(string teks, bool *state);
char Controller();
void masuk(string *usn, string *teks, bool *state);



int main(){
	string pass = "";
	string usn = "";
	bool state = true;
	
	while(state == true){
		masuk(&usn, &pass, &state);
	}
	
	cout << "\nend";
	
	return 0;
}


void masuk(string *usn, string *teks, bool *state){
	
	system("CLS");
	
	cout << "\n\n Masukkan Username: ";
	
	if (!((*usn).empty())){
		cout << *usn << endl;
	}
	else{
		cin >> *usn;
	}
	
	
	cout << " Masukkan Password: ";
	for(int i = 0; i < (*teks).length(); i++){
		cout << "#";
	}
	
	*teks = Censorship(*teks, state);
}



string Censorship(string teks, bool *state){
	string kalimat = teks;
	char huruf;

	while(true){
		huruf = getch();
		if(huruf == Enter){
			*state = false;
			return kalimat;
		}
		else if(kalimat.empty() && huruf == Backspace){
    		return kalimat;
		}
		else if(!kalimat.empty() && huruf == Backspace){
    		kalimat.pop_back();
    		return kalimat;
		}
		else{
			cout << "#";
			kalimat += huruf;
		}
	}
}



char Controller(){
	char arah;
	char tujuan;
	
	switch(arah = getch()){
		
		case -32:
			tujuan = getch();
			/*
			INFORMASI TAMBAHAN:
			72 = Atas
			75 = Kiri
			77 = Kanan
			80 = Bawah
			*/
			break;
			
		default:
			tujuan = arah;
			/*
			INFORMASI TAMBAHAN:
			8 = Backspace
			13 = Enter
			27 = Escape
			*/
			break;
	}
	return tujuan;
}
