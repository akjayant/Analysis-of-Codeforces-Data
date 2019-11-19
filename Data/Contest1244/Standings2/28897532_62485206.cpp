#include <bits/stdc++.h>
using namespace std;

#ifdef LOCAL
  #define watch(x) cout << (#x) << " is " << (x) << '\n'
  #define dashline() cout << "=============\n"
#else
  #define watch(x)
  #define dashline()
#endif

typedef long long ll;
typedef vector<int> vi;
typedef pair<int,int> pii;

const int MX = 1e9;
const ll MX2 = 3e18;
const double pi = acos(-1);

const int MOD = 1e9+7;
const int SZ = 524288;

ll cost[4][100011];
vi v[100011];
int p[100011];
int order[100011], osz;

int ans[100011];

void dfs(int id, int par, int st=0)
{
    order[++osz]=id;
    p[id]=st;
    st++; st%=3;
    for(int x:v[id]) if (x!=par) dfs(x,id,st);
}

int main()
{
    cin.tie(0); cout.tie(0);
    ios::sync_with_stdio(0);

    int n; cin>>n;
    int i,j,a,b;
    for(i=1;i<=3;i++) for(j=1;j<=n;j++) cin>>cost[i][j];

    for(i=1;i<n;i++)
    {
        cin>>a>>b;
        v[a].push_back(b);
        v[b].push_back(a);
        if (v[a].size()>2 || v[b].size()>2)
        {
            cout<<-1;
            return 0;
        }
    }
    int root;
    for(i=1;i<=n;i++) if (v[i].size()==1) break;
    root=i;
    dfs(root,root);

    int df[3]={1,2,3},id;
    ll mx=MX2, v;
    do
    {
        v=0;
        for(i=1;i<=n;i++)
        {
            id=order[i];
            v += cost[df[p[id]]][id];
        }
        if (v<mx)
        {
            mx=v;
            for(i=1;i<=n;i++)
            {
                id=order[i];
                ans[id] = df[p[id]];
            }
        }
    }while(next_permutation(df,df+3));

    cout<<mx<<'\n';
    for(i=1;i<=n;i++) cout<<ans[i]<<' ';

    return 0;
}
