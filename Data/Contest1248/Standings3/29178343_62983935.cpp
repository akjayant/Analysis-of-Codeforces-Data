#include <bits/stdc++.h>

using namespace std;

#define taskname "B"
#define forinc(i, a, b) for (int i = (a), _b = (b); i <= _b; ++i)
#define fordec(i, a, b) for (int i = (a), _b = (b); i >= _b; --i)
#define foreach(i, x) for (auto &i : x)
#define ms(x, n) memset(x, n, sizeof(x))
#define sz(x) int((x).size())
#define all(x) (x).begin(), (x).end()
#define uni(x) (x).erase(unique(all(x)), (x).end())
#define fi first
#define se second
#define pb push_back
#define pf push_front

template<typename TH>
void _dbg(const char* sdbg, TH h)
{
	cerr << sdbg << " = " << h << "\n";
}

template<typename TH, typename... TA>
void _dbg(const char* sdbg, TH h, TA... t)
{
	while (*sdbg != ',') cerr << *sdbg++;
	cerr << " = " << h << ",";
	_dbg(sdbg + 1, t...);
}

#define db(...) _dbg(#__VA_ARGS__, __VA_ARGS__)
#define chkpt cerr << "--- Checkpoint here ---\n";

const int N=1e5+5;

int n;
int64_t a[N];

int64_t Calc()
{
    if(n==1)
    {
        return a[1]*a[1];
    }
    vector<int> order;
    int l=1,r=n;
    while(l<r)
    {
        order.pb(l);
        l++;
        order.pb(r);
        r--;
    }
    if(sz(order)<n)
    {
        order.pb(l);
    }
    int64_t x=0,y=0;
    forinc(i,0,sz(order)-1)
    {
        if(i%2==0)
        {
            x+=a[order[i]];
        }
        else
        {
            y+=a[order[i]];
        }
    }
    return x*x+y*y;
}

void Solve()
{
    cin>>n;
    forinc(i,1,n) cin>>a[i];
    sort(a+1,a+1+n);
    int64_t ans=0;
    ans=max(ans,Calc());
    reverse(a+1,a+1+n);
    ans=max(ans,Calc());
    cout<<ans<<'\n';
}

int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	#ifndef ONLINE_JUDGE
	freopen(taskname".INP","r",stdin);
	#endif // ONLINE_JUDGE
	Solve();
    return 0;
}
