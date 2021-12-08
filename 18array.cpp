#include "std_lib_facilities.h"

//első feladat 
//Define a global int array ga of ten ints 
//initialized to 1, 2, 4, 8, 16, etc.
int ga[10] = {1,2,4,8,16,32,64,128,256,512};
//2,3 feladat
//2. Define a function f() taking an int array argument and an int argument
/*indicating the number of elements in the array.
3. In f():
a. Define a local int array la of ten ints.
b. Copy the values from ga into la.
c. Print out the elements of la.
d. Define a pointer p to int and initialize it with an array allocated on
the free store with the same number of elements as the argument array.
e. Copy the values from the argument array into the free-store array.
f. Print out the elements of the free-store array.
g. Deallocate the free-store array.*/
void f(int arrArg[], int NumberOfEl){
    //a
    int la[10];
    //b
    for(int i = 0; i < NumberOfEl; ++i)
    {
        la[i] = ga[i];
    }
    //c
    for(int i = 0; i < NumberOfEl; ++i)
    {
        cout << la[i] << ", ";
    }
    cout << endl;
    //d
    int* p = new int(NumberOfEl);   //lefoglalunk egy akkora memóriát amekkor a tömbünk mérete
    //e
    memcpy(p,arrArg,100*sizeof(int)); //memcpy beépített függvény ami annyit tesz hogy belerakja a legoflalt mermóriába a tömbünk elemeit     
    //f
    for(int i = 0; i < NumberOfEl; ++i){        //kiírjuk a p memóriába erltárol elemeket , addig megy a for amennyi elemet megadtunk
       cout << p[i] << ", ";
    }
    delete[] p;                         // felszabadítjuk a p által lefoglalt memóriát
}


int main(){
   // f(ga,10);
    int aa[10] = {};
    int c = 1;
    for(int i = 1; i<=10;i++){
        c = c*i;
        aa[i-1] = c;
    
       
    }
    f(aa,10);
    return 0;
}