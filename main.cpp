#include <iostream>
#include <cassert>

using namespace std;

int naivePower(int x, int n){
    if (x == 0) {
        return 0;
    }

    if (n == 0) {
        return 1;
    }

    return x * naivePower(x, n - 1);
}

int unoptimizedDCPower(int x, int n) {
    if (x == 0) {
        return 0;
    }
    
    if (n == 0) {
        return 1;
    }

    if (n % 2 == 0){
        return unoptimizedDCPower(x, n / 2) * unoptimizedDCPower(x, n / 2);
    } else {
        return x * unoptimizedDCPower(x, n / 2) * unoptimizedDCPower(x, n / 2);
    }
}

int optimizedDCPower(int x, int n) {
    if (x == 0) {
        return 0;
    }

    if (n == 0) {
        return 1;
    }

    int temp = optimizedDCPower(x, n / 2);

    if (n % 2 == 0) {
        return temp * temp;
    } else {
        return x * temp * temp;
    }
}

int main(){
    assert(naivePower(0,5) == 0);
    assert(naivePower(1,10) == 1);
    assert(naivePower(10,1) == 10);
    assert(naivePower(5,1) == 5);
    assert(naivePower(2, 10) == 1024);
    assert(naivePower(3, 5) == 243);
    assert(naivePower(100, 2) == 10000);
    assert(naivePower(10, 6) == 1000000);
    assert(naivePower(100000, 1) == 100000);

    assert(unoptimizedDCPower(0,5) == 0);
    assert(unoptimizedDCPower(1,10) == 1);
    assert(unoptimizedDCPower(10,1) == 10);
    assert(unoptimizedDCPower(5,1) == 5);
    assert(unoptimizedDCPower(2, 10) == 1024);
    assert(unoptimizedDCPower(3, 5) == 243);
    assert(unoptimizedDCPower(100, 2) == 10000);
    assert(unoptimizedDCPower(10, 6) == 1000000);
    assert(unoptimizedDCPower(100000, 1) == 100000);

    assert(optimizedDCPower(0,5) == 0);
    assert(optimizedDCPower(1,10) == 1);
    assert(optimizedDCPower(10,1) == 10);
    assert(optimizedDCPower(5,1) == 5);
    assert(optimizedDCPower(2, 10) == 1024);
    assert(optimizedDCPower(3, 5) == 243);
    assert(optimizedDCPower(100, 2) == 10000);
    assert(optimizedDCPower(10, 6) == 1000000);
    assert(optimizedDCPower(100000, 1) == 100000);

    cout << "All of the test have passed! Congrats!" << endl;
    return 0;
}