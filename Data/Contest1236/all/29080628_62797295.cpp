#include<bits/stdc++.h>
#define ll long long int
#define pb push_back
#define mpr make_pair
#define mt make_tuple
 
using namespace std;
 
const int N = 1000;
const int mod = 1e9 + 7;
ll power(ll x, ll y, ll p){ ll res = 1; x = x % p;while (y > 0){ if (y & 1) res = (res*x) % p; y = y>>1; x = (x*x) % p;} return res; }

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int n,ind,sq,flag;
    vector<int> groups[N];
    cin>>n;
    ind = 0;
    sq = n*n;
    flag = 1;
    for(int i=1;i<=sq;i++){
        groups[ind].pb(i);
        if(flag)    ind++;
        else    ind--;
        if(ind == n && flag == 1){
            flag = 0;
            ind = n-1;
        }
        if(ind == -1 && flag == 0){
            flag = 1;
            ind = 0;
        }
    }
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++)    cout<<groups[i][j]<<" ";
        cout<<endl;
    }
    return 0;
}