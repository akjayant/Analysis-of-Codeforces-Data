#include<bits/stdc++.h>
#define ll long long
using namespace std;
int a,b,a2,b2,c,t,n;
int main(void){
scanf("%d",&t);
while(t--){
scanf("%d",&n);
a=b=a2=b2=0;
while(n--){
scanf("%d",&c);
if(c%2)a++;
else b++;
}
scanf("%d",&n);
while(n--){
scanf("%d",&c);
if(c%2)a2++;
else b2++;
}
printf("%lld\n",(ll)a*a2+(ll)b*b2);
}
}