#include "std_lib_facilities.h"

void print_array(ostream& os, int* a, int n){           //kiíratjuk a tömnböt kiíratás típusa, tömb neve, mennyi elemet a tömbből
    for(int i = 0;i<n;++i){
        os << a[i] << endl;
        }
    }


    void print_vector(vector<int> vec){
        for(int i=0;i< vec.size();i++){
            cout << vec[i] << " ";
        }
    }

int main(){
    //1
    int x = 7;              // x váéltozó egy értékkel
    int* p1 = &x;     //egy memória címnek megadjuk az x értékét    & ->ez a jel utal az x értékére
    //2
    cout << "Feladat 1. " << endl;
    cout << p1 << " " << x << endl;         //kiíratjuk a memória helyét és az ott tárol értéket
    //3
    int intS[7] = {1,2,4,8,16,32,64};           // létrehozunk egy 7 elemű tömböt 
    int* p2 = intS;             // a p2 memória helyen eltároljuk az egész intS tömbünk összes elemét
    //4
    cout << endl;   
    cout << "Feladat 4. " << endl;
    print_array(cout,p2,7);             // kiíratjuk a p2 memória helyen lefoglalt tömbünk 7db elemét
    //5 
    int* p3 = p2;   
    print_array(cout,p3,7)         ;       // p3 ugyan azt a memória helyet veszi fel mint p2 -> ezáltal ugyan azon értékeket fogja tárolni mint p2
    //6
    p1 = p2;                    // p1-én egyenlővé teszük a p2-bel
    //7
    p3 = p2;                        // p3-nak átadjuk a p2 memóriába tárol értékeit
   
    //8
    cout << endl;
    cout << "Feladat 8. " << endl;
    cout << "P1: " << p1 << endl;           //kiírjuk a p1 és p2 memória helyét (mivel a 26 sorba egyenlővé tettük így ugyan az)
    cout << "P2: " << p2 << endl;
    //9 valgrind szerint nem volt felszabadítatlan memoria terület
    //10
    cout << endl;
    int arrayFor10 [10] = {1,2,4,8,16,32,64,128,256,512};                   //leztrehozunk 2 tömböt 10 értékkel és eltároljuk egy mámória foglalatba
    p1 = arrayFor10;
    //11 
    int arrayFor10v2 [10] = {10,20,40,80,160,320,1280,2560,5120};
    p2 = arrayFor10v2;
    //12
    for(int i = 0; i < 10; ++i){                    //p2 memória foglaltból átmásoljuk p1 memóriájába az értékekekt
        p1[i] = p2[i];
    }

    //13
    vector<int> v_tenInts{ 1,2,4,8,16,32,64,128,256,512 };
	p1 = &v_tenInts[0];
	vector<int> v_tenInts2{ 10,20,40,80,160,320,640,1280,2560,5120 };
	p2 = &v_tenInts2[0]; // &-jellel konkrét értéket ad át
	for (int i = 0; i < 10; ++i)
		p2[i] = p1[i];


    print_vector(v_tenInts2);
    return 0;
}