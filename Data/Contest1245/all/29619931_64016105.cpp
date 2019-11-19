#include <bits/stdc++.h>
#define int long long
using namespace std;
main(){
int n;
cin>>n;
int x[n],y[n],c[n],k[n],p[n+1],r[n],h[n],j[n],g=0,t=0,m=0,S=0;
pair<int, pair<int,int>> a[n*n];
for(int i=0;i<n;i++)cin>>x[i]>>y[i];
for(int i=0;i<n;i++)cin>>c[i];
for(int i=0;i<n;i++)cin>>k[i];
for(int i=0;i<n;i++)a[m++]={c[i],{n,i}};
for(int i=0;i<n;i++)for(int j=0;j<i;j++)a[m++]={(k[j]+k[i])*(abs(x[j]-x[i])+abs(y[j]-y[i])),{j,i}};
sort(a,a+m);
for(int i=0;i<=n;i++)p[i]=i;
function<int(int)> pp=[&p,&pp](int v){return p[v]=(p[v]==v?v:pp(p[v]));};
for(int i=0;i<m;i++){
int v=a[i].second.first,u=a[i].second.second;
if(pp(v)!=pp(u)){
p[p[v]]=p[u];
S+=a[i].first;
if(v==n)r[t++]=u+1;
else h[g]=v+1,j[g++]=u+1;
}
}
cout<<S<<endl;
cout<<t<<endl;
for(int i=0;i<t;i++)cout<<r[i]<<" ";
cout<<endl;
cout<<g<<endl;
for(int i=0;i<g;i++)cout<<h[i]<<" "<<j[i]<<endl;
}

