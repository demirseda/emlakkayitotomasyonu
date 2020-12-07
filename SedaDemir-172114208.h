#include<iostream>
#include<fstream>
#include<iomanip>
#include<string>
using namespace std;
class ev
{
public:
 string site;
 string durum;
 int oda; 
 int metrekare;
 float fiyat;
 int evno; 
 void evGir();
 void evYazdir();
 };
void ev::evGir()
{
 cout.setf(ios::right);
 cout<<"Evin Site Adi..:";
 cin>>site;
 cout<<"Ev Satilik/Kiralik..:";
 cin>>durum;  
 cout<<"Evin Odasi..:";
 cin>>oda;
 cout<<"Evin Metrekaresi..:";
 cin>>metrekare;
 cout<<"Evin Fiyati..:";
 cin>>fiyat;
 cout<<"Evin Numarasi..:";
 cin>>evno;
}
void ev::evYazdir()
{
 cout.setf(ios::right);
 cout<<"Evin Site Adi..:"<<site<<endl;
 cout<<"Evin Durumu..:"<<durum<<endl;
 cout<<"Evin Odasi..:"<<oda<<endl;
 cout<<"Evin Metrekaresi..:"<<metrekare<<endl;
 cout<<"Evin Fiyati..:"<<fiyat<<endl;
 cout<<"Evin Numarasi..:"<<evno<<endl;
 cout<<"**********************************"<<endl;
}
class dosyalar
{
private:
fstream dosya;
fstream yedek;
void DosyaAc()
{
 dosya.open("kayit.txt",ios::out|ios::in|ios::app);
 dosya.setf(ios::left);
}
void DosyaKapat()
{
	dosya.close();
}
void YedekAc()
{
 yedek.open("yedek.txt",ios::out|ios::in|ios::app);
 yedek.setf(ios::left);
}
void YedekKapat()
{
	yedek.close();
}
void evOkuDosyadan(ev &temp)
{
 dosya>>temp.site;
 dosya>>temp.durum;
 dosya>>temp.oda;
 dosya>>temp.metrekare;
 dosya>>temp.fiyat;
 dosya>>temp.evno;
}
void evYazDosyaya(ev &E)
{
 dosya<<endl
 <<setw(10)<<E.site
 <<setw(10)<<E.durum
 <<setw(10)<<E.oda
 <<setw(10)<<E.metrekare
 <<setw(10)<<E.fiyat
 <<setw(10)<<E.evno;
 }
void evYazYedek(ev &E)
{
 yedek<<endl
 <<setw(10)<<E.site
 <<setw(10)<<E.durum
 <<setw(10)<<E.oda
 <<setw(10)<<E.metrekare
 <<setw(10)<<E.fiyat
 <<setw(10)<<E.evno;
 }
public:
ev E;
int sayac;
dosyalar()
{
 evListele();
 system("cls");
}
void evEkle()
{
 DosyaAc();
 E.evGir();
 evYazDosyaya(E); 
 DosyaKapat();
 sayac++;
}
int evBul(int evno)
{
 DosyaAc();
 ev temp; 
 for(int i=1;i<sayac;i++)
 { 
	evOkuDosyadan(temp); 
	if(temp.evno==evno)
	 {
		temp.evYazdir();
		DosyaKapat();
		return 0;
	 }
 } 
cout<<"Aradiginiz Ev Numarasinda Ev Bulunamadi\n\n";
DosyaKapat(); 
return 0;
}
void evListele()
	{
	 sayac=0;
	 DosyaAc();
	 ev temp; 
	 if(!dosya.eof())
	 sayac++; 
	 evOkuDosyadan(temp);
	 while(!dosya.eof())
	 {
	 temp.evYazdir();
	 evOkuDosyadan(temp);
	 sayac++;
	 }
	 DosyaKapat();
	}
void evSil(int no)
{
 DosyaAc();
 YedekAc();
 ev temp;
 
for(int i=1;i<sayac;i++)
 {
 
evOkuDosyadan(temp);
 
if(temp.evno==no)
 {
 cout<<"Silmek istediginiz ev bulundu ve SILINDI\n\n";
 sayac--;
 }
 else
 {
 evYazYedek(temp);
 }
 }
 DosyaKapat();
 remove("kayit.txt");
 YedekKapat();
 rename("yedek.txt","kayit.txt");
}
/*int Guncelle(int no){
DosyaAc();
YedekAc();
ev temp;
 for(int i=1;i<sayac+1;i++)
 {
   evOkuDosyadan(temp);
   if(temp.evno==no)	 
      evEklee();
	  evSil(no);
	  DosyaKapat();
	  return 0;
   }
DosyaKapat();
YedekKapat();
return 0;
}*/
};
class Menu
{
public:
 
string AnaMenu();
string İcmenu();
 
}; 
string Menu::İcmenu()
{
 string secim;
 cout<<"		EMLAK KAYIT OTOMASYONU		"<<endl;
 cout<<"--------------------------"<<endl;
 cout<<"=> 1-Islemler "<<endl;
 cout<<"=> 2-Cikis"<<endl;
 cout<<"--------------------------"<<endl<<endl;
 cout<<"Bir secenek secin lutfen: ";
 cin>>secim;
 system("cls");
return secim;
 
} 
string Menu::AnaMenu()
{
 string secim;
 cout<<endl;
 cout<<"*******************************"<<endl;
 cout<<"* 1-Ekle *"<<endl;
 cout<<"* 2-Bul *"<<endl;
 cout<<"* 3-Sil *"<<endl; 
 cout<<"* 4-Listeyi Goster *"<<endl;
 /*cout<<"* 5-Guncelle *"<<endl;*/
 cout<<"* *"<<endl;
 cout<<"*******************************"<<endl<<endl;
 cout<<"Bir secenek secin lutfen: ";
 cin>>secim;
  system("cls");
 return secim;
 
} 
int main()
{ 
	system ("color c");
 dosyalar b;
 Menu m;
int no; 
 
for(;;)
 {
 string secim_m=m.İcmenu();
 if (secim_m == "1") 
 {
	 secim_m=m.AnaMenu();
	if(secim_m == "1")
	b.evEkle(); 
	if(secim_m == "2")
	{
	cout<<"Bulmak istediginiz evin numarasini giriniz..";
	cin>>no;
	 b.evBul(no);
	}
	if(secim_m == "3")
	{
	cout<<"Silmek istediginiz evin numarasini giriniz..";
	cin>>no;
	b.evSil(no);
	}
	if(secim_m=="4")
	b.evListele();
	/*if (secim_m=="5")
	{
		cout<<"Güncellemek istediginiz evin numarasini giriniz.."; 
		cin>>no;
		b.Guncelle(no); 
	}*/
}
 else if(secim_m=="2")
 exit(1);
 else 
 {
 system("cls");
 cout<<"Yanlis bir giris yaptiniz"<<endl;
 cout<<"Dikkat!!!\nSecenekteki numaralardan birisini giriniz...\n\n";
 }
 }
 
return 0;
}