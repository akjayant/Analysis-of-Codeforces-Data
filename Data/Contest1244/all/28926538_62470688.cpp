#include<bits/stdc++.h>
using namespace std;
#define mp make_pair
const int maxn=2e5;
const int mod=1e9+7;
int n;
char s[maxn+5];
int main()
{

    int T;
    scanf("%d",&T);
    while(T--)
    {
        scanf("%d",&n);
        scanf("%s",s+1);
        int mi=n+1,mx=0;
        for(int i=1;i<=n;++i)
            if(s[i]=='1') mi=min(mi,i),mx=max(mx,i);
        cout<<max(n,2*max(n-mi+1,mx))<<endl;

    }
    return 0;
}
