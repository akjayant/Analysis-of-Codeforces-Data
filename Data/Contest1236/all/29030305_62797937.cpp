#include <bits/stdc++.h>
#define ll long long
#define fr first
#define sc second
#define pii pair<int,int>
#define pll pair<ll,ll>
#define vi vector<ll>
#define all(x) (x).begin(),(x).end()
#define mp make_pair

using namespace std;
ll OO = (ll) 1e18 ;
int Mod = 1e9 + 7;
ll const N = 400 + 10;

ll add(ll a,ll b){
    a%=Mod;
    b%=Mod;
    a+=b;
    a%=Mod;
    a+=Mod;
    a%=Mod;
    return a;
}
ll mul(ll a,ll b){
    a%=Mod;
    b%=Mod;
    a*=b;
    a%=Mod;
    a+=Mod;
    a%=Mod;
    return a;
}
ll fpow(ll a,ll p){
    if(p==0)return 1;
    if(p&1)return mul(a,fpow(a,p-1));
    return fpow(mul(a,a),p>>1);
}
int Ans[N][N];
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    cin.exceptions(cin.failbit);
#ifdef LOCAL
    freopen("in.in", "r", stdin);
#endif
    int n;
    cin >>n ;
    int c = 0;
    for(int j=0;j<n;j++){
        if(j%2==0){
            for(int i=0;i<n;i++){
                Ans[i][j]=++c;
            }
        }
        else{
            for(int i=n-1;i>=0;i--){
                Ans[i][j]=++c;
            }
        }
    }
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            cout << Ans[i][j] << " " ;
        }
        cout << endl;
    }
}
