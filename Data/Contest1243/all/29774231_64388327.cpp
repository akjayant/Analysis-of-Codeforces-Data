#include<bits/stdc++.h>
using namespace std;

#define int long long
#define sp ios_base::sync_with_stdio(false),cin.tie(NULL),cout.tie(NULL)
#define cps CLOCKS_PER_SEC
#define f first
#define s second
#define debug1(x) cout<<x<<"\n"
#define debug2(x,y) cout<<x<<" "<<y<<"\n"
#define debug3(x,y,z) cout<<x<<" "<<y<<" "<<z<<"\n"
#define nl cout<<"\n";
#define pq priority_queue
#define inf 99999999999999999
#define test cout<<"abcd\n";
#define pi pair<int,int>
#define pii pair<int,pi>
#define pb push_back
#define mxn 200005
#define mxnn 500
#define mod (ll)998244353

int32_t main(){
int t;
cin >>t;
while(t--)
{
    int n;
    cin >>n;
    string a,b;
    cin >>a >>b;
    map<char,int>mp;
    for(int i= 0; i<a.size(); i++) mp[a[i]]++;
    for(int j = 0 ;j<b.size(); j++) mp[b[j]]++;
    bool ch = true;
    for(int i = 0; i<26; i++)
    {
        if(mp['a'+i]%2 != 0) ch = false;
    }
    if(!ch)
    {
        cout<<"No\n";
        continue;
    }
    vector<int>ans;
    for(int i = 0; i<n; i++)
    {
        if(a[i] != b[i])
        {
            ans.pb(i);
        }
    }
    if(ans.size() == 0)
    {
        cout<<"Yes\n";
    }
    else if(ans.size() == 2)
    {
        int i = ans[0];
        int j = ans[1];
        if(a[i] == a[j] && b[i] == b[j]) cout<<"Yes\n";
        else cout<<"No\n";
    }
    else cout<<"No\n";
}
return 0;
}
