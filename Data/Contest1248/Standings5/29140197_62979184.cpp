#include<bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef pair<int,int> PII;
const int MAXN = 1e6+10;
const double EPS = 1e-12;
const int mod = 1e9+7;

int T,n,m,cnt;
int a[MAXN],b[MAXN];

int main()
{
    scanf("%d",&T);
    while(T--){
        scanf("%d",&n);
        int c1=0,c2=0;
        for(int i=1;i<=n;i++){
            scanf("%d",&a[i]);
            if(a[i]%2==0)c1++;
        }
        scanf("%d",&m);
        for(int i=1;i<=m;i++){
            scanf("%d",&b[i]);
            if(b[i]%2==0)c2++;
        }
        printf("%lld\n",1ll*(n-c1)*(m-c2)+1ll*c1*c2);
    }
}
