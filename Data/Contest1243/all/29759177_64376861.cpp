#include <bits/stdc++.h>
using namespace std;
#define pb push_back
#define mp make_pair
#define vi vector< int >
#define vb vector< bool >
#define vl vector< ll >
#define all(c)              c.begin(), c.end()
#define endl '\n'
#define sz(v) ((int)((v).size()))
#define fi first
#define sc second
#define Sort(s)  sort(s.begin(),s.end())
#define rsort(s) sort(s.rbegin(),s.rend())
#define  ll long long int
#define ld long double
#define vii vector <vector <int>>
#define present(t, x) (t.find(x) != t.end())
#define frn(i,a,n) for(ll i=a;i<n;i++)
#define uni(a) (a).erase(unique(all(a)), (a).end())
#define fre(i,a,n) for(int i=a;i<=n;i++)
#define drn(i,n,a) for(int i = n;i>=a;i--)
typedef unsigned long long ull;
mt19937 mt(chrono::high_resolution_clock::now().time_since_epoch().count());
inline int mrand() {return abs((int) mt());}
const ll mod = (ll) 1e9 + 7;
const ll N = 100005;
const ll inf = (ll)1e18 + 10;
const ld eps = 1e-12;
const ll LOGN = 20;
const ld PI =  3.14159265358979323846;
ll n;


ll m;

            ll i, j;
            
            
            ll k, p;
            
            
                ll ans;
                
                
                
                        ll t, a[N];
void solve()
 
  {   
  ios::sync_with_stdio(false); 
  cin.tie(nullptr);
  cout.tie(nullptr);        



                cin >> t;

        	for (j = 1; j       <=  t; j++)
	
	
	    {
		
		
		        cin     >>  n;
		
		
		
		
		    
		    
		    for (i      =   1; i        <=  n; i++)
			    
			    
			    
			    cin >> a[i];
		
		
		
		
		                        sort(a  +       1, a    + 1      +  n);
		
		
		
		                        ans     = 0;
	
	
	
	                            	k   = 0;
		
		
		                for (i  =   n; i    >=  1;          i--)
		
		
		        {
			
			
			
			                        k++;
			
			
			
			                        ans  =              max(ans,            min(k,      a[i]));
	
	
		}
	
	
	
	    	cout << ans << endl;
	}
  }


 
 
 
                 
 
int main()
 
 
{
 
#ifndef ONLINE_JUDGE
  freopen("input.txt","r",stdin);
  freopen("output.txt","w",stdout);
#endif

 
 
 
 solve();
   
  
  cerr << "\nTime elapsed: " << 1000 * clock() / CLOCKS_PER_SEC << "ms\n";
    return 0;
}