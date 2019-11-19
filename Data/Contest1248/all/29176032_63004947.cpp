#include<bits/stdc++.h>
#define rep(i,l,r) for (int i=l;i<=r;i++)
using namespace std;
typedef long long ll;
int n,ansx,ansy,ans;
char s[100500],t[100500];
int a[1005];
void ask(int x,int y){
    rep(i,1,n){
        t[i]=s[i],t[i+n]=s[i];
    }
    int sz=0;
    int i=2,now=0;
    int mn=1000,sum=0;
    rep(j,1,n){
        if (t[i+j-1]=='(') now++;
        else now--;
        if (now<mn) mn=now;
    }
    sum=now;
    rep(i,2,n+1){
        if (i>2){
            if (t[i-1]=='(') mn--,sum--;
            else mn++,sum++;
            if (t[i+n-1]=='(') {
                sum++;
            }
            else {
                sum--;
            }
            mn=min(mn,sum);
        }
        if (mn==0&&sum==0) {
            sz++;
        }
    }
    if (sz>ans) {
        ans=sz; ansx=x; ansy=y;
    }
}
int main(){
    ansx=ansy=1,ans=0;
    scanf("%d",&n);
    scanf("%s",s+1);
    int sz0=0,sz1=0;
    rep(i,1,n){
        if (s[i]=='(') sz0++;
        else sz1++;
    }
    if (sz0!=sz1) {
        puts("0");
        puts("1 1");
        return 0;
    }
    ask(1,1);
    rep(i,1,n) rep(j,i+1,n) {
        swap(s[i],s[j]);
        ask(i,j);
        swap(s[i],s[j]);
    }
    printf("%d\n",ans);
    printf("%d %d\n",ansx,ansy);
    return 0;
}