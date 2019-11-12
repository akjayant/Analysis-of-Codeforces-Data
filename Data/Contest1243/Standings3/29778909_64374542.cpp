#include <bits/stdc++.h>
#pragma GCC target("avx2")
#pragma GCC optimization ("O3")
#pragma GCC optimization ("unrolled-loops")
using namespace std;
/*---------------------Define--------------------*/
#define inp "TestCode.inp"
#define out "TestCode.out"
#define pi acos(-1)
#define endl '\n'
#define X first
#define Y second
#define pb push_back
#define mp make_pair
#define pii pair<int,int>
#define ll long long
#define hash lolo
#define y1 MustDefeatGKT1
/*-----------------------------------------------*/
const long long mod=1e9+7;
const long long mod2=1e9+9;
const long long INF=1e12;
const long long oo=1e18+7;
int test=1;
/*-----------------------------------------------*/
void Varvalian()
{
    ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);

    ifstream *fi = new ifstream (inp);
    ofstream *fo = new ofstream (out);
    if(*fi)
    {
        cin.rdbuf( fi->rdbuf() );
        cout.rdbuf( fo->rdbuf() );
    }

}
void db();
/*-------------------Global----------------------*/
int n;
int a[1010];
/*------------------Functions--------------------*/

/*-----------------------------------------------*/

void In()
{
    cin>>n;
    for(int i=1;i<=n;i++)
        cin>>a[i];
}

void Solve()
{
    In();

    sort(a+1, a+1+n);

    int ans = 0;
    for(int i=1;i<=n;i++)
    {
        ans = max(ans, min(n-i+1, a[i]));
    }

    cout<<ans<<endl;
}

void db()
{

}

int32_t main()
{
    Varvalian();

    cin>>test;while(test--)
    Solve();
}
