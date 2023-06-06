#include <iostream>
#include <clocale>
using namespace std;

/*

// S�ra No Alma Kiosku
+ Tc Kimlik No Do�rulama
+ Say� hanesi bulma (stoi d���nda)
- Switch Case
+ Do-While Pratikleri
*/


int main() {
	setlocale(LC_ALL, "Turkish");

	long long int tcKimlik = 0;
	int digitToplam = 0;
	int tcKimlikDogru = 0;
	int digit01 = 0, digit02 = 0, digit03 = 0, digit04 = 0, digit05 = 0, digit06 = 0;
	int digit07 = 0, digit08 = 0, digit09 = 0, digit10 = 0, digit11 = 0, digit1to10Toplam = 0;
	int digit10Dogrulama = 0;

	cout << "\n\n   ---- N�ROLOJ� / KARD�YOLOJ� / ONKOLOJ� ----\n\n";
	
	do {
		cout << " TC kimlik ver: ";
		cin >> tcKimlik;

		// Girdinin hatal� olmas� durumu
		if (cin.fail()) {
			cout << " L�tfen girdinizi sadece rakamlar� kullanarak yap�n." << endl << endl;
			cin.clear();
			cin.ignore();
			tcKimlik = 0;
			continue;
		}
		
		// Digitleri yerine ekleme
		digit01 = (tcKimlik / 10000000000) % 10;
		digit02 = (tcKimlik / 1000000000) % 10;
		digit03 = (tcKimlik / 100000000) % 10;
		digit04 = (tcKimlik / 10000000) % 10;
		digit05 = (tcKimlik / 1000000) % 10;
		digit06 = (tcKimlik / 100000) % 10;
		digit07 = (tcKimlik / 10000) % 10;
		digit08 = (tcKimlik / 1000) % 10;
		digit09 = (tcKimlik / 100) % 10;
		digit10 = (tcKimlik / 10) % 10;
		digit11 = tcKimlik % 10;
		digit1to10Toplam = digit01 + digit02 + digit03 + digit04 + digit05 + digit06 + digit07 + digit08 + digit09 + digit10;
		digit10Dogrulama = (((digit01 + digit03 + digit05 + digit07 + digit09) * 7) - (digit02 + digit04 + digit06 + digit08)) % 10;

		/*
		1. Digit11 do�rulama hatas� / 2. �lk TC Kimlik No'dan k���k olmas� kontrol�
		3. 10. digit do�rulama / 4. Verilebilecek en b�y�k, �nceki 3 y�ntemi de do�rulayan TC Kimlik No'dan b�y�k olmamas�
		�eklinde 4 kontrol altta yap�ld�ktan sonra program�n devam� sa�lan�yor.
		*/
		if (digit1to10Toplam % 10 != digit11 || tcKimlik < 10000000146 || digit10Dogrulama!=digit10 || tcKimlik > 99999999990) {
			cout << " Girdi�iniz TC Kimlik No hatal�d�r, l�tfen kontrol ederek tekrar giriniz." << endl;
		}
		else {
			tcKimlikDogru++;
		}
	} while (tcKimlikDogru != 1);
	
	
	
	cout << "devam";

	//switch case
	
	
	
	
	
	
	
	return 0;
}