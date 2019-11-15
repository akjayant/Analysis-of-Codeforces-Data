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
        string s1,s2;
        cin>>s1>>s2;
        ll i1=-1,i2=-1,f=1;

        fin{
            if(s1[i]!=s2[i]){
                if(i1==-1){
                    i1=i;
                }else if(i2==-1){
                    i2=i;
                }else{
                    f=0;
                }
            }
        }
        if(f==1){
            if(!(s1[i1]==s1[i2] && s2[i1]==s2[i2])){
                f=0;
            }
        }
        if(f==0){
            cout<<"No\n";
        }else{
            cout<<"Yes\n";
        }
    }
}