#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
 
typedef long long       ll;
#define pb                push_back
#define mp                make_pair
#define all(a)            (a).begin(), (a).end()
#define clr(a,h)          memset(a, (h), sizeof(a))
#define F first
#define S second
#define forr(i, b, e)     for (int i = b; i < e; i++)
#define forit(i,b)        for( auto i=b.begin();i!=b.end();i++)
int faster_in(){int r=0,c;for(c=getchar();c<=32;c=getchar());if(c=='-') return -faster_in();for(;c>32;r=(r<<1)+(r<<3)+c-'0',c=getchar());return r;}
 
using namespace std;
using namespace __gnu_pbds;
 
typedef pair<int, int>  ii;
typedef pair<int,ii> iii;
typedef vector<int>     vi;
typedef vector<ii>      vii;
typedef vector<ll>      vll;
typedef tree<int,null_type,less<int>,rb_tree_tag,tree_order_statistics_node_update> ordered_multiset;
const int INF = int(1e9 + 7);
const double EPS = 1e-9;
const double PI = acos(-1);
#define tam 1000056
#define offset 200056
 
const int MOD=1e9+7;
int dp[tam];
string txt;
int f(int num)
{
    if (num<=1)
        return 1;
    if (dp[num]!=-1)
        return dp[num];
    return dp[num]=(f(num-1)+f(num-2))%MOD;
}
void go(ll &tot, char esp)
{
    int c=0;
     tot%=MOD;
    forr(i,0,txt.size())
    {
        if (txt[i]==esp)
            c++;
        else {
            tot*=f(c);
            tot%=MOD;
            c=0;
        }
    }
    tot*=f(c);
    tot%=MOD;
}
int main()
{
    //std::ios::sync_with_stdio(false); cin.tie(0);
    
    memset(dp,-1,sizeof dp);
    f(1e5);
    //cout<<"fin\n";
    cin>>txt;
    int c=0;
    ll tot=1;
    go(tot,'u');
    go(tot,'n');
    if (txt.find('w')!=-1|| txt.find('m')!=-1)
        cout<<"0\n";
    else
    cout<<tot<<endl;
         
}
// 