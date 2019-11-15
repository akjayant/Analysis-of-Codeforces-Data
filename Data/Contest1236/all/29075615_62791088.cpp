#include <bits/stdc++.h>
#define f first
#define s second
#define MOD 1000000007
#define PMOD 998244353
#define pb(x) push_back(x)
using namespace std;

typedef long long int ll;
typedef pair<int,int> pii;
typedef pair<ll,ll> plii;
typedef pair<int, pii> piii;
const int INF = 1e9+10;
const ll LINF = 1LL*INF*INF;
const int MAXN = 2e5+10;
const int MAXM = 5e3+10;

priority_queue<int> pq;
vector<vector<int> > graph;
queue<int> que;

int A[510][510];
char S[MAXN];

int main()
{
    int n,m,k,a,b,x,y,q;
    int sum = 0;
    int cnt = 0;
    int mx = 0;
    int mn = INF;
    int cur = 0, idx = -1;
    int tc;

    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    cin>>n;

    for(int j=1;j<=n;j++){
        if(j&1){
            for(int i=1;i<=n;i++)
                A[i][j] = ++cnt;
        }
        else {
            for(int i=n;i>=1;i--)
                A[i][j] = ++cnt;
        }
    }

    for(int i=1;i<=n;i++,cout<<"\n")
        for(int j=1;j<=n;j++)
            cout<<A[i][j]<<" ";

    return 0;
}
