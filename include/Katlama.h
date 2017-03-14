using namespace std;
#include <iostream>
#include <fstream>
#include <string>

#define ALINACAK_MOD_LINEER 503
#define ALINCAK_MOD_AYRIK_Katlama 503

int katlama_bul(long anahtar)
{
	int sayi[3][3];

	int toplam[3];

	int  a;
	int b=anahtar;
	int j,i;
		for (i=2;i>=0;i--){
			for (j=2;j>=0;j--){

			sayi[i][j]=b %10;

			b=b/10;
			}
		}

	a=sayi[0][0];
	sayi[0][0]=sayi[0][2];
	sayi[0][2]=a;

	a=sayi[2][0];
	sayi[2][0]=sayi[2][2];
	sayi[2][2]=a;

	int sayi1=0;
		for (j=0;j<3;j++){
	for (i=0;i<3;i++){
			sayi1+=sayi[i][j];
			}
			toplam[j]=sayi1%10;

		sayi1=0;
		}

	int son;

	son=toplam[0]*100+toplam[1]*10+toplam[2];
		return son;
}

int katlama_lineer()
{
	int katlamalineer_sayac=0;
	Ogrenci_Bilgileri ogrenciler[500];

	Ogrenci_Bilgileri yazilacak_ogrenci[ALINACAK_MOD_LINEER];

	ifstream ResatDondu("kisiler.txt");

	for(int i=0 ; i<500 ; i++)
	{
		ResatDondu >> ogrenciler[i].numara;
		ResatDondu >> ogrenciler[i].isim;
		ResatDondu >> ogrenciler[i].soyad;
		katlamalineer_sayac++;
	}

	int alinacak_mod,toplam_mod=0;

	for(int i=0 ; i<500 ; i++)
	{

		alinacak_mod = katlama_bul(ogrenciler[i].numara);
		alinacak_mod = alinacak_mod % ALINACAK_MOD_LINEER;

		for(int j=alinacak_mod ; j < ALINACAK_MOD_LINEER ; j++ )
		{
			katlamalineer_sayac++;
			if( yazilacak_ogrenci[j].numara == 0)
			{
				yazilacak_ogrenci[j].numara 	   = ogrenciler[i].numara;
				yazilacak_ogrenci[j].isim 	   = ogrenciler[i].isim;
				yazilacak_ogrenci[j].soyad 	   = ogrenciler[i].soyad;
				yazilacak_ogrenci[j].adim_sayisi = ogrenciler[i].adim_sayisi;
				toplam_mod += ogrenciler[i].adim_sayisi;
				break;
			}else
			{
				 if(j==ALINACAK_MOD_LINEER-1)
                    {
                        j=0;
                    }
				ogrenciler[i].adim_sayisi++;
			}
		}
	}

	ofstream yaz("Katlama_Lineer.txt");
	for(int i=0 ; i<ALINACAK_MOD_LINEER ; i++)
	{
		katlamalineer_sayac++;
		if( yazilacak_ogrenci[i].numara == 0 )
		{
			yaz << "--NULL--" <<endl;
		}else
		{
			yaz << yazilacak_ogrenci[i].numara << "\t" << yazilacak_ogrenci[i].isim;
			yaz << "\t" << yazilacak_ogrenci[i].soyad << "\t";
			yaz << yazilacak_ogrenci[i].adim_sayisi << endl;
		}
	}
	return katlamalineer_sayac+toplam_mod;
}

int katlama_ayrik()
{

	ifstream laks("kisiler.txt");
	int katlamayrik_sayac=0;

		Ogrenci_Bilgileri ogrenciler[500];
		Ogrenci_Bilgileri yazilacak_ogrenciler[ALINCAK_MOD_AYRIK_Katlama];
		Ogrenci_Bilgileri ayrik_tasan[ALINCAK_MOD_AYRIK_Katlama];

		 for(int i=0 ; i<500 ; i++)
		 {
			 laks >> ogrenciler[i].numara;
			 laks >> ogrenciler[i].isim;
			 laks >> ogrenciler[i].soyad;
			 katlamayrik_sayac++;

		 }

		int alinacak_mod,ayrikNumara=0,toplamMod=0;

		for(int i=0 ; i<500 ; i++)
		{
			alinacak_mod = katlama_bul( ogrenciler[i].numara );
			alinacak_mod = alinacak_mod	% ALINCAK_MOD_AYRIK_Katlama;

			for(int j=alinacak_mod ; j<ALINCAK_MOD_AYRIK_Katlama ; j++)
			{
				katlamayrik_sayac++;
				if( yazilacak_ogrenciler[j].numara == 0 )
				{
					yazilacak_ogrenciler[j].numara = ogrenciler[i].numara;
					yazilacak_ogrenciler[j].isim = ogrenciler[i].isim;
					yazilacak_ogrenciler[j].soyad = ogrenciler[i].soyad;
					yazilacak_ogrenciler[j].adim_sayisi = 0;
					break;
				}else
				{
					ayrik_tasan[ayrikNumara].numara = ogrenciler[i].numara;
					ayrik_tasan[ayrikNumara].isim = ogrenciler[i].isim;
					ayrik_tasan[ayrikNumara].soyad = ogrenciler[i].soyad;
					ayrik_tasan[ayrikNumara].adim_sayisi = ayrikNumara;
					toplamMod += ayrikNumara;
					ayrikNumara++;
					break;
				}
			}
		}

		ofstream vakum("Katlama_Ayrik.txt");

		for(int i=0 ; i < ALINCAK_MOD_AYRIK_Katlama ; i++ )
		{
			katlamayrik_sayac++;
			if( yazilacak_ogrenciler[i].numara == 0 )
			{
				vakum << "NULL" << endl;
			}else
			{
				vakum << yazilacak_ogrenciler[i].numara << "\t" << yazilacak_ogrenciler[i].isim;
				vakum << "\t" << yazilacak_ogrenciler[i].soyad << "\t";
				vakum << yazilacak_ogrenciler[i].adim_sayisi << endl;
			}
		}
		vakum << endl;

		vakum << "-----------------------> AYRIK TASMA <-------------------------------------" << endl;

		for(int i=0 ; i<ayrikNumara ; i++)
		{
			vakum << ayrik_tasan[i].numara << "\t" << ayrik_tasan[i].isim;
			vakum << "\t" << ayrik_tasan[i].soyad << "\t";
			vakum << i << endl;
			katlamayrik_sayac++;
		}

		return katlamayrik_sayac+toplamMod;
	}
