#pragma region
#include <bits/stdc++.h>
using namespace std;

typedef vector<int> vi;
typedef vector<vi> vvi;
typedef vector<vvi> vvvi;
typedef pair<int,int> ii;
typedef vector<ii> vii;
typedef vector<vii> vvii;
typedef vector<vvii> vvvii;

typedef vector<double> vd;
typedef vector<vd> vvd;
typedef long long ll;
typedef vector<ll> vll;
typedef vector<vll> vvll;

inline ll pos_mod(ll i, ll n) {return (i % n + n) % n;}
#define FORI(n) for (int i=0;i<(n);i++)
#define FORJ(n) for (int j=0;j<(n);j++)
#define FORK(n) for (int k=0;k<(n);k++)
#define MOD 1000000007
#pragma endregion


int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int t; cin>>t;
    while (t--){
        int a,b,c,d,k; cin>>a>>b>>c>>d>>k;
        for (int i=0;i<=k;i++){
            int j=k-i;
            if (c*i>=a && d*j>=b){
                cout << i << " " << j << endl;
                goto end;
            }
        }
        cout << -1 << endl;
        end: continue;
    }
}