#include <bits/stdc++.h>
using namespace std;
int main(){
int a[10][10],l=0,r=0,i,j,q;
double d[10][10],v[1000]; 
for(i=0;i<10;i++)for(j=0;j<10;j++)cin>>a[i][j];
for(i=0;i<10;i++){
if(i&1){
for(j=9;j>=0;j--){
while(r-l>6)l++;
for(q=l;q<r;q++)d[i][j]+=v[q];
d[i][j]+=6;
d[i][j]/=r-l;
if(a[i][j])v[r++]=min(d[i-a[i][j]][j],d[i][j]);
else v[r++]=d[i][j];
}
}else{
for(j=0;j<10;j++){
if(!i&&!j){
d[i][j]=0;
v[r++]=0;
continue;
}
while(r-l>6)l++;
for(q=l;q<r;q++)d[i][j]+=v[q];
d[i][j]+=6;
d[i][j]/=r-l;
if(a[i][j])v[r++]=min(d[i-a[i][j]][j],d[i][j]);
else v[r++]=d[i][j];
}
}
}
cout<<fixed<<setprecision(10)<<d[9][0];
}