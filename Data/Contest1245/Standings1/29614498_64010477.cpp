#include<bits/stdc++.h>
using namespace std;

map<pair<int, int>, long long > M;
long long solve(int a, int b)
{
    if(a==-1 || b== -1) return 0LL;
    if(a == 0 || b == 0) return a+b+1;
    if(a>b) swap(a, b);
    auto it = M.find(make_pair(a,b));
    if(it!=M.end())
    {
        return it->second;
    }
    int lb = 0;
    for(int i=30; i>=0; --i)
    {
        if( (a&(1<<i))||(b&(1<<i)) )
        {
            lb = i;
            break;
        }
    }

    long long ans = 0;
    // both 0,
    {
        int na = min(a, (1<<lb)-1);
        int nb = min(b, (1<<lb)-1);
        ans += solve(na, nb);
    }
    //a: 1 b = 0;
    if(a >= (1<<lb))
    {
        int na = a-(1<<lb);
        int nb = min(b, (1<<lb)-1);
        ans += solve(na, nb);
    }
    //a: 0 b = 1;
    if(b >= (1<<lb))
    {
        int na = min(a, (1<<lb)-1);
        int nb = b-(1<<lb);
        ans += solve(na, nb);
    }


    return M[make_pair(a, b)] = ans;
}
int main()
{
    int T; scanf("%d", &T);
    while(T--)
    {
        int a, b;
        scanf("%d%d", &a, &b);
        long long ans = solve(b, b) - 2*solve(b, a-1) + solve(a-1, a-1);
        printf("%lld\n", ans);
    }
}