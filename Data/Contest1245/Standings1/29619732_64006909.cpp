#include<bits/stdc++.h>
#define ll long long 
#define mod 1000000007
using namespace std;
char s[1000004];
ll fib[100000];
int main(void){
fib[0]=fib[1]=1;
for(int i=2;i<=100000;i++){
fib[i]=(fib[i-1]+fib[i-2])%mod;
}
scanf("%s",s);
ll tem=0,ans=1,j;
for(int i=0;s[i]!='\0';i++){
if(s[i]=='m'||s[i]=='w'){
cout<<0<<endl;
return 0;
}
if(s[i]=='u'||s[i]=='n'){
tem=1,j=i;
while(s[j+1]==s[i])j++;
ans=ans*fib[j-i+1]%mod;
i=j;
}
}
cout<<ans<<endl;
}