#include <bits/stdc++.h>
using namespace std;

int n;
long long k,a[100009];
long long minidx,maxidx,mincnt,maxcnt,minv,maxv;
long long tored;

int main(){
    scanf("%d %lld",&n,&k);
    for(int i=0;i<n;i++) scanf("%lld",&a[i]);
    sort(a,a+n);
    minidx=0;
    maxidx=n-1;
    minv=a[minidx];
    maxv=a[maxidx];
    mincnt=1;
    maxcnt=1;
    for(int i=minidx+1;i<n;i++){
        if(a[i]==a[minidx]){
            mincnt++;
            minidx++;
        }
        else break;
    }
    for(int i=maxidx-1;i>=0;i--){
        if(a[i]==a[maxidx]){
            maxcnt++;
            maxidx--;
        }
        else break;
    }
    while(k>0&&minv!=maxv){
        bool allused=0;
        if(mincnt>maxcnt){
            long long tored=a[maxidx]-a[maxidx-1];
            long long canch=min(k/maxcnt,tored);
            a[maxidx]-=canch;
            maxv=a[maxidx];
            k-=canch*maxcnt;
            if(tored>canch) allused=1;
        }
        else{
            long long tored=a[minidx+1]-a[minidx];
            long long canch=min(k/mincnt,tored);
            a[minidx]+=canch;
            minv=a[minidx];
            k-=canch*mincnt;
            if(tored>canch) allused=1;
        }
        if(allused) break;
        //
        for(int i=minidx+1;i<n;i++){
            if(a[i]==a[minidx]){
                mincnt++;
                minidx++;
            }
            else break;
        }
        for(int i=maxidx-1;i>=0;i--){
            if(a[i]==a[maxidx]){
                maxcnt++;
                maxidx--;
            }
            else break;
        }
    }
    printf("%lld",maxv-minv);
    return 0;
}
