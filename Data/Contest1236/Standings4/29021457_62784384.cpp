#include<bits/stdc++.h>
using namespace std;
int a,b,c,tem,t;
int main(void){
cin>>t;
while(t--){
cin>>a>>b>>c;
tem=min(b,c/2);
int ans=tem*3;
b-=tem;
ans+=min(a,b/2)*3;
cout<<ans<<endl;;
}}