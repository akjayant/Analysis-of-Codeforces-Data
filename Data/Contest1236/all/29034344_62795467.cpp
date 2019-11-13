#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

int main(int argc, char const *argv[])
{
    ll n;
    cin>>n;
    ll arr[n][n];
    ll num = 1;
    for(ll j=0;j<n;j++){
        if(j%2==0){
            for(ll i=0;i<n;i++){
                arr[i][j] = num++;
            }
        }else{
            for(ll i=n-1;i>=0;i--){
                arr[i][j] = num++;
            }
        }
    }   
    for(ll i=0;i<n;i++){
        for(ll j=0;j<n;j++){
            cout<<arr[i][j]<<" ";
        }
        cout<<"\n";
    }
    return 0;
}