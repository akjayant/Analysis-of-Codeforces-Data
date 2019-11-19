#include<iostream>
#include<cstdio>
using namespace std;
const int N=500+10;
int n;
char c[N];
int l=1,r=1,cnt,ans;
inline int calc(int l,int r){
    swap(c[l],c[r]);
    int mn=n,mi,cnt=0,res=0;
    for(int i=1;i<=n;i++){
        cnt+=(c[i]=='(')?1:-1;
        if(c[i]=='(' && cnt<mn){
            mn=cnt;
            mi=i;
        }
    }
    cnt=0;
    for(int i=1,j=mi;i<=n;i++,(j==n)?j=1:j++)
        if(c[j]=='(')
            cnt++;
        else{
            cnt--;
            if(cnt==0)
                res++;
        }
    swap(c[l],c[r]);
    return res;
}
int main(){
    scanf("%d%s",&n,c+1);
    for(int i=1;i<=n;i++)
        cnt+=(c[i]=='(')?1:-1;
    if(cnt){
        puts("0\n1 1");
        return 0;
    }
    ans=calc(0,0);
    for(int i=1;i<=n;i++)
        for(int j=l+1;j<=n;j++){
            int t=calc(i,j);
            if(t>ans){
                l=i,r=j;
                ans=t;
            }
        }
    printf("%d\n%d %d",ans,l,r);
    return 0;
}