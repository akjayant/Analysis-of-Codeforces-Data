#include <bits/stdc++.h>

using namespace std;

const int mod = 1e9+7;

long long exp(long long b, long long p){

    long long resp = 1;

    b = b % mod;

    while(p > 0){
        if(p & 1){
            resp = (resp * b)%mod;
        }
        p = p >> 1;
        b = (b * b)%mod;
    }

    return resp;
}

int main(){
    ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);

    long long n, m;

    cin >> n >> m;

    cout << exp(((exp(2, m)-1+mod)%mod), n) << endl;

    return 0;
}
