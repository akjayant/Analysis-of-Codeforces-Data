

#include <bits/stdc++.h>
using namespace std;


// M A F I A - M A F I A - M A F I A - M A F I A - M A F I A - M A F I A //

#define int               long long
#define endl              '\n'
#define ff                first
#define ss                second
#define mp                make_pair
#define pb                push_back
#define vii               vector<int> 
#define pii               pair<int,int>
#define vpii              vector< pii >
#define all(v)            v.begin(),v.end()
#define loop(i,s,e)       for(int i=s;i<e;i++)
#define rloop(i,e,s)      for(int i=e;i>=s;i--)
#define mset(a,f)              memset(a,f,sizeof(a))
#define M                 1000000007
#define fastio            ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0)
#define prvec(v)          loop(i_u_j,0,v.size())cout << v[i_u_j] <<" "; cout << endl;
#define prarr(arr,n)      loop(i_u_j,0,n)cout << arr[i_u_j] << " "; cout << endl;
#define bug(...)        __f (#__VA_ARGS__, __VA_ARGS__)


template <typename Arg1>
void __f (const char* name, Arg1&& arg1) { cout << name << " : " << arg1 << endl; }
template <typename Arg1, typename... Args>
void __f (const char* names, Arg1&& arg1, Args&&... args)
{
     const char* comma = strchr (names + 1, ',');
     cout.write (names, comma - names) << " : " << arg1 << " | "; __f (comma + 1, args...);
}

// M A F I A - M A F I A - M A F I A - M A F I A - M A F I A - M A F I A //
const int N = 3e5 + 7;
int n;
int arr[N];


void solve()
{
      double l,p,c,d,k;
      cin >> l >> p >> c >> d >> k;
      double req = ceil(l/c) + ceil(p/d);
      // bug(req,k);
      if(req > k) cout << -1 << endl;
      else
      {
            cout << ceil(l/c) << " " << ceil(p/d) << endl;
      }
}

int32_t main() {
    fastio;
#ifndef ONLINE_JUDGE
    freopen("input.txt",  "r",  stdin);
    freopen("output.txt", "w", stdout);
 #endif
  
  int t = 1; 
  cin>>t;
  
  while(t--) solve();
  
  


}


// M A F I A - M A F I A - M A F I A - M A F I A - M A F I A - M A F I A //













