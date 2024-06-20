#include <iostream>
using namespace std;

int func_4(int edi, int esi, int edx){
    int eax_return = edx;
    eax_return = eax_return - esi;
    int ecx = eax_return;
    ecx = ecx >> 31;
    ecx = ecx + eax_return;
    eax_return = eax_return >> 1;
    ecx = eax_return + ecx;

//    if (edi <= ecx){

//    }else{
        
//    }
    cout <<"edi:"<< edi << "ecx" << ecx << "eax" << eax_return << "esi" << esi << "edx" << edx;
}

int main(){
    int a, b;
    cin >> a >> b;

    if (a == 0 && b ==0){
        cout << "BOMB!";
    }

    if (!(a < 14)){
        cout << "BOMB!";
    }

    int val1 = 0;
    int va12 = 14;
    func_4(a,val1, va12);
    return 0;
}
