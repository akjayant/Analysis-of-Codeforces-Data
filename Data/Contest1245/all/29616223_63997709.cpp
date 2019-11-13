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
#define tam 400056
#define offset 200056
 
const int MOD=1e9+7;
 
int main()
{
    std::ios::sync_with_stdio(false); cin.tie(0);
    int casos;
    cin>>casos;
    forr(i,0,casos)
    {
        int a,b;
        cin>>a>>b;
        if (__gcd(a,b)==1)
            cout<<"Finite\n";
        else
            cout<<"Infinite\n";
    }
         
}
// 