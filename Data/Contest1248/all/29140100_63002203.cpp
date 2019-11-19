#include<bits/stdc++.h>
using namespace std;
#define rep(i,a,b) for(int i=(a);i<=(b);++i)
#define dep(i,a,b) for(int i=(a);i>=(b);--i)
#define pb push_back
typedef long long ll;
const int maxn=(int)2e5+100;
const int mod=(int)1e9+7;
int n,ans=0,l,r;
char s[maxn];
int fun(){
    int ans=0;
    int c[550]={0,},pre[550],sub[550];
    rep(i,1,n){
        c[i]=c[i-1];
        if(s[i]=='(') c[i]++;
        else c[i]--; 
    }
    pre[1]=c[1];
    rep(i,2,n) pre[i]=min(pre[i-1],c[i]);
    sub[n]=c[n];
    dep(i,n-1,1) sub[i]=min(sub[i+1],c[i]);
    rep(i,0,n-1) if((sub[i+1]-c[i]>=0)&&(pre[i]+c[n]-c[i]>=0)) ans++;
    return ans;
}
int main(){
    scanf("%d%s",&n,s+1);
    int l=0,r=0;
    rep(i,1,n){
        if(s[i]=='(') l++;
        else r++; 
    }
    if(l!=r) return printf("0\n1 1\n"),0;
    rep(i,1,n) rep(j,i,n){
        char t1=s[i],t2=s[j];
        s[i]=t2;s[j]=t1;
        int tmp=fun();
        if(tmp>ans){
            ans=tmp;l=i;r=j;
        }
        s[i]=t1;s[j]=t2;
    }
    if(ans==0) printf("0\n1 1\n");
    else printf("%d\n%d %d\n",ans,l,r);
}