#include<iostream>
#include<cstdio>
#include<algorithm>
#include<cstring>
#include<stdlib.h>
using namespace std;

int t,n;
int a[1000+5];

int main(){
    scanf("%d",&t);
    while(t--){
        int mmax=0;
        scanf("%d",&n);
        for(int i=1;i<=n;i++){
            scanf("%d",&a[i]);
        }
        sort(a+1,a+1+n);
        for(int i=1;i<=n;i++){
            mmax=max(mmax,min(a[i],n-i+1));
        }
        printf("%d\n",mmax);
    }
    return 0;
}
