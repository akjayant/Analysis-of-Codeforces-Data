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
#define MAX 100005

int ct[26];

int main(){
    vector<pair<int, int>> moves;
    int k, n, flag, i, j, wind;
    string s, t;
    cin >> k;
    while(k--){
        memset(ct, 0, 26*sizeof(int));
        moves.clear();
        flag=0;
        cin >> n >> s >> t;
        for (i=0; i<n; i++){
            if (s[i]!=t[i]){
                ct[s[i]-'a']++; ct[t[i]-'a']++;
            }
        }
        for (i=0; i<26; i++){
            if (ct[i]%2!=0){
                cout << "No\n";
                flag=1;
                break;
            }
        }
        if (flag) continue;
        for (i=n-1; i>=0; i--){
            if (s[i]!=t[i]){
                wind=i;
                break;
            }
            if (i==0){
                cout << "Yes\n0\n";
                flag=1;
                break;
            }
        }
        if (flag) continue;
        for (i=0; i<n; i++){
            if (s[i]!=t[i]){
                for (j=i+1; j<n; j++){
                    if (s[i]==s[j]){
                        s[j]=t[i];
                        t[i]=s[i];
                        moves.pb({j, i});
                        break;
                    }
                    if (s[i]==t[j]){
                        t[j]=s[wind];
                        s[wind]=t[i];
                        t[i]=s[i];
                        moves.pb({wind, j});
                        moves.pb({wind, i});
                        break;
                    }
                }
            }
        }
        cout << "Yes" << endl << moves.size() << endl;
        for (auto x: moves){
            cout << x.F+1 << " " << x.S+1 << endl;
        }
    }
}
