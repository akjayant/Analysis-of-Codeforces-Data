#include <bits/stdc++.h>
//#include <ext/pb_ds/assoc_container.hpp>
//#include <ext/pb_ds/tree_policy.hpp>
//typedef tree < int , null_type, less <int>, rb_tree_tag, tree_order_statistics_node_update> TREE;
#define ll long long int
#define ull unsigned long long int
#define pb push_back
#define mp make_pair
#define vi vector<int>
#define pii pair<int,int>
#define pss pair<short,short>
#define pld pair<long double,long double >
#define ld long double
#define piii  pair<pii,int>
#define vii vector<pair<int,int> >
#define st first
#define nd second
#define pll pair<ll,ll>
#define speed ios::sync_with_stdio(false);cin.tie();cout.tie();
#define M_PI 3.14159265358979323846
//#define int long long
const int mod=1000000007;
//const int mod=998244353;
const int inf=1000000009;
const long long INF=1000000000000000009;
const long long big=1000000000000000;
const long double eps=0.0000000001;
using namespace std;
int main()
{
    speed
    int q;
    cin>>q;
    for(int i=1;i<=q;i++)
    {
        int a,b,c,d,k;
        cin>>a>>b>>c>>d>>k;
        int x=a/c,y=b/d;
        if(a%c!=0)
            x++;
        if(b%d!=0)
            y++;
        if(x+y>k)
            cout<<"-1\n";
        else
            cout<<x<<" "<<y<<endl;
    }
    return 0;
}
