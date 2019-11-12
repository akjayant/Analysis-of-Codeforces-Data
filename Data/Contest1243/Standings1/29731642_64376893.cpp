#include<bits/stdc++.h>
using namespace std;
#define ll long long
const int maxn=1000000+10;
int a[10000];
int main()
{
    int k,n,x;
    scanf("%d",&k);
    while(k--){
        memset(a,0,sizeof(a));
        scanf("%d",&n);
        for(int i=0;i<n;i++){
            scanf("%d",&x);
            a[x]++;
        }
        int ans=0,len=0;
        int cur=0;
        //枚举高度
        for(int i=n;i>0;i--){
            cur+=a[i];
            if(i<=cur){
                len=i;
                break;
            }
        }
        printf("%d\n",len);
    }
    return 0;
}
