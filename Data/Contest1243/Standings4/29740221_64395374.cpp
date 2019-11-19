// #include<bits/stdc++.h>
#include<iostream>
#include<vector>
#include<unordered_map>
#include<algorithm>
#include<string>
#include<cmath>

#define ll long long

using namespace std;

ll M = 1e9 + 7;
ll N = 1e6;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    ll n;
    cin >> n;
    ll x = n;

    if(n==1){
        cout << 1 << endl;
        return 0;
    }

    vector<bool> isprime(N+1,true);
    isprime[0] = isprime[1] = false;
    ll ctr = 0;

    for(ll i=2; i<=N && i<=n; i++){
        if(isprime[i]){
            
            if(n%i==0){
                ctr++;
                if(ctr==1) x=i;
                while(n%i==0) n /= i;
            }

            for(ll j=2*i; j<=N && j<=n; j+=i){
                isprime[j] = false;
            }
        }
    }

    if(n!=1) ctr++;

    if(ctr==1) cout << x << endl;
    else cout << 1 << endl;

    return 0;
}
