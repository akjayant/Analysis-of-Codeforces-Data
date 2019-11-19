#include <iostream>
#include <set>
#include <bits/stdc++.h>
using namespace std;
 
#define ll long long int
#define fin for(i=0;i<n;i++)
#define fim for(i=0;i<m;i++)
#define fjn for(j=0;j<n;j++)
#define fjm for(j=0;j<m;j++)
#define pb push_back
 
ll i,j,k,t;

int main(){
	t=1;
    while(t--){
        ll n;
        cin>>n;
        vector <ll> v;

        for(i=2;i<=sqrt(n);i++){
            if(n%i==0){
                v.pb(i);
                v.pb(n/i);
            }
        }
        v.pb(n);
        sort(v.begin(),v.end());
        ll f=0;
        for(i=1;i<v.size();i++){
            if(v[i]%v[0]!=0)
            f=1;
        }
        if(f==0){
            cout<<v[0];
        }else{
            cout<<"1";
        }
    }
}