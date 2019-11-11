#include<iostream>
using namespace std;

long gcd(long a, long b) {
    while(b) {
        long c = a%b;
        a = b;
        b = c;
    }
    return a;
}

int main() {
    ios_base::sync_with_stdio(false);
    int tests; cin >> tests;
    
    int A, B;
    while(cin >> A >> B) {
        cout << (gcd(A, B) == 1 ? "Finite" : "Infinite") << endl;    
    }
}