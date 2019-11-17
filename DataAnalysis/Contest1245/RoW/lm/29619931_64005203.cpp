using namespace std;
int main(){
string s;
int mod=1e9+7;
cin>>s;
for(int i=0;i<s.size();i++)
if(s[i]=='w'||s[i]=='m')cout<<0,exit(0);
int a,b=1,c=0;
for(int i=0;i<s.size();i++){
if(s[i]==s[i-1]&&(s[i]=='u'||s[i]=='n'))a=(b+c)%mod;
else a=b;
c=b,b=a;
}
cout<<b;
}
