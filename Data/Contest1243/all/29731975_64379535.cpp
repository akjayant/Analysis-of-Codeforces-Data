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
    int uno =-1,dos=-1;
    forn(i,0,n){
        if(s[i] != t[i]){
            if(uno == -1){
                uno = i;
            }
            else if(dos == -1){
                dos = i;
            }
            else{
                cout << "No" << endl;
                return ;
            }
        }
    }
    if(dos == -1){
        cout << "No" << endl;
        return ;
    }
    if(t[uno] == t[dos] && s[uno] == s[dos]){
        cout << "Yes" << endl;
    }
    else
        cout << "No" << endl;
}

int main(){__
    int t;
    cin >> t;
    while(t--){
        solve();
    }
    return 0;
}
