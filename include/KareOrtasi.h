#include <iostream>
#include <fstream>
#include <string>

using namespace std;

#define ALINACAK_MOD_LINEER_Kare 503
#define ALINCAK_MOD_AYRIK_Kare 503

int kare_bul(long anahtar)
{
	int i=0;
	  long	long int a =anahtar;
		int b[20],c[20];

		int j,k=0;


		a=a*a;

		while (a>=1)
		{
			b[i]=a%10;
			a=a/10;
			i++;
		}


		for(j=i-1;j>=0;j--)
		{

			c[k]=b[j];
			k++;

		}

	 	int tut[3];

	 	int l;

	 	if (i%2==0)
	 	{
	 		for(l=0;l<3;l++){

	 			tut[l]=c[i/2+l];

	 		}
		}else for(l=0;l<3;l++){

	 			tut[l]=c[i/2+l-1];

	 		}

	 	int sonuc;

		sonuc=tut[0]*100+tut[1]*10+tut[2];

		return sonuc;
}

int Kare_ortasi_Lineer()
{
	int karelineer_sayac=0;
	Ogrenci_Bilgileri ogrenciler[500];

		Ogrenci_Bilgileri yazilacak_ogrenci[ALINACAK_MOD_LINEER_Kare];

		ifstream ResatDondu("kisiler.txt");

		for(int i=0 ; i<500 ; i++)
		{
			ResatDondu >> ogrenciler[i].numara;
			ResatDondu >> ogrenciler[i].isim;
			ResatDondu >> ogrenciler[i].soyad;
			karelineer_sayac++;
		}

		int alinacak_mod,toplam_mod=0;

		for(int i=0 ; i<500 ; i++)
		{

			alinacak_mod = kare_bul(ogrenciler[i].numara);
			alinacak_mod = alinacak_mod % ALINACAK_MOD_LINEER_Kare;


			for(int j=alinacak_mod ; j < ALINACAK_MOD_LINEER_Kare ; j++ )
			{   karelineer_sayac++;
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
					 if(j==ALINACAK_MOD_LINEER_Kare-1)
                    {
                        j=0;
                    }
					ogrenciler[i].adim_sayisi++;
				}
			}
		}

		ofstream yaz("KareOrtasi_Lineer.txt");
		for(int i=0 ; i<ALINACAK_MOD_LINEER_Kare ; i++)
		{
			karelineer_sayac++;
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
		return karelineer_sayac+toplam_mod;

}

int Kare_ortasi_Ayrik()
{
	ifstream laks("kisiler.txt");

			int kareayrik_sayac=0;
			Ogrenci_Bilgileri ogrenciler[500];
			Ogrenci_Bilgileri yazilacak_ogrenciler[ALINCAK_MOD_AYRIK_Kare];
			Ogrenci_Bilgileri ayrik_tasan[ALINCAK_MOD_AYRIK_Kare];

			 for(int i=0 ; i<500 ; i++)
			 {
				 laks >> ogrenciler[i].numara;
				 laks >> ogrenciler[i].isim;
				 laks >> ogrenciler[i].soyad;
				 kareayrik_sayac++;
			 }

			int alinacak_mod,ayrikNumara=0,toplamMod=0;

			for(int i=0 ; i<500 ; i++)
			{
				alinacak_mod = katlama_bul( ogrenciler[i].numara );
				alinacak_mod = alinacak_mod	% ALINCAK_MOD_AYRIK_Kare;


				for(int j=alinacak_mod ; j<ALINCAK_MOD_AYRIK_Kare ; j++)
				{
					kareayrik_sayac++;
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

			ofstream vakum("KareOrtasi_Ayrik.txt");

			for(int i=0 ; i < ALINCAK_MOD_AYRIK_Kare ; i++ )
			{
				kareayrik_sayac++;
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
				kareayrik_sayac++;
				vakum << ayrik_tasan[i].numara << "\t" << ayrik_tasan[i].isim;
				vakum << "\t" << ayrik_tasan[i].soyad << "\t";
				vakum << i << endl;
			}
			return kareayrik_sayac+toplamMod;
}
