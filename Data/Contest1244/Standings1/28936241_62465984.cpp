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
void work(){
    scanf("%d%d%d%d%d",&a,&b,&c,&d,&k);swap(a,c);swap(b,d);
    int x=c/a+(c%a>0);
    int y=d/b+(d%b>0);
    if(x+y<=k)
        printf("%d %d\n",x,y);
    else puts("-1");
}
int main(){
    int t;scanf("%d",&t);
    while(t--)work();
}
