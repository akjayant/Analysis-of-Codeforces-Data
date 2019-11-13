#include <bits/stdc++.h>
using namespace std;
int main(){
int t;
cin>>t;
while(t--){
int n,a,b,c;
string s,t;
cin>>n>>a>>b>>c;
cin>>s;
for(int i=0;i<n;i++){
if(s[i]=='R'){
if(b)t+='P',b--;
else t+='?';
}
if(s[i]=='P'){
if(c)t+='S',c--;
else t+='?';
}
if(s[i]=='S'){
if(a)t+='R',a--;
else t+='?';
}
}
if(n-a-b-c<(n+1)/2)cout<<"NO"<<endl;
else{
cout<<"YES"<<endl;
for(int i=0;i<n;i++)
if(t[i]=='?'){
if(a)cout<<'R',a--;
else if(b)cout<<'P',b--;
else cout<<"S";
}else cout<<t[i];
cout<<endl;
}
}
}
