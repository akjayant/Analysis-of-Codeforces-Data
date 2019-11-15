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
    vector<pi>ans;
    for(int i = 0 ;i<n; i++)
    {
        char c = a[i];
        if(a[i] == b[i]) continue;
        bool ch1 = false;
        int x;
        for(int j = i+1; j<n; j++)
        {
            if(a[j] == c)
            {
                ch1 = true;
                x = j;
                break;
            }
        }
            if(ch1)
            {
                ans.pb({x,i});
                char cc = a[x];
                a[x] = b[i];
                b[i] = cc;

            }
        else
        {
            for(int j = i+1; j<n; j++)
            {
                if(b[j] == c)
                {
                    x = j;
                    break;
                }
            }
            ans.pb({x,x});
            ans.pb({x,i});
            char cc = a[x];
            a[x] = b[i];
            b[x] = cc;
        }
    }
    cout<<"Yes\n";
    cout<<ans.size()<<"\n";
    for(int i = 0 ;i<ans.size(); i++) cout<<ans[i].f+1<<" "<<ans[i].s+1<<"\n";
}
return 0;
}
