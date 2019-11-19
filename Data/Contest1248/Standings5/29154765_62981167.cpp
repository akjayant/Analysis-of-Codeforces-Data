#include <bits/stdc++.h>
using namespace std;
#define pb push_back
#define mp make_pair
#define vi vector< int >
#define vb vector< bool >
#define vl vector< ll >
#define all(c)              c.begin(), c.end()
#define endl '\n'
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
const ll inf = (ll)1e18 + 10;
const ld eps = 1e-12;
const ll LOGN = 20;
const ld PI =  3.14159265358979323846;


                    const int Nre   =  1000010;


void solve()
 
  {   
  ios::sync_with_stdio(false); 
  cin.tie(nullptr);
  cout.tie(nullptr);        


            ll t;
              
              
                ll nre;
                
                  ll mre;
  
  
                      cin>>t;
    
    
                    ll pre[Nre];
    
            
            ll qre[Nre];
   
   
     while(t--)
    {
    
    
                            cin  >> nre;
       
       
       
             for(int i=0;i < nre;i++)
             
                {
                            cin>>pre[i];
                    
                    
                    
                }
       
       
       
                             cin    >>  mre;
       
       
       
        
         for(int i=0;i  <   mre;i++)
         
         
                {
                    
                    
                        cin>>qre[i];
                    
                    
                }
      
      
      
      
                  ll ocre   =   0;
                  
                  
                   ll ecre   =0;
      
      
      
       
       
                 for(int i=0;i      <       mre;i++)
        {
            
            
            
            
            
                                if(qre[i]   %   2==0){
            
            
            ecre++;
            
            
                                }
            else
            {
                
                
                            ocre++;
        
        
                    }
                
            
            
            
        }
      
      
      
                      ll djfdhf=0;
      
      
      
      
                              for(int i=0;i <   nre;i++)
                
                
                {
            
            
            
                                                if(pre[i]%2==0)
            {
            
            
                    
                    
                    
                    
                    
                                    djfdhf          +=      ecre;
            }
          
          
          
                  else
            
            
                {
                
                
                    djfdhf          +=      ocre;
            }
        }
        cout<<djfdhf<<endl;
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