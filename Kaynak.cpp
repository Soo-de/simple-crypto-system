//***********************************************************************************************************************
//**                                                                                                                   **
//**                                     SAKARYA ÜNÝVERSÝTESÝ                                                          **
//**                          BÝLGÝSAYAR VE BÝLÝÞÝM BÝLÝMLERÝ FAKÜLTESÝ                                                **
//**                                BÝLGÝSAYAR MÜHENDÝSLÝÐÝ BÖLÜMÜ                                                     **
//**                                                                                                                   **
//**                                  ÖDEV NUMARASI...: 2                                                              **
//**                                  ÖÐRENCÝ ADI.....: SUDE ANDURMAN                                                  **
//**                                  ÖÐRENCÝ NUMARASI: b231210005                                                     **
//**                                  DERS GRUBU......: A                                                              **
//**                                                                                                                   ** 
//**                                                                                                                   **  
//**           Amaç: Bir kripto para platformu için hesap açma ve yönetim iþlemlerinin yerine                          **
//**                        getirildiði nesne tabanlý uygulama yazýlmasýdýr.                                           **
//**                                                                                                                   **  
//**                                                                                                                   **
//***********************************************************************************************************************


#include <iostream>
#include <locale.h>//TÜRKÇE KLAVYE ÝÇÝN
#include <iomanip>//SETW ÝÇÝN
#include <vector>//HESAP OLUÞTURULDUÐUNDA DÝZÝYE ATANABÝLMESÝ ÝÇÝN
#include <ctime>//RAND'IN DAHA ÝYÝ ÇALIÞABÝLMESÝ ÝÇÝN
using namespace std;

class tarih //TABAN SINIF DEÐERLER TARÝHE BAÐLI DEÐÝÞÝYOR
{
protected:
	int gun;//YENÝ GÜN ALMAK ÝÇÝN
	int ay;//YENÝ AY ALMAK ÝÇÝN
	int yil;//YENÝ YIL ALMAK ÝÇÝN
	int gunfarki;//DEÐER HESAPLAMA ÝÞLEMLERÝ ÝÇÝN KAÇ GÜN GEÇTÝÐÝNÝ TUTMAK ÝÇÝN
	int ayfarki;//DEÐER HESAPLAMA ÝÞLEMLERÝ ÝÇÝN KAÇ AY GEÇTÝÐÝNÝ TUTMAK ÝÇÝN
	int yilfarki;//DEÐER HESAPLAMA ÝÞLEMLERÝ ÝÇÝN KAÇ YIL GEÇTÝÐÝNÝ TUTMAK ÝÇÝN
	int suankigunkontrol;//DEÐER HESAPLAMA ÝÞLEMLERÝ ÝÇÝN ÝLK TARÝHÝ TUTMAK ÝÇÝN
	int suankiaykontrol;//DEÐER HESAPLAMA ÝÞLEMLERÝ ÝÇÝN ÝLK TARÝHÝ TUTMAK ÝÇÝN
public:
	tarih() :gun(1), ay(1), yil(2023), gunfarki(0), ayfarki(0), yilfarki(0), suankigunkontrol(1), suankiaykontrol(1)
	{}
	tarih(int g, int a, int y) : gun(g), ay(a), yil(y)
	{}
	void tarihyazdir()
	{
		cout << "**********************************************" << endl;
		cout << setw(30) << "Bugünün Tarihi" << endl;
		cout << setw(17) << "[ " << gun << " / " << ay << " / " << yil << " ]" << endl;
		cout << "**********************************************" << endl;
	}//BULUNULAN GÜNÜN TARÝHÝNÝ YAZDIRMA FONKSÝYONUNUN SONU

	void tarihal()
	{
		char kontrol = 'e';
		cout << "Bilgilendirme: Bulunduðunuz tarihten eskiye gidemezsiniz." << endl << endl;
		int suankiyil;
		suankiyil = yil;//YIL FARKI HESABI ÝÇÝN
		int suankiay;
		suankiay = ay;//AY FARKI HESABI ÝÇÝN 
		suankiaykontrol = suankiay;//ÝLK AYI KAYBETMEMEK ÝÇÝN ÜYE DEÐÝÞKENE ÝLK TARÝH DEÐERÝNÝ ATADIM 
		int suankigun;
		suankigun = gun;//GÜN FARKI HESABI ÝÇÝN
		suankigunkontrol = suankigun;//ÝLK GÜNÜ KAYBETMEMEK ÝÇÝN ÜYE DEÐÝÞKENE ÝLK TARÝH DEÐERÝNÝ ATADIM 
		do
		{

			cout << "Yýlý giriniz :"; cin >> yil;
			cout << endl;
			if (yil < suankiyil)//GEÇMÝÞE GÝTMEME KONTROLÜ
			{
				kontrol = 'e';
				cout << "<<  Geçersiz yýl girdiniz, girdiðiniz yýlýn þuanki yýldan küçük \"olmamasýna\" dikkat ediniz  >>" << endl << endl;
			}
			else
			{
				yilfarki = yil - suankiyil;
				kontrol = 'h';
			}

		} while (kontrol != 'h');

		do
		{
			cout << "Ayý giriniz :"; cin >> ay;
			cout << endl;
			if (ay > 12 || ay < 1)//GEÇERSÝZ AY DEÐERÝ GÝRÝLME KONTROLÜ
			{
				kontrol = 'e';
				cout << "<<  Geçersiz ay girdiniz, 0-13 \"arasýnda\" olmasýna dikkat ediniz  >>" << endl << endl;
			}
			else if (yil == suankiyil)//GEÇMÝÞE GÝTMEME KONTROLÜ ÝÇÝN
			{
				if (ay < suankiay)
				{
					kontrol = 'e';
					cout << "<<  Geçersiz ay girdiniz, girdiðiniz ayýn þuanki aydan küçük \" olmamasýna \" dikkat ediniz  >>" << endl << endl;
				}
				else
				{
					ayfarki = ay - suankiay;
					kontrol = 'h';
				}
			}
			else//SORUNSUZ DEÐERLER ÝÇÝN AY FARKI HESAPLANMASI
			{
				if (yilfarki == 0)
				{
					ayfarki = ay - suankiay;
					kontrol = 'h';
				}
				else if (yilfarki == 1)
				{
					ayfarki = (12 - suankiay) + ay;
					kontrol = 'h';
				}
				else
				{
					ayfarki = (yilfarki - 1) * 12 + (12 - suankiay) + ay;
					kontrol = 'h';
				}
			}
		} while (kontrol != 'h');
		do
		{
			cout << "Günü giriniz :"; cin >> gun;
			cout << endl;
			if (gun < 1 || gun >30)//GÜN SAYISININ SINIRLANDIRILMASI
			{
				if (ay == 2)
				{
					cout << "<<  Geçersiz gün girdiniz, 0-29 \"arasýnda\" olmasýna dikkat ediniz  >>" << endl << endl;
					kontrol = 'e';
				}
				else
				{
					cout << "<<  Geçersiz gün girdiniz, 0-31 \"arasýnda\" olmasýna dikkat ediniz  >>" << endl << endl;
					kontrol = 'e';
				}
			}
			else if (ay == 2)//ÞUBAT AYININ ÖZEL DURUMUNUN KONTROLÜ ÝÇÝN
			{
				if (gun > 28) //GÜN KONTROLÜ
				{
					kontrol = 'e';
					cout << "<<  Geçersiz gün girdiniz, Þubat ayý için 28 den büyük gün giremezsiniz  >>" << endl << endl;
				}
				else if (yil == suankiyil)//GEÇMÝÞE GÝTMEME KONTROLÜ ÝÇÝN 
				{
					if (ay == suankiay)
					{
						if (gun < suankigun)//YIL VE AYLAR EÞÝTSE GEÇMÝÞE GÝTMEME KONTROLÜ
						{
							kontrol = 'e';
							cout << "<<  Geçersiz gün girdiniz, girdiðiniz günün þuanki günden küçük \"olmamasýna \" dikkat ediniz  >>" << endl << endl;
						}
						else//GEÇMÝÞE GÝDÝLMEMÝÞSE GÜN FARKININ HESAPLANMASI
						{
							gunfarki = gun - suankigun;
							kontrol = 'h';
						}
					}
					else//EÐER AYNI YIL ÝÇÝNDEYSE AMA FARKLI AYDAYSA GEÇMÝÞE GÝTME KONTROLÜ YAPMADAN ÝÞLEM YAPILMASI
					{
						if (ayfarki == 1)//"-" SONUÇ OLMAMASI ÝÇÝN KONTROL
						{
							gunfarki = gun + (30 - suankigun);
							kontrol = 'h';
						}
						else
						{
							gunfarki = (ayfarki - 1) * 30 + (30 - suankigun) + gun;
							kontrol = 'h';
						}
					}
				}
				else//FARKLI BÝR YILDAYSA GÜN FARKI ÝÞLEMLERÝNÝN YAPILMASI
				{
					if (suankiay == 2)//ÝLK TARÝH ÞUBAT AYIYSA ONA GÖRE ÝÞLEM YAPILMASI
					{
						gunfarki = (ayfarki - 1) * 30 + (28 - suankigun) + gun;
						kontrol = 'h';
					}
					else//ÝLK TARÝH ÞUBATTAN FARKLI OLANLAR ÝÇÝN ÝÞLEM YAPILMASI
					{
						gunfarki = (ayfarki - 1) * 30 + (30 - suankigun) + gun;
						kontrol = 'h';
					}
				}
			}
			else if (yil == suankiyil)//ÞUBAT AYINDAN FARKLI AYLAR ÝÇÝN TARÝH KONTROLÜ
			{
				if (ay == suankiay)
				{
					if (gun < suankigun)
					{
						kontrol = 'e';
						cout << "<<  Geçersiz gün girdiniz, girdiðiniz günün þuanki günden küçük \"olmamasýna \" dikkat ediniz  >>" << endl << endl;
					}
					else//AYNI YIL AYNI AY ÝÇÝN GEÇMÝÞE GÝDÝLMEMÝÞSE GÜN FARKININ HESAPLANMASI
					{
						gunfarki = gun - suankigun;
						kontrol = 'h';
					}
				}
				else//AYNI YIL ÝÇÝNDE FARKLI AYDA ÝSE 
				{
					if (ayfarki == 1)
					{
						gunfarki = gun + (30 - suankigun);
						kontrol = 'h';
					}
					else
					{
						gunfarki = (ayfarki - 1) * 30 + (30 - suankigun) + gun;
						kontrol = 'h';
					}
				}
			}
			else//AYNI YIL ÝÇÝNDE DEÐÝLSE TARÝH KONTROLÜ YAPMADAN ÇIKMAK ÝÇÝN
			{
				if (suankiay == 2)//ÝLK TARÝH ÞUBAT OLMASI DURUMUNUN HESABI
				{
					gunfarki = (ayfarki - 1) * 30 + (28 - suankigun) + gun;
					kontrol = 'h';
				}
				else
				{
					gunfarki = (ayfarki - 1) * 30 + (30 - suankigun) + gun;
					kontrol = 'h';
				}
			}
		} while (kontrol != 'h');//NOT: UZUN AY GEÇÝÞLERÝNDE ÞUBAT AYININ 28 GÜN OLMA ÝHTÝMALÝNÝN HESABINI YAPAMADIM
	}//TARÝH ALMA FONKSÝYONUNUN SONU
};

class hesap :public tarih
{
private:
	vector <int> ozelhesapNo;//ÖZEL HESPALARIN TUTULMASI
	vector <int> genelhesapNo;//GENEL HESPLARIN TUTULMASI
	vector <float> bakiye_ozel;//ÖZEL HESAPLARIN BAKÝYELERÝNÝN TUTULMASI
	vector <float> bakiye_genel;//GENEL HESAPLARIN BAKÝYELERÝNÝN TUTULMASI
	float genel_deger;//GENEL HESABIN KRÝPTO DEÐERÝNÝN TUTULMASI
	float ozel_deger;//ÖZEL HESABIN KRÝPTO DEÐERÝNÝN TUTULMASI
	int ozelhesapsayisi;//KAÇ HESAP AÇILDIÐININ HESAPLANMASI ÝÇÝN
	int genelhesapsayisi;//KAÇ HESAP AÇILDIÐININ HESAPLANMASI ÝÇÝN

public:
	hesap() :tarih(), genelhesapNo(0), ozelhesapNo(0), bakiye_ozel(0), bakiye_genel(0), genel_deger(1.0), ozel_deger(1.0), ozelhesapsayisi(1), genelhesapsayisi(1)
	{}
	hesap(int ghn, int ohn, int bo, int bg, float gd, float od) : genelhesapNo(ghn), ozelhesapNo(ohn), bakiye_ozel(bo), bakiye_genel(bg)
	{}

	void genel_hesap_olusturma()
	{
		int no_al;
		float bakiye_al;
		char cýkýs = 'h';//ekledin!!!!!!!!
		cout << "<<  Hesabýnýz Ýçin Hesap Numarasý Giriniz  >>" << endl << endl;
		cin >> no_al;
		if (genelhesapsayisi == 1)//ÝLK HESAP AÇILIRKEN
			genelhesapNo.push_back(no_al);
		else
		{
			do//SON KONTROLLERÝN BÝTÝP NUMARANIN VEKTÖRE ATANMASI
			{
				do//BÜTÜN DÝZÝ ELEMANLARIYLA GÝRÝLEN YENÝ NUMARANIN "TEKRAR" KARÞILAÞTIRILMASI
				{
					for (int i = 0; i < genelhesapsayisi - 1; i++)//ÖNCEKÝ HESAPAPLAR ÝLE AYNI NUMARA ALIP ALMAMA KONTROLÜ
					{
						if (no_al == genelhesapNo[i])
						{
							do
							{
								cout << "Girdiðiniz Numaranýn Önceki Hesaplarýnýzla Ayný Olmamasýna Dikkat Ediniz" << endl;
								cout << "Yeni ve Geçerli bir numara giriniz : "; cin >> no_al;
								if (no_al == genelhesapNo[i])
									cýkýs = 'h';
								else
									cýkýs = 'd';
							} while (cýkýs != 'd');
						}
						else
							cýkýs = 't';
					}
				} while (cýkýs != 't');
				genelhesapNo.push_back(no_al);
				cýkýs = 'e';
			} while (cýkýs != 'e');
		}
		genelhesapsayisi++;
		cout << endl << endl;
		cout << "<<  Eklemek Ýstediðiniz Miktarý Giriniz  >>" << endl;
		cout << setw(23) << " 1 kripto = " << genel_deger << " TL " << endl << endl;
		cout << "(Ýlk yüklemenizde lütfen en az 1 kripto para)" << endl;
		cout << setw(38) << "(olacak þekilde yükleme yapýnýz)" << endl;
		cin >> bakiye_al;
		if (bakiye_al / genel_deger < 1)//ÝLK YÜKLEYÝÞTE EN AZ 1 KRÝPTO YÜKLENDÝÐÝNÝN KONTROLÜ
		{
			do
			{
				cout << " Lütfen en az 1 kripto yükleyebilecek deðerde bir miktar giriniz. " << endl << endl;
				cout << "Yüklemek istediðiniz bakiyeyi giriniz: "; cin >> bakiye_al;
			} while (bakiye_al / genel_deger < 1);
		}
		bakiye_genel.push_back(bakiye_al / genel_deger);
		cout << endl << endl;
		cout << "*************************************************" << endl << endl;
		cout << setw(39) << "<<  Menüye dönebilirsiniz  >>" << endl << endl;
		cout << "*************************************************" << endl << endl;
	}//GENEL HESAP OLUÞTURMASININ SONU
	void ozel_hesap_olusturma()
	{
		int no_al;
		float bakiye_al;
		char cýkýs = 'h';
		cout << "<<  Hesabýnýz Ýçin Hesap Numarasý Giriniz  >>" << endl << endl;
		cin >> no_al;
		if (ozelhesapsayisi == 1)
			ozelhesapNo.push_back(no_al);
		else
		{
			do//SON KONTROLLERÝN BÝTÝP NUMARANIN VEKTÖRE ATANMASI
			{
				do//BÜTÜN DÝZÝ ELEMANLARIYLA GÝRÝLEN YENÝ NUMARANIN "TEKRAR" KARÞILAÞTIRILMASI
				{
					for (int i = 0; i < ozelhesapsayisi - 1; i++)//ÖNCEKÝ HESAPAPLAR ÝLE AYNI NUMARA ALIP ALMAMA KONTROLÜ
					{
						if (no_al == ozelhesapNo[i])
						{
							do
							{
								cout << "Girdiðiniz Numaranýn Önceki Hesaplarýnýzla Ayný Olmamasýna Dikkat Ediniz" << endl;
								cout << "Yeni ve Geçerli bir numara giriniz : "; cin >> no_al;
								if (no_al == ozelhesapNo[i])
									cýkýs = 'h';
								else
									cýkýs = 'd';
							} while (cýkýs != 'd');
						}
						else
							cýkýs = 't';
					}
				} while (cýkýs != 't');
				ozelhesapNo.push_back(no_al);
				cýkýs = 'e';
			} while (cýkýs != 'e');

		}
		ozelhesapsayisi++;
		cout << endl << endl;
		cout << "<<  Eklemek Ýstediðiniz Miktarý Giriniz  >>" << endl;
		cout << setw(23) << " 1 kripto = " << ozel_deger << " TL " << endl;
		cout << "(Ýlk yüklemenizde lütfen en az 1 kripto para)" << endl;
		cout << setw(38) << "(olacak þekilde yükleme yapýnýz)" << endl;
		cin >> bakiye_al;
		if (bakiye_al / ozel_deger < 1)//ÝLK YÜKLEYÝÞTE EN AZ 1 KRÝPTO YÜKLENDÝÐÝNÝN KONTROLÜ
		{
			do
			{
				cout << " Lütfen en az 1 kripto yükleyebilecek deðerde bir miktar giriniz. " << endl << endl;
				cout << "Yüklemek istediðiniz bakiyeyi giriniz: "; cin >> bakiye_al;
			} while (bakiye_al / ozel_deger < 1);
		}
		bakiye_ozel.push_back(bakiye_al / ozel_deger);
		cout << endl << endl;
		cout << "*************************************************" << endl << endl;
		cout << setw(39) << "<<  Menüye dönebilirsiniz  >>" << endl << endl;
		cout << "*************************************************" << endl << endl;
	}//ÖZEL HESAP OLUÞTURMASININ SONU 

	void genelhesap_deger()
	{
		int zararyapilangun;//ZARAR YAPILAN GUN SAYISI
		int karyapilangun;//KAR YAPILAN GUN SAYISI
		if (gunfarki == 0)//HÝÇ BÝR GÜN GEÇMEMÝÞSE 
			genel_deger = genel_deger;
		else
		{
			zararyapilangun = gunfarki / 15;
			karyapilangun = gunfarki - zararyapilangun;
			if (zararyapilangun == 0)
				genel_deger = genel_deger * karyapilangun * 1.01;
			else if (karyapilangun == 0)
				genel_deger = genel_deger * zararyapilangun * 0.95;
			else
				genel_deger = genel_deger * karyapilangun * 1.01 * zararyapilangun * 0.95;
		}
	}//GENEL HESAPLAR ÝÇÝN DEÐER HESAPLAMASININ SONU 
	void ozelhesap_deger()
	{
		int zarargunleri = 0;
		int kargunleri;
		if (suankiaykontrol == 2)
			kargunleri = (28 - suankigunkontrol) + gun;
		if (ayfarki == 0)
			kargunleri = gun - suankigunkontrol;
		else
			kargunleri = (30 - suankigunkontrol) + gun;

		int zarargunlerisecimi1[3];//HER AY ÝÇÝN FARKLI KAR GÜNÜ OLUCAÐI ÝÇÝN BÝ BAÞLANGIÇTAKÝ AY ÝÇÝN BÝR DE BÝTÝÞ AYI ÝÇÝN,
		int zarargunlerisecimi2[3];//RASTGELE GÜN OLUÞTURMASI ÝÇÝN 2 DÝZÝ AÇTIM ÇÜNKÜ ARADAKÝ AYLARDA ZATEN KESÝN 3 GÜN ZARAR YAPILIYO OLUCAK
		srand(time(0));
		for (int i = 0; i < 3; i++)
		{
			zarargunlerisecimi1[i] = 1 + (rand() % 30);//ÝLK AY ÝÇÝN RASTGELE GÜN BELÝRLENMESÝ 
			if (zarargunlerisecimi1[i] == zarargunlerisecimi1[i - 1] || zarargunlerisecimi1[i] == zarargunlerisecimi1[i - 2])
				do//HER BÝRÝNÝN BÝRÝBÝRÝNDEN FARKLI OLDUÐUNU KONTROL ETMEK ÝÇÝN
				{
					zarargunlerisecimi1[i] = 1 + (rand() % 30);
				} while (zarargunlerisecimi1[i] != zarargunlerisecimi1[i - 1] || zarargunlerisecimi1[i] != zarargunlerisecimi1[i - 2]);

				zarargunlerisecimi2[i] = 1 + (rand() % 30);//SON AY ÝÇÝN RASTGELE GÜN BELÝRLENMESÝ
				if (zarargunlerisecimi2[i] == zarargunlerisecimi2[i - 1] || zarargunlerisecimi2[i] == zarargunlerisecimi2[i - 2])
					do//HER BÝRÝNÝN BÝRÝBÝRÝNDEN FARKLI OLDUÐUNU KONTROL ETMEK ÝÇÝN
					{
						zarargunlerisecimi2[i] = 1 + (rand() % 30);
					} while (zarargunlerisecimi2[i] != zarargunlerisecimi2[i - 1] || zarargunlerisecimi2[i] != zarargunlerisecimi2[i - 2]);
		}
		for (int i = 0; i < 3; i++)
		{
			if (suankigunkontrol < zarargunlerisecimi1[i])//BAÞLANGIÇTA BULUNULAN AYIN VE BULUNULAN GÜNÜN ZARAR GÜNLERÝNÝ DAHÝL EDÝP ETMEYECEÐÝNÝN KONTROLÜ
				zarargunleri = zarargunleri + 1;
			if (gun >= zarargunlerisecimi2[i])//YENÝ TARÝHTE BULUNULAN AYIN VE BULUNULAN GÜNÜN ZARAR GÜNLERÝNÝ DAHÝL EDÝP ETMEYECEÐÝNÝN KONTROLÜ
				zarargunleri = zarargunleri + 1;
		}
		if (zarargunleri >= kargunleri)//"-" DEÐER OLMAMASI ÝÇÝN
			kargunleri = zarargunleri - kargunleri;
		if (ayfarki == 1)
		{
			if (kargunleri == 0 || kargunleri < 0)//HER ÝHTÝMALE KARÞI "-" YA DA "0" DEÐERÝ OLMAMASI ÝÇÝN
				ozel_deger = ozel_deger * (zarargunleri * 0.9);
			else if (zarargunleri == 0 || zarargunleri < 0)
				ozel_deger = ozel_deger * kargunleri * 1.05;
			else
				ozel_deger = ozel_deger * (zarargunleri * 0.9) * kargunleri * 1.05;
		}
		else if (ayfarki > 1)
		{
			if (kargunleri == 0 || kargunleri < 0)//HER ÝHTÝMALE KARÞI "-" YA DA "0" DEÐERÝ OLMAMASI ÝÇÝN
				ozel_deger = ozel_deger * (ayfarki - 1) * (3 + zarargunleri) * 0.9 * 27 * 1.05;
			else if (zarargunleri == 0 || zarargunleri < 0)
				ozel_deger = ozel_deger * (ayfarki - 1) * 3 * 0.9 * (kargunleri + 27) * 1.05;
			else
				ozel_deger = ozel_deger * (ayfarki - 1) * (3 + zarargunleri) * 0.9 * (kargunleri + 27) * 1.05;
		}
		else if (ayfarki == 0)
		{
			if (kargunleri == 0 || kargunleri < 0)//HER ÝHTÝMALE KARÞI "-" YA DA "0" DEÐERÝ OLMAMASI ÝÇÝN
				ozel_deger = ozel_deger * (zarargunleri * 0.9);
			else if (zarargunleri == 0 || zarargunleri < 0)
				ozel_deger = ozel_deger * (kargunleri * 1.05);
			else
				ozel_deger = ozel_deger * (kargunleri * 1.05) * (zarargunleri * 0.9);
		}//NOT: 1 KERE "-" HATASI ALDIÐIM ÝÇÝN HER TÜRLÜ SORUNU ENGELLEMEK ÝÇÝN SONRADAN KONTROLLER EKLEDÝM BAZILARI GEREKSÝZ OLABÝLÝR 
	}//ÖZEL HESAPLAR ÝÇÝN DEÐER HESAPLAMASININ SONU

	void para_ekle()//buradan sonrasýný yapmadýn !!!!!!!
	{
		float ekle;//PARA EKLEMEK ÝÇÝN
		int num_al;//NUMARA ALMAK ÝÇÝN
		char tur_al;//HESAP TÜRÜ ALMAK ÝÇÝN
		char dongu;//DÖNGÜ KONTROLÜ ÝÇÝN
		int kontrol = 0;//GÝRÝLEN NUMARANIN HERHANGÝ BÝR HESAPLA EÞLEÞÝP EÞLEÞMEDÝÐÝ KONTROLÜ
		do//HATALI ÝÞLEMLER ÝÇÝN TEKRAR BAÞA DÖNMEK ÝÇÝN ÝLK DÖNGÜ
		{
			cout << "<< Yükleme Yapmak Ýstediðiniz Hesap Türünü Giriniz  >>" << endl;
			cout << setw(40) << "<< Özel Hesap = o   //   Genel Hesap = g >>" << endl;
			cin >> tur_al;
			if (tur_al == 'o')//ÖZEL HESAP ÝÞLEMLERÝ ÝÇÝN 
			{
				if (ozelhesapsayisi == 1)//HENÜZ HESAP OLUÞTURULMAMIÞSA 
				{
					system("CLS");
					cout << endl << endl;
					cout << setw(48) << "<<  Henüz Aktif Hesabýnýz Bulunmamaktadýr  >>" << endl << endl;
					cout << "*************************************************" << endl << endl;
					cout << setw(41) << "<<  Menüye Yönlendiriliyorsunuz  >>" << endl << endl;
					cout << "*************************************************" << endl << endl;
					dongu = 'ç';
				}
				else
				{
					cout << "<<  Yükleme Yapmak Ýstediðiniz Hesabýn Numarasýný Giriniz  >>" << endl << endl;
					cout << "Özel Hesap Numaralarýnýz ; " << endl;
					for (int i = 0; i < ozelhesapsayisi - 1; i++)//ÖZEL HESAP NUMARALARININ HATIRLATILMASI
					{
						cout << i + 1 << ". Hesap = " << ozelhesapNo[i] << endl;
					}
					cout << endl << endl;
					cin >> num_al;
					do//ÝKÝNCÝ DÖNGÜ BAÞLANGICI
					{
						for (int i = 0; i < ozelhesapsayisi - 1; i++)//HERHANGÝ BÝR HESAPLA EÞLEÞÝP EÞLEÞMEME DURUMU KONTROLÜ
						{
							if (num_al == ozelhesapNo[i])
							{
								kontrol++;
							}
						}
						if (kontrol == 0)//EÞLEÞMEMÝÞSE ÝKÝNCÝ DÖNGÜDEN ÇIKIÞ MENÜYE DÖNÜÞ
						{
							cout << endl << endl << "<<  Lütfen geçerli bir hesap numarasý giriniz  >>" << endl << endl;
							cout << "*************************************************" << endl << endl;
							cout << setw(41) << "<<  Menüye Yönlendiriliyorsunuz  >>" << endl << endl;
							cout << "*************************************************" << endl << endl;
							system("PAUSE");
							dongu = 't';
							system("CLS");
						}
						else//EÞLEÞMÝÞSE SEÇÝLEN HESAP ÝÇÝN ÝSTENEN ÝÞLEMÝN YAPILMASI
						{
							for (int i = 0; i < ozelhesapsayisi - 1; i++)//EÞLEÞÝLEN HESABIN BULUNUP O HESABA ÝÞLEM YAPILMASI
							{
								if (num_al == ozelhesapNo[i])
								{
									cout << endl << endl << "<<  Eklemek Ýstediðiniz Miktarý Giriniz  >>" << endl;
									cout << setw(23) << " 1 kripto = " << ozel_deger << " TL " << endl;
									cout << setw(27) << "Þuanki bakiyeniz = " << bakiye_ozel[i] << endl;
									cin >> ekle;
									ekle = ekle / ozel_deger;
									bakiye_ozel[i] = bakiye_ozel[i] + ekle;
									cout << endl << endl;
									cout << "*************************************************" << endl << endl;
									cout << setw(39) << "<<  Menüye dönebilirsiniz  >>" << endl << endl;
									cout << "*************************************************" << endl << endl;
									dongu = 't';
								}
							}
						}

					} while (dongu != 't');//ÝKÝNCÝ DÖNGÜ BÝTÝÞÝ
				}
				dongu = 'ç';//ÝLK DÖNGÜDEN ÇIKIÞ ÝÇÝN
			}
			else if (tur_al == 'g')//GENEL HESAP ÝÞLEMLERÝ ÝÇÝN
			{
				if (genelhesapsayisi == 1)//HENÜZ HESAP AÇILMAMIÞSA ÝÞLEM YAPILMASININ ENGELLENMESÝ
				{
					system("CLS");
					cout << endl << endl;
					cout << setw(48) << "<<  Henüz Aktif Hesabýnýz Bulunmamaktadýr  >>" << endl << endl;
					cout << "*************************************************" << endl << endl;
					cout << setw(41) << "<<  Menüye Yönlendiriliyorsunuz  >>" << endl << endl;
					cout << "*************************************************" << endl << endl;
					dongu = 'ç';
				}
				else
				{
					cout << "<<  Yükleme Yapmak Ýstediðiniz Hesabýn Numarasýný Giriniz  >>" << endl << endl;
					cout << "Genel Hesap Numaralarýnýz ; " << endl;
					for (int i = 0; i < genelhesapsayisi - 1; i++)//GENEL HESAP NUMARALARININ HATIRLATILMASI
					{
						cout << i + 1 << ".Hesap = " << genelhesapNo[i] << endl;
					}
					cout << endl << endl;
					cin >> num_al;
					do//ÝKÝNCÝ DÖNGÜ BAÞLANGICI
					{
						for (int i = 0; i < genelhesapsayisi - 1; i++)//HERHANGÝ BÝR HESAPLA EÞLEÞÝP EÞLEÞMEME DURUMU KONTROLÜ
						{
							if (num_al == genelhesapNo[i])
							{
								kontrol++;
							}
						}
						if (kontrol == 0)//EÞLEÞMEMÝÞSE ÝKÝNCÝ DÖNGÜDEN ÇIKIÞ MENÜYE DÖNÜÞ
						{
							cout << endl << endl << "<<  Lütfen geçerli bir hesap numarasý giriniz  >>" << endl << endl;
							cout << "*************************************************" << endl << endl;
							cout << setw(41) << "<<  Menüye Yönlendiriliyorsunuz  >>" << endl << endl;
							cout << "*************************************************" << endl << endl;
							system("PAUSE");
							dongu = 't';
							system("CLS");
						}
						else//EÞLEÞMÝÞSE SEÇÝLEN HESAP ÝÇÝN ÝSTENEN ÝÞLEMÝN YAPILMASI
						{
							for (int i = 0; i < genelhesapsayisi - 1; i++)//EÞLEÞÝLEN HESABIN BULUNUP O HESABA ÝÞLEM YAPILMASI
							{
								if (num_al == genelhesapNo[i])
								{
									cout << endl << endl << "<<  Eklemek Ýstediðiniz Miktarý Giriniz  >>" << endl;
									cout << setw(23) << " 1 kripto = " << genel_deger << " TL " << endl;
									cout << setw(27) << "Þuanki bakiyeniz = " << bakiye_genel[i] << endl;
									cin >> ekle;
									ekle = ekle / genel_deger;
									bakiye_genel[i] = bakiye_genel[i] + ekle;
									cout << endl << endl;
									cout << "*************************************************" << endl << endl;
									cout << setw(39) << "<<  Menüye dönebilirsiniz  >>" << endl << endl;
									cout << "*************************************************" << endl << endl;
									dongu = 't';
								}
							}
						}
					} while (dongu != 't');//ÝKÝNCÝ DÖNGÜ BÝTÝÞÝ
				}
				dongu = 'ç';//ÝLK DÖNGÜDEN ÇIKMAK ÝÇÝN
			}
			else//GEÇERSÝZ ÝÞLEM GÝRÝLMESÝNÝN ÖNLENMESÝ
			{
				cout << "<<  Geçersiz Bir Ýþlem Girdiniz Lütfen Tekrar Giriniz  >>" << endl;
				system("PAUSE");
				dongu = 'd';
				system("CLS");
			}
		} while (dongu != 'ç');
	}//PARA EKLEME FONKSÝYONUNUN SONU

	void para_cek()
	{
		float cek;//PARA ÇEKMEK ÝÇÝN
		int num_al;//NUMARA ALMAK ÝÇÝN
		char tur_al;//HESAP TÜRÜ ALMAK ÝÇÝN
		char dongu;//DÖNGÜ KONTROLÜ ÝÇÝN
		char karar;//ÝKÝNCÝ DÖNGÜ KONTROLÜ 
		int kontrol = 0;//GÝRÝLEN NUMARANIN HERHANGÝ BÝR HESAPLA EÞLEÞÝP EÞLEÞMEDÝÐÝ KONTROLÜ
		do//HATALI ÝÞLEMLER ÝÇÝN TEKRAR BAÞA DÖNMEK ÝÇÝN ÝLK DÖNGÜ
		{
			system("CLS");
			cout << "<<  Para Çekmek Ýstediðiniz Hesap Türünü Giriniz  >>" << endl;
			cout << setw(40) << "<< Özel Hesap = o   //   Genel Hesap = g >>" << endl;
			cin >> tur_al;
			if (tur_al == 'o')//ÖZEL HESAPLAR ÝÇÝN ÝÞLEM
			{
				if (ozelhesapsayisi == 1)//HENÜZ HESAP AÇILMAMIÞSA BÝRÝNCÝ DÖNGÜDEN ÇIKIP MENÜYE DÖNÜÞ
				{
					system("CLS");
					cout << endl << endl;
					cout << setw(48) << "<<  Henüz Aktif Hesabýnýz Bulunmamaktadýr  >>" << endl << endl;
					cout << "*************************************************" << endl << endl;
					cout << setw(41) << "<<  Menüye Yönlendiriliyorsunuz  >>" << endl << endl;
					cout << "*************************************************" << endl << endl;
					dongu = 'ç';
				}
				else
				{
					cout << "<<  Para Çekmek Ýstediðiniz Hesabýn Numarasýný Giriniz  >>" << endl << endl;
					cout << "Özel Hesap Numaralarýnýz ; " << endl;
					for (int i = 0; i < ozelhesapsayisi - 1; i++)//ÖZEL HESAP NUMARALARININ HATIRLATILMASI
					{
						cout << i + 1 << ". Hesap = " << ozelhesapNo[i] << endl;
					}
					cout << endl << endl;
					cin >> num_al;
					do//ÝKÝNCÝ DÖNGÜ BAÞLANGICI
					{
						for (int i = 0; i < ozelhesapsayisi - 1; i++)//HERHANGÝ BÝR HESAPLA EÞLEÞÝP EÞLEÞMEME DURUMU KONTROLÜ
						{
							if (num_al == ozelhesapNo[i])
							{
								kontrol++;
							}
						}
						if (kontrol == 0)//EÞLEÞMEMÝÞSE ÝKÝNCÝ DÖNGÜDEN ÇIKIÞ MENÜYE DÖNÜÞ
						{
							cout << endl << endl << "<<  Lütfen geçerli bir hesap numarasý giriniz  >>" << endl << endl;
							cout << "*************************************************" << endl << endl;
							cout << setw(41) << "<<  Menüye Yönlendiriliyorsunuz  >>" << endl << endl;
							cout << "*************************************************" << endl << endl;
							system("PAUSE");
							dongu = 't';
							system("CLS");
						}
						else
						{
							for (int i = 0; i < ozelhesapsayisi - 1; i++)//GÝRÝLEN HESAP NUMARASININ OLDUÐU HESABI BULMAK ÝÇÝN
							{
								if (num_al == ozelhesapNo[i])//EÞLEÞEN NUMARALI HESAP ÝÇÝN ÝÞLEM UYGULANMASI
								{
									cout << endl << endl << "<<  Çekmek Ýstediðiniz Miktarý Giriniz  >>" << endl;
									cout << setw(23) << " 1 kripto = " << ozel_deger << " TL " << endl;
									cout << setw(27) << "Þuanki bakiyeniz= " << bakiye_ozel[i] << endl;
									cin >> cek;
									if (cek > bakiye_ozel[i])//YETERLÝ BAKÝYE YOKSA ÝÞLEMÝN ENGELLENMESÝ
									{
										cout << endl << endl << "Yeterli Bakiyeniz Bulunmamaktadýr Ýþleminiz Sonlandýrýlýyor" << endl << endl;
										cout << "<<  Tekrar Ýþlem Yapmak Ýstiyorsanýz Devam(d) Ýstemiyorsanýz Çýkýþ(ç) Tuþlayýnýz  >> " << endl << endl;
										cin >> karar;//ÝÞLEME DEVAM EDÝP ETMEME KARARI
										if (karar == 'd')
										{
											dongu = 'd';
											system("CLS");
											continue;
										}
										else
											dongu = 't';
									}
									else//BAKÝYE YETERLÝYSE ÝÞLEMLERÝN YAPILMASI
									{
										bakiye_ozel[i] = bakiye_ozel[i] - cek;
										cek = cek * ozel_deger;
										cout << endl << endl;
										cout << "Baþarýlý bir þekilde \"" << cek << "\" TL çektiniz" << endl << endl;
										cout << "*************************************************" << endl << endl;
										cout << setw(39) << "<<  Menüye dönebilirsiniz  >>" << endl << endl;
										cout << "*************************************************" << endl << endl;
										dongu = 't';
									}
								}
							}
						}
					} while (dongu != 't');//ÝKÝNCÝ DÖNGÜ BÝTÝÞÝ
				}
				dongu = 'ç';//BÝRÝNCÝ DÖNGÜ ÇIKIÞI
			}
			else if (tur_al == 'g')//GENEL HESAPLAR ÝÇÝN ÝÞLEMLER
			{
				if (genelhesapsayisi == 1)//HENÜZ HEAP AÇILMAMIÞSA DÖNGÜYÜ BÝRÝNCÝ DÖNGÜYÜ BÝTÝRÝP MENÜYE DÖNÜLMESÝ
				{
					system("CLS");
					cout << endl << endl;
					cout << setw(48) << "<<  Henüz Aktif Hesabýnýz Bulunmamaktadýr  >>" << endl << endl;
					cout << "*************************************************" << endl << endl;
					cout << setw(41) << "<<  Menüye Yönlendiriliyorsunuz  >>" << endl << endl;
					cout << "*************************************************" << endl << endl;
					dongu = 'ç';
				}
				else//HESAP VARSA ÝÞLEME DEVAM EDÝLMESÝ
				{
					cout << "<<  Para Çekmek Ýstediðiniz Hesabýn Numarasýný Giriniz  >>" << endl << endl;
					cout << "Genel Hesap Numaralarýnýz ; " << endl;
					for (int i = 0; i < genelhesapsayisi - 1; i++)//GENEL HESAP NUMARALARININ HATIRLATILMASI
					{
						cout << i + 1 << ". Hesap = " << genelhesapNo[i] << endl;
					}
					cout << endl << endl;
					cin >> num_al;
					do//ÝKÝNCÝ DÖNGÜ BAÞLANGICI
					{
						for (int i = 0; i < genelhesapsayisi - 1; i++)//HERHANGÝ BÝR HESAPLA EÞLEÞÝP EÞLEÞMEME DURUMU KONTROLÜ
						{
							if (num_al == genelhesapNo[i])
							{
								kontrol++;
							}
						}
						if (kontrol == 0)//EÞLEÞMEMÝÞSE ÝKÝNCÝ DÖNGÜDEN ÇIKIÞ MENÜYE DÖNÜÞ
						{
							cout << endl << endl << "<<  Lütfen geçerli bir hesap numarasý giriniz  >>" << endl << endl;
							cout << "*************************************************" << endl << endl;
							cout << setw(41) << "<<  Menüye Yönlendiriliyorsunuz  >>" << endl << endl;
							cout << "*************************************************" << endl << endl;
							system("PAUSE");
							dongu = 't';
							system("CLS");
						}
						else//EÞLEÞEN NUMARA VARSA ÝÞLEME DEVAM EDÝLMESÝ
						{
							for (int i = 0; i < genelhesapsayisi - 1; i++)//EÞLEÞEN NUMARALI HESABIN BULUNMASI ÝÇÝN 
							{
								if (num_al == genelhesapNo[i])
								{
									cout << endl << endl << "<<  Çekmek Ýstediðiniz Miktarý Giriniz  >>" << endl;
									cout << setw(23) << " 1 kripto = " << genel_deger << " TL " << endl;
									cout << setw(27) << "Þuanki bakiyeniz= " << bakiye_genel[i] << endl;
									cin >> cek;
									if (cek > bakiye_genel[i])//YETERLÝ BAKÝYE YOKSA ÝÞLEMÝN ENGELLENMESÝ
									{
										cout << endl << endl << "Yeterli Bakiyeniz Bulunmamaktadýr Ýþleminiz Sonlandýrýlýyor" << endl << endl;
										cout << "<<  Tekrar Ýþlem Yapmak Ýstiyorsanýz Devam(d) Ýstemiyorsanýz Çýkýþ(ç) Tuþlayýnýz  >> " << endl << endl;
										cin >> karar;//ÝÞLEME DEVAM EDÝP ETMEME KARARI
										if (karar == 'd')
										{
											dongu = 'd';
											system("CLS");
											continue;
										}
										else
											dongu = 't';
									}
									else//YETERLÝ BAKÝYE VARSA ÝÞLEMÝN YAPILMASI
									{
										bakiye_genel[i] = bakiye_genel[i] - cek;
										cek = cek * genel_deger;
										cout << endl << endl;
										cout << "Baþarýlý bir þekilde \"" << cek << "\" TL çektiniz" << endl << endl;
										cout << "*************************************************" << endl << endl;
										cout << setw(39) << "<<  Menüye dönebilirsiniz  >>" << endl << endl;
										cout << "*************************************************" << endl << endl;
										dongu = 't';
									}
								}
							}
						}
					} while (dongu != 't');//ÝKÝNCÝ DÖNGÜ BÝTÝÞÝ
				}
				dongu = 'ç';//BÝRÝNCÝ DÖNGÜDEN ÇIKIÞ
			}
			else//GEÇERSÝZ ÝÞLEM GÝRÝLMESÝNÝN ÖNLENMESÝ
			{
				cout << "<<  Geçersiz Bir Ýþlem Girdiniz Lütfen Tekrar Giriniz  >>" << endl;
				system("PAUSE");
				dongu = 'd';
				system("CLS");
			}
		} while (dongu != 'ç');
	}//PARA ÇEKME FONKSÝYONUNUN SONU
	void listele()
	{
		cout << setw(25) << "<<  Genel Hesaplarýnýz  >>" << endl << endl;
		if (genelhesapsayisi == 1)//HENÜZ GENEL HESAP OLUÞTURULMAMIÞSA BUNUN BELÝRTÝLMESÝ
		{
			cout << "<<  Henüz Aktif Genel Hesabýnýz Bulunmamaktadýr  >>" << endl << endl;
		}
		else//OLUÞTURULAN HESAPLARIN LÝSTELENMESÝ
		{
			for (int i = 0; i < genelhesapsayisi - 1; i++)
			{
				cout << "Hesap Numarasý : " << genelhesapNo[i] << endl;
				cout << "Bakiyesi : " << bakiye_genel[i] << endl << endl;
			}
		}
		cout << setw(25) << "<<  Özel Hesaplarýnýz  >>" << endl << endl;
		if (ozelhesapsayisi == 1)//HENÜZ ÖZEL HESAP OLUÞTURULMAMIÞSA BUNUN BELÝRTÝLMESÝ
		{
			cout << "<<  Henüz Aktif Özel Hesabýnýz Bulunmamaktadýr  >>" << endl << endl;
		}
		else//OLUÞTURULAN HESAPLARIN LÝSTELENMESÝ
		{
			for (int i = 0; i < ozelhesapsayisi - 1; i++)
			{
				cout << "Hesap Numarasý : " << ozelhesapNo[i] << endl;
				cout << "Bakiyesi : " << bakiye_ozel[i] << endl << endl;
			}
		}
		cout << endl << endl;
		cout << "*************************************************" << endl << endl;
		cout << setw(39) << "<<  Menüye dönebilirsiniz  >>" << endl << endl;
		cout << "*************************************************" << endl << endl;
	}//HESAP LÝSTELEME FONKSÝYONUNUN SONU
};

int main()
{
	setlocale(LC_ALL, "Turkish");
	int islem;//MENÜDEN SEÇÝLEN NUMARANIN TUTULMASI
	int hesapsayisigenel = 0;//OLUÞTURULAN GENEL HESAP SAYISI
	int hesapsayisiozel = 0;//OLUÞTURULAN ÖZEL HESAP SAYISI 
	hesap bugun;//BULUNULAN GÜNE AÝT VERÝLERE ULAÞILMASI ÝÇÝN 

	do
	{
		cout << "***********************************************" << endl;
		cout << setw(40) << "YAPMAK ÝSTEDÝÐÝNÝZ ÝÞLEMÝ GÝRÝNÝZ" << endl;
		cout << setw(31) << "[1] Genel Hesap Aç" << endl;
		cout << setw(30) << "[2] Özel Hesap Aç" << endl;
		cout << setw(26) << "[3] Para Ekle" << endl;
		cout << setw(25) << "[4] Para Çek" << endl;
		cout << setw(36) << "[5] Hesaplarýmý Listele" << endl;
		cout << setw(22) << "[6] Tarih" << endl;
		cout << setw(22) << "[7] Çýkýþ" << endl;
		cout << "***********************************************" << endl;
		cin >> islem;//YAPILACAK ÝÞLEMÝN SEÇÝLMESÝ 
		if (islem > 7 || islem <= 0)//GEÇERSÝZ ÝÞLEM KONTROLÜ
		{
			cout << "Lütfen Geçerli Bir Ýþlem Giriniz." << endl << endl;
			system("PAUSE");
		}
		if (islem == 1)//GENEL HESAP AÇMA
		{
			system("CLS");

			bugun.genel_hesap_olusturma();
			hesapsayisigenel++;//HESAP OLUÞTURULDUÐU ÝÇÝN SAYISINI ARTTIRMA

			system("PAUSE");
		}
		if (islem == 2)//ÖZEL HESAP OLUÞTURMA
		{
			system("CLS");

			bugun.ozel_hesap_olusturma();
			hesapsayisiozel++;//HESAP OLUÞTURULDUÐU ÝÇÝN SAYISINI ARTTIRMA

			system("PAUSE");
		}
		if (islem == 3)//PARA EKLEME
		{
			system("CLS");

			if (hesapsayisiozel == 0 && hesapsayisigenel == 0)//HENÜZ HÝÇBÝR HESAP OLUÞTURULAMMAIÞSA ÝÞLEMÝN ENGELLENMESÝ
			{
				cout << endl << endl << setw(47) << "<<  Henüz Aktif Hesabýnýz Bulunmamaktadýr  >>" << endl;
				cout << endl << endl;
				cout << "*************************************************" << endl << endl;
				cout << setw(41) << "<<  Menüye Yönlendiriliyorsunuz  >>" << endl << endl;
				cout << "*************************************************" << endl << endl;
			}
			else//HERHANGÝ BÝR HESAP VARSA ÝÞLEME DEVAM EDÝLMESÝ
			{
				bugun.para_ekle();
			}

			system("PAUSE");
		}
		if (islem == 4)//PARA ÇEKME
		{
			system("CLS");

			if (hesapsayisiozel == 0 && hesapsayisigenel == 0)//HENÜZ HÝÇBÝR HESAP OLUÞTURULAMMAIÞSA ÝÞLEMÝN ENGELLENMESÝ
			{
				cout << endl << endl << setw(47) << "<<  Henüz Aktif Hesabýnýz Bulunmamaktadýr  >>" << endl;
				cout << endl << endl;
				cout << "*************************************************" << endl << endl;
				cout << setw(41) << "<<  Menüye Yönlendiriliyorsunuz  >>" << endl << endl;
				cout << "*************************************************" << endl << endl;
			}
			else//HERHANGÝ BÝR HESAP VARSA ÝÞLEME DEVAM EDÝLMESÝ
			{
				bugun.para_cek();
			}

			system("PAUSE");
		}
		if (islem == 5)//HESAPLARIN LÝSTELENMESÝ
		{
			system("CLS");

			bugun.listele();

			system("PAUSE");
		}
		if (islem == 6)//TARÝHÝN AYARLANMASI, GÖRÜLMESÝ
		{
			system("CLS");

			char karar;//YAPILACAK ÝÞLEME KARAR VERÝLMESÝ
			bugun.tarihyazdir();
			cout << "Tarihi deðiþtirmek ister misiniz ?  e/h"; cin >> karar; cout << endl;//KARARIN ALINMASI
			if (karar == 'e')
			{
				bugun.tarihal();//TARÝHÝ DEÐÝÞTÝRME FONKSÝYONU
				bugun.genelhesap_deger();//GENEL HESAPLARIN KRÝPTO DEÐERÝNÝN BELÝRLENMESÝ FONKSÝYONU
				bugun.ozelhesap_deger();//ÖZEL HESAPLARIN KRÝPTO DEÐERÝNÝN BELÝRLENMESÝ FONKSÝYONU
				cout << "*************************************************" << endl << endl;
				cout << setw(39) << "<<  Menüye dönebilirsiniz  >>" << endl << endl;
				cout << "*************************************************" << endl << endl;
			}
			else//TARÝH DEÐÝÞTÝRÝLMEK ÝSTENMÝYORSA 
			{
				cout << "*************************************************" << endl << endl;
				cout << setw(39) << "<<  Menüye dönebilirsiniz  >>" << endl << endl;
				cout << "*************************************************" << endl << endl;
				system("PAUSE");
				system("CLS");
				continue;
			}

			system("PAUSE");
		}

		system("CLS");

	} while (islem != 7);//UYGULAMADAN ÇIKMAK ÝÇÝN DÖNGÜNÜN SONLANDIRILMASI

	cout << "************************************************" << endl << endl;
	cout << setw(43) << "Bizi Tercih Ettiðiniz Ýçin Teþekkürler" << endl << endl;//BÝTÝRÝÞ EKRANI
	cout << "************************************************" << endl << endl;

	system("PAUSE");

	return 0;
}