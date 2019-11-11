#include<bits/stdc++.h>
using namespace std;
int t,n,a,b,c;
char s[1000];
char ans2[1000];
int main(void){
cin>>t;
while(t--){
cin>>n>>a>>b>>c;
scanf("%s",s);
memset(ans2,0,sizeof(ans2));
int ans=0;
for(int i=0;i<n;i++){
if(s[i]=='R'){
if(b)b--,ans++,ans2[i]='P';
}
else if(s[i]=='P'){
if(c)c--,ans++,ans2[i]='S';
}
else {
if(a)a--,ans++,ans2[i]='R';
}
//cout<<a<<" "<<b<<" "<<c<<" "<<ans<<endl;
}
for(int i=0;i<n;i++){
if(!ans2[i]){
if(a)a--,ans2[i]='R';
else if(b)b--,ans2[i]='P';
else c--,ans2[i]='S';
}
}
ans2[n]='\0';
//cout<<(?"YES)
if(ans>=(n/2+n%2)){
printf("YES\n%s\n",ans2);
}
else cout<<"NO"<<endl;
}
}