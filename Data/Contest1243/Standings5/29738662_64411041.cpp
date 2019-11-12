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
bool check(string s)
{
    sort(ALL(s));ll siz=s.size();
    for(int i=0;i<(siz-1);i++)
    {
        if(s[i]==s[i+1])
            i++;
        else
        {
            return true;
        }
    }
    return false;

}
void solve()
{
    ll n;cin>>n;
    string s,t;
    cin>>s>>t;
    string s1,s2;
    vector<pair<char,ll> >vp1,vp2;
    for(int i=0;i<s.size();i++)
    {
        if(s[i]!=t[i])
        {
            s1+=s[i];
            vp1.pb(mp(s[i],i+1));
            vp2.pb(mp(t[i],i+1));
            s2+=t[i];
        }
    }

    if(s1.size()==0)
    {
        sort(ALL(s));
        ll siz=s.size()-1;
        for(int i=0;i<siz;i++)
        {
            if(s[i]==s[i+1])
            {
                cout<<"Yes"<<endl;
                cout<<i<<" "<<i+1<<endl;
                return ;
            }
        }
    }

    string st=s1+s2;
    if(check(st))
    {
        cout<<"No"<<endl;
        return ;
    }
    //sort(ALL(vp1));sort(ALL(vp2));
    cout<<"Yes"<<endl;
    vpair sol;
    for(int i=0;i<vp1.size();)
    {
        if(vp1[i].F==vp2[i].F)
            {i++;
            continue;
            }
        char c=vp1[i].F;
        ll ind=vp1[i].S,flag=0;
        for(int j=(i+1);j<vp1.size();j++)
        {
            if(c==vp1[j].F)
            {
                sol.pb(mp(vp1[j].S,vp2[i].S));
                vp1[j].F=vp2[i].F;
                flag=1;
                i++;
                break;
            }
        }
        if(!flag)
        {
            for(int j=i;j<vp2.size();j++)
            {
                if(c==vp2[j].F)
                {
                    sol.pb(mp(vp1[i+1].S,vp2[j].S));
                    ll ch= vp1[i+1].F;
                    vp1[i+1].F=vp2[j].F;
                    vp2[j].F=ch;
                }
            }
        }

    }
    cout<<sol.size()<<endl;
    fr(sol.size())
    cout<<sol[i].F<<" "<<sol[i].S<<endl;

}
int32_t main()
{
    fast;
    ll t=1;cin>>t;
    fr(t)
    solve();
}
