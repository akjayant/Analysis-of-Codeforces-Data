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
	cin>>t;
    while(t--){
        ll n;
        cin>>n;
        ll a[n];
        fin
        cin>>a[i];
        sort(a,a+n);
        ll x=1;
        for(i=n-1;i>=0;i--){
            if(a[i]<x){
                break;
            }
            x++;
        }
        cout<<x-1<<endl;
    }
}