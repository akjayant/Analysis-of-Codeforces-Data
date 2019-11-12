#include <bits/stdc++.h>
#define inp_out_work ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
#define testCase    int T; cin>>T; while(T--)
#define fr(i,n) for(int i=0;i<n;i++)
#define fro(s,e) for(int i=s;i<=e;i++)
#define pb push_back
#define ll long long
#define debug(P) cout<<#P<<' '<<P<<endl
#define mod 1000000007
#define MAXN 1001

using namespace std;


ll modPower(ll x,ll y){
    x%=mod;
    ll res = 1;
    while(y){
        if(y&1)res= (res*x)%mod;
        x = (x*x)%mod;
        y>>=1;
    }
    return res;
}

int main(){
    inp_out_work
    int n;
    cin>>n;
    vector <int> v[n];
    int hi = n*n, lo = 1;
    fr(t,(n>>1)){
        fr(i,n)v[i].push_back(lo++), v[i].push_back(hi--);
    }

    if(n&1){
        fr(i,n)v[i].push_back(lo++);
    }
    fr(i,n){
        for(int x : v[i])cout<< x <<' ';
        cout<< endl;
    }
}
