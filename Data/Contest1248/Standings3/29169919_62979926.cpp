#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
const int MAXN = 1e5 + 5;
const int MOD = 1e9 + 7;
int a[MAXN];
int b[MAXN];

int main()
{
    int T;
    scanf("%d",&T);
    while(T--)
    {
        int n,m;
        int jia=0,jib=0,oua=0,oub=0;
        scanf("%d",&n);
        for(int i=1;i<=n;++i) {
            scanf("%d", &a[i]);
            if(a[i]%2==0)
                oua++;
            else
                jia++;
        }
        scanf("%d",&m);
        for(int i=1;i<=m;++i) {
            scanf("%d", &b[i]);
            if(b[i]%2==0)
                oub++;
            else
                jib++;
        }
        printf("%lld\n",1ll*jib*jia+1ll*oub*oua);
    }
    return 0;
}