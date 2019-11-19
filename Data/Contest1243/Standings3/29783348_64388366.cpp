/*
nītor (present infinitive nītī, perfect active nīsus sum or nīxus sum); third conjugation, deponent
  I bear or rest upon something, lean on; I am supported by; I am based on.
  I press forward, advance.
  I mount, climb, ascend; fly.
*/
#include <bits/stdc++.h>
using namespace std;
mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
#define ll long long
#define INF 0x3f3f3f3f
#define pb push_back
#define F first
#define S second
#define fastcin ios::sync_with_stdio(false); cin.tie(NULL);

int main(){
    ll i, n;
    cin >> n;
    for (i=2; i*i<=n; i++){
        if (n%i==0){
            while(n%i==0) n/=i;
            if (n==1) {
                cout << i << endl;
            }
            else {
                cout << 1 << endl;
            }
            return 0;
        }
    }
    cout << n << endl;
}
