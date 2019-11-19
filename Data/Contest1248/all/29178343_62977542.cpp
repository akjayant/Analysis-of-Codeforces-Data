#include <bits/stdc++.h>

using namespace std;

#define taskname "A"
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

void Solve()
{
    int nTest;
    cin>>nTest;
    while(nTest--)
    {
        int n;
        cin>>n;
        vector<int> f(2,0),g(2,0);
        forinc(i,1,n)
        {
            int x;
            cin>>x;
            f[x%2]++;
        }
        cin>>n;
        forinc(i,1,n)
        {
            int x;
            cin>>x;
            g[x%2]++;
        }
        cout<<(int64_t)f[0]*g[0]+(int64_t)f[1]*g[1]<<'\n';
    }
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
