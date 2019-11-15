#include<bits/stdc++.h>
using namespace std;
const int maxn=100000+10;
const int base=1000000000+7;

int n;
string s;
long long f[maxn];

int main(){
    cin>>s;n=s.length();s=" "+s;
    for(int i=1;i<=n;i++)
        if (s[i]=='w' || s[i]=='m') {
            cout<<0;return 0;
        }
    f[0]=1;
    for(int i=1;i<=n;i++){
        f[i]=f[i-1];
        if (i>=2 && s[i-1]=='u' && s[i]=='u') f[i]=(f[i]+f[i-2])%base;
        if (i>=2 && s[i-1]=='n' && s[i]=='n') f[i]=(f[i]+f[i-2])%base;
    }
    cout<<f[n];
}
