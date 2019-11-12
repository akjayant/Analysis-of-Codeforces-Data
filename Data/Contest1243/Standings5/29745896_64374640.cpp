#include<bits/stdc++.h>
#define ll long long
#define pii pair<int,int>
using namespace std;
const int maxn=1e3+7;
int a[maxn];
int main()
{
    int T;
    scanf("%d",&T);
    while(T--){
        int n;
        scanf("%d",&n);
        for(int i=1;i<=n;i++)scanf("%d",&a[i]);
        sort(a+1,a+1+n);
        for(int i=n;i>=1;i--){
            if(a[n-i+1]>=i){
                printf("%d\n",i);
                break;
            }

        }
    }
    return 0;
}
