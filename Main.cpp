#include <iostream>
#include <clocale>
using namespace std;

/*

// Sýra No Alma Kiosku
+ Tc Kimlik No Doðrulama
+ Sayý hanesi bulma (stoi dýþýnda)
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

	cout << "\n\n   ---- NÖROLOJÝ / KARDÝYOLOJÝ / ONKOLOJÝ ----\n\n";
	
	do {
		cout << " TC kimlik ver: ";
		cin >> tcKimlik;

		// Girdinin int olmamasý kontrolü (Yoksa döngü sonsuza dönüyor)
		if (cin.fail()) {
			cout << " Lütfen girdinizi sadece rakamlarý kullanarak yapýn." << endl << endl;
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
		1. Digit11 doðrulama hatasý / 2. Ýlk TC Kimlik No'dan küçük olmasý kontrolü
		3. 10. digit doðrulama / 4. Verilebilecek en büyük, önceki 3 yöntemi de doðrulayan TC Kimlik No'dan büyük olmamasý
		þeklinde 4 kontrol altta yapýldýktan sonra programýn devamý saðlanýyor.
		*/
		if (digit1to10Toplam % 10 != digit11 || tcKimlik < 10000000146 || digit10Dogrulama!=digit10 || tcKimlik > 99999999990) {
			cout << " Girdiðiniz TC Kimlik No hatalýdýr, lütfen kontrol ederek tekrar giriniz." << endl;
		}
		else {
			tcKimlikDogru++;
		}
	} while (tcKimlikDogru != 1);
	
	
	
	cout << "switch-case ile devamý geliþtirilecek";

	switch{
	case:1{cout << "1"; break; }
	case:2{cout << "2"; break; }
	default:cout << "break";
	}
	
	
	
	
	
	
	
	return 0;
}