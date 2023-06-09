#include <iostream>
#include <clocale>
#include <chrono>
#include <thread>
#include <ctime>
#include <iomanip>
using namespace std;

/*

///  Sýra No Alma Kiosk Simülasyonu   ///
- 4 Aþamalý Tc Kimlik No Doðrulama
- Sayý hanesi bulma (stoi dýþýnda)
- Switch Case
- Do-While Pratikleri
- Makinenin Sürekli Çalýþmasý
- TC Kimlik No'ya 4523 girildiðinde makinenin kapatýlmasý simülesi (ve notu)
- Error anýnda makinenin kapatýlmasý simülesi
- Kaðýt yazdýrýlýrken 1 saniye bekletilmesi simülesi
- Kaðýt yazdýrýldýktan sonra 3,5 saniye görüntülenip döngü baþýna dönüþ

*/

void siraNoKagit(int,int,int,int,int,int,int);

int main() {
	setlocale(LC_ALL, "Turkish");
	
	srand(time(NULL));
	long long int tcKimlik = 0;
	int digitToplam = 0;
	int tcKimlikDogru = 0;
	int digit01 = 0, digit02 = 0, digit03 = 0, digit04 = 0, digit05 = 0, digit06 = 0;
	int digit07 = 0, digit08 = 0, digit09 = 0, digit10 = 0, digit11 = 0, digit1to10Toplam = 0;
	int digit10Dogrulama = 0;
	int bolum = 0;
	int cikis = 4523;

	//
	auto now = chrono::system_clock::now();
	time_t nowTime = chrono::system_clock::to_time_t(now);
	tm tm;
	localtime_s(&tm, &nowTime);
	int gun = tm.tm_mday;
	int ay = tm.tm_mon + 1;
	int yil = tm.tm_year + 1900;
	int saat = tm.tm_hour;
	int dakika = tm.tm_min;
	int saniye = tm.tm_sec;
	
	//std::cout << "Tarih: " << gun << "/" << ay << "/" << yil << std::endl;
	//std::cout << "Saat: " << saat << ":" << dakika << ":" << saniye << std::endl;

	cout << "\n\n   ---- NÖROLOJÝ / KARDÝYOLOJÝ / ONKOLOJÝ ----\n";
	cout << "                              Çýkýþ kodu: "<<cikis<<"\n\n" << endl;
	

	for (;;) {

		do {
			cout << " Lütfen TC Kimlik Numaranýzý giriniz: ";
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

			if (tcKimlik == cikis) { exit(0); }

			/*
			1. Digit11 doðrulama hatasý / 2. Ýlk TC Kimlik No'dan küçük olmasý kontrolü
			3. 10. digit doðrulama / 4. Verilebilecek en büyük, önceki 3 yöntemi de doðrulayan TC Kimlik No'dan büyük olmamasý
			þeklinde 4 kontrol altta yapýldýktan sonra programýn devamý saðlanýyor.
			*/
			if (digit1to10Toplam % 10 != digit11 || tcKimlik < 10000000146 || digit10Dogrulama!=digit10 || tcKimlik > 99999999990) {
				cout << endl << " Girdiðiniz TC Kimlik No hatalýdýr, lütfen kontrol ederek tekrar giriniz." << endl;
			}
			else {
				tcKimlikDogru++;
			}
		} while (tcKimlikDogru != 1);
	

		cout << endl << " 1. NÖROLOJÝ" << endl
			<< " 2. KARDÝYOLOJÝ" << endl
			<< " 3. ONKOLOJÝ" << endl << endl
			<< " Ýþlem yaptýrmak istediðiniz bölümü seçiniz: ";
		cin >> bolum;

		switch (bolum) {
		case 1:
			cout << " Ýþleminiz yapýlýyor, lütfen bekleyiniz..." << endl << endl;
			std::this_thread::sleep_for(std::chrono::seconds(1));
			siraNoKagit(1,gun,ay,yil,saat,dakika,saniye);
			break;
		case 2:
			cout << " Ýþleminiz yapýlýyor, lütfen bekleyiniz..." << endl << endl;
			std::this_thread::sleep_for(std::chrono::seconds(1));
			siraNoKagit(2, gun, ay, yil, saat, dakika, saniye);
			break;
		case 3:
			cout << " Ýþleminiz yapýlýyor, lütfen bekleyiniz..."<< endl <<endl;
			std::this_thread::sleep_for(std::chrono::seconds(1));
			siraNoKagit(3, gun, ay, yil, saat, dakika, saniye);
			break;
			
		default:cout << "Lütfen listedeki bölümlerden birini seçiniz!";
		}
			
		std::this_thread::sleep_for(std::chrono::milliseconds(3500));

		cout << "\033[7;1H\033[J";

	}

	return 0;
}

void siraNoKagit(int snk,int _gun,int _ay,int _yil, int _saat,int _dakika,int _saniye) {
	int siraNo = rand() % 299;
	

	if (snk == 1) {
		siraNo += 100;
		cout << endl << endl << "     ,......................," << endl
			<< "     |                      |" << endl
			<< "     |    ÞEHÝR HASTANESÝ   |" << endl
			<< "     |      - NÖROLOJÝ -    |" << endl
			<< "     |                      |" << endl
			<< "     |    Randevulu Hasta   |" << endl
			<< "     |                      |" << endl
			<< "     |                      |" << endl
			<< "     |          " << siraNo << "         |" << endl
			<< "     |                      |" << endl
			<< "     |                      |" << endl
			<< "     | " << setfill('0') << setw(2) << _gun << "/" << setw(2) << _ay << "/" << _yil << "  " << setw(2) << _saat << ":" << setw(2) << _dakika << ":" << setw(2) << _saniye << " | " << endl
			<< "     |                      |" << endl
			<< "     | Acil þifalar dileriz |" << endl
			<< "     '......................'" << endl << endl;
	}
	else if (snk == 2) {
		siraNo += 300;
		cout << endl << endl << "     ,......................," << endl
			<< "     |                      |" << endl
			<< "     |    ÞEHÝR HASTANESÝ   |" << endl
			<< "     |    - KARDÝYOLOJÝ -   |" << endl
			<< "     |                      |" << endl
			<< "     |    Randevulu Hasta   |" << endl
			<< "     |                      |" << endl
			<< "     |                      |" << endl
			<< "     |          " << siraNo << "         |" << endl
			<< "     |                      |" << endl
			<< "     |                      |" << endl
			<< "     | " << setfill('0') << setw(2) << _gun << "/" << setw(2) << _ay << "/" << _yil << "  " << setw(2) << _saat << ":" << setw(2) << _dakika << ":" << setw(2) << _saniye << " | " << endl
			<< "     |                      |" << endl
			<< "     | Acil þifalar dileriz |" << endl
			<< "     '......................'" << endl << endl;
	}
	else if (snk == 3) {
		siraNo += 600;
		cout << endl << endl << "     ,......................," << endl
			<< "     |                      |" << endl
			<< "     |    ÞEHÝR HASTANESÝ   |" << endl
			<< "     |      - ONKOLOJÝ -    |" << endl
			<< "     |                      |" << endl
			<< "     |    Randevulu Hasta   |" << endl
			<< "     |                      |" << endl
			<< "     |                      |" << endl
			<< "     |          " << siraNo << "         |" << endl
			<< "     |                      |" << endl
			<< "     |                      |" << endl
			<< "     | " << setfill('0') << setw(2) << _gun << "/" << setw(2) << _ay << "/" << _yil << "  " << setw(2) << _saat << ":" << setw(2) << _dakika << ":" << setw(2) << _saniye << " | " << endl
			<< "     |                      |" << endl
			<< "     | Acil þifalar dileriz |" << endl
			<< "     '......................'" << endl << endl;
	}
	else {
		cout << " HATA!" << endl
			<< " - Bu makine hatalý bir iþlem yürüttü." << endl
			<< " - Lütfen yetkiliye haber verin!" << endl << endl;
		exit(0);
	}

}