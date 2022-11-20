#include <iostream>
#include <conio.h>
#include <windows.h>
using namespace std;



////   P R O T O T Y P E
// --------- Menu ------- */
/**/ bool First_Menu();
/**/ bool Admin_Menu();
/**/ bool User_Menu();
/**/
// --------- Misc ------- */
/**/ void Version();  //Hapus Nanti
/**/
/**/
// --------- Utama ------- */
/**/ void Register();
/**/ void Login();



int main(){
	system("color 70");
	
	while(First_Menu() == true){}
	
	return 0;
}


// =======	DAFTAR VOID MENU ====== 

bool First_Menu(){
		     
	cout << "\n Aplikasi Laundry\
		     \n Versi 1.0";
		     
	cout << "\n  --+ 1. Login\
		     \n  --+ 2. Register\
		     \n  --+ 3. Exit\
		     \n  --+ 4. Versi Aplikasi";
	switch(getch()){
		case '1':
			Login();
			break;
		case '2':
			Register();
			break;
		case '3':
			exit(0);
			break;
		case '4':
			Version();
			break;
		default:
			break;
	};
	
	system("CLS");
	
	return true;
	
}


bool Admin_Menu(){
	system("CLS");
	
	cout << "\n  Selamat Datang!!!\n\
			 \n  --+ 1. Buat Pesanan\
			 \n  --+ 2. Lihat Pesanan\
			 \n  --+ 3. Hapus atau Selesaikan Pesanan\
		     \n  --+ 4. Lihat Pesananku\
			 \n  --+ 5. Keluar";
		    
	switch(getch()){
		case '1':
			break;
		case '2':
			break;
		case '3':
			break;
		case '4':
			break;
		case '5':
			return false;
			break;
		default:
			break;
	}
	
	return true;
}



bool User_Menu(){
	system("CLS");
	
	cout << "\n  Selamat Datang!!!\n\
			 \n  --+ 1. Pesan\
		     \n  --+ 2. Lihat Pesananku\
			 \n  --+ 3. Keluar";
		    
	switch(getch()){
		case '1':
			break;
		case '2':
			break;
		case '3':
			return false;
			break;
		default:
			break;
	}
	
	return true;
}



// ========= ISI MENU =========

void Version(){
	
	system("CLS");
	
	cout << "\n\n Menu ini akan dihapus nanti,\
			 \n Menu dibuat untuk memberi keterangan guna\
			 \n mengetahui perkembangan program.\n\
			 \n > Alur Menu [SELESAI]\
			 \n > Struct Laundry\
			 \n > Struct Riwayat Laundry\
			 \n > Struct Keanggotaan (Admin/User)\
			 \n > Add Last Laundry\
			 \n > Delete First Laundry\
			 \n > Add Last Riwayat Laundry\
			 \n > Sorting\
			 \n > Searching\
			 \n > File Eksternal\
			 \n > Login Session\
			 \n > Perindah Tampilan";
	getch();
}

void Register(){
	string Menu[5] = { "\n Username\t: ",
					   " Password\t: "  ,
					   " Nama\t\t: "    ,
					   " Alamat\t\t: "  ,
					   " No. HP\t\t: " };
					   
	string Respon[4] = {};
	int nomor;
	
	system("CLS");
	
					   
	for(int i = 0; i < 5; i++){
		cout << Menu[i];
		
		if(i < 4){
			cin >> Respon[i];
		}
		else{
			cin >> nomor;
		}
	}
}


void Login(){
	string USN, PASS;
	
	system("CLS");
	
	cout << "\n Username\t: ";
	cin >> USN;
	
	cout << " Password\t: ";
	cin >> PASS;
	
	if(true){
		cout << " Bener gan";
		// while(Admin_Menu() == true);
		while(User_Menu() == true);
	}
	else{
		cout << " Salah gan";
		getch();
	}
	
}









