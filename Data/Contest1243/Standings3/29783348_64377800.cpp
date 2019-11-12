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
    int k, n, i, a;
    vector<int> v;
    cin >> k;
    while(k--){
        cin >> n;
        v.clear();
        for (i=0; i<n; i++){
            cin >> a;
            v.pb(a);
        }
        sort(v.rbegin(), v.rend());
        i=0;
        while(i+1<n && v[i+1]>=i+2){
            //printf("v[i+1] is %d and n-(i+1) is %d\n", v[i+1], n-(i+1));
            i++;
        }
        cout << i+1 << endl;
    }
}
