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
string s, t;
/*------------------Functions--------------------*/
bool check()
{
    int cnt[30];
    for(int i=1;i<=26;i++)
        cnt[i]=0;
    for(int i=0;i<n;i++)
    {
        cnt[s[i]-'a'+1]++;
        cnt[t[i]-'a'+1]++;
    }
    for(int i=1;i<=26;i++)
        if(cnt[i]%2==1)
            return 1;
    return 0;
}
/*-----------------------------------------------*/

void In()
{
    cin>>n;
    cin>>s>>t;
}

void Solve()
{
    In();

    if(check())
    {
        cout<<"No"<<endl;
        return;
    }

    vector<pii> ans;

    for(int i=0;i<n;i++)
    {
        if(s[i] == t[i])
            continue;
        else
        {
            for(int j=i+1;j<n;j++)
            {
                if(s[j] == s[i])
                {
                    ans.pb(mp(j+1,i+1));
                    swap(s[j], t[i]);
                    //cout<<s<<endl<<t<<endl<<endl;
                    break;
                }
                if(t[j] == s[i])
                {
                    ans.pb(mp(j+1,j+1));
                    ans.pb(mp(j+1,i+1));
                    swap(s[j], t[j]);
                    swap(s[j], t[i]);
                    //cout<<i<<" "<<j<<endl<<s<<endl<<t<<endl<<endl;
                    break;
                }
            }
        }
    }

    cout<<"Yes"<<endl;
    cout<<ans.size()<<endl;
    for(int i=0;i<ans.size();i++)
        cout<<ans[i].X<<" "<<ans[i].Y<<endl;

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
