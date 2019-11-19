

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
#define mset(a,f)          memset(a,f,sizeof(a))
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
int n, K;
int arr[N];
map < int ,int > freq;
set<int> st;
bool check(int m)
{
    int i = 0, j = n-1; 
    if( arr[j] - arr[i] <= m ) return 1;

    int k = K;
    int s = arr[i];
    int e = arr[j];
    int a = freq[s];
    int b = freq[e];
    // cout << m << " **** " << endl;
    // bug(s,a,e,b,k);
    while( k > 0 )
    {   
        if( abs(e - s)  <= m ) return 1;
        if( a <= b )
        {    
            auto it = st.lower_bound(s);
            if( *it == s) it++;
            int mxinc = ( *it - s );
            int in = min(k/a,mxinc);
            int ns = s;
        
            if( in == 0 ) return 0;
            else 
            {   
                ns = s + in;
                k = k - in*a;
            }
            // bug(in,ns);
            s = ns;
            a = a + freq[ns];

        }
        else
        {       
            // if( m < 5) cout << " here ";
            auto it = st.lower_bound(e);
            if( *it == e) it--;
            int mxinc = abs( *it - e );
            // if( m < 5) cout << mxinc;
            int in = min(k/b,mxinc);
            int ne = e;
            if( in == 0 ) return 0;
            else
            {
                ne = ne - in;
                k = k - in*b;
            }
            e = ne;
            b = b + freq[ne];
        }
        // bug(s,a,e,b);
    }
    if( abs(e - s) <= m)return 1;
    return 0;
}


void solve()
{
    cin >> n >> K;
    loop(i,0,n) cin >> arr[i];
    sort(arr,arr+n);

    loop(i,0,n)
    {   
        st.insert(arr[i]);
        freq[arr[i]]++;
    }

    int ans = 1e10;
    int s = 0, e = 1e10;

    while( s <= e)
    {
        int mid = (s+e)/2;
        if( check(mid) )
        {   
            // cout << mid << " yy " << endl;
            ans = mid;
            e = mid-1;
        }
        else s = mid + 1;
    }
    cout << ans ;
}

int32_t main() {
    fastio;
#ifndef ONLINE_JUDGE
    freopen("input.txt",  "r",  stdin);
    freopen("output.txt", "w", stdout);
 #endif
  
  int t = 1; 
  //cin>>t;
  
  while(t--) solve();
  
  


}


// M A F I A - M A F I A - M A F I A - M A F I A - M A F I A - M A F I A //













