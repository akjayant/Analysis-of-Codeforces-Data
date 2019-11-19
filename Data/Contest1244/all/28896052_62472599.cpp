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
char a[oo];
/*-----------------code-----------------------*/


void input()
{
    //read
    cin>>n;
    int t1=n,t2=0,t3=0;
    for(int i=1;i<=n;i++)
        {
            cin>>a[i];
            if(a[i] == '1' )
                {
                    t1+=1;
                    t2 = max(t2,(n-i+1)*2);
                    t3 = max(t3,i*2);
                }
        }
    cout<<max(max(t1,t2),t3)<<"\n";
}

void cre()
{

}

void solve()
{
    cre();
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
