#include <iostream>
#include <conio.h>
#include <string>  //string::pop_back & string::empty
#include <windows.h>
using namespace std;

#define Enter 13
#define Backspace 8

char Controller(bool anti);
string Censorship(string teks, bool *state);
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
		huruf = Controller(true);
		if(huruf == -32){
			
		}
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
		else if(huruf != 224 && huruf > 31){
			cout << "#";
			kalimat += huruf;
		}
	}
}



char Controller(bool anti){
	char key;
	char tujuan;
	
	switch(key = getch()){
		
		case -32:
			tujuan = getch();
			if(anti == true){ return -32; }
			else{ return tujuan; }
			break;
			
		default:
			tujuan = key;
			break;
	}
	return tujuan;
}
