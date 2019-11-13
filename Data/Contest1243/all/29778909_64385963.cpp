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
    bool flag=1;
    for(int i=0;i<n;i++)
    {
        if(s[i]!=t[i])
        {
            flag=0;
            break;
        }
    }
    if(flag)
    {
        cout<<"No"<<endl;
        return;
    }
    int cnt=0;
    for(int i=0;i<n;i++)
    {
        if(s[i] != t[i])
        {
            cnt++;
            flag=0;
            for(int j=i+1;j<n;j++)
            {
                if(s[j] != t[j])
                {
                    if(s[i] == s[j] && t[i] == t[j])
                    {
                        cnt++;
                        flag=1;
                        swap(s[j], t[i]);
                        break;
                    }
                    else
                    {
                        cout<<"No"<<endl;
                        return;
                    }
                    break;
                }
            }
            if(!flag)
            {
                cout<<"No"<<endl;
                return;
            }
            else
                break;
        }
    }
    for(int i=0;i<n;i++)
    {
        if(s[i]!=t[i])
        {
            cout<<"No"<<endl;
            return;
        }
    }
    cout<<"Yes"<<endl;


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
