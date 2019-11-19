#include<bits/stdc++.h>
/*---------------------Define--------------------*/
#define int long long
#define next nextt
#define pii pair<int,int>
#define fi first
#define se second
#define rd random
#define ll long long
#define taskname ""
#define pb push_back
#define mp make_pair
#define pb push_back
#define popb pop_back
#define popf pop_front
#define pf push_front
/*-------------------necesary---------------------*/
using namespace std;
mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
/*------------------limit-------------------------*/
const int base  = 1e9+7;
const int oo = 1e6 + 10;
const int gh = 1e3 + 3 ;
const int inf = 1e15 + 5 ;
/*-----------------globalvari-----------------------*/
int n,m,k,q;
int a[oo][3];
vector<int> con[oo];
/*-----------------code-----------------------*/


void input()
{
    //read
    cin>>n;
    for(int j=1;j<=3;j++)
        for(int i=1;i<=n;i++)
            cin>>a[i][j];
    int x,y;
    for(int i=1;i<n;i++)
    {
        cin>>x>>y;
        con[x].pb(y);
        con[y].pb(x);
        if(con[x].size()>=3) {cout<<-1;exit(0);}
        if(con[y].size()>=3) {cout<<-1;exit(0);}
    }
}

void cre()
{

}

int ok[oo];
int col[oo];
int res[oo];

void solve()
{
    cre();
    int ans = inf;
    int x,y;
    vector<int> v;
    for(int i=1;i<=n;i++)
        if(con[i].size()==1) x = i;
    y = con[x][0];
    ok[x]= 1;
    ok[y] = 1;
    v.pb(x);
    v.pb(y);

    while(v.size()!=n)
    {
        for(int i=0;i<con[y].size();i++)
        if(ok[con[y][i]]==0) {y = con[y][i];ok[y]=1;break;}
        v.pb(y);
    }


    for(int i=1;i<=3;i++)
        for(int j=1;j<=3;j++)
            {
                int s = 0;
                if(i==j) continue;
                col[v[0]] = i;
                col[v[1]] = j;
                int t=6-i-j;
                int ii=i,jj=j;
                for(int k = 2 ; k<n ; k++)
                    {
                        t = 6 - ii - jj;
                        col[v[k]] = t;
                        ii=jj,jj=t;
                    }
                for(int k=0;k<n;k++ )
                {
                    s += a[v[k]][col[v[k]]];
                }
                if(ans>s)
                {
                    ans = s;
                    for(int k=0;k<n;k++)
                        res[v[k]] = col[v[k]];
                }
                //ans = min(ans,s);
            }
    cout<<ans<<"\n";
    for(int i=1;i<=n;i++)
        cout<<res[i]<<" ";

    //for(int i=1;i<=n;i++)

    //int x = 1;
    //int y = con[1][0];

    //main code here :))
}

void ouput()
{

    //write
}

int32_t main()
{

    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    //#ifndef ONLINE_JUDGES
    if (ifstream("test.txt"))
    {
        freopen("test.txt", "r", stdin);
        #ifdef CHECKING
            freopen(taskname".out", "w", stdout);
        #else
            //\freopen("test.out", "w", stdout);
        #endif //CHECKING
    }
    else if (ifstream(taskname".inp"))
    {
        freopen(taskname".inp", "r", stdin);
        freopen(taskname".out", "w", stdout);
    }
    //#endif // ONLINE_JUDGES
    int t=1;
   // cin>>t;

    while(t--)
    {
    input();
    solve();
    ouput();
    }
}

//ilove??<3
