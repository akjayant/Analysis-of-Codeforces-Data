#include<bits/stdc++.h>

using namespace std;

#define NMAX 100005

const long long MOD = 1000000007;

int main() {
    long long fib [NMAX];
    fib[0] = fib[1] = 1;
    for(int i = 2; i < NMAX; i++) {
        fib[i] = fib[i-1]+fib[i-2];
        fib[i] %= MOD;
    }
    string s;
    cin>>s;
    int n = s.length();
    int seguidas = (s[0] == 'n' or s[0] == 'u');
    long long sol = 1;
    
    for(int i = 0; i < n; i++)
        if(s[i] == 'm' or s[i] =='w') {
            cout<<0<<endl;
            return 0;
        }
    for(int i = 1; i < n; i++) {
        if(s[i] != s[i-1]) {
            sol *= fib[seguidas];
            sol %= MOD;
            seguidas = 0;
        }
        if(s[i] == 'u' and s[i-1] == 'u') {
            seguidas++;
        } else if(s[i] == 'n' and s[i-1] == 'n') {
            seguidas++;
        } else if(s[i] == 'u') {
            seguidas = 1;
        } else if(s[i] == 'n') {
            seguidas = 1;
        }

        //cerr<<i<<' '<<s[i]<<": "<<seguidas<<endl;
    }
    sol *= fib[seguidas];
    sol %= MOD;
    cout<<sol<<endl;
}