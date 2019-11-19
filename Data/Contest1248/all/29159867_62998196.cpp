#include<bits/stdc++.h>
using namespace std;
#define mod 1000000007

long long arr[100010];

int main(){

    int n,m;

    cin>>n>>m;

    arr[1]=2;
    arr[2]=4;

    int maxx = max(n,m);

    for(int i=3;i<=maxx;i++){
        arr[i]=arr[i-1]+arr[i-2];
        arr[i]%=mod;
    }

    long long ans = (arr[n]+arr[m]-2);
    ans%=mod;

    cout<<ans;

    
} 