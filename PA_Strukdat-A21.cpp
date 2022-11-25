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
/**/ void Show(Node *head, Node *tail, bool asc, bool riwayat, string specific);
/**/ int  lenLL(Node *head);
/**/ long long int gettime();
/**/ void quickSort(struct Node **headRef, bool username);
/**/ struct Node *getTail(struct Node *cur);
/**/ struct Node *partition(struct Node *head, struct Node *end, struct Node **newHead, struct Node **newEnd, bool username);
/**/ struct Node *quickSortRecur(struct Node *head, struct Node *end, bool username);
/**/ int fibonacciSearch(Node *node, string x, int n);
/**/ void Search(Node **head, Node **tail);
/**/
/**/
// --------- Utama ------- //
/**/ void Register(Node *head, Node **headacc, Node **tailacc);
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

	system("CLS");

	cout << "\n Aplikasi Laundry\
		     \n Versi 1.0";

	cout << "\n  --+ 1. Login\
		     \n  --+ 2. Register\
		     \n  --+ 3. Exit\
		     \n  --+ 4. Versi Aplikasi";
		     
	switch (getch()){
		case '1':
			Login(HEADACC, TAILACC);
			break;
		case '2':
			Register(HEADACC, &HEADACC, &TAILACC);
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
			 \n  --+ 2. Lihat Semua Pesanan\
			 \n  --+ 3. Lihat Pesanan Akun Admin\
			 \n  --+ 4. Hapus atau Selesaikan Pesanan\
		     \n  --+ 5. Lihat Riwayat Pesanan\
		     \n  --+ 6. Update Data Akun\
			 \n  --+ 7. Search Data Akun\
			 \n  --+ 8. Keluar";

	switch (getch()){
		case '1':
			Add_Last(&HEAD, &TAIL, HEADACC);
			break;
		case '2':
			Show(HEAD, TAIL, true, false, "");
			break;
		case '3':
			Show(HEAD, TAIL, true, false, active_user);
			break;
		case '4':
			To_Riwayat(&HEAD, &TAIL, &HEADLOG, &TAILLOG);
			break;
		case '5':
			Show(HEADLOG, TAILLOG, true, true, "");
			break;
		case '6':
			break;
		case '7':
			Search(&HEAD, &TAIL);
			break;
		case '8':
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

	switch (getch()){
		case '1':
			Add_Last(&HEAD, &TAIL, HEADACC);
			break;
		case '2':
			Show(HEAD, TAIL, true, false, active_user);
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
			 \n > Sorting						  [HAMPIR SELEAI]\
			 \n > Searching\
			 \n > File Eksternal\
			 \n > Login Session                   [SELESAI]\
			 \n > Perindah Tampilan";
	getch();
}

int lenLL(Node *head){
	int i = 0;
	Node *temp = head;

	while (temp != NULL){
		i++;
		temp = temp->next;
	}
	return i;
}


long long int gettime(){
    time_t t = time(0);
    tm* now = localtime(&t);
    
	long long int Year = (now->tm_year + 1900) * 10000000000; 
    long long int Mon  = (now->tm_mon + 1) * 100000000;
    long long int Day  = now->tm_mday * 1000000;
    
    long long int Hour = now->tm_hour * 10000;
    long long int Min  = now->tm_min * 100;
    long long int Sec  = now->tm_sec;
    
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
	
	// Cek Kecocokan Username dengan Password
	if(temp->akun.username == USN){
		if(temp->akun.password == PASS){
			logged = true;
		}
	}
	
	
	// Jikalau Cocoque
	if (logged){
		active_user = temp->akun.username;
		
		// Jika Admin
		if (USN == "Admind"){
			while(Admin_Menu() == true){};
		}
		
		// Jika User
		else{
			while (User_Menu() == true){};
		}
	}
	
	// Jikalau Tidak Cocoque
	else{
		cout << " Email atau Password\n";
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
    	   \n           (Ketik '0' untuk menggunakan data akun)\
    	   \n                  (Ketik '9' untuk kembali)"
		 << endl;

	cout << " Nama Customer\t: ";
	fflush(stdin);
	getline(cin, nama);
	if(nama == "0"){
		nama = temp->akun.nama;
		cout << "\t ---> " << nama << endl;
	}
	else if(nama == "9" || nama == ""){
		return;
	}

	cout << " No Handphone\t: +62";
	cin >> nomor;
	if(nomor == 0){
		nomor = temp->akun.no_hp;
		cout << "\t ---> +62" << nomor << endl;
	}
	else if(nomor == 9){
		return;
	}

	cout << " Alamat Customer: ";
	fflush(stdin);
	getline(cin, alamat);
	if(alamat == "0"){
		alamat = temp->akun.alamat;
		cout << "\t ---> " << alamat << endl;
	}
	else if(alamat == "9" || alamat == ""){
		return;
	}

	Daftar_Kategori();

	cout << " Masukkan kategori cucian Anda ->";
	kategori = getche();
	intkategori = (int)kategori - 48;
	if(kategori == '\n'){
		return;
	}

	fflush(stdin);
	cout << "\n Berat Cucian (Kg):";
	cin >> berat;
	cout << " ---------------------------------------------------------" << endl;

	harga = berat * hrg[intkategori - 1];
	cout << harga;

	// Tambahkan Data ke Struct (Add Last) 
	Node *newNode = new Node;

	newNode->data.nama = nama;
	newNode->data.nomor_hp = nomor;
	newNode->data.kategori = kategori;
	newNode->data.berat = berat;
	newNode->data.harga = harga;
	newNode->data.username = active_user;
	newNode->prev = *tail;
	newNode->next = NULL;

	// Jikalau LL Kosong
	if (*head == NULL && *tail == NULL){
		*head = newNode;
		*tail = newNode;
	}
	
	// Jikalau LL Tidak Kosong
	else{
		(*tail)->next = newNode;
		*tail = newNode;
	}
	cout << endl;
	cout << "  =======================================================" << endl;
	cout << " |           Pesanan Telah Berhasil Ditambahkan          |" << endl;
	cout << "  =======================================================" << endl;
	system("pause");
}

void Register(Node *head, Node **headacc, Node **tailacc){
	
	string nama, email, alamat, username, password;
	long long int no_hp;
	
	quickSort(&(*headacc), true);
	
	while(true){
		system("CLS");
		cout << "\n =========================================================\
	           \n                        FORM REGISTRASI                   \
	    	   \n =========================================================\n \
	    	   \n                     DATA AKUN CUSTOMER LAUNDRY           \
	    	   \n ---------------------------------------------------------\
	    	   \n\
	    	   \n           (Ketik '0' untuk membatalkan registrasi)"
			 << endl;
	
		cout << " Username\t: ";
		fflush(stdin);
		getline(cin, username);
		
		if (fibonacciSearch(head, username, lenLL(head)) != -1){
	        cout << "    Username sudah ada\n";
	        system("pause");
		}
		else if(username == "0" || username == ""){
			return;
		}
		else{
			break;
		}
	}


	cout << " Nama Customer\t: ";
	fflush(stdin);
	getline(cin, nama);
	if(nama == "0" || nama == ""){
		return;
	}

	cout << " No Handphone\t: +62";
	cin >> no_hp;
	if(no_hp == 0){
		return;
	}

	cout << " Alamat Email\t: ";
	fflush(stdin);
	getline(cin, email);
	if(email == "0" || email == ""){
		return;
	}

	cout << " Alamat Rumah\t: ";
	fflush(stdin);
	getline(cin, alamat);
	if(alamat == "0" || alamat == ""){
		return;
	}

	cout << " Password\t: ";
	fflush(stdin);
	getline(cin, password);
	if(password == "0" || password == ""){
		return;
	}
	
	cout << " ---------------------------------------------------------" << endl;

	// Tambahkan Data ke Struct
	Node *newNode = new Node;

	newNode->akun.nama = nama;
	newNode->akun.no_hp = no_hp;
	newNode->akun.email = email;
	newNode->akun.alamat = alamat;
	newNode->akun.username = username;
	newNode->akun.password = password;

	if (*headacc == NULL && *tailacc == NULL){
		*headacc = newNode;
		*tailacc = newNode;
	}
	else{
		(*headacc)->prev = newNode;
		newNode->next = *headacc;
		newNode->prev = NULL;
		*headacc = newNode;
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


void Show(Node *head, Node *tail, bool asc, bool riwayat, string specific){

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
			
			if(temp->data.username == specific || specific == ""){
				
				cout << "\n  -----------------[" << indeks << "]----------------:" << endl;
				
				if(riwayat == false){
			
					cout << " | Nama Customer\t: "  << temp->data.nama << endl;
					cout << " | No Handphone \t: "   << temp->data.nomor_hp << endl;
					cout << " | Jenis Cucian \t: "   << temp->data.kategori << endl;
					cout << " | Berat Cucian \t: "   << temp->data.berat << endl;
					cout << " | Harga Cucian \t: "   << temp->data.harga << endl;
					
				} else{
					
					cout << " | Nama Customer\t: "  << temp->log.nama << endl;
					cout << " | No Handphone\t\t: "   << temp->log.nomor_hp << endl;
					cout << " | Jenis Cucian\t\t: "   << temp->log.kategori << endl;
					cout << " | Berat Cucian\t\t: "   << temp->log.berat << endl;
					cout << " | Harga Cucian\t\t: "   << temp->log.harga << endl;
					
					long long int a = temp->log.tanggal;
					int year = (a % 1000000000000 - a % 10000000000)/10000000000;
					int month = (a % 10000000000 - a % 100000000)/100000000;
					int day = (a % 100000000 - a % 1000000)/1000000;
					int hour = (a % 1000000 - a % 10000)/10000;
					int min = (a % 10000 - a % 100)/100;
					int sec = a % 100;
		
					// Bagian Pemberian Tanggal
					cout << " | Tanggal Selesai\t: ";
					cout << year << "/" << month       << "/";
					cout << (day - 10 > 0 ? "" : "0")  << day  << "  ";
					cout << (hour - 10 > 0 ? "" : "0") << hour << ":";
					cout << (min - 10 > 0 ? "" : "0")  << min  << ":";
					cout << (sec - 10 > 0 ? "" : "0")  << sec  << endl;
					
				}
			
				cout << "  ------------------------------------:" << endl;
			
			}
			
			if(indeks % 5 == 0){
				cout << " Klik '0' untuk kembali,\
						\n Klik lainnya untuk lanjut ke halaman berikutnya.";
				if(getch() == '0'){return;}
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
		system("CLS");
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
		system("CLS");
		cout << "\n  =======================================================" << endl;
		cout << " |            Data Telah Berhasil Diselesaikan           |" << endl;
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

// ===========================================================
// ||                      QUICK SORT 						||
// ===========================================================
struct Node *getTail(struct Node *cur){
    while (cur != NULL && cur->next != NULL) cur = cur->next;
    return cur;
}
 
struct Node *partition(struct Node *head, struct Node *end, struct Node **newHead, struct Node **newEnd, bool username){
    struct Node *pivot = end;
    struct Node *prev = NULL, *cur = head, *tail = pivot;
    
    while (cur != pivot){
		if(username == true){
			if (cur->data.username < pivot->data.username){
				if ((*newHead) == NULL) (*newHead) = cur;
				prev = cur;
				cur = cur->next;
			}else{
				if (prev) prev->next = cur->next;
				struct Node *tmp = cur->next;
				cur->next = NULL;
				tail->next = cur;
				tail = cur;
				cur = tmp;
			}
		}
		else{
			if (cur->log.tanggal < pivot->log.tanggal){
				if ((*newHead) == NULL) (*newHead) = cur;
				prev = cur;
				cur = cur->next;
			}else{
				if (prev) prev->next = cur->next;
				struct Node *tmp = cur->next;
				cur->next = NULL;
				tail->next = cur;
				tail = cur;
				cur = tmp;
			}	
		}
    }
    if ((*newHead) == NULL) (*newHead) = pivot;
    (*newEnd) = tail;
    return pivot;
}
 
struct Node *quickSortRecur(struct Node *head, struct Node *end, bool username){
    if (!head || head == end) return head;
    Node *newHead = NULL, *newEnd = NULL;

	if(username == true) {
		struct Node* pivot = partition(head, end, &newHead, &newEnd, true);
		if (newHead != pivot) {
			struct Node *tmp = newHead;
			while (tmp->next != pivot) tmp = tmp->next;
			tmp->next = NULL;
			newHead = quickSortRecur(newHead, tmp, true);
			tmp = getTail(newHead);
			tmp->next = pivot;
			pivot->next = quickSortRecur(pivot->next, newEnd, true);
		}
	}
    else {
		struct Node* pivot = partition(head, end, &newHead, &newEnd, false);
		if (newHead != pivot){
			struct Node *tmp = newHead;
			while (tmp->next != pivot) tmp = tmp->next;
			tmp->next = NULL;
			newHead = quickSortRecur(newHead, tmp, false);
			tmp = getTail(newHead);
			tmp->next = pivot;
			pivot->next = quickSortRecur(pivot->next, newEnd, false);
		}
	}
	
    return newHead;
}
 
void quickSort(struct Node **headRef, bool username){
	if(username == true){
    	(*headRef) = quickSortRecur(*headRef, getTail(*headRef), true);
	}
	else{
		(*headRef) = quickSortRecur(*headRef, getTail(*headRef), false);
	}
    return;
}


int fibonacciSearch(Node *node, string x, int n)
{
    int F0 = 0;
    int F1 = 1;
    int F = F0 + F1;
    while (F < n)
    {
        F0 = F1;
        F1 = F;
        F = F0 + F1;
    }

    int offset = -1;
    
    while (F > 1)
    {
        // Inisiasi awal
        Node *head = node;
        
        int i = min(offset + F0, n - 1);
        for (int trv = 0; head->next != NULL && trv < i; trv++)
        {
            head = head->next;
        }
        if (head->akun.username < x)
        {
            F = F1;
            F1 = F0;
            F0 = F - F1;
            offset = i;
        }
        else if (head->akun.username > x)
        {
            F = F0;
            F1 = F1 - F0;
            F0 = F - F1;
        }
        else
        {
            return i;
        }
    }

    Node *head2 = node;
    for (int trv = 0; head2->next != NULL && trv < offset + 1; trv++)
    {
        head2 = head2->next;
	}
    if (F1 && head2->akun.username == x)
        return offset + 1;
    return -1;
}

void Search(Node **head, Node **tail) {
	quickSort(head, true);
	system("cls");
	string nama;
	Node *temp = *head;

	cout << " =========================================================\
           \n                          SEARCH DATA                     \
    	   \n =========================================================\n\
    	   \n                 SEARCH NAMA COSTUMER LAUNDRY             \
    	   \n ---------------------------------------------------------\n"
		 << endl;

	cout << "Masukan nama costumer yang ingin dicari : ";
	getline(cin, nama); fflush(stdin);

	int ind = fibonacciSearch(*head, nama, lenLL(*head));
    
	if (ind >= 0){
		cout << " ==================================" << endl;
		cout << "||        Data ditemukan         ||" << endl;
		cout << " ==================================" << endl;

		cout << "\n  -----------------[" << ind << "]----------------:" << endl;

		while(temp->data.username != nama) {
			if(temp->data.username == nama){
				cout << " | Nama Customer\t: "  << temp->data.nama << endl;
				cout << " | No Handphone \t: "   << temp->data.nomor_hp << endl;
				cout << " | Jenis Cucian \t: "   << temp->data.kategori << endl;
				cout << " | Berat Cucian \t: "   << temp->data.berat << endl;
				cout << " | Harga Cucian \t: "   << temp->data.harga << endl;
				break;
			}
				temp = temp->next;
		}

		getche();
	}
    else {
        cout << nama << " tidak ada dalam Linked List";
		getche();
	}
}
