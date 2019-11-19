#include <bits/stdc++.h>
#define ll long long
#define ld long double
#define mod 1000000007
#define mod1 998244353
#define timepass 1073741824
#define MAXN 200000 + 5
#define LOGN 20
#define over ((1ll << 32))
using namespace std;
#define N 2005
 
/*#include<ext/pb_ds/assoc_container.hpp>
#include<ext/pb_ds/tree_policy.hpp>
using namespace __gnu_pbds;
/*template <typename T>
using ordered_set = tree<T, null_type, less<T>, rb_tree_tag, tree_order_statistics_node_update>;*/
 
#define pb push_back
#define mp make_pair
#define ff first
#define ss second
#define int ll 
#define all(arr) arr.begin() , arr.end()
#define FAST ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL)
#define rep(i , a , n) for(int i = a ; i < n ; i++)
#define rrep(i , n , a) for (int i = n - 1 ; i >= a ; i--)
#define ms(arr , val) memset(arr , val , sizeof(arr))
#define sp(a , x) cout << fixed << setprecision(a) << x << endl; 
#define siz(temp) (ll)temp.size()
#define len(temp) (ll)temp.length()
#define s(arr) sort(all(arr))
#define r(arr) reverse(all(arr))
#define rs(arr) s(arr) ; r(arr)
#define pi acos(-1)
#define con continue
#define endl "\n"
#define w(q) while(q--)
 
//debug
#define trace1(x)                cout<<#x<<": "<<x<<endl
#define trace2(x, y)             cout<<#x<<": "<<x<<" | "<<#y<<": "<<y<<endl
#define trace3(x, y, z)          cout<<#x<<":" <<x<<" | "<<#y<<": "<<y<<" | "<<#z<<": "<<z<<endl
#define trace4(a, b, c, d)       cout<<#a<<": "<<a<<" | "<<#b<<": "<<b<<" | "<<#c<<": "<<c<<" | "<<#d<<": "<<d<<endl
#define trace5(a, b, c, d, e)    cout<<#a<<": "<<a<<" | "<<#b<<": "<<b<<" | "<<#c<<": "<<c<<" | "<<#d<<": "<<d<<" | "<<#e<< ": "<<e<<endl
#define trace6(a, b, c, d, e, f) cout<<#a<<": "<<a<<" | "<<#b<<": "<<b<<" | "<<#c<<": "<<c<<" | "<<#d<<": "<<d<<" | "<<#e<< ": "<<e<<" | "<<#f<<": "<<f<<endl
#define trace7(a, b, c, d, e, f , g) cout<<#a<<": "<<a<<" | "<<#b<<": "<<b<<" | "<<#c<<": "<<c<<" | "<<#d<<": "<<d<<" | "<<#e<< ": "<<e<<" | "<<#f<<": "<< f << " | "<< #g <<": "<<g<<endl
#define trace8(a, b, c, d, e, f , g , h) cout<<#a<<": "<<a<<" | "<<#b<<": "<<b<<" | "<<#c<<": "<<c<<" | "<<#d<<": "<<d<<" | "<<#e<< ": "<<e<<" | "<<#f<<": "<< f << " | " << #g <<": "<< g <<" | "<<#h<< ": " << h << endl
 
typedef pair<int , int> pii;
typedef pair<int , pii> piii;
typedef vector<int> vi;
typedef vector<pii> vpii;
typedef vector<piii> vpiii;

signed main()
{
    FAST;
    int n , m , k;
    cin >> n >> m >> k;
    vector< vector < int > > row(n + 1);
    vector< vector < int > > col(m + 1);
    rep(i , 1 , n + 1)
        row[i].pb(0);
    rep(i , 1 , m + 1)
        col[i].pb(0);
    rep(i , 0 , k)
    {
        int a , b;
        cin >> a >> b;
        row[a].pb(b);
        col[b].pb(a);
    }
    rep(i , 1 , n + 1)
        sort(all(row[i]));
    rep(j , 1 , m + 1)
        sort(all(col[j]));
    int ru = 1 , cl = 1 , rd = n , cr = m;
    int r = 1 , c = 1;
    int ans = k + 1;
    while(ru <= rd && cl <= cr)
    {
        auto it = lower_bound(all(row[r]) , c);
        int next = -1;
        if (it == row[r].end())
            next = cr;
        else
        {
            next = min(cr , *it - 1);
        }
        ans = ans + next - c;
        ru++;
        c = next;
        cr = min(cr , next);
        //trace8(r , c , next , ans , ru , cr , rd , cl);
        if (!(ru <= rd && cl <= cr))
            break;
        it = lower_bound(all(col[c]) , r);
        if (it == col[c].end())
            next = rd;
        else
            next = min(rd , *it - 1);
        ans = ans + next - r;
        rd = min(rd , next);
        cr--;
        r = next;
        //trace8(r , c , next , ans , ru , cr , rd , cl);
        if (!(ru <= rd && cl <= cr))
            break;
        it = lower_bound(all(row[r]) , c);
        if (it == row[r].begin())
            c = cl;
        else
        {
            --it;
            next = max(cl , *it + 1);
        }
        ans = ans + c - next;
        rd--;
        cl = max(cl , next);
        c = next;
        //trace8(r , c , next , ans , ru , cr , rd , cl);
        if (!(ru <= rd && cl <= cr))
            break;
        it = lower_bound(all(col[c]) , r);
        if (it == col[c].begin())
        {
            r = ru;
        }
        else
        {
            --it;
            next = max(*it + 1 , ru);
        }
        ans = ans + r - next;
        cl++;
        ru = max(ru , next);
        r = next;
        //trace8(r , c , next , ans , ru , cr , rd , cl);
    }
    if (ans == n * m)
    {
        cout << "Yes\n";
    }
    else
        cout << "No\n";
    return 0;
}