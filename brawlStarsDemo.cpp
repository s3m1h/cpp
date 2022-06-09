#include <iostream>
#include <string>
#include <list>
#include <map>

using namespace std;

class Saldiri {
protected:
    int Hasar = 0;
    string SaldiriIsmi;
    string Menzil;
    string DoldurmaHizi;
};

class Savunma {
protected:
    int Saglik = 0;
    string HareketHizi;
};

class Aksesuar {
protected:
    virtual void Aksesuar1() = 0;
    virtual void Aksesuar2() = 0;
};

class YildizGucu {
protected:
    virtual void YildizGucu1() = 0;
    virtual void YildizGucu2() = 0;
};

class Savasci : public Saldiri, public Savunma
{
public:
    void Istatistikler(string extraSaldiriOzellligi = "") {
        cout << "\n\n======================================================================================\n";
        cout << "\t\t\t\tSAVASCI ISTATISTIKLERI";
        cout << "\n\n";
        cout << "\t\tSAGLIK: " << "\t" << Saglik << "\tHAREKET HIZI: " << HareketHizi;
        cout << "\n";
        cout << "\n\n";
        cout << "\t\tHASAR: " << "\t" << Hasar << "\tMENZIL: " << Menzil << "\tDOLDURMA HIZI: " << DoldurmaHizi << extraSaldiriOzellligi;
        cout << "\n\n";
    }
    virtual string SavasciAdi() = 0;
    virtual void Saldiri() = 0;
    virtual void SuperSaldiri() = 0;
    virtual void ExstraIstatistikler() = 0;

};

class Mortis : public Savasci, public Aksesuar, public YildizGucu {
    
private:
    double IleriAtilmaBeklemeSuresi;
private:
    int SuperHasar = 1300;
    string SuperMenzil;
    int SuperHasarBasinaIyilesme = 500; // %125
    int KomboCarki = 1200;
    
public:
    // Inherited via Aksesuar
    virtual void Aksesuar1() override
    {
        cout <<"Kombo Carki" << "Mortis kuregini dondurmeye baslar ve etrafindaki tum dusmanlara 1300 hasar verir";
    }

    virtual void Aksesuar2() override
    {
        cout << "Mortisin saldirisi 4 saniyeligine daha hizli dolar";
    }

    // Inherited via YildizGucu
    virtual void YildizGucu1() override
    {
        cout << "Mortis uzun mesafeli saldirisina 2 saniye erken gecer";
    }

    virtual void YildizGucu2() override
    {
        cout << "Mortis yendigi savascilarin ruhunu toplar ve sagligini 1000 arttirir";
        Saglik += 1000;
    }

    void ExstraIstatistikler() {
        cout << "\n";
        cout << "\t\tSUPER HASAR: " << "\t" << SuperHasar << "\tSUPER MENZIL: " << SuperMenzil << "\tHASAR BASINA IYILESME: " << SuperHasarBasinaIyilesme;
        cout << "\n\n====================================================================================\n";
    }

    virtual void Saldiri() override
    {
        cout << "KUREK DARBESI: "<<"Mortis ileri atilip bir kürek darbesi indirir, girisimci ruhuyla kendine is firsatlari yaratir.";
    }

    virtual void SuperSaldiri() override
    {
        cout << "Mortis, dusman savascilarin sagligini emip kendi sagligini arttiran bir vampir yarasa surusu cagirir. Tuyler urpertici!";
    }

    virtual string SavasciAdi() override {

        return "Mortis";
    }
};

class Penny :public Savasci,public Aksesuar, public YildizGucu {
protected:
    int TopSagligi = 4060;
    int TopHasari = 1740;
    string TopMenzili = "COK UZUN";
    // Inherited via Savasci
    virtual void Saldiri() override
    {
        cout << "Altin mermi... " << "Penny, bir altin kesesi atesler.Kese bir dusmana carparsa patlar ve icindeki altinlar arkadaki dusmanlara sacilir";
        
    }
    virtual void SuperSaldiri() override
    {
        cout << "Yasli topcu..." << "Penny topunu yerlestirir! Bu top uzun menzilde dusmanlara vurabilir, siper almis olsalar bile";
    }
public:
    // Inherited via Aksesuar
    virtual void Aksesuar1() override
    {
        cout << "Uzaktan patlatici... " << "Penny topunu patlatir. Bu patlama duvarlari parcalar ve yakindaki dusmanlara 1500 hasar verir.";
    }

    virtual void Aksesuar2() override
    {
        cout << "Kaptanin pusulasi... " << "Penny, bulundugu konuma bir top atisi yaptirir.";
    }

    // Inherited via YildizGucu
    virtual void YildizGucu1() override
    {
        cout << "Son patlatan... " << "Penny'nin topu yok edildigi anda yakinindaki dusmanlara 4 bombaylar son bir atis yapar. Herbir atis 1680 hasar verir.";
    }

    virtual void YildizGucu2() override
    {
        cout << "Ates toplari... " << "Penny'nin tareti vurdugu yerleri uc saniye yakar. Yanan herbir alan dusmana saniyede 400 hasar verir.";
    }

    // Inherited via Savasci
    virtual void ExstraIstatistikler() override
    {
        cout << "\n";
        cout << "\t\tTOP SAGLIGI: " << "\t" << TopSagligi << "\tTOP HASARI: " << TopHasari << "\tTOP MENZILI: " << TopMenzili;
        cout << "\n\n====================================================================================\n";
    }

    // Inherited via Savasci
    virtual string SavasciAdi() override
    {
        return "Penny";
    }
};
class Eve :public Savasci {

};
class Leon :public Savasci {

};
class ElPrimo :public Savasci {

};
class Poco :public Savasci {

};
class Rosa :public Savasci {

};
class Nita :public Savasci {

};
class Barley :public Savasci {

};
class Frank :public Savasci {

};
class Piper :public Savasci {

};
class Bibi :public Savasci {

};
class Bea :public Savasci {

};
class Edgar :public Savasci {

};
class Grom :public Savasci {

};
class Tara :public Savasci {

};
class Max :public Savasci {

};
class Spike :public Savasci {

};
class Byron :public Savasci {

};
class Amber :public Savasci {

};
class Lou :public Savasci {

};
class Buzz :public Savasci {

};
class Ash :public Savasci {

};
class Fang :public Savasci {

};

class Etkinlik {
public:
    string EtkinlilkIsmi="";
    virtual void EtkinlikBilgisi() = 0;

};

class KupaEtkinlik:public Etkinlik {

};

class OzelEtkinlik :public Etkinlik {

};

class RobotIsgali:public OzelEtkinlik {
public:
    virtual void EtkinlikBilgisi() override {
        cout << "Kasayi robotlardan koruma gorevi...";
    }
};

class ElmasKapmaca :public KupaEtkinlik {
    // Inherited via KupaEtkinlik
    virtual void EtkinlikBilgisi() override
    {
        cout << "\t3e 3luk bir Elmas toplama savasi...";
    }
};

class SavasTopu :public KupaEtkinlik {
    // Inherited via KupaEtkinlik
    virtual void EtkinlikBilgisi() override
    {
        cout << "\t3e 3luk bir Futbol maci...Topu rakip takimin kalesine ulastirip gol at...";
    }
};

class OdulAvi :public KupaEtkinlik {
    // Inherited via KupaEtkinlik
    virtual void EtkinlikBilgisi() override
    {
        cout << "\t3e 3luk bir arena oyunu...Takimin için yildizlari topla...";
    }
};

class Soygun :public KupaEtkinlik {
    // Inherited via KupaEtkinlik
    virtual void EtkinlikBilgisi() override
    {
        cout << "\t3e 3luk bir kasa patlatmaca...";
    }
};

class Hesaplasma :public KupaEtkinlik {
    // Inherited via KupaEtkinlik
    virtual void EtkinlikBilgisi() override
    {
        cout << "\tArenada Hayatta kal...";
    }
};

class OyunYoneticisi {
public:
    
    void SavasciSec(Savasci* savasci) {
        savasci->Istatistikler();
        savasci->ExstraIstatistikler();
        cout << "\n";
        cout << "\n\n\t"<<savasci->SavasciAdi() << " secildi...";
    }
    void EtkinlikSec(Etkinlik* etkinlik) {
        etkinlik->EtkinlikBilgisi();
    }
};

// Method bildirimleri
void GirisMenu();
void OyunMenuPrint();
void SavasciMenuPrint();
void EtkinlikMenuPrint();
void AkisDurdur();


int main()
{
    // SAVASCI ORNEKLERI
    Mortis mortis;
    Penny penny;

    // ETKINLIK ORNEKLERI
    Soygun soygun;
    ElmasKapmaca elmasKapmaca;
    SavasTopu savasTopu;
    Hesaplasma hesaplasma;
    cout << "\n\n";

    char ch;
    char secim;
    OyunYoneticisi oyunYoneticisi;
    Savasci* savasci;
    Etkinlik* etkinlik;

    savasci = 0;
    etkinlik = 0;

    GirisMenu();
    while(true) {

        system("cls");

        OyunMenuPrint();

        cin >> ch;

        system("cls");

        if (ch == '1') {
            // -------------------------------SAVASCI BOLUMU BASLANGICI
            system("cls");

            SavasciMenuPrint();

            cin >> secim;

            system("cls");

            if (secim == '1') {
                cout << "\tSavasci seciliyor...";
                savasci = &mortis;
                oyunYoneticisi.SavasciSec(savasci);
                AkisDurdur();
            }
            else if (secim == '2') {
                cout << "\tSavasci seciliyor...";
                savasci = &penny;
                oyunYoneticisi.SavasciSec(savasci);
                cout << "Penny Secildi...";
                AkisDurdur();
            }
            // -------------------------------SAVASCI BOLUMU BITISI
        }
        else if (ch == '2') {
            // -------------------------------ETKINLIK BOLUMU BASLANGICI
            system("cls");

            EtkinlikMenuPrint();

            cin >> secim;
            if (secim == '1') {
                cout << "Soygun Etkinligi seciliyor...";
                etkinlik = &soygun;
                oyunYoneticisi.EtkinlikSec(&soygun);
                AkisDurdur();
            }
            else if (secim == '2') {
                cout << "Elmas kapmaca etkinligi seciliyor...";
                etkinlik = &elmasKapmaca;
                oyunYoneticisi.EtkinlikSec(&elmasKapmaca);
                AkisDurdur();
            }
            else if (secim == '3') {
                cout << "Savas topu etkinligi seciliyor...";
                etkinlik = &savasTopu;
                oyunYoneticisi.EtkinlikSec(&savasTopu);
                AkisDurdur();
            }
            else if (secim == '4') {
                cout << "Hesaplasma etkinligi seciliyor...";
                etkinlik = &hesaplasma;
                oyunYoneticisi.EtkinlikSec(&hesaplasma);
                AkisDurdur();
            }
            else {
                cout << "Yanlis bir karakter girdiniz...Lutfen yukaridaki seceneklerden birinin numarasini giriniz...";
            }
            // ----------------------ETKINLIK BOLUMU BITISI
        }
        else if (ch == '3') {
            // -------------------------------BRAWL BOLUMU BASLANGICI
            system("cls");

            if (savasci == 0) {
                cout << "\n\tHerhangi bir savasci secmediniz...Lutfen savasci sectikten sonra oyunu baslatin.";
            }
            else if (etkinlik == 0) {
                cout << "\n\tHerhangi bir etkinlik secmediniz...Lutfen bir etkinlik sectikten sonra oyunu baslatin.";
            }
            else {
                cout << "\n\n\tOyun baslatiliyor...\n";
                savasci->Saldiri();
                cout << "\n\nSuper saldiri yapiliyor...\n\n";
                AkisDurdur();
                savasci->SuperSaldiri();
                cout <<"\n\n" << savasci->SavasciAdi() << " hahahah...\n\n";
                cout << "\n\nSuper ozellik aktiflestiriliyor...";
                AkisDurdur();
                if (savasci == &mortis) {
                    mortis.Aksesuar1();
                }
            }
            AkisDurdur();
            // -------------------------------BRAWL BOLUMU BITISI
        }
        else if (ch == 'q') {
            cout << "Oyundan cikiliyor...";
            break;
        }
        else {
            cout << "Bir hata olustu...Oyundan cikiliyor.";
            break;
        }
    }
    cout << "\n\n";
    cout << "\n\n";
    return 0;
}
void GirisMenu() {
    cout << "====================================================";
    cout << "\n\n\tBRAWLSTARS DEMO";
    cout << "\n";
    cout << "\n\tYAPIMCI : Semih ACAR";
    cout << "\n\tOKUL : KSU MUHENDISLIK FAKULTESI";
    cout << "\n\tDERS : NESNE YONELIMLI PROGRAMLAMA";
    cout << "\n\n====================================================";
    cout <<"\n";
    cout << "Enter tusuna basarak devam ediniz...";
    cin.get();
}
void OyunMenuPrint() {
    cout << "====================================================";
    cout << "\n\n\n\tOYUN ANA MENU";
    cout << "\n\n\t(1). SAVASCI SEC";
    cout << "\n\n\t(2). ETKINLIK SEC";
    cout << "\n\n\t(3). BRAWL";
    cout << "\n\n\t(q). CIKIS YAP";
    cout << "\n\n\n====================================================";
    cout << "\n\n\t LUTFEN ASAGIDAKI TALIMATLARI OKUYUNUZ...";
    cout << "\n\n*** Oyunu oynamak icin once savasci ve etkinlikleri sirayla seciniz...";
    cout << "\n\n*** Daha sonra brawl secenegi ile oyunu baslatiniz...";
    cout << "\n\n*** Sectiginiz numarayi girip Enter tusuna basiniz...";
    cout << "\n\n>";
}
void SavasciMenuPrint() {
    cout << "\n\n\tSAVASCILAR...";
    cout << "\n\n\t(1). MORTIS";
    cout << "\n\n\t(2). PENNY";
    cout << "\n\n\t(3). GALE";
    cout << "\n\n\t(4). SPIKE";
    cout << "\n\n\t(5). CROWN";
    cout << "\n\n\t(6). LEON";
    cout << "\n\n\tSavasci secmek icin numarayi girip Entera basın...";
}
void EtkinlikMenuPrint() {
    cout << "\n\n\t ETKINLIKLER...";
    cout << "\n\n\t(1). SOYGUN";
    cout << "\n\n\t(2). ELMAS KAPMACA";
    cout << "\n\n\t(3). SAVAS TOPU";
    cout << "\n\n\t(4). HESAPLASMA";
    cout << "\n\n\tEtkinlik secmek icin numarayi girip Entera basın...";
}
void AkisDurdur() {
    cin.get();
    cin.ignore();
}