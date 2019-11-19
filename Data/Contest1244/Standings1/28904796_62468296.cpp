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
        int n;
        cin>>n;
        string napis;
        cin>>napis;
        int mini=inf,maks=-1;
        for(int j=0;j<n;j++)
            if(napis[j]=='1')
        {
            mini=min(mini,j+1);
            maks=max(maks,j+1);
        }
        if(maks==-1)
            cout<<n<<"\n";
        else
        {
            int wynik=max(2*(n-(mini-1)),2*(n-(n-maks)));
            cout<<wynik<<"\n";
        }
    }
    return 0;
}
