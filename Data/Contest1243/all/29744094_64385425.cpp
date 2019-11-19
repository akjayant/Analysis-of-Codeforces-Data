#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define ss second
#define ff first
#define pb push_back
#define mp make_pair
bool ok[1000100];
ll o=1000000;
int main(){
    ios_base::sync_with_stdio(0);
    for(int i=2;i<=o;i++){
        if(ok[i])
            continue;
        for(int j=i+i;j<=o;j+=i){ok[j]=1;}
    }
    ll n;
    cin>>n;
    ll x=n;
    ll mx=1,sum=0;
    if(n<=o)
    {
        if(!ok[n]){cout<<n;return 0;}
    }
    for(int i=2;i<=min(o,n);i++){
        if(n%i==0){
                mx=i;
                sum++;
            while(n%i==0){
                n/=i;
            }
        }
    }
    if(sum==0){
        cout<<x;
        return 0;
    }
    if(n>1){sum++;mx=max(n,mx);}
    if(sum>1){cout<<1;return 0;}
    ll h=1;
    while(h*mx<x){
        h*=mx;
    }
    cout<<x/h;

    return 0;
    }
//
