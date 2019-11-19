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

#define ld long double
#define vii vector <vector <int>>
#define present(t, x) (t.find(x) != t.end())
#define int long long
#define frn(i,a,n) for(int i=a;i<n;i++)
#define uni(a) (a).erase(unique(all(a)), (a).end())
#define fre(i,a,n) for(int i=a;i<=n;i++)
#define drn(i,n,a) for(int i = n;i>=a;i--)
typedef unsigned long long ull;
mt19937 mt(chrono::high_resolution_clock::now().time_since_epoch().count());
inline int mrand() {return abs((int) mt());}

void solve()
 
  {   
  ios::sync_with_stdio(false); 
  cin.tie(nullptr);
  cout.tie(nullptr);        




                    int nre;
	
	
	
	
	                cin         >>  nre;


                                	vi dhfvhdfvhd;
	
	
	
	                        for(int i               =           2;      i       *       i       <=  nre;         i++)
	                        
	                        
	                        
	                        
	                        
	                        
	                            {
	
	
	
	                	if (nre         %       i           ==  0) 
	                	
	                	
	                	
	                	    {
			
			
			
			
			                                                dhfvhdfvhd.pb(i);
			
			
			
			
			
			                            if (i        *             i                   !=          nre)
			                            
			                            
			                            
			                            
			                            
			                            
			                            
			                            {
				
				
				
				
				
				
				
				                        dhfvhdfvhd.pb(nre               /       i);
	
	
	
	        		}
		
	                	        
	                	        
	                	        
	                	    }
  
	                                
	                                
	                            }







                                        	dhfvhdfvhd.pb(nre); 
	
	
	
	                                    int     dfgdhfghdfgfdhfgdhfgdhg             =       0;
	frn(i,0,sz(dhfvhdfvhd))
	
	
	
	
	                                {
		
		
		
		
		
		                                    dfgdhfghdfgfdhfgdhfgdhg                 =       __gcd(dfgdhfghdfgfdhfgdhfgdhg,                    dhfvhdfvhd[i]);
	
	                                    
	                                    
	                                }







                                	cout << dfgdhfghdfgfdhfgdhfgdhg << '\n';
  }


 
 
 
                 
 
int32_t main()
 
 
{
 
#ifndef ONLINE_JUDGE
  freopen("input.txt","r",stdin);
  freopen("output.txt","w",stdout);
#endif

 
 
 
 solve();
   
  
  cerr << "\nTime elapsed: " << 1000 * clock() / CLOCKS_PER_SEC << "ms\n";
    return 0;
}