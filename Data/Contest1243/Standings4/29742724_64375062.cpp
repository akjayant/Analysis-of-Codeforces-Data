#include <iostream>
#include <string>
#include <cmath>
#include <map>
#include <stack>
#include <vector>
#include <cstdio>
#include <set>
#include <cstring>
#include <queue>
#include <algorithm>
#define inf 0x3f3f3f3f
using namespace std;
typedef long long ll;
const int maxn=1005;
int t,n,a[maxn],sum[maxn];
int main()
{
    ios::sync_with_stdio(false),cin.tie(0),cout.tie(0);
    cin>>t;
    while(t--)
    {
        memset(sum,0,sizeof(sum));
        cin>>n;
        for(int i=1;i<=n;i++)cin>>a[i],sum[a[i]]++;
        for(int i=n-1;i>=1;i--)sum[i]+=sum[i+1];
        int maxn=0;
        for(int i=1;i<=n;i++)
            if(sum[i]>=i)maxn=max(maxn,i);
        cout<<maxn<<endl;
    }

    return 0;
}
