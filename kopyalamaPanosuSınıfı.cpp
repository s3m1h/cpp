#include <iostream>
#include <string.h>
#include <stdlib.h>
#include <list>

using namespace std;

class KopyalamaPanosu{
    private:
        int count = 0;
        list<string> PanoListesi;
        
    public:
        int KopyalamaSayisi();
        list<string> Pano();
};

class GelismisKopyalamaPanosu:public KopyalamaPanosu{
    private:
        list<string> Favoriler;
        int BildirimSayisiGorevCubugu;
        int BildirimSayisiMasaustu;
    public:
        list<string> Favorilerim();
        void TarayiciYerimlerineKaydet();
        void MasaustuBildirimi();
        void GorevCubuguSimgeBildirimi();
};

list<string> KopyalamaPanosu::Pano(){
    count +=1;
    return PanoListesi;
}
int KopyalamaPanosu::KopyalamaSayisi()
{
    return count;
}

void GelismisKopyalamaPanosu::GorevCubuguSimgeBildirimi(){
    cout<<"\n\n\tKopyalanan veri panoya Eklendi..";
}
void GelismisKopyalamaPanosu::MasaustuBildirimi(){
    cout<<"\n\n\tKopyalanan veri panoya Eklendi..";
}
void GelismisKopyalamaPanosu::TarayiciYerimlerineKaydet(){
    cout<<"\n\n\tVarsayilan olarak kullanılan tarayıcının yerimlerine kaydedildi.";
}
list<string> GelismisKopyalamaPanosu::Favorilerim(){
    return Favoriler;
}
        void Giris();
        void Ayarlar();
        void PanoListele();
        void PanoyaEkle(string data);
        void PanoTemizle();
        void FavorilerimeEkle(string data);


int main(){
    char giris, menuNo;
    int num;
    string data;
    GelismisKopyalamaPanosu kopyalamaPanosu;
    cout<<"\n\n\t\t 1. Giris";
    cout<<"\n\n\t\t 2. Ayarlar";
    cout<<"\n\n\t\t q. Cikis";
    cin>>giris;
    if(giris =='1'){
        while(true)
        {
            Giris();
            cin>>menuNo;
            if(menuNo =='1'){
                cout<<"\n\n\tKopyalanan veriyi giriniz: "; cin>>data;
                PanoyaEkle(data);
                cout<<"\n\n\tVeriyi favorilere eklemek ister misin?\n\n\t Evet icin (1) Hayır icin (0)";

                cin>>num;
                if(num==1){
                    FavorilerimeEkle(data);
                }
                if(num==0){
                    continue;
                }
            }
            else if(menuNo =='2'){
                PanoTemizle();
                cout<<"\n\n\tIslem basarili...";
                cout<<"\n\n\tDevam etmek icin entera basin... \n";
                cin.ignore();
                cin.get();
            }
            else if(menuNo =='3'){
                PanoListele();
                cout<<"\n\n\tDevam etmek icin entera basin... \n";
                cin.ignore();
                cin.get();
            }
            else if(menuNo =='q'){
                break;
            }
            else{
                cout<<"Beklenmeyen bir hata olustu. Programdan cikiliyor...";
                break;
            }
        }
        
    }
    else if(giris =='q'){
        cout<<"\n\n\tCikis yapildi...";
    }
    return 0;

}
void Giris()
{
    cout<<"\t <<<<---------------------------------->>>>";
	cout<<"\n\n\t\tKopyalama Panosu";
	cout<<"\n\n\t\t 1. Panoya Ekle";
    cout<<"\n\n\t\t 2. Panoyu Temizle";
    cout<<"\n\n\t\t 3. Panoyu Listele";
    cout<<"\n\n\t\t 4. Ayarlar";
    cout<<"\n\n\t\t 0. Cikis";
    cout<<"\n\n\n\t<<<<---------------------------------->>>>";
}

void Ayarlar(){
    cout<<"\n\n\t\t 1. Simge bildirimi olarak ayarla";
    cout<<"\n\n\t\t 2. Masaüstü Bildirimi olarak ayarla";
    cout<<"\n\n\t\t 3. Varsayılan bildirim ayarı";
}
void FavorilerimeEkle(string data){
    GelismisKopyalamaPanosu pano;
    pano.Favorilerim().push_back(data);
}
void PanoyaEkle(string data){
    KopyalamaPanosu pano;
    pano.Pano().push_back(data);
}
void PanoTemizle(){
    KopyalamaPanosu pano;
    pano.Pano().clear();
}
void PanoListele(){
    KopyalamaPanosu pano;
    for (auto itr = pano.Pano().begin(); itr != pano.Pano().end(); itr++)
        cout << *itr <<"\n";
}