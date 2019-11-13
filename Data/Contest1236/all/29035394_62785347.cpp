#include<bits/stdc++.h>
using namespace std;
#define FasterIO ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0)

typedef unsigned long long ull;
typedef long long ll;
typedef double db;

#define mem(a,x) memset(a,x,sizeof(a))
#define pb push_back
#define ff first
#define ss second
#define mk make_pair
#define pi pair<int,int>
#define vi vector<int>
#define pL pair<ll,ll>
#define vL vector<ll>
#define vp vector<pi>
#define vpL vector<pL>

const int MX=300000;
const ll inf=1e18;
const ll mod=1e9+7;

int main()
{
    FasterIO;
    int q, n;
    cin>>q;
    while(q--)
    {
        int a, b, c;
        cin>>a>>b>>c;
        int sm=0;
        sm=min(c/2, b)*3; b-=min(c/2, b);
        sm+=min(a, b/2)*3;
        cout<<sm<<endl;
    }
    return 0;
}
