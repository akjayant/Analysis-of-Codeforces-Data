#include<bits/stdc++.h>
#include<algorithm>
#include <fstream>
#include <sstream>
#include <string>
using namespace std;
#define pb push_back
#define pf push_front
#define pob pop_back
#define pof pop_front
#define is insert
#define rep1(i,a,b) for(long long i=a;i<=b;i++)
#define mp make_pair
#define mh make_heap
#define F first
#define S second
//#define fin cin
//#define fout cout
#define file ifstream fin("input.txt");ofstream fout("output.txt");
#define fast ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
#define fr(n) for(int i=0;i<n;i++)
#define rep(i,a,b) for(int i=a;i<b;i++)
#define ALL(x) (x).begin(), (x).end()
#define int long long
typedef long long ll;
#define lb lower_bound
#define ub uper_bound
#define bs lower_bound
typedef pair<ll,ll> pairs;
typedef vector<ll> vi;
typedef vector<pairs> vpair;
void solve()
{
    ll n;cin>>n;
    string s,t;
    cin>>s>>t;
    string s1,s2;
    for(int i=0;i<s.size();i++)
    {
        if(s[i]!=t[i])
        {
            s1+=s[i];
            s2+=t[i];
        }
    }
    if(s1.size()>2)
    {
        cout<<"No"<<endl;return ;
    }
    else if(s1.size()==1)
    {
        cout<<"No"<<endl;return ;
    }
    else if(s1.size()==2)
    {
        if(s1[0]==s1[1] && s2[0]==s2[1])
        {
            cout<<"Yes"<<endl;
        }
        else
        {
            cout<<"No"<<endl;
        }
        return ;
    }
    else if(s1.size()==0)
    {
        sort(ALL(s));
        ll siz=s.size()-1;
        for(int i=0;i<siz;i++)
        {
            if(s[i]==s[i+1])
            {
                cout<<"Yes"<<endl;
                return ;
            }
        }
    }
    cout<<"No"<<endl;

}
int32_t main()
{
    fast;
    ll t=1;cin>>t;
    fr(t)
    solve();
}
