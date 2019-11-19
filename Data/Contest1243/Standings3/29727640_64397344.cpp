#include <bits/stdc++.h>

using namespace std;
#define ll long long
const int MAXN=3e3+1;
const int inf = MAXN;
vector<vector<int>> trans(MAXN, vector<int>(0));

int n;
vector<pair<int , int>> ans(0);

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    ll n;
    cin>>n;
    if(n==1) {
        cout<<1;
        return 0;
    }
    ll maxP=-1;
    int kol_vo=0;
    for(ll i=2;i*i<=n;i++){
        if(n%i!=0) continue;
        maxP=max(i, maxP);
        kol_vo++;
        while(n%i==0){
            n/=i;
        }
    }
    if(n!=1) {
        maxP=max(maxP, n);
        kol_vo++;
    }
    if(kol_vo>=2){
        cout<<1<<endl;
    }
    else{
        cout<<maxP<<endl;
    }
}