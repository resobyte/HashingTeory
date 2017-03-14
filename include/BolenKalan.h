#include <iostream>
#include <fstream>
#include <string>

#define ALINACAK_MOD 503
#define ALINACAK_MOD_AYRIK 503

using namespace std;

int Mod_Lineer()
{
	 int toplam_mod=0;
	 int sayac_lineer=0;
	 ifstream kisiler_oku("kisiler.txt");
	 Ogrenci_Bilgileri ogrenci[500];

	 Ogrenci_Bilgileri yazilacak_ogrenci[ALINACAK_MOD];
	 for(int i=0 ; i<500 ; i++)
	 {
		 kisiler_oku >> ogrenci[i].numara;
		 kisiler_oku >> ogrenci[i].isim;
		 kisiler_oku >> ogrenci[i].soyad;
		 sayac_lineer++;
	 }
	 int alinacak_mod;

	 for(int i=0 ; i<500 ; i++)
	 {


		  alinacak_mod = ogrenci[i].numara % ALINACAK_MOD;
		  for(int j=alinacak_mod ; j<ALINACAK_MOD ; j++ )
		  {   sayac_lineer++;
			  if( yazilacak_ogrenci[j].numara == 0 )
			  {
				  yazilacak_ogrenci[j].numara 	   = ogrenci[i].numara;
				  yazilacak_ogrenci[j].isim 	   = ogrenci[i].isim;
				  yazilacak_ogrenci[j].soyad 	   = ogrenci[i].soyad;
				  yazilacak_ogrenci[j].adim_sayisi = ogrenci[i].adim_sayisi;
				  toplam_mod += ogrenci[i].adim_sayisi;
				  break;
			  }else
			  {   if(j==ALINACAK_MOD-1)
                    {
                        j=0;
                    }
				  ogrenci[i].adim_sayisi++;
			  }
		  }
	 }

	 ofstream modlineer("Mod_Lineer.txt");

	 for(int i=0 ; i<ALINACAK_MOD ; i++)
	 {
		 sayac_lineer++;
		 if(yazilacak_ogrenci[i].numara == 0)
		 {
			 modlineer << "--NULL--" << endl;
		 }else
		 {
			 modlineer << yazilacak_ogrenci[i].numara << "\t" << yazilacak_ogrenci[i].isim << "\t"
				 << yazilacak_ogrenci[i].soyad << "\t" << yazilacak_ogrenci[i].adim_sayisi << endl;
		 }

	 }

	 return sayac_lineer+toplam_mod;
} // mod lineer sonu

int mod_ayrik_tasma()
{
	ifstream laks("kisiler.txt");
	int sayac_ayrik=0;

	Ogrenci_Bilgileri ogrenciler[500];
	Ogrenci_Bilgileri yazilacak_ogrenciler[ALINACAK_MOD_AYRIK];
	Ogrenci_Bilgileri ayrik_tasan[ALINACAK_MOD_AYRIK];

	 for(int i=0 ; i<500 ; i++)
	 {
		 laks >> ogrenciler[i].numara;
		 laks >> ogrenciler[i].isim;
		 laks >> ogrenciler[i].soyad;
		 sayac_ayrik++;

	 }

	int alinacak_mod,ayrikNumara=0,toplamMod=0;

	for(int i=0 ; i<500 ; i++)
	{
		alinacak_mod = ogrenciler[i].numara % ALINACAK_MOD_AYRIK;

		for(int j=alinacak_mod ; j<ALINACAK_MOD_AYRIK ; j++)
		{
			sayac_ayrik++;
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

	ofstream vakum("Mod_Ayrik.txt");

	for(int i=0 ; i<ALINACAK_MOD_AYRIK ; i++ )
	{
		sayac_ayrik++;
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
		sayac_ayrik++;
	}

	return sayac_ayrik+toplamMod;
}

