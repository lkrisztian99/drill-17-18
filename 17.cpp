#include "std_lib_facilities.h"

//4. Write a function print_array10(ostream& os, int* a) that prints out the
//values of a (assumed to have ten elements) to os.
void print_array10(ostream& os, int* a){             // 4. feladat kiíratása     // ostream& os ->azért ezt adjuk meg mert így tudunk majd neki kimenetet adni (cout)
    for(int i = 0;i<10;++i){                                // int* a  -> megadjuk hogy számok lesznek int típusuak, 
        os << a[i] << endl;
    }
}
//7. Write a function print_array(ostream& os, int* a, int n) that prints out
//the values of a (assumed to have n elements) to os.
void print_array(ostream& os, int* a, int n){               // kiíratás definiálása ostream= cout    -> int* a -> tömbünk neve   -> megadjuk mennyi elemet iírunk ki a tömbböl
    for(int i = 0;i<n;i++){
        os << a[i] << endl;                                 //kiíratjuk a tömbünk elemeit
    }
}

//10.
int* DynamicArray(int n)                                // mi adjuk meg a tömb méretét
{
	int* a = new int[n];                                // itt hozzuk létre az adott méretű tömböt            
	int counter = 100;                                     /// azért kell mert 100-tól indítjuk a számoakt amik bele mennek a tömbbe pl i[0]=100, i[1]=101 etc..
	for (int i = 0; i < n; i++)
		a[i] = counter++;                               // feltöltjük a tömbünket n- elemmel a mit megadtunk neki(8-s feladat)

	return a;
}
//10.
vector<int*> DynamicVector(int n){          // függvény aminek segítségével mi adjuk meg vektorunk méretét
    vector<int*> asd;                   //itt hozzuk létre a vektort
    int counter = 100;                      // 100-tól kérjük a vektorunkba a számokat...
    int szam1=0;
    for(int i = 0; i < n; i++)                  //belepakoljuk a vektorba az adott mennyiségű számot (amit mi adtunk meg)
        
        
        asd.push_back(new int {counter++ });             //ez a konkrét vektorba pakolás
    return asd;
}
//10.
void print_vector(vector<int*> vec){                        
    for(int i = 0; i < vec.size();i++){                         //kiíratjuk a vektorunk elemeit
        cout << *vec[i] << endl;                            // azért *vec[i] mert így a számot nem a memória értékét írja ki
    }   
}
//10.
void TorolVektor(vector<int*> vec){                         // kitöröljük a vektorunk összes elemét
    for(int i = 0;i<vec.size();i++){
        delete vec[i];
    }
}

int main(){
    //1. Allocate an array of ten ints on the free store using new.
    int* alloc = new int[10];                         //lefoglalunk 10 intméretü memóriát 
    //2. Print the values of the ten ints to cout.
    cout << "Feladat 2." << endl;                       //végigmegyünk a tömbön és kiíratjuk az értékeit
    for(int i = 0; i<10; ++i){
        cout << alloc[i] << endl;
    }
    //3. Deallocate the array (using delete[]).
    delete[] alloc;                                     //felszabadítja a memóriát amit ezelőtt lefoglaltunk
    //4. Write a function print_array10(ostream& os, int* a) that prints out the
    //values of a (assumed to have ten elements) to os.
    cout << "Feladat 4." << endl;                       //meghívjuk a fent megírt függvényt
    print_array10(cout, alloc);
    //5. Allocate an array of ten ints on the free store; initialize it with the values
    //100, 101, 102, etc.; and print out its values.
    cout << "Feladat 5." << endl;                                               //lefoglaltuk a 10 memória helyet és meg is adtuk az értékét
    int* alloc2 = new int[10]{100,101,102,103,104,105,106,107,108,109};
    print_array10(cout, alloc2);                                                //meghívtuk ugyan azt a függvényt mint a 4-s feladatnál csak más tömböt(alloc2)adtunk meg neki
    delete[] alloc2;
    //6. Allocate an array of 11 ints on the free store; initialize it with the values
    //100, 101, 102, etc.; and print out its values.
    cout << "Feladat 6." << endl;
    int* alloc3 = new int[11]{100,101,102,103,104,105,106,107,108,109,110};             // itt egy 11-méretü tömb létrehozva számok deklarálva
    print_array10(cout, alloc3);                                                    //kiíratás
    delete[] alloc3;                                                                //memória afelszabadítás
    //8. Allocate an array of 20 ints on the free store; initialize it with the values
    //100, 101, 102, etc.; and print out its values.
    cout << "Feladat 8." << endl;                                           
    int* allocFor20 = DynamicArray(20);                                 //létrehozzuk az adott méretű tömbünket
    print_array(cout,allocFor20,20);                                    //kiíratjuk a tömbünk elmeit
    delete[] allocFor20;                                                
    //10. Do 5, 6, and 8 using a vector instead of an array and a print_vector() instead of print_array()
    cout << "Feladat 10. - 10" << endl;
    vector<int*> vectorFor10 = DynamicVector(20);               //megadjunk a vektorunk méretét és elemeinek számát
    print_vector(vectorFor10);                      //kiírjok a vektorunk tartalmát
    TorolVektor(vectorFor10);
    cout << "Feladat 10. - 11" << endl;
    vector<int*> vectorFor11 = DynamicVector(10);
    print_vector(vectorFor11);
    TorolVektor(vectorFor11);
    cout << "Feladat 10. - 20" << endl;
    vector<int*> vectorFor20 = DynamicVector(16);
    print_vector(vectorFor20);
    TorolVektor(vectorFor20);
    
    return 0;
}