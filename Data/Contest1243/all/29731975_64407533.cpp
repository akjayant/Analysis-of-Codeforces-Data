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
int main(){__
    lli n;
    cin >> n;
    vector<lli> factores;
    for(lli x = 2ll; x*x <= n; x++){
        lli cont =0;
        //cout << "n entra " << n << endl;
        //cout << "probamos con " << x << endl;
        while(n%x == 0){
            n/=x;
            cont++;
        }
        //cout << "cont sale " << cont << endl;
        if(cont) factores.pb(x);
    }
    if(n > 1) factores.pb(n);

    if(factores.size() == 1){
        cout << factores[0] << endl; 
    }
    else
        cout << 1 << endl;
    return 0;
}
