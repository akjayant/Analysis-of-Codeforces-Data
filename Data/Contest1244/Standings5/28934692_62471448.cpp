#include<iostream>
#include<cstdio>
#include<cmath>
#include<algorithm>
using namespace std;
char s[1005];
void solve() {
    int n;cin>>n;scanf("%s",s+1);
    int cnt1=0,cnt2=0,flag1=0,flag2=0;
    for(int i=1;i<=n;i++,cnt1++) {
        if(s[i]!='1')continue;
        else {flag1=1;break;}
    }
    for(int i=n;i>=1;i--,cnt2++) {
        if(s[i]!='1')continue;
        else {flag2=1;break;}
    }
    int ans=0;
    if(!flag1&&!flag2)ans=n;
    else ans=n*2-min(cnt1,cnt2)*2;
    cout<<ans<<endl;
}
int main() {
    int t;cin>>t;
    while(t--)solve();
}