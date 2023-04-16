
// & tanımlandığı adresi döndürür.
// *p dereferencing
// hex
// least significant byte
// most significant byte
// floatingpointerror
// linkedlist örnek

#include <iostream>
using namespace std;

struct eleman {
    int data; // elemanda saklanacak olan verinin tutulduğu değişkendir
    eleman* next; //: elemanın bağlı listedeki bir sonraki elemanın adresini tutan bir pointer
};

eleman* first = nullptr; //  bağlı listenin ilk elemanının adresini tutmak için

void Add(int element) {
    eleman* yenieleman = new eleman;
    yenieleman->data = element;  
    yenieleman->next = nullptr;   
    if (first == nullptr) { // Eğer bağlı liste boş ise,
        first = yenieleman;  // "first" değişkeni, yeni eleamın adresiyle güncellenir.
       
    }
    else {
        cout << first->data << " ";
        eleman* temp = first; 
        while (temp->next != nullptr) {   
            temp = temp->next;
        }
        temp->next = yenieleman; 
    }
    cout << element<< " Elemani listeye eklendi "<<endl;
}

int GetAllList() {
    int count=0;
    if (first == nullptr) {
        cout << "Liste Bos." << endl;
    }
    else {
        eleman* temp = first;  
        while (temp != nullptr) { 
            cout << temp->data << " ";  
            temp = temp->next; // Geçici işaretçi, bir sonraki düğümün adresine atanır.
            count++;
        }
        cout << endl;
    }
    return count;
}
void Insert(int element, int index) {
    eleman* yenieleman = new eleman; 
    yenieleman->data = element; 
    yenieleman->next = nullptr; //  Yeni elamanın next pointerı önceki elemandan sonraki elemanın adresini işaret etmek için nullptr olarak atanır.

    if (first == nullptr) {  // Eğer listenin başı nullptr ise, yani liste boşsa, yeni eleman listeye baş olarak eklenir
        first = yenieleman;
        
    }
    else if (index == 0) {  // : Eğer index 0 ise, yani yeni bağlı listenin başına eklenecekse, yeni eleman listenin başı yapılır 
        yenieleman->next = first;
        first = yenieleman;
    }
    else { 
        eleman* temp = first;  // : Listenin başından başlayarak, geçici bir pointer  tanımlanır ve listenin ilk elemanını işaret eder.
        for (int i = 0; i < index - 1 && temp->next != nullptr; i++) {  // Döngü, yeni eleman ekleneceği konuma kadar veya son elemana ulaşana kadar temp işaretçisi ile liste üzerinde gezinir.
            temp = temp->next;
        }
        yenieleman->next = temp->next;  //  Yeni eleman, temp işaretçisinin gösterdiği elemanın next işaretçisine bağlanır.
        temp->next = yenieleman;    // temp işaretçisinin gösterdiği elemanın next işaretçisi, yeni elemanın adresine atanarak yeni elemanın, listenin belirtilen konumuna eklenir.
    }
    cout << element<< " elemani " << index << " indexe eklendi"<< endl;
}

int Find_index(eleman* baslangic, int x) { 

    int index = 0;
    eleman* current = baslangic; // Bu satır, current  eleman pointerı tanımlar ve listenin ilk elemanı ile (first)eşitlenir. Bu, fonksiyonun geçerli elemandan başlaması için gereklidir.
    while (current != NULL) { 
        if (current->data == x) { 
            return index; 
        }
        index++;
        current = current->next; //  Bu satır, current işaretçisini bir sonraki elemana taşır. Bu, döngünün sonraki elemana geçmesini sağlar.
    }
    return -1; // eleman bulunamadıysa -1 döndürür
}

void Delete(int index) {
    
    if (first == nullptr) { // : Eğer bağlı liste boşsa (yani başlangıç eleman nullptr ise), ekrana "Liste Bos." yazdırılır.
        cout << "Liste Bos." << endl;
    } 
    else if (index == 0) { 
        eleman* temp = first; //  Geçici bir eleman pointerı oluşturulur ve bağlı listenin ilk elemanına atanır.
        first = first->next; //  Başlangıç elemanın, bir sonraki elemanın adresi atanır atanır.
        //first = first->next satırı, bağlı listenin ilk elemanını silmek için gereklidir
        // . Bu satırı çıkardığınızda, first düğümünün gösterdiği elemanı başka bir yere kaydırmadan ilk elemanı siliyorsunuz. Bu durumda, bağlı listenin ilk elemanını silmeye çalıştığınızda hala ilk elemanı gösteren bir referansınız var,
        //  ancak bu düğüm artık bellekte yok, bu nedenle Segmentation fault hatası .
        cout << temp->data<<" Eleman Silindi" <<std::endl;
        delete temp; //  düğümü bellekten silinir.
    }
    else { 
        eleman* temp = first; //  Geçici bir eleman pointerı oluşturulur ve bağlı listenin ilk elemanına atanır.
        eleman* prev = nullptr; //  Önceki eleman nullptr olarak tanımlanır. Bu, başlangıçta silinecek elemanın bağlı listenin başındaki bir eleman olması durumunda, önceki düğümün işaret edeceği hiçbir şey olmadığı anlamına gelir.
        
         //Segmentation fault hatası . iGetAllList(); index return edilip silinmesi gereken indexle bir logic yapıldı.
        int counter= GetAllList();
        if (counter<index)
        {
            //Segmentation fault hatası .
            cout <<"Seçilen index listenin boyutunu aşiyor..."<< endl;
            return;
        }
        
        for (int i = 0; i < index && temp->next != nullptr; i++) {
            // temp düğümünden index sayısı kadar ileri gidilir ve prev düğümü de bu sırada güncellenir.
            //Eğer temp düğümü nullptr olursa (yani index geçersizdir), "Gecersiz Indeks" mesajı ekrana yazdırılır.
            cout << i+temp->data << endl;
            cout << temp->next << endl;
            prev = temp;
            temp = temp->next; //: bağlı listedeki bir sonraki elemanın adresi. 
        } 
        if (temp == nullptr) {
            cout << "Gecersiz Indeks" << endl;
        }
        else {
            cout << "prev.next"<<prev->next<< endl;
            cout <<"temp.next"<<temp->next << endl;
            prev->next = temp->next; //: seçilen indexin adresini sıfıra yani nullptr yapıyoruz Eğer prev->next değeri nullptr yapılmazsa, prev->next hala silinen elemanın adresini gösterecektir.
            cout << temp->data<<" Eleman Silindi" <<std::endl;
            delete temp;  // delete anahtar kelimesi, C++ programlama dilinde bellek yönetimi için kullanılır. new anahtar kelimesi ile ayrılan dinamik bellek bloklarını geri vermek veya silmek için kullanılır.
        }
    }
    // cout << index << " indexli  Eleman Silindi" << endl;
}

void Charma(){
    int var =8;
    void*ptr=&var;
    std::cout<<ptr;
}

void Increment(int *a){
    *a+=1;
}

void PointerAritmetic(){

    int *dizi= new int[10];
    // for (size_t i = 0; i < 10; i++)
    // {
    //     dizi[i]=i;
    //     std::cout<<dizi[i];

    // }
    for (size_t i = 0; i < 10; i++)
    {
        *(dizi+i)=i+1;  // 0 index 2002 1 2006
        std::cout<<*(dizi+i)<<std::endl;
        std::cout<<dizi[i]<<std::endl;
        std::cout<<(dizi+i)<<std::endl;
    }
    
}
int main() {
    int choice, element,index,find_index;

    while (true) {
        cout << "Ne yapmak istersinzi:" << endl;
        cout << "1- listeye eleman ekleme" << endl;
        cout << "2- listenin tamamini göster" << endl;
        cout << "3- belirtilen idexe eleman ekleme." << endl;
        cout << "4- girilen elemanin bagli listedki indexini bulma : " << endl;
        cout << "5- belirtilen indexteki elemani silme: " << endl;
        cout << "6- cikis." << endl;
        cin >> choice;

        switch (choice) {
            case 1:
                cout<< "Lİsteye eklenicez elemani giriniz : "<<endl;
                cin >> element;
                Add(element);
                break;

            case 2:
                GetAllList();
                break;

            case 3:
                cout << "Lİsteye eklenicez elemani giriniz  : ";
                cin >> element;
                cout << "Hangi indexe eklensin :  ";
                cin >> index;
                Insert(element, index);
                break;

            case 4:
                cout << " elemani giriniz  : ";
                cin >> element;
                find_index=Find_index(first,element);
                if (find_index == -1) {
                    cout << "Eleman bulunamadı." << endl;
                   
                }
                else 
                {
                    cout << "Elemanın indeksi: " << find_index << endl;
                }
                break;
            case 5:
                cout << " indexi giriniz  : ";
                cin >> index;
                Delete(index);
                break;
            case 6:
                cout<< "Güle GÜle : "<<endl;
                exit(0);
                break;
        }
    }

    return 0;
}