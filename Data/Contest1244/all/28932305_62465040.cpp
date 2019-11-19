#include<bits/stdc++.h>
using namespace std;
#define ll long long int
ll t,a,b,c,d,k;
int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    ll i,j;
    cin>>t;
    while(t--){
        cin>>a>>b>>c>>d>>k;
        ll req1=a/c;
        ll req2=b/d;
        if(a%c!=0){
            req1++;
        } 
        if(b%d!=0){
            req2++;
        }
        if(req1+req2>k){
            cout<<"-1\n";
        } else {
            cout<<req1<<" "<<req2<<"\n";
        }
    }
    return 0;
}