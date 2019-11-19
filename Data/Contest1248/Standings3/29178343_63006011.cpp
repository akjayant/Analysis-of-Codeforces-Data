#include <bits/stdc++.h>

using namespace std;

#define taskname "C"
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

const int N=1e5+5,MOD=1e9+7;

const int dx[]={-1,0,1,0};
const int dy[]={0,-1,0,1};

int a[10][10];
int fib[N],sumFib[N];

int Bit(int x,int i)
{
    return (x>>i)&1;
}

void Test(int n,int m)
{
    int ans=0;
    int maxBit=(1<<(n*m))-1;
    forinc(mask,0,maxBit)
    {
        forinc(i,1,n)
        {
            forinc(j,1,m)
            {
                a[i][j]=Bit(mask,(i-1)*m+j-1);
            }
        }
        bool can=true;
        forinc(i,1,n)
        {
            forinc(j,1,m)
            {
                int cnt=0;
                forinc(k,0,3)
                {
                    int ni=i+dx[k],nj=j+dy[k];
                    if(1<=ni&&ni<=n&&1<=nj&&nj<=m)
                    {
                        if(a[ni][nj]==a[i][j])
                        {
                            cnt++;
                        }
                    }
                }
                if(cnt>1)
                {
                    can=false;
                }
            }
        }
        if(can)
        {
            ans++;
        }
    }
    cout<<ans<<'\n';
}

void Solve()
{
    int n,m;
    cin>>n>>m;
    fib[1]=1;
    fib[2]=1;
    forinc(i,3,N-1)
    {
        fib[i]=(fib[i-1]+fib[i-2])%MOD;
    }
    forinc(i,1,N-1)
    {
        sumFib[i]=(sumFib[i-1]+fib[i])%MOD;
    }
    int ans=(fib[m+1]+sumFib[n-1])%MOD;
    ans=(int64_t)ans*2%MOD;
    cout<<ans<<'\n';
}

int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	#ifndef ONLINE_JUDGE
	freopen(taskname".INP","r",stdin);
	#endif // ONLINE_JUDGE
//	forinc(n,2,2)
//	{
//	    forinc(m,1,10)
//	    {
//	        db(n,m);
//	        Test(n,m);
//	    }
//	}
    Solve();
    return 0;
}
