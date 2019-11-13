#include<bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp> 
using namespace __gnu_pbds; 
using namespace std;

#define ff              first
#define ss              second
#define int             long long
#define pb              push_back
#define mp              make_pair
#define pii             pair<int,int>
#define vi              vector<int>
#define mii             map<int,int>
#define pqb             priority_queue<int>
#define pqs             priority_queue<int,vi,greater<int> >
#define setbits(x)      __builtin_popcountll(x)
#define zrobits(x)      __builtin_ctzll(x)
#define mod             1000000007
#define inf             1e18
#define ps(x,y)         fixed<<setprecision(y)<<x
#define mk(arr,n,type)  type *arr=new type[n];
#define w(x)            int x; cin>>x; while(x--)
#define pw(b,p)         pow(b,p) + 0.1
mt19937                 rng(chrono::steady_clock::now().time_since_epoch().count());

typedef tree<int, null_type, less<int>, rb_tree_tag, tree_order_statistics_node_update> pbds;

void c_p_c()
{
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    #ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    #endif
}

int32_t main()
{
    c_p_c();
    w(t)
    {
        int n,r,p,s; cin>>n>>r>>p>>s;

        string st; cin>>st;

        int rd=0,pd=0,sd=0;

        for(auto ch : st)
        {
            if(ch=='R')
                rd++;
            else if(ch=='S')
                sd++;
            else
                pd++;
        }

        int req = (n+1)/2;

        int can = min(r,sd) + min(p,rd) + min(s,pd);

        if(can<req)
        {
            cout<<"NO\n";
        }

        else
        {
            cout<<"YES\n";

            string ans;

            for(auto ch : st)
            {
                ans += '0';
            }

            for(int i=0;i<n;++i)
            {
                int ch=st[i];

                if(ch=='R' && p)
                    ans[i]='P',p--;

                if(ch=='P' && s)
                    ans[i]='S',s--;

                if(ch=='S' && r)
                    ans[i]='R',r--;
            }

            for(int i=0;i<n;++i)
            {
                if(ans[i]!='0')
                    continue;

                if(r)
                    ans[i]='R',r--;

                else if(s)
                    ans[i]='S',s--;

                else if(p)
                    ans[i]='P',p--;
            }

            cout<<ans<<'\n';
        }
    }
    return 0;
}