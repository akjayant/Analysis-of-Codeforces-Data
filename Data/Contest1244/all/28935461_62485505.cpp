#include<bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp> // Common file
#include <ext/pb_ds/tree_policy.hpp> // Including tree_order_statistics_node_update
using namespace std;
using namespace __gnu_pbds;

#define lsc(x)      scanf("%lld",&x)
#define sc(x)       scanf("%d",&x)
#define lpr(x)      printf("%lld ",x)
#define pr(x)       printf("%d ",x)
#define n_l         printf("\n")
#define VI          vector<int>
#define VII         vector<long long int>
#define MI          map<int, int>
#define PI          pair<int, int>
#define m_p         make_pair
#define pb          push_back
#define mset(x,y)   memset(x,y,sizeof(x))
#define sz(v)       (int)v.size()
#define all(v)      v.begin(), v.end()
#define fr(i, a, n) for(int i=a;i<=n;i++)
mt19937 rng32(chrono::steady_clock::now().time_since_epoch().count());
const int N=(int)1e6+5;
const int mod = 1000000007;
typedef long long ll;
// order_of_key (val): returns the no. of values strictly less than val
// find_by_order (k): returns the kth largest element iterator.(0-based)
// vector<int>::iterator itr=lower_bound(v.begin(),v.end(),x);
// s.substr(pos[0-indexed], len(default=till end))
typedef tree<ll,null_type,less<ll>,rb_tree_tag,tree_order_statistics_node_update> ordered_set;
#define TRACE

#ifdef TRACE
#define trace(...) __f(#__VA_ARGS__, __VA_ARGS__)
template <typename Arg1>
void __f(const char* name, Arg1&& arg1){
	cerr << name << " : " << arg1 << std::endl;
}
template <typename Arg1, typename... Args>
void __f(const char* names, Arg1&& arg1, Args&&... args){
	const char* comma = strchr(names + 1, ',');cerr.write(names, comma - names) << " : " << arg1<<" | ";__f(comma+1, args...);
}
#else
#define trace(...)
#endif
#define int long long
set<int> :: iterator fi, ses, se, mx;
set<int> s;
map<int, int> mp;
signed main(){
    int n, k;lsc(n);lsc(k);
    fr(i, 1, n){
        int x;lsc(x);
        mp[x]++;
        s.insert(x);
    }
    while(k){
        if (s.size()==1){
            pr(0);n_l;
            return 0;
        }
        fi = s.begin();
        se = s.find(*s.rbegin());
        //trace(*se);
        int vfi = *fi;
        int vse = *se;
        //trace(k, vfi, vse, mp[vfi], mp[vse]);
        if (mp[vfi] <= mp[vse]){
            mx = ++fi;
            int vmx = *mx;
            int diff = vmx - vfi;
            int req = diff * mp[vfi];
            //trace(1, vmx, diff, req);
            if (req <= k){
                k-=req;
                mp[vmx]+=mp[vfi];
                mp[vfi]=0;
                s.erase(vfi);
            }
            else{
                int rm = k/mp[vfi];
                k=0;
                //mp[vfi + rm] = mp[vfi];
                //mp[vfi]=0;
                s.erase(vfi);
                s.insert(vfi+rm);
            }
        }else{
            mx = --se;
            int vmx = *mx;
            int diff = vse -vmx;
            int req = diff * mp[vse];
            //trace(vmx, diff, req);
            if (req <= k){
                k-=req;
                mp[vmx] += mp[vse];
                mp[vse]=0;
                s.erase(vse);
            }
            else{
                int rm = k/mp[vse];
                k=0;
                //mp[vfi + rm] = mp[vfi];
                //mp[vfi]=0;
                s.erase(vse);
                s.insert(vse-rm);
            }

        }
    }
    lpr(*s.rbegin() - *s.begin());n_l;


    return 0;
}

