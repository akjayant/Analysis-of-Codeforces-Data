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
#define res(a,z,n) for(int i = 1 ; i<=n ; i ++) a[i] = z;
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
int a[oo];
string s1,s2;
int cnt[30];
set<int> vt[30];
/*-----------------code-----------------------*/


void input()
{
    //read
    cin>>n;
    memset(cnt,0,sizeof(cnt));
    cin>>s1>>s2;

}

void cre()
{
    //sort(a+1,a+n+1,greater<int>() );
    for(int i=0;i<n;i++)
    {
        //vt[s1[i]-'a'].insert(i);
        cnt[s2[i]-'a']++;
        cnt[s1[i]-'a']++;
    }


}

void solve()
{
    cre();

    int cnt = 0;
    vector<int> q;
    for(int i=0;i<n;i++)
        if(s1[i]!=s2[i]) q.pb(i),cnt++;
    if(cnt == 0) cout<<"YES\n";
    if(cnt!=2) cout<<"NO\n";

    else
    {
    swap(s1[q[0]],s2[q[1]]);
    if(s1==s2) {
            //cerr<<s1<< " " <<s2<<endl;
            cout<<"YES\n";

    }
    else cout<<"NO\n";
    }
    //queue<pii> q;

    //if(a[i]<i) {cout<<i-1<<"\n";return ;}
    //cout<<n<<"\n";
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
    cin>>t;

    while(t--)
    {
    input();
    solve();
    ouput();
    }
}

//ilove??<3
