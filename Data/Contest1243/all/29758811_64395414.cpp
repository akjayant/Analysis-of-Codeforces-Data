#include<bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>

#pragma GCC optimize(-O3)
#pragma GCC optimize(Ofast)
#pragma GCC optimize("unroll-loops")

#define fi first
#define se second
#define ll long long
#define all(x) x.begin(), x.end()
#define sqr(x) ((x) * (x))
#define PB push_back
using namespace std;
using namespace __gnu_pbds;

const ll N = 3e5 + 200;
const ll MOD = 1e9 + 7;
mt19937_64 rnd(chrono::system_clock::now().time_since_epoch().count());

template <typename T>
using _set = tree<T, null_type, less<T>, rb_tree_tag, tree_order_statistics_node_update>;
//ll n,ans[N],x,step;
//vector<ll> v;
//queue<ll> q;
//void add(ll i)
//{
//    if(i < 1 || i > n || ans[i]) return;
//    ans[i] = step;
//    q.push(i);
//}
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
//    for(n = 1; n <= 100; n++)
//    {
//        step = 0;
//        v.clear();
//        for(int i = 2; i * i <= n; i++)
//            if(n % i == 0)
//            {
//                v.PB(i);
//                if(n / i != i) v.PB(n / i);
//            }
//        for(int i = 1; i <= n; i++) ans[i] = 0;
//        for(int i = 1; i <= n; i++) if(ans[i] == 0)
//            {
//                step++;
//                add(i);
//                while(!q.empty())
//                {
//                    for(auto x : v)
//                    {
//                        add(q.front() + x);
//                        add(q.front() - x);
//                    }
//                    q.pop();
//                }
//            }
////        for(int i = 1; i <= n; i++) cout<<ans[i]<<" ";
//        if(!v.empty()&& step > 1) cout<<n<<" - "<<step<<endl;
//    }
    ll top,edd,x,n;
    cin>>n;
    top = 0;
    for(ll i = 2; i * i <= n; i++) if(n % i == 0)
    {
        top = i;
        break;
    }
    if(top == 0) top = n;
    x = n;
    edd = 1;
    if(n == 1) return cout<<1,0;
    while(x > 1)
    {
        if(x == 1) break;
        if(x % top) edd = 0;
        x /= top;
    }
    if(edd) cout<<top;
    else cout<<1;
    return 0;
}
