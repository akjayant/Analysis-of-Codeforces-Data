//ZJ_MRZ's Code
#include<iostream>
#include<cstdio>
#include<cstring>
#include<string>
#include<algorithm>
#include<cmath>
#include<vector>
using namespace std;
int T,n,m;
int main() {
    scanf("%d",&T);
    while(T--) {
        long long ax=0,ay=0,bx=0,by=0;
        scanf("%d",&n);
        for(int i=1;i<=n;i++) {
            long long ls;
            scanf("%lld",&ls);
            if(ls%2==0) {
                ay++;
            } 
            else {
                ax++;
            }
        }
        scanf("%d",&m);
        for(int i=1;i<=m;i++) {
            long long ls;
            scanf("%lld",&ls);
            if(ls%2==0) {
                by++;
            } 
            else {
                bx++;
            }
        }
        long long ans=(ay*by)+(ax*bx);
        printf("%lld\n",ans);       
    }
    return 0;
}