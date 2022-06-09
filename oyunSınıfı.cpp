
#include <iostream>
#include <string>
class Oyun {
private:
    int OyunFiyati = 0;
    int OyunSayisi = 0;
public:
    virtual void OyunBilgisi() = 0;
    virtual int GetOyunSayisi() {
        return OyunSayisi;
    }
    friend class MobilOyun;
    friend class MasaustuOyun;
};


class MobilOyun :public Oyun {

public:
    MobilOyun() {
        this->OyunSayisi += 1;
    }
    virtual void OyunBilgisi() override
    {
        std::cout << "Mobil oyun..." << std::endl;
    }
    virtual void PlatformVarmi(std::string p) {
        try
        {
            if (p == "android" or p == "ios") {
                std::cout << "bu platformda calisiyor..." << std::endl;
            }
            else {
                throw "Böyle bir mobil platform yok";
            }
        }
        catch (const char* ch)
        {
            std::cerr << ch;
        }
    }
    
};

class MasaustuOyun : public Oyun {
public:
    MasaustuOyun() {
        this->OyunSayisi += 1;
    }
    virtual void OyunBilgisi() override
    {
        std::cout << "Masaustu oyun..." << std::endl;
    }

};


class Candy :public MobilOyun {
private:
    std::string OyunIsmi = "Candy";
public:
    void IsimYazdir() {
        std::cout << OyunIsmi;
    }
};

class Pokemon :public MobilOyun {
private:
    std::string OyunIsmi = "Pokemon";
public:
    void IsimYazdir() {
        std::cout << OyunIsmi;
    }
};
class Fifa21 :public MasaustuOyun {
private:
    std::string OyunIsmi = "Fifa21";
public:
    void IsimYazdir() {
        std::cout << OyunIsmi;
    }
};
class Pes21 :public MasaustuOyun {
private:
    std::string OyunIsmi = "Pes21";
public:
    void IsimYazdir() {
        std::cout << OyunIsmi;
    }
};


int main()
{
    Candy candy;
    candy.IsimYazdir();
    candy.OyunBilgisi();
    candy.PlatformVarmi("android");
    std::cout << candy.GetOyunSayisi() << std::endl;
    std::cout << "\n\n" << std::endl;
    
    Pokemon pokemon;
    pokemon.IsimYazdir();
    pokemon.OyunBilgisi();
    pokemon.PlatformVarmi("telefon");
    std::cout << candy.GetOyunSayisi() << std::endl;
}

