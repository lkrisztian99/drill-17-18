#include "std_lib_facilities.h"

vector<int> gv = {1,2,4,8,16,32,64,128,254,512};

void f(vector<int> arg){
     vector<int> lv(10);
    lv = arg;
   
    for(int i: lv)
        cout << i << ", ";
    cout << endl;
    
    vector<int> lv2 = arg;
    for(int i : lv2)
        cout << i << ", ";

}

int main(){
    f(gv);
    cout << endl;
    vector<int> vv;
    int c = 1;
    for(int i = 1; i <= 10; i++){
        vv.push_back(c*=i);
    }
    f(vv);


    return 0;
}