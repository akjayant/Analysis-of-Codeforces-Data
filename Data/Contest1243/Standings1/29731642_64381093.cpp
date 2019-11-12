#include<bits/stdc++.h>
using namespace std;
#define ll long long
const int maxn=1000000+10;
char s[maxn],t[maxn];
int a[maxn],b[maxn];
int main()
{
    int k,n,x;
    scanf("%d",&k);
    while(k--){
        scanf("%d",&n);
        scanf("%s %s",s,t);
        int times=0;
        for(int i=0;i<n;i++){
            if(s[i]!=t[i]){
                a[times]=s[i];
                b[times]=t[i];
                times++;
            }
        }
        // printf("%d\n",times);
        if(times!=2) printf("No\n");
        else {
            // printf("%d %d %d %d\n",a[0],a[1],b[0],b[1]);
            if(a[0]==a[1] && b[0]==b[1]) printf("Yes\n");
            else printf("No\n");
        }
    }
    return 0;
}
