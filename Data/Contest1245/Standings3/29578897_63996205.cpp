#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int,int> pii;
const int MAXN=300050;
const ll llINF=~(1ll<<63);
const int INF=~(1<<31),MOD=1e9+7;
#define lowbit(x) x&-x



int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        int l,r;
        cin>>l>>r;
        if(__gcd(l,r)==1)puts("Finite");
        else puts("Infinite");
    }
    return 0;
}
