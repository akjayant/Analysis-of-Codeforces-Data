#include<bits/stdc++.h>
using namespace std;
#define ll long long int
#define MOD 1000000007
ll t,n;
vector<ll>v[305];
int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin>>n;
    ll i,j,k,idx=1,fr=1;
    for(i=1;i<=n*n;i++){
        v[idx].push_back(i);
        if(fr==1){
            idx++;
        } else {
            idx--;
        }
        if(idx==n+1){
            idx=n;
            fr=0;
        } else if(idx==0){
            idx=1;
            fr=1;
        }
    }
    for(i=1;i<=n;i++){
        for(auto it:v[i]){
            cout<<it<<" ";
        }
        cout<<"\n";
    }
    return 0;
}