#include <iostream>
#include <clocale>
using namespace std;

/*

// S�ra No Alma Kiosku

- Tc Kimlik No Do�rulama
- - Say� hanesi bulma (stoi d���nda)
- Switch Case
- Do-While Pratikleri
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
		cout << "tc kimlik ver: ";
		cin >> tcKimlik;

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
		//digit10Dogrulama = (((digit01 + digit03 + digit05 + digit07 + digit09) * 7) - (digit02 + digit04 + digit06 + digit08)) % 10;

		cout << tcKimlik;

		cout << tcKimlik < 10000000146;

		if (digit1to10Toplam%10 == digit11) {
			cout << "do�ru";
			tcKimlikDogru++;
		}
				
		
	}while (tcKimlikDogru != 1);
	
	/*
	do {
		cout << " L�tfen 11 haneli TC Kimlik Numaran�z� Giriniz: ";
		cin >> tcKimlik;

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
		digitToplam = digit01 + digit02 + digit03 + digit04 + digit05 + digit06 + digit07 + digit08 + digit09 + digit10;

		if (digit1to10toplam % 10 != digit11 || tcKimlik < 10000000146 || (((digit01 + digit03 + digit05 + digit07 + digit09) * 7) - (digit02 + digit04 + digit06 + digit08)) % 10 != digit10) {
			cout << " \n TC Kimlik No hatal� girilmi�tir.\n L�tfen kontrol ederek tekrar giriniz." << endl << endl;
		}
		else {
			tcKimlikDogru++;
		}
	} while (tcKimlikDogru == 0);

	cout << " Devam";
	*/
	/*
	

	//cout << ;

	/*
	T.C.Kimlik Numaralar�m�z�n 1. 3. 5. 7. ve 9. hanelerinin toplam�n�n 7 kat�ndan,
	2. 4. 6. ve 8. hanelerinin toplam� ��kart�ld���nda, elde edilen sonucun 10'a b�l�m�nden kalan, yani Mod10'u bize 10. haneyi verir.

		26*7=182-7=175
		7

	12345678901
	40633024912
	25211412244

	//switch case
	
	
	*/
	
	
	
	
	return 0;
}