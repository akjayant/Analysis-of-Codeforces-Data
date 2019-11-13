#include <bits/stdc++.h>

using namespace std;

#define REP(i,a,b) for(int i = a; i < b; i++)
#define DB( x ) cout << #x << " = " << x << endl;
#define sz(s) ((int)((s).size()))
#define endl '\n'

typedef long long ll;
typedef unsigned long long ull;
typedef pair<int, int> pii;
typedef pair<int, pii> tri;
typedef vector <vector <ll>> matrix;
typedef pair<string, string> pss;

const ll mod = (ll)1e9 + 7;
const int MAX = 100001;

const int oo = 0x3f3f3f3f;



int main() {

    ios_base :: sync_with_stdio(0); cin.tie(0);

    int tc; cin >> tc;

    while(tc--){

        int n, r, p, s; cin >> n >> r >> p >> s;

        string a; cin >> a;

        //caso 1

        string solve = string(n, '\0');

        for(int i = 0;i < n;++i){
            if(a[i] == 'S'){
                if(r){
                    r--;
                    solve[i] = 'R';
                }
            }
            if(a[i] == 'R'){
                if(p){
                    p--;
                    solve[i] = 'P';
                }
            }
            if(a[i] == 'P'){
                if(s){
                    s--;
                    solve[i] = 'S';
                }
            }
        }

        for(int i = 0;i < n;++i){
            if(solve[i] != '\0') continue;
            if(a[i] == 'R'){
                if(r){
                    r--;
                    solve[i] = 'R';
                }
            }
            if(a[i] == 'S'){
                if(s){
                    s--;
                    solve[i] = 'S';
                }
            }
            if(a[i] == 'P'){
                if(p){
                    p--;
                    solve[i] = 'P';
                }
            }
        }

        for(int i = 0;i < n;++i){
            if(solve[i] != '\0') continue;
            if(a[i] == 'S') solve[i] = 'P';
            if(a[i] == 'R') solve[i] = 'S';
            if(a[i] == 'P') solve[i] =  'R';
        }

        int cont = 0;

        for(int i = 0;i < n;++i){
            if(solve[i] == 'R' && a[i] == 'S') ++cont;
            if(solve[i] == 'S' && a[i] == 'P') ++cont;
            if(solve[i] == 'P' && a[i] == 'R') ++cont;
        }

        double x = n;
        int tot = (int)(ceil(x / 2.0));

        if(cont >= tot)
            cout << "YES\n" << solve << endl;
        else cout << "NO\n";
    }
}