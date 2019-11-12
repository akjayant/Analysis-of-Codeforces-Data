#include <bits/stdc++.h>
using namespace std;
typedef long long int ll;
ll mod=1000000007;
bool check(pair<ll,ll> p1,pair<ll,ll> p2)
{
    return p2.second>p1.second;
}
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    ll n,k;
    cin>>n;
    ll ans=n*n;
    vector<ll> v[n];
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<n;j++)
        {
            v[j].push_back(ans--);
        }
        if(ans==0)
        {
            break;
        }
        for(int j=n-1;j>=0;j--)
        {
            v[j].push_back(ans--);
        }
    }
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<n;j++)
        {
            cout<<v[i][j]<<" ";
        }
        cout<<endl;
    }
	return 0;
}