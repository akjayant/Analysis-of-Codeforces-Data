#include<bits/stdc++.h>
using namespace std;
const int maxn=200005;
int n,K,a[3*maxn],b[maxn];
void print(int x){
    if (x==0) printf("W");
    else printf("B");
}
void solve1(int l,int r){
    int p=min((r-l+2)/2,K);
    for (int i=l;i<=l+p-1;i++) a[i]=a[l-1];
    for (int i=r;i>=r-p+1;i--) a[i]=a[l-1];
    if (p%2==1&&l+p<r-p-1){
        for (int i=l+p;i<=r-p;i++) a[i]=1-a[i];
    }
}
void solve2(int l,int r){
    int p=min((r-l+1)/2,K);
    for (int i=l;i<=l+p-1;i++) a[i]=a[l-1];
    for (int i=r;i>=r-p+1;i--) a[i]=a[r+1];
    if (p%2==1&&l+p<=r-p){
        for (int i=l+p;i<=r-p;i++) a[i]=1-a[i];
    }
}
int main(){
    scanf("%d%d",&n,&K);
    for (int i=1;i<=n;i++) {
        char ch=getchar();
        while (ch!='W'&&ch!='B') ch=getchar();
        if (ch=='W') a[i]=0; else a[i]=1;
        a[i+n]=a[i],a[i+2*n]=a[i];
    }
    int st=0;
    for (int i=1;i<2*n;i++) if (a[i]==a[i+1]) {st=i; break;}
    if (st==0){
        K%=2;
        if (K==1) {for (int i=2;i<=n+1;i++) print(a[i]); puts("");}
        else {for (int i=1;i<=n;i++) print(a[i]); puts("");}
    } else {
        int las=st+1;
        for (int i=st+2;i<=st+n;i++)
            if (a[i]==a[i+1]) {
                //printf("%d %d\n",las+1,i-1);
                if (las+1>i-1) {las=i+1; continue;}
                if (a[i]==a[las]) solve1(las+1,i-1);
                else solve2(las+1,i-1);
                las=i+1;
            }
        for (int i=st;i<=st+n-1;i++){
            if (i>n) b[i-n]=a[i]; else b[i]=a[i];
        }
        //printf("!!!%d\n",n);
        for (int i=1;i<=n;i++) print(b[i]); puts("");
    }
    return 0;
}
