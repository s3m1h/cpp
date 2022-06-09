#include <iostream>
#include <fstream>
using namespace std;

// kullanılan islemler
// kalıtım, şablon, virtual, friend, dosyaya yazma, try catch
/*
kalıtım: bir sınıfın özelliklerini başka bir sınıfa aktarma
örnek: class A , class B --> class A:public B

kompozisyon: bir sınıfın nesnesini başka bir sınıfta hayata getirme
örnek: class A, class B  --> class B { A a_nesnesi;}

virtual:içerisinde tamamlanmıs veya tamamlanmamıs metod tamamlanan fonksiyon
örnek: virtual void fonksiyon() = 0;  virtual void fonksiyon(){......}
***
* ici tamamlanmamıs bir virtual fonksiyonu olan sınıfı, kalıtım eden tum sınıflar
* bu fonksiyonu tekrar yazıp içerisini doldurmak zorundadır

friend: bir sınıfın , başka bir sınıfın private özelliklerine erişebilmesi icin arkadaş olması durumu 
örnek: friend class classismi , friend void fonksiyon();

şablonlar:sınıf üzerine template <class T> yazılarak kullanılır. bu sınıfı birden fazla veri tipi ile kullanabilme
özelliği sağlıyor. buradaki T ifadesi bir takma addır ama  genel bir kullanımdır. Typedan gelir. 

dosya: dosya işlemleri ofstream: dosyaya yazar, ifstream: dosyadan okur

try catch: hata yönetimi

*/

class Program {
public:
    virtual void ProgramBilgisi() = 0;
};

template <class T>
class HesapMakinesi:public Program {
protected:
    T sayi1, sayi2;
public:
    HesapMakinesi() {
        cout << "1.sayi: " << endl;
        cin >> sayi1;
        cout << "2.sayi: " << endl;
        cin >> sayi2;
    }
    HesapMakinesi(T sayi1, T sayi2) {
        this->sayi1 = sayi1;
        this->sayi2 = sayi2;
    }
    T Topla() { return sayi1 + sayi2; }
    T Cikar() { return sayi1 - sayi2; }
    T Carp() { return sayi1 * sayi2; }
    T Bol() { 
        try
        {
            if (sayi2 <=0) {
              
                throw "payda sifir veya sifirdan kucuk olamaz....";
            }
            else {
                return sayi1 / sayi2;
            }
            
        }
        catch (const char* mesaj)
        {
            cerr << mesaj << endl;
        }
        }
    friend class GelismisHesapMakinesi;

    void ProgramBilgisi() {
        cout << "Hesap makinesi...\n\n";
    }
};


class GelismisHesapMakinesi :public Program, public HesapMakinesi<float> {

public:
    int KareAl() { return pow(sayi1, sayi2); }
    void ProgramBilgisi() {
        cout << "Gelismis hesap makinesi...\n\n";
    }
};


int main()
{
    GelismisHesapMakinesi gelismisHesapMakinesi;
    gelismisHesapMakinesi.ProgramBilgisi();
    cout <<"topla: "<< gelismisHesapMakinesi.Topla() << endl;
    cout <<"carp: "<< gelismisHesapMakinesi.Carp() << endl;
    cout <<"bol: "<< gelismisHesapMakinesi.Bol() << endl;
    cout <<"cikar: "<< gelismisHesapMakinesi.Cikar() << endl;

    HesapMakinesi<int> hesapMakinesi(5, 5);
    cout <<"toplam sonucu: "<<hesapMakinesi.Topla() << endl;

    ofstream yaz;
    yaz.open("dosya.txt");
    yaz << gelismisHesapMakinesi.Topla();
    yaz << gelismisHesapMakinesi.Carp();
    yaz << gelismisHesapMakinesi.Bol();
    yaz << gelismisHesapMakinesi.Cikar();
    yaz.close();


    return 0;
}
