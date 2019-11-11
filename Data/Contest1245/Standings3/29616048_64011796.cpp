#include<iostream>
#include<string>
#include<cstring>
#include<cmath>
using namespace std;

long long T[100101];

int main() {
    ios_base::sync_with_stdio(false);
//    int tests; cin >> tests;
    
    string s;
    while(cin >> s) {
        T[0] = 1;
        for(int i=1; i<=s.size(); i++) {
            if (s[i-1] == 'm' || s[i-1] == 'w') {
                T[i] = 0;
            } else if (i >= 2 && (s[i-1] == 'u' && s[i-2] == 'u' || s[i-1] == 'n' && s[i-2] == 'n')) {
                T[i] = (T[i-1] + T[i-2]) % 1000000007;
            } else {
                T[i] = T[i-1];
            }
        }
        cout << T[s.size()] << endl;
    }
}