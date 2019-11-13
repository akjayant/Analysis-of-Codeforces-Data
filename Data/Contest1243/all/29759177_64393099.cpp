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
#define frn(i,a,n) for(int i=a;i<n;i++)
#define uni(a) (a).erase(unique(all(a)), (a).end())
#define pii pair <int,int>
#define fre(i,a,n) for(int i=a;i<=n;i++)
#define drn(i,n,a) for(int i = n;i>=a;i--)
typedef unsigned long long ull;
mt19937 mt(chrono::high_resolution_clock::now().time_since_epoch().count());
inline int mrand() {return abs((int) mt());}
const ll mod = (ll) 1e9 + 7;
const ll inf = (ll)1e18 + 10;
const ld eps = 1e-12;
const ll LOGN = 20;
const ld PI =  3.14159265358979323846;


                    const int Nre           =       3e5         + 100;



                                                        int are[Nre];


                                            int chcdhfghdgf[Nre];
void solve()
 
  {   
  ios::sync_with_stdio(false); 
  cin.tie(nullptr);
  cout.tie(nullptr);        


 
 
 
                       int tre;
    
    
                                                cin >> tre;
   fre(tt,1,tre)
 
 
 
    {
 
 
                               	int nre;
    	
    	
    	                        cin >> nre;
    	
    	
    	        string sre;
    	
    
    
                            	string tre;
    
    
                            	cin     >>   sre        >>  tre;
    
    
    
                                    	vi ggre;
    
    
    
            	frn(i,0,nre)
    
    
    
    	{
    		
    		
    		
    		                        if(sre[i]       !=      tre[i])
    		
    		
    		        {
    			
    			
    			
    			
    			
    			                    chcdhfghdgf[sre[i]      -       '0']++;
    		
    		
    		
    		
    		
    		                                    	chcdhfghdgf[tre[i]      - '0']++;
    			
    			
    			
    			
    			                        ggre.pb(i);
			
    		            
    		            
    		        }
	
	
	
	
		}
	
	
	
	            	bool gfre           =   0;
	
	
	
		frn(i,0,30)
	
	
	
	
		{
	
	
	
	                        		if(chcdhfghdgf[i]               %       2)
			
			
			{
			
			
			
			            	gfre             = 1;
				
				
				
				
				
				                        cout << "No" << endl;
			
			
			
			                    	break;
			
			    
			    
	
	
	
	        		}
		
		    
		    
		    
		}
		
		
		
		                        if(gfre)
		                        
		                        
		                                {
		                                    
		                                            continue;
		                                    
		                                    
		                                    
		                                }
		
		
		
		                    int mre     =               (int)ggre.size();
		
		
		
		                                        vector <pii> opre;
		
		
		
		
		
		                        bool ddre            = 0;
			
			
			
			
			                frn(i,0,mre)
		
		
		
		{
		
		
		
		
		
		                        	if(sre[ggre[i]]             ==           tre[ggre[i]])
		                        	
		                        	
		                        	
		                        	        {
		                        	            
		                        	            
		                        	                        continue;
		                        	            
		                        	            
		                        	            
		                        	            
		                        	            
		                        	        }
		
		
		
		
		                            	gfre                =       0;
			
			
			
			
			            frn(j,i+1,mre)
			
			
			
			{
			
			
			
			
			                    	if(tre[ggre[i]]                         ==      tre[ggre[j]])
				
				
				
				{
				
				
				                        	opre.pb(mp(ggre[i],                 ggre[j]));
				
				
				
				
				
				
				
				
				
				                        	swap(sre[ggre[i]],          tre[ggre[j]]);
				
				
				
				                    	gfre = 1;
					
					
					
					        break;
			
			
				}
			
			    
			    
			}
		
		
		
		
		
		
		                    	
		                    	
		                    	
		                    	                                if(gfre)continue;;
			
			
			
			
			
			                            frn(j,i+1,mre)
			
			
			{
			
			
			
			                            	if(tre[ggre[i]]                 ==       sre[ggre[j]])
				
				
				
				{
				
				
				
				
				
				
				
				    	
				    	
				    	
				    	                opre.pb(mp(ggre[j],                         ggre[j]));
					
					
					                    
					                    
					                    
					                    
					                    
					                    
					                    
					                            swap(sre[ggre[j]],                      tre[ggre[j]]);
					
					
					
					                    opre.pb(mp(ggre[i],                           ggre[j]));
					
					
					
					
					
					                                            swap(sre[ggre[i]],tre[ggre[j]]);
			
			
			
			
			
			
			
			
			                                    		gfre                = 1;
					break;
			
			
			
			
			    	}
			
			    
			    
			}
			
			
			
			
			                    if(gfre                  == 0)
			
			
			    {
				
				
				
				        ddre                     = 1;
				
				
				
				
				
				
				                    cout << "No" << endl;
		
		
		        		break;
			
			        
			        
			    
			        
			        
			    }
	
	
		}
	
	
	
	                    	        if(ddre)                        continue;
	
	
	
	
	                                                        	cout << "Yes" << endl;
		
		
		
		
		                                            
		                                            
		                                            
		                                                cout << (int)opre.size() << endl;
	
	
	
	
	
	                	frn(i,0,opre.size())
		
		
		
		{
		
		
		
		
		                        	cout << opre[i].fi              +       1       << " "      <<      opre[i].sc      +       1 << endl;



		}




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