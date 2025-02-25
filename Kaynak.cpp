//***********************************************************************************************************************
//**                                                                                                                   **
//**                                     SAKARYA �N�VERS�TES�                                                          **
//**                          B�LG�SAYAR VE B�L���M B�L�MLER� FAK�LTES�                                                **
//**                                B�LG�SAYAR M�HEND�SL��� B�L�M�                                                     **
//**                                                                                                                   **
//**                                  �DEV NUMARASI...: 2                                                              **
//**                                  ��RENC� ADI.....: SUDE ANDURMAN                                                  **
//**                                  ��RENC� NUMARASI: b231210005                                                     **
//**                                  DERS GRUBU......: A                                                              **
//**                                                                                                                   ** 
//**                                                                                                                   **  
//**           Ama�: Bir kripto para platformu i�in hesap a�ma ve y�netim i�lemlerinin yerine                          **
//**                        getirildi�i nesne tabanl� uygulama yaz�lmas�d�r.                                           **
//**                                                                                                                   **  
//**                                                                                                                   **
//***********************************************************************************************************************


#include <iostream>
#include <locale.h>//T�RK�E KLAVYE ���N
#include <iomanip>//SETW ���N
#include <vector>//HESAP OLU�TURULDU�UNDA D�Z�YE ATANAB�LMES� ���N
#include <ctime>//RAND'IN DAHA �Y� �ALI�AB�LMES� ���N
using namespace std;

class tarih //TABAN SINIF DE�ERLER TAR�HE BA�LI DE����YOR
{
protected:
	int gun;//YEN� G�N ALMAK ���N
	int ay;//YEN� AY ALMAK ���N
	int yil;//YEN� YIL ALMAK ���N
	int gunfarki;//DE�ER HESAPLAMA ��LEMLER� ���N KA� G�N GE�T���N� TUTMAK ���N
	int ayfarki;//DE�ER HESAPLAMA ��LEMLER� ���N KA� AY GE�T���N� TUTMAK ���N
	int yilfarki;//DE�ER HESAPLAMA ��LEMLER� ���N KA� YIL GE�T���N� TUTMAK ���N
	int suankigunkontrol;//DE�ER HESAPLAMA ��LEMLER� ���N �LK TAR�H� TUTMAK ���N
	int suankiaykontrol;//DE�ER HESAPLAMA ��LEMLER� ���N �LK TAR�H� TUTMAK ���N
public:
	tarih() :gun(1), ay(1), yil(2023), gunfarki(0), ayfarki(0), yilfarki(0), suankigunkontrol(1), suankiaykontrol(1)
	{}
	tarih(int g, int a, int y) : gun(g), ay(a), yil(y)
	{}
	void tarihyazdir()
	{
		cout << "**********************************************" << endl;
		cout << setw(30) << "Bug�n�n Tarihi" << endl;
		cout << setw(17) << "[ " << gun << " / " << ay << " / " << yil << " ]" << endl;
		cout << "**********************************************" << endl;
	}//BULUNULAN G�N�N TAR�H�N� YAZDIRMA FONKS�YONUNUN SONU

	void tarihal()
	{
		char kontrol = 'e';
		cout << "Bilgilendirme: Bulundu�unuz tarihten eskiye gidemezsiniz." << endl << endl;
		int suankiyil;
		suankiyil = yil;//YIL FARKI HESABI ���N
		int suankiay;
		suankiay = ay;//AY FARKI HESABI ���N 
		suankiaykontrol = suankiay;//�LK AYI KAYBETMEMEK ���N �YE DE���KENE �LK TAR�H DE�ER�N� ATADIM 
		int suankigun;
		suankigun = gun;//G�N FARKI HESABI ���N
		suankigunkontrol = suankigun;//�LK G�N� KAYBETMEMEK ���N �YE DE���KENE �LK TAR�H DE�ER�N� ATADIM 
		do
		{

			cout << "Y�l� giriniz :"; cin >> yil;
			cout << endl;
			if (yil < suankiyil)//GE�M��E G�TMEME KONTROL�
			{
				kontrol = 'e';
				cout << "<<  Ge�ersiz y�l girdiniz, girdi�iniz y�l�n �uanki y�ldan k���k \"olmamas�na\" dikkat ediniz  >>" << endl << endl;
			}
			else
			{
				yilfarki = yil - suankiyil;
				kontrol = 'h';
			}

		} while (kontrol != 'h');

		do
		{
			cout << "Ay� giriniz :"; cin >> ay;
			cout << endl;
			if (ay > 12 || ay < 1)//GE�ERS�Z AY DE�ER� G�R�LME KONTROL�
			{
				kontrol = 'e';
				cout << "<<  Ge�ersiz ay girdiniz, 0-13 \"aras�nda\" olmas�na dikkat ediniz  >>" << endl << endl;
			}
			else if (yil == suankiyil)//GE�M��E G�TMEME KONTROL� ���N
			{
				if (ay < suankiay)
				{
					kontrol = 'e';
					cout << "<<  Ge�ersiz ay girdiniz, girdi�iniz ay�n �uanki aydan k���k \" olmamas�na \" dikkat ediniz  >>" << endl << endl;
				}
				else
				{
					ayfarki = ay - suankiay;
					kontrol = 'h';
				}
			}
			else//SORUNSUZ DE�ERLER ���N AY FARKI HESAPLANMASI
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
			cout << "G�n� giriniz :"; cin >> gun;
			cout << endl;
			if (gun < 1 || gun >30)//G�N SAYISININ SINIRLANDIRILMASI
			{
				if (ay == 2)
				{
					cout << "<<  Ge�ersiz g�n girdiniz, 0-29 \"aras�nda\" olmas�na dikkat ediniz  >>" << endl << endl;
					kontrol = 'e';
				}
				else
				{
					cout << "<<  Ge�ersiz g�n girdiniz, 0-31 \"aras�nda\" olmas�na dikkat ediniz  >>" << endl << endl;
					kontrol = 'e';
				}
			}
			else if (ay == 2)//�UBAT AYININ �ZEL DURUMUNUN KONTROL� ���N
			{
				if (gun > 28) //G�N KONTROL�
				{
					kontrol = 'e';
					cout << "<<  Ge�ersiz g�n girdiniz, �ubat ay� i�in 28 den b�y�k g�n giremezsiniz  >>" << endl << endl;
				}
				else if (yil == suankiyil)//GE�M��E G�TMEME KONTROL� ���N 
				{
					if (ay == suankiay)
					{
						if (gun < suankigun)//YIL VE AYLAR E��TSE GE�M��E G�TMEME KONTROL�
						{
							kontrol = 'e';
							cout << "<<  Ge�ersiz g�n girdiniz, girdi�iniz g�n�n �uanki g�nden k���k \"olmamas�na \" dikkat ediniz  >>" << endl << endl;
						}
						else//GE�M��E G�D�LMEM��SE G�N FARKININ HESAPLANMASI
						{
							gunfarki = gun - suankigun;
							kontrol = 'h';
						}
					}
					else//E�ER AYNI YIL ���NDEYSE AMA FARKLI AYDAYSA GE�M��E G�TME KONTROL� YAPMADAN ��LEM YAPILMASI
					{
						if (ayfarki == 1)//"-" SONU� OLMAMASI ���N KONTROL
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
				else//FARKLI B�R YILDAYSA G�N FARKI ��LEMLER�N�N YAPILMASI
				{
					if (suankiay == 2)//�LK TAR�H �UBAT AYIYSA ONA G�RE ��LEM YAPILMASI
					{
						gunfarki = (ayfarki - 1) * 30 + (28 - suankigun) + gun;
						kontrol = 'h';
					}
					else//�LK TAR�H �UBATTAN FARKLI OLANLAR ���N ��LEM YAPILMASI
					{
						gunfarki = (ayfarki - 1) * 30 + (30 - suankigun) + gun;
						kontrol = 'h';
					}
				}
			}
			else if (yil == suankiyil)//�UBAT AYINDAN FARKLI AYLAR ���N TAR�H KONTROL�
			{
				if (ay == suankiay)
				{
					if (gun < suankigun)
					{
						kontrol = 'e';
						cout << "<<  Ge�ersiz g�n girdiniz, girdi�iniz g�n�n �uanki g�nden k���k \"olmamas�na \" dikkat ediniz  >>" << endl << endl;
					}
					else//AYNI YIL AYNI AY ���N GE�M��E G�D�LMEM��SE G�N FARKININ HESAPLANMASI
					{
						gunfarki = gun - suankigun;
						kontrol = 'h';
					}
				}
				else//AYNI YIL ���NDE FARKLI AYDA �SE 
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
			else//AYNI YIL ���NDE DE��LSE TAR�H KONTROL� YAPMADAN �IKMAK ���N
			{
				if (suankiay == 2)//�LK TAR�H �UBAT OLMASI DURUMUNUN HESABI
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
		} while (kontrol != 'h');//NOT: UZUN AY GE���LER�NDE �UBAT AYININ 28 G�N OLMA �HT�MAL�N�N HESABINI YAPAMADIM
	}//TAR�H ALMA FONKS�YONUNUN SONU
};

class hesap :public tarih
{
private:
	vector <int> ozelhesapNo;//�ZEL HESPALARIN TUTULMASI
	vector <int> genelhesapNo;//GENEL HESPLARIN TUTULMASI
	vector <float> bakiye_ozel;//�ZEL HESAPLARIN BAK�YELER�N�N TUTULMASI
	vector <float> bakiye_genel;//GENEL HESAPLARIN BAK�YELER�N�N TUTULMASI
	float genel_deger;//GENEL HESABIN KR�PTO DE�ER�N�N TUTULMASI
	float ozel_deger;//�ZEL HESABIN KR�PTO DE�ER�N�N TUTULMASI
	int ozelhesapsayisi;//KA� HESAP A�ILDI�ININ HESAPLANMASI ���N
	int genelhesapsayisi;//KA� HESAP A�ILDI�ININ HESAPLANMASI ���N

public:
	hesap() :tarih(), genelhesapNo(0), ozelhesapNo(0), bakiye_ozel(0), bakiye_genel(0), genel_deger(1.0), ozel_deger(1.0), ozelhesapsayisi(1), genelhesapsayisi(1)
	{}
	hesap(int ghn, int ohn, int bo, int bg, float gd, float od) : genelhesapNo(ghn), ozelhesapNo(ohn), bakiye_ozel(bo), bakiye_genel(bg)
	{}

	void genel_hesap_olusturma()
	{
		int no_al;
		float bakiye_al;
		char c�k�s = 'h';//ekledin!!!!!!!!
		cout << "<<  Hesab�n�z ��in Hesap Numaras� Giriniz  >>" << endl << endl;
		cin >> no_al;
		if (genelhesapsayisi == 1)//�LK HESAP A�ILIRKEN
			genelhesapNo.push_back(no_al);
		else
		{
			do//SON KONTROLLER�N B�T�P NUMARANIN VEKT�RE ATANMASI
			{
				do//B�T�N D�Z� ELEMANLARIYLA G�R�LEN YEN� NUMARANIN "TEKRAR" KAR�ILA�TIRILMASI
				{
					for (int i = 0; i < genelhesapsayisi - 1; i++)//�NCEK� HESAPAPLAR �LE AYNI NUMARA ALIP ALMAMA KONTROL�
					{
						if (no_al == genelhesapNo[i])
						{
							do
							{
								cout << "Girdi�iniz Numaran�n �nceki Hesaplar�n�zla Ayn� Olmamas�na Dikkat Ediniz" << endl;
								cout << "Yeni ve Ge�erli bir numara giriniz : "; cin >> no_al;
								if (no_al == genelhesapNo[i])
									c�k�s = 'h';
								else
									c�k�s = 'd';
							} while (c�k�s != 'd');
						}
						else
							c�k�s = 't';
					}
				} while (c�k�s != 't');
				genelhesapNo.push_back(no_al);
				c�k�s = 'e';
			} while (c�k�s != 'e');
		}
		genelhesapsayisi++;
		cout << endl << endl;
		cout << "<<  Eklemek �stedi�iniz Miktar� Giriniz  >>" << endl;
		cout << setw(23) << " 1 kripto = " << genel_deger << " TL " << endl << endl;
		cout << "(�lk y�klemenizde l�tfen en az 1 kripto para)" << endl;
		cout << setw(38) << "(olacak �ekilde y�kleme yap�n�z)" << endl;
		cin >> bakiye_al;
		if (bakiye_al / genel_deger < 1)//�LK Y�KLEY��TE EN AZ 1 KR�PTO Y�KLEND���N�N KONTROL�
		{
			do
			{
				cout << " L�tfen en az 1 kripto y�kleyebilecek de�erde bir miktar giriniz. " << endl << endl;
				cout << "Y�klemek istedi�iniz bakiyeyi giriniz: "; cin >> bakiye_al;
			} while (bakiye_al / genel_deger < 1);
		}
		bakiye_genel.push_back(bakiye_al / genel_deger);
		cout << endl << endl;
		cout << "*************************************************" << endl << endl;
		cout << setw(39) << "<<  Men�ye d�nebilirsiniz  >>" << endl << endl;
		cout << "*************************************************" << endl << endl;
	}//GENEL HESAP OLU�TURMASININ SONU
	void ozel_hesap_olusturma()
	{
		int no_al;
		float bakiye_al;
		char c�k�s = 'h';
		cout << "<<  Hesab�n�z ��in Hesap Numaras� Giriniz  >>" << endl << endl;
		cin >> no_al;
		if (ozelhesapsayisi == 1)
			ozelhesapNo.push_back(no_al);
		else
		{
			do//SON KONTROLLER�N B�T�P NUMARANIN VEKT�RE ATANMASI
			{
				do//B�T�N D�Z� ELEMANLARIYLA G�R�LEN YEN� NUMARANIN "TEKRAR" KAR�ILA�TIRILMASI
				{
					for (int i = 0; i < ozelhesapsayisi - 1; i++)//�NCEK� HESAPAPLAR �LE AYNI NUMARA ALIP ALMAMA KONTROL�
					{
						if (no_al == ozelhesapNo[i])
						{
							do
							{
								cout << "Girdi�iniz Numaran�n �nceki Hesaplar�n�zla Ayn� Olmamas�na Dikkat Ediniz" << endl;
								cout << "Yeni ve Ge�erli bir numara giriniz : "; cin >> no_al;
								if (no_al == ozelhesapNo[i])
									c�k�s = 'h';
								else
									c�k�s = 'd';
							} while (c�k�s != 'd');
						}
						else
							c�k�s = 't';
					}
				} while (c�k�s != 't');
				ozelhesapNo.push_back(no_al);
				c�k�s = 'e';
			} while (c�k�s != 'e');

		}
		ozelhesapsayisi++;
		cout << endl << endl;
		cout << "<<  Eklemek �stedi�iniz Miktar� Giriniz  >>" << endl;
		cout << setw(23) << " 1 kripto = " << ozel_deger << " TL " << endl;
		cout << "(�lk y�klemenizde l�tfen en az 1 kripto para)" << endl;
		cout << setw(38) << "(olacak �ekilde y�kleme yap�n�z)" << endl;
		cin >> bakiye_al;
		if (bakiye_al / ozel_deger < 1)//�LK Y�KLEY��TE EN AZ 1 KR�PTO Y�KLEND���N�N KONTROL�
		{
			do
			{
				cout << " L�tfen en az 1 kripto y�kleyebilecek de�erde bir miktar giriniz. " << endl << endl;
				cout << "Y�klemek istedi�iniz bakiyeyi giriniz: "; cin >> bakiye_al;
			} while (bakiye_al / ozel_deger < 1);
		}
		bakiye_ozel.push_back(bakiye_al / ozel_deger);
		cout << endl << endl;
		cout << "*************************************************" << endl << endl;
		cout << setw(39) << "<<  Men�ye d�nebilirsiniz  >>" << endl << endl;
		cout << "*************************************************" << endl << endl;
	}//�ZEL HESAP OLU�TURMASININ SONU 

	void genelhesap_deger()
	{
		int zararyapilangun;//ZARAR YAPILAN GUN SAYISI
		int karyapilangun;//KAR YAPILAN GUN SAYISI
		if (gunfarki == 0)//H�� B�R G�N GE�MEM��SE 
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
	}//GENEL HESAPLAR ���N DE�ER HESAPLAMASININ SONU 
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

		int zarargunlerisecimi1[3];//HER AY ���N FARKLI KAR G�N� OLUCA�I ���N B� BA�LANGI�TAK� AY ���N B�R DE B�T�� AYI ���N,
		int zarargunlerisecimi2[3];//RASTGELE G�N OLU�TURMASI ���N 2 D�Z� A�TIM ��NK� ARADAK� AYLARDA ZATEN KES�N 3 G�N ZARAR YAPILIYO OLUCAK
		srand(time(0));
		for (int i = 0; i < 3; i++)
		{
			zarargunlerisecimi1[i] = 1 + (rand() % 30);//�LK AY ���N RASTGELE G�N BEL�RLENMES� 
			if (zarargunlerisecimi1[i] == zarargunlerisecimi1[i - 1] || zarargunlerisecimi1[i] == zarargunlerisecimi1[i - 2])
				do//HER B�R�N�N B�R�B�R�NDEN FARKLI OLDU�UNU KONTROL ETMEK ���N
				{
					zarargunlerisecimi1[i] = 1 + (rand() % 30);
				} while (zarargunlerisecimi1[i] != zarargunlerisecimi1[i - 1] || zarargunlerisecimi1[i] != zarargunlerisecimi1[i - 2]);

				zarargunlerisecimi2[i] = 1 + (rand() % 30);//SON AY ���N RASTGELE G�N BEL�RLENMES�
				if (zarargunlerisecimi2[i] == zarargunlerisecimi2[i - 1] || zarargunlerisecimi2[i] == zarargunlerisecimi2[i - 2])
					do//HER B�R�N�N B�R�B�R�NDEN FARKLI OLDU�UNU KONTROL ETMEK ���N
					{
						zarargunlerisecimi2[i] = 1 + (rand() % 30);
					} while (zarargunlerisecimi2[i] != zarargunlerisecimi2[i - 1] || zarargunlerisecimi2[i] != zarargunlerisecimi2[i - 2]);
		}
		for (int i = 0; i < 3; i++)
		{
			if (suankigunkontrol < zarargunlerisecimi1[i])//BA�LANGI�TA BULUNULAN AYIN VE BULUNULAN G�N�N ZARAR G�NLER�N� DAH�L ED�P ETMEYECE��N�N KONTROL�
				zarargunleri = zarargunleri + 1;
			if (gun >= zarargunlerisecimi2[i])//YEN� TAR�HTE BULUNULAN AYIN VE BULUNULAN G�N�N ZARAR G�NLER�N� DAH�L ED�P ETMEYECE��N�N KONTROL�
				zarargunleri = zarargunleri + 1;
		}
		if (zarargunleri >= kargunleri)//"-" DE�ER OLMAMASI ���N
			kargunleri = zarargunleri - kargunleri;
		if (ayfarki == 1)
		{
			if (kargunleri == 0 || kargunleri < 0)//HER �HT�MALE KAR�I "-" YA DA "0" DE�ER� OLMAMASI ���N
				ozel_deger = ozel_deger * (zarargunleri * 0.9);
			else if (zarargunleri == 0 || zarargunleri < 0)
				ozel_deger = ozel_deger * kargunleri * 1.05;
			else
				ozel_deger = ozel_deger * (zarargunleri * 0.9) * kargunleri * 1.05;
		}
		else if (ayfarki > 1)
		{
			if (kargunleri == 0 || kargunleri < 0)//HER �HT�MALE KAR�I "-" YA DA "0" DE�ER� OLMAMASI ���N
				ozel_deger = ozel_deger * (ayfarki - 1) * (3 + zarargunleri) * 0.9 * 27 * 1.05;
			else if (zarargunleri == 0 || zarargunleri < 0)
				ozel_deger = ozel_deger * (ayfarki - 1) * 3 * 0.9 * (kargunleri + 27) * 1.05;
			else
				ozel_deger = ozel_deger * (ayfarki - 1) * (3 + zarargunleri) * 0.9 * (kargunleri + 27) * 1.05;
		}
		else if (ayfarki == 0)
		{
			if (kargunleri == 0 || kargunleri < 0)//HER �HT�MALE KAR�I "-" YA DA "0" DE�ER� OLMAMASI ���N
				ozel_deger = ozel_deger * (zarargunleri * 0.9);
			else if (zarargunleri == 0 || zarargunleri < 0)
				ozel_deger = ozel_deger * (kargunleri * 1.05);
			else
				ozel_deger = ozel_deger * (kargunleri * 1.05) * (zarargunleri * 0.9);
		}//NOT: 1 KERE "-" HATASI ALDI�IM ���N HER T�RL� SORUNU ENGELLEMEK ���N SONRADAN KONTROLLER EKLED�M BAZILARI GEREKS�Z OLAB�L�R 
	}//�ZEL HESAPLAR ���N DE�ER HESAPLAMASININ SONU

	void para_ekle()//buradan sonras�n� yapmad�n !!!!!!!
	{
		float ekle;//PARA EKLEMEK ���N
		int num_al;//NUMARA ALMAK ���N
		char tur_al;//HESAP T�R� ALMAK ���N
		char dongu;//D�NG� KONTROL� ���N
		int kontrol = 0;//G�R�LEN NUMARANIN HERHANG� B�R HESAPLA E�LE��P E�LE�MED��� KONTROL�
		do//HATALI ��LEMLER ���N TEKRAR BA�A D�NMEK ���N �LK D�NG�
		{
			cout << "<< Y�kleme Yapmak �stedi�iniz Hesap T�r�n� Giriniz  >>" << endl;
			cout << setw(40) << "<< �zel Hesap = o   //   Genel Hesap = g >>" << endl;
			cin >> tur_al;
			if (tur_al == 'o')//�ZEL HESAP ��LEMLER� ���N 
			{
				if (ozelhesapsayisi == 1)//HEN�Z HESAP OLU�TURULMAMI�SA 
				{
					system("CLS");
					cout << endl << endl;
					cout << setw(48) << "<<  Hen�z Aktif Hesab�n�z Bulunmamaktad�r  >>" << endl << endl;
					cout << "*************************************************" << endl << endl;
					cout << setw(41) << "<<  Men�ye Y�nlendiriliyorsunuz  >>" << endl << endl;
					cout << "*************************************************" << endl << endl;
					dongu = '�';
				}
				else
				{
					cout << "<<  Y�kleme Yapmak �stedi�iniz Hesab�n Numaras�n� Giriniz  >>" << endl << endl;
					cout << "�zel Hesap Numaralar�n�z ; " << endl;
					for (int i = 0; i < ozelhesapsayisi - 1; i++)//�ZEL HESAP NUMARALARININ HATIRLATILMASI
					{
						cout << i + 1 << ". Hesap = " << ozelhesapNo[i] << endl;
					}
					cout << endl << endl;
					cin >> num_al;
					do//�K�NC� D�NG� BA�LANGICI
					{
						for (int i = 0; i < ozelhesapsayisi - 1; i++)//HERHANG� B�R HESAPLA E�LE��P E�LE�MEME DURUMU KONTROL�
						{
							if (num_al == ozelhesapNo[i])
							{
								kontrol++;
							}
						}
						if (kontrol == 0)//E�LE�MEM��SE �K�NC� D�NG�DEN �IKI� MEN�YE D�N��
						{
							cout << endl << endl << "<<  L�tfen ge�erli bir hesap numaras� giriniz  >>" << endl << endl;
							cout << "*************************************************" << endl << endl;
							cout << setw(41) << "<<  Men�ye Y�nlendiriliyorsunuz  >>" << endl << endl;
							cout << "*************************************************" << endl << endl;
							system("PAUSE");
							dongu = 't';
							system("CLS");
						}
						else//E�LE�M��SE SE��LEN HESAP ���N �STENEN ��LEM�N YAPILMASI
						{
							for (int i = 0; i < ozelhesapsayisi - 1; i++)//E�LE��LEN HESABIN BULUNUP O HESABA ��LEM YAPILMASI
							{
								if (num_al == ozelhesapNo[i])
								{
									cout << endl << endl << "<<  Eklemek �stedi�iniz Miktar� Giriniz  >>" << endl;
									cout << setw(23) << " 1 kripto = " << ozel_deger << " TL " << endl;
									cout << setw(27) << "�uanki bakiyeniz = " << bakiye_ozel[i] << endl;
									cin >> ekle;
									ekle = ekle / ozel_deger;
									bakiye_ozel[i] = bakiye_ozel[i] + ekle;
									cout << endl << endl;
									cout << "*************************************************" << endl << endl;
									cout << setw(39) << "<<  Men�ye d�nebilirsiniz  >>" << endl << endl;
									cout << "*************************************************" << endl << endl;
									dongu = 't';
								}
							}
						}

					} while (dongu != 't');//�K�NC� D�NG� B�T���
				}
				dongu = '�';//�LK D�NG�DEN �IKI� ���N
			}
			else if (tur_al == 'g')//GENEL HESAP ��LEMLER� ���N
			{
				if (genelhesapsayisi == 1)//HEN�Z HESAP A�ILMAMI�SA ��LEM YAPILMASININ ENGELLENMES�
				{
					system("CLS");
					cout << endl << endl;
					cout << setw(48) << "<<  Hen�z Aktif Hesab�n�z Bulunmamaktad�r  >>" << endl << endl;
					cout << "*************************************************" << endl << endl;
					cout << setw(41) << "<<  Men�ye Y�nlendiriliyorsunuz  >>" << endl << endl;
					cout << "*************************************************" << endl << endl;
					dongu = '�';
				}
				else
				{
					cout << "<<  Y�kleme Yapmak �stedi�iniz Hesab�n Numaras�n� Giriniz  >>" << endl << endl;
					cout << "Genel Hesap Numaralar�n�z ; " << endl;
					for (int i = 0; i < genelhesapsayisi - 1; i++)//GENEL HESAP NUMARALARININ HATIRLATILMASI
					{
						cout << i + 1 << ".Hesap = " << genelhesapNo[i] << endl;
					}
					cout << endl << endl;
					cin >> num_al;
					do//�K�NC� D�NG� BA�LANGICI
					{
						for (int i = 0; i < genelhesapsayisi - 1; i++)//HERHANG� B�R HESAPLA E�LE��P E�LE�MEME DURUMU KONTROL�
						{
							if (num_al == genelhesapNo[i])
							{
								kontrol++;
							}
						}
						if (kontrol == 0)//E�LE�MEM��SE �K�NC� D�NG�DEN �IKI� MEN�YE D�N��
						{
							cout << endl << endl << "<<  L�tfen ge�erli bir hesap numaras� giriniz  >>" << endl << endl;
							cout << "*************************************************" << endl << endl;
							cout << setw(41) << "<<  Men�ye Y�nlendiriliyorsunuz  >>" << endl << endl;
							cout << "*************************************************" << endl << endl;
							system("PAUSE");
							dongu = 't';
							system("CLS");
						}
						else//E�LE�M��SE SE��LEN HESAP ���N �STENEN ��LEM�N YAPILMASI
						{
							for (int i = 0; i < genelhesapsayisi - 1; i++)//E�LE��LEN HESABIN BULUNUP O HESABA ��LEM YAPILMASI
							{
								if (num_al == genelhesapNo[i])
								{
									cout << endl << endl << "<<  Eklemek �stedi�iniz Miktar� Giriniz  >>" << endl;
									cout << setw(23) << " 1 kripto = " << genel_deger << " TL " << endl;
									cout << setw(27) << "�uanki bakiyeniz = " << bakiye_genel[i] << endl;
									cin >> ekle;
									ekle = ekle / genel_deger;
									bakiye_genel[i] = bakiye_genel[i] + ekle;
									cout << endl << endl;
									cout << "*************************************************" << endl << endl;
									cout << setw(39) << "<<  Men�ye d�nebilirsiniz  >>" << endl << endl;
									cout << "*************************************************" << endl << endl;
									dongu = 't';
								}
							}
						}
					} while (dongu != 't');//�K�NC� D�NG� B�T���
				}
				dongu = '�';//�LK D�NG�DEN �IKMAK ���N
			}
			else//GE�ERS�Z ��LEM G�R�LMES�N�N �NLENMES�
			{
				cout << "<<  Ge�ersiz Bir ��lem Girdiniz L�tfen Tekrar Giriniz  >>" << endl;
				system("PAUSE");
				dongu = 'd';
				system("CLS");
			}
		} while (dongu != '�');
	}//PARA EKLEME FONKS�YONUNUN SONU

	void para_cek()
	{
		float cek;//PARA �EKMEK ���N
		int num_al;//NUMARA ALMAK ���N
		char tur_al;//HESAP T�R� ALMAK ���N
		char dongu;//D�NG� KONTROL� ���N
		char karar;//�K�NC� D�NG� KONTROL� 
		int kontrol = 0;//G�R�LEN NUMARANIN HERHANG� B�R HESAPLA E�LE��P E�LE�MED��� KONTROL�
		do//HATALI ��LEMLER ���N TEKRAR BA�A D�NMEK ���N �LK D�NG�
		{
			system("CLS");
			cout << "<<  Para �ekmek �stedi�iniz Hesap T�r�n� Giriniz  >>" << endl;
			cout << setw(40) << "<< �zel Hesap = o   //   Genel Hesap = g >>" << endl;
			cin >> tur_al;
			if (tur_al == 'o')//�ZEL HESAPLAR ���N ��LEM
			{
				if (ozelhesapsayisi == 1)//HEN�Z HESAP A�ILMAMI�SA B�R�NC� D�NG�DEN �IKIP MEN�YE D�N��
				{
					system("CLS");
					cout << endl << endl;
					cout << setw(48) << "<<  Hen�z Aktif Hesab�n�z Bulunmamaktad�r  >>" << endl << endl;
					cout << "*************************************************" << endl << endl;
					cout << setw(41) << "<<  Men�ye Y�nlendiriliyorsunuz  >>" << endl << endl;
					cout << "*************************************************" << endl << endl;
					dongu = '�';
				}
				else
				{
					cout << "<<  Para �ekmek �stedi�iniz Hesab�n Numaras�n� Giriniz  >>" << endl << endl;
					cout << "�zel Hesap Numaralar�n�z ; " << endl;
					for (int i = 0; i < ozelhesapsayisi - 1; i++)//�ZEL HESAP NUMARALARININ HATIRLATILMASI
					{
						cout << i + 1 << ". Hesap = " << ozelhesapNo[i] << endl;
					}
					cout << endl << endl;
					cin >> num_al;
					do//�K�NC� D�NG� BA�LANGICI
					{
						for (int i = 0; i < ozelhesapsayisi - 1; i++)//HERHANG� B�R HESAPLA E�LE��P E�LE�MEME DURUMU KONTROL�
						{
							if (num_al == ozelhesapNo[i])
							{
								kontrol++;
							}
						}
						if (kontrol == 0)//E�LE�MEM��SE �K�NC� D�NG�DEN �IKI� MEN�YE D�N��
						{
							cout << endl << endl << "<<  L�tfen ge�erli bir hesap numaras� giriniz  >>" << endl << endl;
							cout << "*************************************************" << endl << endl;
							cout << setw(41) << "<<  Men�ye Y�nlendiriliyorsunuz  >>" << endl << endl;
							cout << "*************************************************" << endl << endl;
							system("PAUSE");
							dongu = 't';
							system("CLS");
						}
						else
						{
							for (int i = 0; i < ozelhesapsayisi - 1; i++)//G�R�LEN HESAP NUMARASININ OLDU�U HESABI BULMAK ���N
							{
								if (num_al == ozelhesapNo[i])//E�LE�EN NUMARALI HESAP ���N ��LEM UYGULANMASI
								{
									cout << endl << endl << "<<  �ekmek �stedi�iniz Miktar� Giriniz  >>" << endl;
									cout << setw(23) << " 1 kripto = " << ozel_deger << " TL " << endl;
									cout << setw(27) << "�uanki bakiyeniz= " << bakiye_ozel[i] << endl;
									cin >> cek;
									if (cek > bakiye_ozel[i])//YETERL� BAK�YE YOKSA ��LEM�N ENGELLENMES�
									{
										cout << endl << endl << "Yeterli Bakiyeniz Bulunmamaktad�r ��leminiz Sonland�r�l�yor" << endl << endl;
										cout << "<<  Tekrar ��lem Yapmak �stiyorsan�z Devam(d) �stemiyorsan�z ��k��(�) Tu�lay�n�z  >> " << endl << endl;
										cin >> karar;//��LEME DEVAM ED�P ETMEME KARARI
										if (karar == 'd')
										{
											dongu = 'd';
											system("CLS");
											continue;
										}
										else
											dongu = 't';
									}
									else//BAK�YE YETERL�YSE ��LEMLER�N YAPILMASI
									{
										bakiye_ozel[i] = bakiye_ozel[i] - cek;
										cek = cek * ozel_deger;
										cout << endl << endl;
										cout << "Ba�ar�l� bir �ekilde \"" << cek << "\" TL �ektiniz" << endl << endl;
										cout << "*************************************************" << endl << endl;
										cout << setw(39) << "<<  Men�ye d�nebilirsiniz  >>" << endl << endl;
										cout << "*************************************************" << endl << endl;
										dongu = 't';
									}
								}
							}
						}
					} while (dongu != 't');//�K�NC� D�NG� B�T���
				}
				dongu = '�';//B�R�NC� D�NG� �IKI�I
			}
			else if (tur_al == 'g')//GENEL HESAPLAR ���N ��LEMLER
			{
				if (genelhesapsayisi == 1)//HEN�Z HEAP A�ILMAMI�SA D�NG�Y� B�R�NC� D�NG�Y� B�T�R�P MEN�YE D�N�LMES�
				{
					system("CLS");
					cout << endl << endl;
					cout << setw(48) << "<<  Hen�z Aktif Hesab�n�z Bulunmamaktad�r  >>" << endl << endl;
					cout << "*************************************************" << endl << endl;
					cout << setw(41) << "<<  Men�ye Y�nlendiriliyorsunuz  >>" << endl << endl;
					cout << "*************************************************" << endl << endl;
					dongu = '�';
				}
				else//HESAP VARSA ��LEME DEVAM ED�LMES�
				{
					cout << "<<  Para �ekmek �stedi�iniz Hesab�n Numaras�n� Giriniz  >>" << endl << endl;
					cout << "Genel Hesap Numaralar�n�z ; " << endl;
					for (int i = 0; i < genelhesapsayisi - 1; i++)//GENEL HESAP NUMARALARININ HATIRLATILMASI
					{
						cout << i + 1 << ". Hesap = " << genelhesapNo[i] << endl;
					}
					cout << endl << endl;
					cin >> num_al;
					do//�K�NC� D�NG� BA�LANGICI
					{
						for (int i = 0; i < genelhesapsayisi - 1; i++)//HERHANG� B�R HESAPLA E�LE��P E�LE�MEME DURUMU KONTROL�
						{
							if (num_al == genelhesapNo[i])
							{
								kontrol++;
							}
						}
						if (kontrol == 0)//E�LE�MEM��SE �K�NC� D�NG�DEN �IKI� MEN�YE D�N��
						{
							cout << endl << endl << "<<  L�tfen ge�erli bir hesap numaras� giriniz  >>" << endl << endl;
							cout << "*************************************************" << endl << endl;
							cout << setw(41) << "<<  Men�ye Y�nlendiriliyorsunuz  >>" << endl << endl;
							cout << "*************************************************" << endl << endl;
							system("PAUSE");
							dongu = 't';
							system("CLS");
						}
						else//E�LE�EN NUMARA VARSA ��LEME DEVAM ED�LMES�
						{
							for (int i = 0; i < genelhesapsayisi - 1; i++)//E�LE�EN NUMARALI HESABIN BULUNMASI ���N 
							{
								if (num_al == genelhesapNo[i])
								{
									cout << endl << endl << "<<  �ekmek �stedi�iniz Miktar� Giriniz  >>" << endl;
									cout << setw(23) << " 1 kripto = " << genel_deger << " TL " << endl;
									cout << setw(27) << "�uanki bakiyeniz= " << bakiye_genel[i] << endl;
									cin >> cek;
									if (cek > bakiye_genel[i])//YETERL� BAK�YE YOKSA ��LEM�N ENGELLENMES�
									{
										cout << endl << endl << "Yeterli Bakiyeniz Bulunmamaktad�r ��leminiz Sonland�r�l�yor" << endl << endl;
										cout << "<<  Tekrar ��lem Yapmak �stiyorsan�z Devam(d) �stemiyorsan�z ��k��(�) Tu�lay�n�z  >> " << endl << endl;
										cin >> karar;//��LEME DEVAM ED�P ETMEME KARARI
										if (karar == 'd')
										{
											dongu = 'd';
											system("CLS");
											continue;
										}
										else
											dongu = 't';
									}
									else//YETERL� BAK�YE VARSA ��LEM�N YAPILMASI
									{
										bakiye_genel[i] = bakiye_genel[i] - cek;
										cek = cek * genel_deger;
										cout << endl << endl;
										cout << "Ba�ar�l� bir �ekilde \"" << cek << "\" TL �ektiniz" << endl << endl;
										cout << "*************************************************" << endl << endl;
										cout << setw(39) << "<<  Men�ye d�nebilirsiniz  >>" << endl << endl;
										cout << "*************************************************" << endl << endl;
										dongu = 't';
									}
								}
							}
						}
					} while (dongu != 't');//�K�NC� D�NG� B�T���
				}
				dongu = '�';//B�R�NC� D�NG�DEN �IKI�
			}
			else//GE�ERS�Z ��LEM G�R�LMES�N�N �NLENMES�
			{
				cout << "<<  Ge�ersiz Bir ��lem Girdiniz L�tfen Tekrar Giriniz  >>" << endl;
				system("PAUSE");
				dongu = 'd';
				system("CLS");
			}
		} while (dongu != '�');
	}//PARA �EKME FONKS�YONUNUN SONU
	void listele()
	{
		cout << setw(25) << "<<  Genel Hesaplar�n�z  >>" << endl << endl;
		if (genelhesapsayisi == 1)//HEN�Z GENEL HESAP OLU�TURULMAMI�SA BUNUN BEL�RT�LMES�
		{
			cout << "<<  Hen�z Aktif Genel Hesab�n�z Bulunmamaktad�r  >>" << endl << endl;
		}
		else//OLU�TURULAN HESAPLARIN L�STELENMES�
		{
			for (int i = 0; i < genelhesapsayisi - 1; i++)
			{
				cout << "Hesap Numaras� : " << genelhesapNo[i] << endl;
				cout << "Bakiyesi : " << bakiye_genel[i] << endl << endl;
			}
		}
		cout << setw(25) << "<<  �zel Hesaplar�n�z  >>" << endl << endl;
		if (ozelhesapsayisi == 1)//HEN�Z �ZEL HESAP OLU�TURULMAMI�SA BUNUN BEL�RT�LMES�
		{
			cout << "<<  Hen�z Aktif �zel Hesab�n�z Bulunmamaktad�r  >>" << endl << endl;
		}
		else//OLU�TURULAN HESAPLARIN L�STELENMES�
		{
			for (int i = 0; i < ozelhesapsayisi - 1; i++)
			{
				cout << "Hesap Numaras� : " << ozelhesapNo[i] << endl;
				cout << "Bakiyesi : " << bakiye_ozel[i] << endl << endl;
			}
		}
		cout << endl << endl;
		cout << "*************************************************" << endl << endl;
		cout << setw(39) << "<<  Men�ye d�nebilirsiniz  >>" << endl << endl;
		cout << "*************************************************" << endl << endl;
	}//HESAP L�STELEME FONKS�YONUNUN SONU
};

int main()
{
	setlocale(LC_ALL, "Turkish");
	int islem;//MEN�DEN SE��LEN NUMARANIN TUTULMASI
	int hesapsayisigenel = 0;//OLU�TURULAN GENEL HESAP SAYISI
	int hesapsayisiozel = 0;//OLU�TURULAN �ZEL HESAP SAYISI 
	hesap bugun;//BULUNULAN G�NE A�T VER�LERE ULA�ILMASI ���N 

	do
	{
		cout << "***********************************************" << endl;
		cout << setw(40) << "YAPMAK �STED���N�Z ��LEM� G�R�N�Z" << endl;
		cout << setw(31) << "[1] Genel Hesap A�" << endl;
		cout << setw(30) << "[2] �zel Hesap A�" << endl;
		cout << setw(26) << "[3] Para Ekle" << endl;
		cout << setw(25) << "[4] Para �ek" << endl;
		cout << setw(36) << "[5] Hesaplar�m� Listele" << endl;
		cout << setw(22) << "[6] Tarih" << endl;
		cout << setw(22) << "[7] ��k��" << endl;
		cout << "***********************************************" << endl;
		cin >> islem;//YAPILACAK ��LEM�N SE��LMES� 
		if (islem > 7 || islem <= 0)//GE�ERS�Z ��LEM KONTROL�
		{
			cout << "L�tfen Ge�erli Bir ��lem Giriniz." << endl << endl;
			system("PAUSE");
		}
		if (islem == 1)//GENEL HESAP A�MA
		{
			system("CLS");

			bugun.genel_hesap_olusturma();
			hesapsayisigenel++;//HESAP OLU�TURULDU�U ���N SAYISINI ARTTIRMA

			system("PAUSE");
		}
		if (islem == 2)//�ZEL HESAP OLU�TURMA
		{
			system("CLS");

			bugun.ozel_hesap_olusturma();
			hesapsayisiozel++;//HESAP OLU�TURULDU�U ���N SAYISINI ARTTIRMA

			system("PAUSE");
		}
		if (islem == 3)//PARA EKLEME
		{
			system("CLS");

			if (hesapsayisiozel == 0 && hesapsayisigenel == 0)//HEN�Z H��B�R HESAP OLU�TURULAMMAI�SA ��LEM�N ENGELLENMES�
			{
				cout << endl << endl << setw(47) << "<<  Hen�z Aktif Hesab�n�z Bulunmamaktad�r  >>" << endl;
				cout << endl << endl;
				cout << "*************************************************" << endl << endl;
				cout << setw(41) << "<<  Men�ye Y�nlendiriliyorsunuz  >>" << endl << endl;
				cout << "*************************************************" << endl << endl;
			}
			else//HERHANG� B�R HESAP VARSA ��LEME DEVAM ED�LMES�
			{
				bugun.para_ekle();
			}

			system("PAUSE");
		}
		if (islem == 4)//PARA �EKME
		{
			system("CLS");

			if (hesapsayisiozel == 0 && hesapsayisigenel == 0)//HEN�Z H��B�R HESAP OLU�TURULAMMAI�SA ��LEM�N ENGELLENMES�
			{
				cout << endl << endl << setw(47) << "<<  Hen�z Aktif Hesab�n�z Bulunmamaktad�r  >>" << endl;
				cout << endl << endl;
				cout << "*************************************************" << endl << endl;
				cout << setw(41) << "<<  Men�ye Y�nlendiriliyorsunuz  >>" << endl << endl;
				cout << "*************************************************" << endl << endl;
			}
			else//HERHANG� B�R HESAP VARSA ��LEME DEVAM ED�LMES�
			{
				bugun.para_cek();
			}

			system("PAUSE");
		}
		if (islem == 5)//HESAPLARIN L�STELENMES�
		{
			system("CLS");

			bugun.listele();

			system("PAUSE");
		}
		if (islem == 6)//TAR�H�N AYARLANMASI, G�R�LMES�
		{
			system("CLS");

			char karar;//YAPILACAK ��LEME KARAR VER�LMES�
			bugun.tarihyazdir();
			cout << "Tarihi de�i�tirmek ister misiniz ?  e/h"; cin >> karar; cout << endl;//KARARIN ALINMASI
			if (karar == 'e')
			{
				bugun.tarihal();//TAR�H� DE���T�RME FONKS�YONU
				bugun.genelhesap_deger();//GENEL HESAPLARIN KR�PTO DE�ER�N�N BEL�RLENMES� FONKS�YONU
				bugun.ozelhesap_deger();//�ZEL HESAPLARIN KR�PTO DE�ER�N�N BEL�RLENMES� FONKS�YONU
				cout << "*************************************************" << endl << endl;
				cout << setw(39) << "<<  Men�ye d�nebilirsiniz  >>" << endl << endl;
				cout << "*************************************************" << endl << endl;
			}
			else//TAR�H DE���T�R�LMEK �STENM�YORSA 
			{
				cout << "*************************************************" << endl << endl;
				cout << setw(39) << "<<  Men�ye d�nebilirsiniz  >>" << endl << endl;
				cout << "*************************************************" << endl << endl;
				system("PAUSE");
				system("CLS");
				continue;
			}

			system("PAUSE");
		}

		system("CLS");

	} while (islem != 7);//UYGULAMADAN �IKMAK ���N D�NG�N�N SONLANDIRILMASI

	cout << "************************************************" << endl << endl;
	cout << setw(43) << "Bizi Tercih Etti�iniz ��in Te�ekk�rler" << endl << endl;//B�T�R�� EKRANI
	cout << "************************************************" << endl << endl;

	system("PAUSE");

	return 0;
}