#include <bits/stdc++.h>
using namespace std;
#define endl '\n'
#define __ ios_base::sync_with_stdio(0);cin.tie(0);
#define forn(i,a,n) for(int i =a; i < n; i++)
#define fi first
#define se second
#define pb push_back
typedef vector<int> vi;
typedef vector<vi> vvi;
typedef long long int lli;
typedef pair<int,int> pii;
#define MOD 1000000007 
#define MAXN

void solve(){
    int n;
    cin >> n;
    string s,t;
    cin >> s >> t;
    vi c(26,0);
    forn(i,0,n){
        c[s[i]-'a']++;
        c[t[i]-'a']++;
    }
    forn(i,0,26){
        if(c[i]%2){
            cout << "No" << endl;
            return ;
        }
    }
    vector<pii> moves;
    forn(i,0,n-1){
        if(s[i] == t[i]) continue;
        //checar en t
        bool flag = false;
        forn(j,i+1,n){
            if(t[j] == s[i]){
                //movemos arriba
                moves.pb(pii(i+1,j));
                swap(s[i+1],t[j]);
                //movemos abajo
                moves.pb(pii(i+1,i));
                swap(s[i+1],t[i]);
                flag = true;
                break;
            }
        }
        if(!flag){
            //buscamos en s
            forn(j,i+1,n){
                if(s[i] == s[j]){
                    //movemos abajo
                    moves.pb(pii(j,i));
                    swap(s[j],t[i]);
                    break;
                }
            }
        }
    }
    //cout << s << endl;
    //cout << t << endl;
    cout << "Yes" << endl;
    cout << moves.size() << endl;
    for(pii p: moves){
        cout << p.fi+1 << " " << p.se+1 << endl;
    }
}

int main(){__
    int t;
    cin >> t;
    while(t--){
        solve();
    }
    return 0;
}
