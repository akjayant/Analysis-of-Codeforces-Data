#include <bits/stdc++.h>
#define i long long
#define re return
using namespace std;
i p[50],t[50];
i w(i b,i x,i l){
if(x>=l)re p[b+1];
if(x+t[b+1]<l)re 0;
re w(b-1,x,l)*2+w(b-1,x+(1<<b),l);
}
i q(i b,i y,i r){
if(y+t[b+1]<=r)re p[b+1];
if(y>r)re 0;
re q(b-1,y,r)*2+q(b-1,y+(1<<b),r);
}
i a(i b,i x,i y,i l,i r){
if(x+t[b+1]<l)re 0;
if(y>r)re 0;
if(x>=l) re q(b,y,r);
if(y+t[b+1]<=r) re w(b,x,l);
return a(b-1,x,y,l,r)+a(b-1,x+(1<<b),y,l,r)+a(b-1,x,y+(1<<b),l,r);
}
main(){
p[0]=1;
for(i j=1;j<50;j++)p[j]=p[j-1]*3,t[j]=(1<<j)-1;
i t,l,r;
cin>>t;
while(t--){
cin>>l>>r;
i s=(l?0:1);
for(i j=0;j<30;j++)s+=a(j-1,0,1<<j,l,r)*2;
cout<<s<<endl;
}
}
