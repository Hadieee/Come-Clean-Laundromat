#include <iostream>
#include <conio.h>
#include <windows.h>
#include <stdlib.h>
#include <stdio.h>
#include <time.h>
using namespace std;


////   D E K L A R A S I   ////
/**/ struct Data_Laundry{
/**/ 	string nama;
/**/ 	long long int nomor_hp;
/**/ 	string alamat;
/**/ 	char kategori;
/**/ 	double berat;
/**/ 	int harga;
/**/ 	int total;
/**/	string username;
/**/ };
////
////
/**/ struct Data_Riwayat{
/**/ 	string nama;
/**/ 	long long int nomor_hp;
/**/	string alamat;
/**/ 	char kategori;
/**/ 	double berat;
/**/ 	int harga;
/**/ 	int total;
/**/	string username;
/**/ 	long long int tanggal;
/**/ };
////
////
/**/ struct Data_Akun{
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
/**/ 	Data_Laundry data;
/**/	Data_Riwayat log;
/**/ 	Data_Akun akun;
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
/**/ struct Node *HEADACC = NULL;
/**/ struct Node *TAILACC = NULL;
/**/
/**/ struct Node *posisi;
/**/
/**/ int hrg[8] = {8000, 25000, 22000,
/**/ 			   15000, 10000, 20000,
/**/ 			   10000, 30000};
/**/
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
/**/ 
// --------- Misc ------- //
/**/ void Version(); //<----------- Hapus Nanti
/**/ void Show(Node *head, Node *tail, bool asc, bool riwayat);
/**/ int  lenLL(Node *head);
/**/ long long int gettime();
/**/
/**/ 
// --------- Utama ------- //
/**/ void Register(Node **head, Node **tail);
/**/ void Login(Node *head, Node *tail);
/**/
/**/ 
// --------- User -------- //
/**/ void Add_Last(Node **head, Node **tail, Node *headlog);
/**/ void Update_Data(string username, Node **head, Node **tail);
/**/ 
/**/ 
// --------- Admin ------- //
/**/ void Admin_Acc(Node **head, Node **tail);  //<--------- Hapus Nanti
/**/ void To_Riwayat(Node **head, Node **tail, Node **headlog, Node **taillog);
/**/ void Delete_First(Node **head, Node **tail);
/**/
/**/ 
// --------- Others ------- //
/**/ void Daftar_Kategori();
/**/
/**/ 



int main()
{
	system("color 70");
	Admin_Acc(&HEADACC, &TAILACC);

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
		Login(HEADACC, TAILACC);
		break;
	case '2':
		Register(&HEADACC, &TAILACC);
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
		Add_Last(&HEAD, &TAIL, HEADACC);
		break;
	case '2':
		Show(HEAD, TAIL, true, false);
		break;
	case '3':
		To_Riwayat(&HEAD, &TAIL, &HEADLOG, &TAILLOG);
		break;
	case '4':
		Show(HEADLOG, TAILLOG, true, true);
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
		Add_Last(&HEAD, &TAIL, HEADACC);
		break;
	case '2':
		break;
	case '3':
		Update_Data(active_user, &HEADACC, &TAILACC);
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
			 \n > Alur Menu                       [SELESAI]\
			 \n > Struct Laundry                  [SELESAI]\
			 \n > Struct Riwayat Laundry          [SELESAI]\
			 \n > Struct Keanggotaan (Admin/User) [SELESAI]\
			 \n > Add Last Laundry                [SELESAI]\
			 \n > Delete First Laundry            [SELESAI]\
			 \n > Add Last Riwayat Laundry        [SELESAI]\
			 \n > Lihat Pesanan ASC/DESC          [SELESAI]\
			 \n ---> Menu pilihan ASC / DESC belum\
			 \n ---> Menu lihat pesanan pengguna belum\
			 \n > Sorting\
			 \n > Searching\
			 \n > File Eksternal\
			 \n > Login Session                   [SELESAI]\
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
    time_t t = time(0);
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
	fflush(stdin);
	getline(cin, USN);

	cout << " Password\t: ";
	
	fflush(stdin);
	getline(cin, PASS);
	
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
		active_user = temp->akun.username;
		
		if (USN == "Admind"){
			while(Admin_Menu() == true){};
		}
		else{
			while (User_Menu() == true){};
		}
	}
	else{
		cout << " Salah gan\n";
		system("pause");
	}
}




// ==================== USER ===================== //

void Add_Last(Node **head, Node **tail, Node *headacc){
	system("cls");
	char kategori;
	string nama;
	string alamat;
	int intkategori, harga;
	long long int nomor;
	double berat;
	
	// Transvers
	Node *temp = headacc;
	
	while(temp != NULL){
		
		if(temp->akun.username == active_user){
			break;
		}

		temp = temp->next;
	}


	cout << " =========================================================\
           \n                        FORM PESANAN                      \
    	   \n =========================================================\n\n \
    	   \n                     DATA CUSTOMER LAUNDRY                \
    	   \n ---------------------------------------------------------\
    	   \n\
    	   \n           (Ketik '0' untuk menggunakan data akun)"
		 << endl;

	cout << " Nama Customer\t: ";
	fflush(stdin);
	getline(cin, nama);
	if(nama == "0"){
		nama = temp->akun.nama;
		cout << "\t ---> " << nama << endl;
	}

	cout << " No Handphone\t: +62";
	cin >> nomor;
	if(nomor == 0){
		nomor = temp->akun.no_hp;
		cout << "\t ---> +62" << nomor << endl;
	}

	cout << " Alamat Customer: ";
	fflush(stdin);
	getline(cin, alamat);
	if(alamat == "0"){
		alamat = temp->akun.alamat;
		cout << "\t ---> " << alamat << endl;
	}

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
	newNode->data.username = active_user;
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
	cout << " |           Pesanan Telah Berhasil Ditambahkan          |" << endl;
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

	cout << " Alamat Email\t: ";
	fflush(stdin);
	getline(cin, email);

	cout << " Alamat Rumah\t: ";
	fflush(stdin);
	getline(cin, alamat);

	cout << " Username\t: ";
	fflush(stdin);
	getline(cin, username);

	cout << " Password\t: ";
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


void Show(Node *head, Node *tail, bool asc, bool riwayat){

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
		if (asc == true){
			indeks = 1;
			temp = head;
		}

		// Descending
		else{
			indeks = lenLL(head);
			temp = tail;
		}

		while (temp != NULL){
			
			if(riwayat == false){
			
				cout << " [" << indeks << "]" << endl;
				cout << " Nama Customer\t: "  << temp->data.nama << endl;
				cout << " No Handphone\t: "   << temp->data.nomor_hp << endl;
				cout << " Jenis Cucian\t: "   << temp->data.kategori << endl;
				cout << " Berat Cucian\t: "   << temp->data.berat << endl;
				cout << " Harga Cucian\t: "   << temp->data.harga << endl;
				
			} else{
				
				cout << " [" << indeks << "]" << endl;
				cout << " Nama Customer\t: "  << temp->log.nama << endl;
				cout << " No Handphone\t: "   << temp->log.nomor_hp << endl;
				cout << " Jenis Cucian\t: "   << temp->log.kategori << endl;
				cout << " Berat Cucian\t: "   << temp->log.berat << endl;
				cout << " Harga Cucian\t: "   << temp->log.harga << endl;
				cout << " Tanggal Selesai\t: "   << temp->log.tanggal << endl;
				
			}

			// Traversal
			// Ascending
			if (asc == true){
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
	if (*head == NULL){
		return;
	}
	Node *newNode = new Node;

	newNode->log.nama     = (*head)->data.nama;
	newNode->log.nomor_hp = (*head)->data.nomor_hp;
	newNode->log.kategori = (*head)->data.kategori;
	newNode->log.berat    = (*head)->data.berat;
	newNode->log.harga    = (*head)->data.harga;
	newNode->log.username = (*head)->data.username;
	newNode->log.tanggal  = gettime();
	newNode->prev = NULL;
	newNode->next = NULL;
	
	system("pause");

	if (*headlog == NULL && *taillog == NULL){
		*taillog = newNode;
		*headlog = newNode;
	}
	else{
		newNode->prev = *taillog;
		(*taillog)->next = newNode;
		*taillog = newNode;
	}
	
	Delete_First(&(*head), &(*tail));
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
		cout << "\n  =======================================================" << endl;
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

void Update_Data(string username, Node **head, Node **tail){
	system("cls");
	string email, alamat, password, nama;
	long long int no_hp;

	cout << " =========================================================\
           \n                          FORM USER                       \
    	   \n =========================================================\n\n \
    	   \n              UPDATE DATA AKUN CUSTOMER LAUNDRY           \
    	   \n ---------------------------------------------------------\
    	   \n\
    	   \n           (Ketik '0' untuk menggunakan data lama)"
		 << endl;

	// Tambahkan Node Bantu
	Node *temp = *head;

	// Transvers
	while(temp != NULL){
		
		if(temp->akun.username == username){
			break;
		}

		temp = temp->next;
	}


	cout << " Nama Customer Lama\t: " << temp->akun.nama << endl;
	cout << " Nama Customer Baru\t: ";
	fflush(stdin);
	getline(cin, nama);
	if(nama == "0"){
		nama = temp->akun.nama;
	}


	cout << " No Handphone Lama\t: +62" << temp->akun.no_hp << endl;
	cout << " No Handphone Baru\t: +62";
	cin >> no_hp;
	if(no_hp == 0){
		no_hp = temp->akun.no_hp;
	}


	cout << " Alamat Email Lama\t: " << temp->akun.email << endl;
	cout << " Alamat Email Baru\t: ";
	fflush(stdin);
	getline(cin, email);
	if(email == "0"){
		email = temp->akun.email;
	}


	cout << " Alamat Rumah Lama\t: " << temp->akun.alamat << endl;
	cout << " Alamat Rumah Baru\t: ";
	fflush(stdin);
	getline(cin, alamat);
	if(alamat == "0"){
		alamat = temp->akun.alamat;
	}


	cout << " Password Lama\t\t: ------\n";
	cout << " Password Baru\t\t: ";
	fflush(stdin);
	getline(cin, password);
	if(password == "0"){
		password = temp->akun.password;
	}

	cout << " ---------------------------------------------------------" << endl;
	
	temp->akun.nama = nama;
	temp->akun.no_hp = no_hp;
	temp->akun.email = email;
	temp->akun.alamat = alamat;
	temp->akun.password = password;

	cout << endl;
	cout << "  =======================================================" << endl;
	cout << " |          Data Akun Telah Berhasil Diupdate!           |" << endl;
	cout << "  =======================================================" << endl;
	system("pause");
}
