#include <iostream>
#include <string>
#include <time.h>
#include <fstream>
#include <stdlib.h>

#include "OgrenciBilgileri.h"
#include "Katlama.h"
#include "BolenKalan.h"
#include "KareOrtasi.h"

using namespace std;

void rastgele_kisi_olustur();

void arama_yap(int dizi[]);

long rastgele(long max,long min)
{
    long a;
    a= (rand()* 4578 % (max-min) ) + min;//RAND_MAX =32767  OLDUGUNDAN DOLAYI 4578 SAYISIYLA CARPILIR.
return a;
}

void bubbleSort(int dizi[], int elemanSayisi)
{
     int temp;
     int i, j;

     for (i=1; i<elemanSayisi; i++)
     {
         for (j=0; j<elemanSayisi-i; j++)
         {
             if(dizi[j] > dizi[j+1])
             {
                        temp = dizi [j];
                        dizi [j] = dizi [j+1];
                        dizi [j+1] = temp;
             }
         }
     }

}

int main()
{
	rastgele_kisi_olustur();
	int dizi[6];

	dizi[0] = Mod_Lineer();

	dizi[1] = mod_ayrik_tasma();

	dizi[2] = katlama_lineer();

	dizi[3] = katlama_ayrik();

	dizi[4] = Kare_ortasi_Lineer();

	dizi[5] = Kare_ortasi_Ayrik();

	arama_yap(dizi);




	return 0;
}

void rastgele_kisi_olustur()
{
	srand(time(NULL));
	string isimler[70] = { "Jane","Tom","Mehmet","Hakan","Semih","Ali","Samet","Kadir","Ramazan","Umut","Sam","Resat","Mane","Yusa","Yusuf","Hale","Eda","Elif","Sevgi","Hamid","Natay","Tahaa","Denis","Tugba","Cansel","Mairi","Zarate","Cassano","Martin","Sayton","Kamil","Sukran","Perihan","Semra","Duygu","Aylin","Kader","Ahmet","Burak","Aslan","Arda","Polat","Cahit","Timur","Zeynep","Damla","Derya","Tugce","Omer","Rasim","Gokce","Dilan","Andac","Aysu","Acelya","Meltem","Burcu","Ekin","Dilek","Ýpek","\0" };
	string soyadlar[70] = { "Yilmaz","Ersun","Aysel","Orcun","Demir","Onur","Mehlika","Sorhan","Gezer","Kacan","Alaran","Dondu","Eraslan","Tiysa","Simpos","Devaraa","Klara","Restos","Kurt","Seyid","Hakkan","Arslan","Bram","Polar","Mirsat","Dogu","Kuzey","Salt","Kaymaz","Lame","Kas","Neset","Savas","Baris","Osman","Avsar","Durmaz","Karam","Kara","Sac","Utyas","Kimya","Dunya","Ayasa","Otkan","Surla","Masd","Hasan","Urtas","Jack","Hale","Kar","Asli","Gozde","Seyhan","Yuksel","Sofu","Alkan","Kismet","Celebi","Kaya","Uz","Ozcan","Silahci","Yasin","Tuna","Oylum","Gul","\0" };

	ofstream kisiler("kisiler.txt");

	Ogrenci_Bilgileri Ogrenciler[500];

	long tmp=0;

	Ogrenciler[0].numara=rastgele(150000000,100000000);
        for (int i=1;i<501;i++){
        	Ogrenciler[i].numara=rastgele(150000000,100000000);
            int j=i-1;
            while(j>=1){
                if (Ogrenciler[i].numara == Ogrenciler[j].numara){
                	Ogrenciler[i].numara=rastgele(150000000,100000000);
                    j=i-1;
                }
                else j--;
            }
        }

        for(int i=0 ; i<500 ; i++)
        {
        	for(int j=0 ; j< 500 ; j++)
        	{
        		if(Ogrenciler[i].numara == Ogrenciler[j].numara && i != j)
        		{
        			cout << "cakisti ve bitti" << endl;
        		}
        	}
        }
	for(int i=0 ; i<500 ; i++)
	{
		if( i % 2 == 0)
		{
			tmp = rand() % 59;
			Ogrenciler[i].isim = isimler[tmp];
			Ogrenciler[i].soyad = soyadlar[tmp];
		}
		else
		{
			tmp = rand() % 59;
			Ogrenciler[i].isim = soyadlar[tmp];
			Ogrenciler[i].soyad = isimler[tmp];
		}
	}

	for(int i=0 ; i<500 ; i++)
	{
		kisiler << Ogrenciler[i].numara << "\t" << Ogrenciler[i].isim;
		kisiler << "\t" << Ogrenciler[i].soyad << endl;
	}

}

void arama_yap(int dizi[])
{

	for(int i=0 ; i<6 ; i++)
	{
		if(i==0)
		{
			cout << "Bolen kalan lineer = " << dizi[0] << endl;
		}

		if(i==1)
		{
			cout << "Bolen kalan ayrik = " << dizi[1] << endl;
		}
		if(i==2)
		{
			cout << "Katlama Lineer = " << dizi[2] << endl;
		}
		if(i==3)
		{
			cout << "Katlama Ayrik = " << dizi[3] << endl;
		}
		if(i==4)
		{
			cout << "KareOrtasi lineer = " << dizi[4] << endl;
		}
		if(i==5)
		{
			cout << "KareOrtasi Ayrik = " << dizi[5] << endl;
		}
	}
	int gecici[5];
	for(int i=0;i<6;i++)
    {
        gecici[i]=dizi[i];
    }
	bubbleSort(gecici,6);


        if(gecici[0]==dizi[0])
		{
			cout << " en hizli yontem Bolen kalan lineer = " << dizi[0] << endl;
		}

		 if(gecici[0]==dizi[1])
		{
			cout << "en hizli yontem Bolen kalan ayrik = " << dizi[1] << endl;
		}
		 if(gecici[0]==dizi[2])
		{
			cout << "en hizli yontem Katlama Lineer = " << dizi[2] << endl;
		}
		 if(gecici[0]==dizi[3])
		{
			cout << "en hizli yontem Katlama Ayrik = " << dizi[3] << endl;
		}
		 if(gecici[0]==dizi[4])
		{
			cout << "en hizli yontem KareOrtasi lineer = " << dizi[4] << endl;
		}
		 if(gecici[0]==dizi[5])
		{
			cout <<"en hizli yontem KareOrtasi Ayrik = " << dizi[5] << endl;
		}




}


