#include <iostream>
using namespace std;

int func(int a, int b, int n) {
    int result = n - b;  // Corresponds to sub %esi,%eax when esi=0 initially
    result >>= 1;        // Corresponds to sar %eax

    if (a <= result) {
        return 0;
    } else if (a > result) {
        return 2 * func(a, result + 1, n); // Recursively calls itself with adjusted parameters
    }
    return result;
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
