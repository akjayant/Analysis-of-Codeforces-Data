#include <bits/stdc++.h>
#define lson root<<1
#define rson root<<1|1
using namespace std;
//priority_queue<int,vector<int>,greater<int> > q;
typedef long long ll;
const int inf=0x3f3f3f3f;
const int maxn=1e5+7;
int main()
{
    int t;
    scanf("%d",&t);
    int a,b,c;
    while(t--){
        scanf("%d%d%d",&a,&b,&c);
        int ans=0;
        int temp=min(b,c/2);
        b-=temp;
        ans+=temp*3;
        temp=min(a,b/2);
        ans+=temp*3;
        printf("%d\n",ans);
    }
    return 0;
}
