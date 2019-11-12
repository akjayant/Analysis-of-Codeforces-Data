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
    int k; cin >> k;
    string s, t, ss, tt;
    int n = s.size(), i, ct=0;
    int freq[10005];
    while(k--){
        memset(freq, 0, 10005);
        ct=0; ss=""; tt="";
        cin >> n >> s >> t;
        for (i=0; i<n; i++) if (s[i]!=t[i]) ct++;
        if (ct==0){
            cout << "Yes" << endl;
            continue;
        }
        if (ct!=2){
            cout << "No" << endl;
            continue;
        }
        for (i=0; i<n; i++) if (s[i]!=t[i]){
            ss+=s[i];
            tt+=t[i];
        }
        if (ss[0]==ss[1] && tt[1]==tt[0]) {
            cout << "Yes" << endl;
            continue;
        }
        else{
            cout << "No" << endl;
            continue;
        }
    }
}
