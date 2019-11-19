#include<cstring>
#include<vector>
#include<algorithm>
#include<iostream>
#include<cmath>
#include<cstdio>
using namespace std;
#define maxn 31000
#define maxm 201000
int n,b,c,a,d,k;
char s[11100];
void work(){
    scanf("%d%s",&n,s+1);
    int ans=n;
    for(int i=1;i<=n;i++)
        if(s[i]=='1')
        ans=max(ans,max(i+i,(n-i+1)*2));
    printf("%d\n",ans);
}
int main(){
    int t;scanf("%d",&t);
    while(t--)work();
}
