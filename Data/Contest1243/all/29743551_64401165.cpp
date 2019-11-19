#include<bits/stdc++.h>
using namespace std;
int cnt1[26];
int cnt2[26];
typedef pair<int,int> pii;
#define fi first
#define se second
#define ll long long
int main()
{
    ios::sync_with_stdio(false);
    ll n;
    cin>>n;
    int p=sqrt(n);
    vector<ll>vec;
    for(int i=2;i<=p;i++)
    {
        bool f=0;
        while(n%i==0) f=1,n/=i;
        if(f) vec.push_back(i);
    }
    if(n!=1) vec.push_back(n);
    if(vec.size()>=2 || vec.size()==0) cout<<1<<'\n';
    else cout<<vec[0]<<'\n';
}
