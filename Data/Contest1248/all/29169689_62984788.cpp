#include <bits/stdc++.h>
using namespace std;
#define ll long long int
#define rep(i,s,f) for(i=s;i<f;i++)
#define print(v) for(auto &z:v) cout<<z<<' ';cout<<'\n'
#define hi cout<<'h'<<'i'<<'\n' 
#define pb push_back
#define pii pair<int,int>
#define F first
#define S second
#define B begin()
#define E end()
#define vi vector<int>
#define vii vector<pair<int,int>>
#define boost ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0)
#define clean(arr) memset(arr,0,sizeof(arr))
#define mod 1000000007
#define mod2 998244353
#define space 100005
//<<fixed << setprecision(9)

int main()
{
    int n,i,j,t;
    boost;

    cin>>n;
    int arr[n];
    rep(i,0,n)cin>>arr[i];
    sort(arr,arr+n);
    int m=(n+1)/2;
    ll x=0,y=0;
    
    for(i=n-1;i>n-1 - m;i--)x+=arr[i];
    for(i=n-1-m;i>=0;i--)y+=arr[i];
    
    cout<<(x*x+y*y);


    return 0;
}

