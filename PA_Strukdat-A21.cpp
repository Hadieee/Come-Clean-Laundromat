#include <iostream>
#include <conio.h>
#include <windows.h>
#include <stdlib.h>
#include <stdio.h>
#include <time.h>
using namespace std;

////   D E K L A R A S I   ////
/**/ struct dataLaundry{
/**/ 	string nama;
/**/ 	long long int nomor_hp;
/**/ 	string alamat;
/**/ 	char kategori;
/**/ 	double berat;
/**/ 	int harga;
/**/ 	int total;
/**/ };
////
/**/ struct dataRiwayat{
/**/ 	string nama;
/**/ 	long long int nomor_hp;
/**/	string alamat;
/**/ 	long long int tanggal;
/**/ 	char kategori;
/**/ 	double berat;
/**/ 	int harga;
/**/ 	int total;
/**/ };
////
/**/ struct dataAkun{
/**/ 	string username;
/**/ 	string password;
/**/ 	string nama;
/**/ 	string alamat;
/**/ 	string email;
/**/ 	long long int no_hp;
/**/ };
/**/
/**/ struct Node{
/**/ 	Node *prev;
/**/ 	dataLaundry data;
/**/ 	dataAkun akun;
/**/ 	Node *next;
/**/ };
/**/
/**/
/**/ struct Node *HEAD = NULL;
/**/ struct Node *TAIL = NULL;
/**/
/**/ struct Node *HEADLOG = NULL;
/**/ struct Node *TAILLOG = NULL;
/**/
/**/ struct Node *HEADAcc = NULL;
/**/ struct Node *TAILAcc = NULL;
/**/
/**/ struct Node *posisi;
/**/
/**/ int hrg[8] = {8000, 25000, 22000,
/**/ 			   15000, 10000, 20000,
/**/ 			   10000, 30000};
/**/
/**/ string active_user = "";
/**/
/**/
/**/




////   P R O T O T Y P E   ////
// --------- Menu ------- //
/**/ bool First_Menu();
/**/ bool Admin_Menu();
/**/ bool User_Menu();
/**/
// --------- Misc ------- //
/**/ void Version(); //<----------- Hapus Nanti
/**/ void Show(Node *head, Node *tail, char jalur);
/**/ int  lenLL(Node *head);
/**/ void To_Riwayat(Node **head, Node **tail, Node **headlog, Node **taillog);
/**/ long long int gettime();
/**/
// --------- Utama ------- //
/**/ void Register(Node **head, Node **tail);
/**/ void Login(Node *head, Node *tail);
/**/
// --------- User -------- //
/**/ void Add_Last(Node **head, Node **tail);
/**/ void UpdateData(string username, Node **head, Node **tail);
/**/ 
// --------- Admin ------- //
/**/ void Admin_Acc(Node **head, Node **tail);  //<--------- Hapus Nanti
/**/ void Delete_First(Node **head, Node **tail);
/**/
// --------- Others ------- //
/**/ void Daftar_Kategori();
/**/



int main()
{
	system("color 70");
	Admin_Acc(&HEADAcc, &TAILAcc);

	while (First_Menu() == true){}

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
		     
	switch (getch())
	{
	case '1':
		Login(HEADAcc, TAILAcc);
		break;
	case '2':
		Register(&HEADAcc, &TAILAcc);
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

	cout << "\n  Selamat Datang " << active_user <<"!!!\n\
			 \n  --+ 1. Buat Pesanan\
			 \n  --+ 2. Lihat Pesanan\
			 \n  --+ 3. Hapus atau Selesaikan Pesanan\
		     \n  --+ 4. Lihat Riwayat Pesanan\
		     \n  --+ 5. Update Data Akun\
			 \n  --+ 6. Keluar";

	switch (getch())
	{
	case '1':
		break;
	case '2':
		Show(HEAD, TAIL, '1');
		break;
	case '3':
		Delete_First(&HEAD, &TAIL);
		break;
	case '4':
		Show(HEADLOG, TAILLOG, '0');
		break;
	case '5':
		break;
	case '6':
		active_user = "";
		return false;
		break;
	default:
		break;
	}

	return true;
}

bool User_Menu(){
	
	system("CLS");

	cout << "\n  Selamat Datang " << active_user <<"!!!\n\
			 \n  --+ 1. Pesan\
		     \n  --+ 2. Lihat Pesananku\
		     \n  --+ 3. Update Data Akun\
			 \n  --+ 4. Keluar";

	switch (getch())
	{
	case '1':
		Add_Last(&HEAD, &TAIL);
		break;
	case '2':
		break;
	case '3':
		UpdateData("username", &HEAD, &TAIL);
		break;
	case '4':
		active_user = "";
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
			 \n > Struct Laundry [SELESAI]\
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

int lenLL(Node *head)
{
	int i = 0;
	Node *temp = head;

	while (temp != NULL)
	{
		i++;
		temp = temp->next;
	}
	return i;
}


long long int gettime(){
    time_t t = time(0);   // get time now
    tm* now = localtime(&t);
    
	long long int Year = (now->tm_year + 1900) * 10000000000; 
    long long int Mon =  (now->tm_mon + 1) * 100000000;
    long long int Day =  now->tm_mday * 1000000;
    
    long long int Hour = now->tm_hour * 10000;
    long long int Min =  now->tm_min * 100;
    long long int Sec =  now->tm_sec;
    
    return Year + Mon + Day + Hour + Min + Sec;
}


void Login(Node *head, Node *tail){
	string USN, PASS;
	bool logged = false;

	system("CLS");

	cout << "\n Username\t: ";
	cin >> USN;

	cout << " Password\t: ";
	cin >> PASS;
	
	// traversal
	Node *temp = head;
	
	while(temp->akun.username != USN && temp->next != NULL){
		temp = temp->next;
	}
	
	if(temp->akun.username == USN){
		if(temp->akun.password == PASS){
			logged = true;
		}
	}
	

	if (logged){
		cout << " Bener gan";
		
		active_user = temp->akun.username;
		
		if (USN == "Admind"){
			while(Admin_Menu() == true){};
		}
		else{
			while (User_Menu() == true){};
		}
	}
	else{
		cout << " Salah gan";
		system("pause");
	}
}




// ==================== USER ===================== //

void Add_Last(Node **head, Node **tail){
	system("cls");
	char kategori;
	string nama;
	string alamat;
	int intkategori, harga, nomor;
	double berat;

	cout << " =========================================================\
           \n                        FORM PESANAN                      \
    	   \n =========================================================\n\n \
    	   \n                     DATA CUSTOMER LAUNDRY                \
    	   \n ---------------------------------------------------------"
		 << endl;

	cout << " Nama Customer\t: ";
	fflush(stdin);
	getline(cin, nama);

	cout << " No Handphone\t: +62";
	cin >> nomor;

	cout << " Alamat Customer: ";
	fflush(stdin);
	getline(cin, alamat);

	Daftar_Kategori();

	cout << " Masukkan kategori cucian Anda ->";
	kategori = getche();
	intkategori = (int)kategori - 48;

	fflush(stdin);
	cout << "\n Berat Cucian (Kg):";
	cin >> berat;
	cout << " ---------------------------------------------------------" << endl;

	harga = berat * hrg[intkategori - 1];
	cout << harga;

	// Tambahkan Data ke Struct
	Node *newNode = new Node;

	newNode->data.nama = nama;
	newNode->data.nomor_hp = nomor;
	newNode->data.kategori = kategori;
	newNode->data.berat = berat;
	newNode->data.harga = harga;
	newNode->prev = *tail;
	newNode->next = NULL;

	if (*head == NULL && *tail == NULL)
	{
		*head = newNode;
		*tail = newNode;
	}
	else
	{
		(*tail)->next = newNode;
		*tail = newNode;
	}
	cout << endl;
	cout << "  =======================================================" << endl;
	cout << " |        Data Terakhir Telah Berhasil Ditambahkan       |" << endl;
	cout << "  =======================================================" << endl;
	system("pause");
}

void Register(Node **head, Node **tail){
	
	system("cls");
	string nama, email, alamat, username, password;
	long long int no_hp;
	cout << " =========================================================\
           \n                        FORM REGISTRASI                   \
    	   \n =========================================================\n\n \
    	   \n                     DATA AKUN CUSTOMER LAUNDRY           \
    	   \n ---------------------------------------------------------"
		 << endl;

	cout << " Nama Customer\t: ";
	fflush(stdin);
	getline(cin, nama);

	cout << " No Handphone\t: +62";
	cin >> no_hp;

	cout << " Alamat Email: ";
	fflush(stdin);
	getline(cin, email);

	cout << " Alamat Rumah: ";
	fflush(stdin);
	getline(cin, alamat);

	cout << " Username : ";
	fflush(stdin);
	getline(cin, username);

	cout << " Password: ";
	fflush(stdin);
	getline(cin, password);

	cout << " ---------------------------------------------------------" << endl;

	// Tambahkan Data ke Struct
	Node *newNode = new Node;

	newNode->akun.nama = nama;
	newNode->akun.no_hp = no_hp;
	newNode->akun.email = email;
	newNode->akun.alamat = alamat;
	newNode->akun.username = username;
	newNode->akun.password = password;

	if (*head == NULL && *tail == NULL){
		*head = newNode;
		*tail = newNode;
	}
	else{
		(*head)->prev = newNode;
		newNode->next = *head;
		newNode->prev = NULL;
		*head = newNode;
	}
	cout << endl;
	cout << " =======================================================" << endl;
	cout << "|            Data Akun Telah Berhasil Dibuat           |" << endl;
	cout << " =======================================================" << endl;
	system("pause");
}

// =========================== ADMIN ======================

void Admin_Acc(Node **head, Node **tail){   // Hapus Nanti

	Node *newNode = new Node;
	
	newNode->akun.nama = "Admin";
	newNode->akun.no_hp = 81200010002;
	newNode->akun.email = "Admin@gmail.com";
	newNode->akun.alamat = "Jalan bersamanya 12";
	newNode->akun.username = "Admind";
	newNode->akun.password = "123";
	newNode->next = NULL;
	newNode->prev = NULL;
	
	*head = newNode;
	*tail = newNode;
}


void Show(Node *head, Node *tail, char jalur){

	system("CLS");

	if (head == NULL){
		cout << "  =======================================================" << endl;
		cout << " |                  LinkedList Kosong                   |" << endl;
		cout << "  =======================================================" << endl;
		system("pause");
		return;
	}
	else{
		Node *temp;
		int indeks;

		// Ascending
		if (jalur == '0'){
			indeks = 1;
			temp = head;
		}

		// Descending
		else{
			indeks = lenLL(head);
			temp = tail;
		}

		while (temp != NULL){

			cout << " [" << indeks << "]" << endl;
			cout << " Nama Customer\t: " << temp->data.nama << endl;
			cout << " No Handphone\t: " << temp->data.nomor_hp << endl;
			cout << " Jenis Cucian\t: " << temp->data.kategori << endl;
			cout << " Berat Cucian\t: " << temp->data.berat << endl;
			cout << " Harga Cucian\t: " << temp->data.harga << endl;

			// Traversal
			// Ascending
			if (jalur == '0'){
				temp = temp->next;
				indeks++;
			}

			// Descending
			else{
				temp = temp->prev;
				indeks--;
			}
		}

		system("pause");
	}
}


void To_Riwayat(Node **head, Node **tail, Node **headlog, Node **taillog){
	Node *newNode = new Node;

	newNode->data.nama     = (*head)->data.nama;
	newNode->data.nomor_hp = (*head)->data.nomor_hp;
	newNode->data.kategori = (*head)->data.kategori;
	newNode->data.berat    = (*head)->data.berat;
	newNode->data.harga    = (*head)->data.harga;
	newNode->prev = *taillog;
	newNode->next = NULL;

	if (*headlog == NULL && *taillog == NULL)
	{
		*headlog = newNode;
		*taillog = newNode;
	}
	else
	{
		(*taillog)->next = newNode;
		*taillog = newNode;
	}
}

void Delete_First(Node **head, Node **tail){
	
	if (*head == NULL && *tail == NULL){
		
		cout << "  =======================================================" << endl;
		cout << " |                  LinkedList Kosong                   |" << endl;
		cout << "  =======================================================" << endl;
		system("pause");
	}
	else if ((*head)->next == NULL){
		Node *del = *head;
		*head = NULL;
		*tail = NULL;
		delete del;
		cout << "  =======================================================" << endl;
		cout << " |              Data Telah Berhasil Dihapus              |" << endl;
		cout << "  =======================================================" << endl;
		system("pause");
	}
	else{
		Node *del;
		del = *head;
		*head = (*head)->next;
		(*head)->prev = NULL;
		delete del; // hapus node
		cout << endl;
		cout << "  =======================================================" << endl;
		cout << " |              Data Telah Berhasil Dihapus              |" << endl;
		cout << "  =======================================================" << endl;
		system("pause");
	}
}

// ========================= Others ===================

void Daftar_Kategori(){
	
	cout << "  ------------------------------------------------------- \
    	   \n |                   JENIS LAUNDRY                       |\
    	   \n  ------------------------------------------------------- \
		   \n | [1]  Pakaian Biasa                                    |\
		   \n | [2]  Stelan Jas                                       |\
		   \n | [3]  Stelan Blazer                                    |\
		   \n | [4]  Gaun Panjang                                     |\
		   \n | [5]  Gaun Pendek                                      |\
		   \n | [6]  Pakaian Rajut                                    |\
		   \n | [7]  Selimut                                          |\
		   \n | [8]  Bed Cover                                        |\
		   \n  -------------------------------------------------------"
		 << endl;
}

void UpdateData(string username, Node **head, Node **tail){
	system("cls");
	string email, alamat, password, nama;
	int no_hp;

	cout << " =========================================================\
           \n                          FORM USER                       \
    	   \n =========================================================\n\n \
    	   \n              UPDATE DATA AKUN CUSTOMER LAUNDRY           \
    	   \n ---------------------------------------------------------"
		 << endl;

	cout << " Nama Customer\t: ";
	fflush(stdin);
	getline(cin, nama);

	cout << " No Handphone\t: +62";
	cin >> no_hp;

	cout << " Alamat Email: ";
	fflush(stdin);
	getline(cin, email);

	cout << " Alamat Rumah: ";
	fflush(stdin);
	getline(cin, alamat);

	cout << " Password: ";
	fflush(stdin);
	getline(cin, password);

	cout << " ---------------------------------------------------------" << endl;

	// Tambahkan Node Bantu
	Node *temp = *head;

	while(temp != NULL){
		
		if(temp->data.nama == username)
		{
			temp->akun.nama = nama;
			temp->akun.no_hp = no_hp;
			temp->akun.email = email;
			temp->akun.alamat = alamat;
			temp->akun.password = password;

			cout << endl;
			cout << "  =======================================================" << endl;
			cout << " |         Data Akun Telah Berhasil Diupdate !           |" << endl;
			cout << "  =======================================================" << endl;
			system("pause");
			break;
		}

		temp = temp->next;
	}
}
