//#pragma GCC optimize(2)


#include<bits/stdc++.h>
using namespace std;
/*#include<ext/pb_ds/assoc_container.hpp>
#include<ext/pb_ds/tree_policy.hpp>
#include<ext/pb_ds/hash_policy.hpp>
#include<ext/pb_ds/trie_policy.hpp>
#include<ext/pb_ds/priority_queue.hpp>
#include<ext/rope>*/
//using namespace __gnu_cxx;
//using namespace __gnu_pbds;
//void err(istream_iterator<string> it){cerr<<endl;}
//template<typename T, typename... Args>void err(istream_iterator<string> it, T a, Args... args){cerr << *it << " = " << a << " , ";err(++it, args...);}
#define error(args...) { string _s = #args; replace(_s.begin(), _s.end(), ',', ' '); stringstream _ss(_s); istream_iterator<string> _it(_ss); err(_it, args); }
#define mem(a,b) memset((a),b,sizeof((a)))
#define fpre(x) cout<<fixed<<setprecision(x)
#define clr(v) (v).clear()
#define pii pair<int,int>
#define pdd pair<double,double>
#define pli pair<ll,int>
#define pll pair<ll,ll>
#define mp make_pair
#define eb emplace_back
#define pb emplace_back
#define ll long long
#define ld long double
#define ull unsigned long long
#define uint unsigned int
#define ushort unsigned short
#define IOS ios::sync_with_stdio(0);cin.tie(0);cout.tie(0)
#define lowbit(i) (i&(-i))
#define lson rt<<1
#define rson lson|1
#define fi first
#define se second
const double eps=1e-10;
inline int dcmp(double x)
{
    if(x<-eps)
        return -1;
    if(x>eps)
        return 1;
    return 0;
}
//-----------------------------------------------head

char s[100005];
char t[100005];
vector<pii>res;
int c[30];
int main()
{
    IOS;
    int _;
    for(cin>>_; _; --_)
    {
        int n;
        cin>>n;
        cin>>s;
        cin>>t;
        mem(c,30);
        for(int i=0; i<n; ++i)
            ++c[s[i]-'a'],++c[t[i]-'a'];
        bool ok=1;
        for(int i=0; ok&&i<26; ++i)
            if(c[i]%2==1)
                ok=0;
        if(!ok)
        {
            cout<<"No"<<endl;
            continue;
        }

        res.clear();
        for(int i=0; i<n; ++i)
        {
            if(s[i]==t[i])
                continue;
            else
            {
                bool f=0;
                int j=i+1;
                for(; j<n&&!f; ++j)
                    if(s[j]==s[i])
                    {
                        f=1;
                        break;
                    }
                if(f)
                {

                    res.pb(mp(j,i));
                    swap(s[j],t[i]);
                }
                else
                {
                    j=i+1;
                    for(; !f&&j<n; ++j)
                        if(t[j]==s[i])
                        {
                            f=1;
                            break;
                        }
                    res.pb(mp(n-1,j));
                    res.pb(mp(n-1,i));
                    swap(t[i],t[j]);
                    swap(s[n-1],t[j]);
                }
            }
        }
        cout<<"Yes"<<endl;
        cout<<res.size()<<endl;
        for(auto i:res)
            cout<<i.fi+1<<' '<<i.se+1<<endl;
    }
}
