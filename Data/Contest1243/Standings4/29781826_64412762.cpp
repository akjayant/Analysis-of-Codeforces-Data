//////////////////////// AUTHOR -PRIYANSHI JAIN ////////////////////
//////////////////////// INSTITUTE - IIT JODHPUR /////////////////////


//typedef cpp_ll c_i;
#include<bits/stdc++.h>
typedef long long ll ;
#define MOD 1000000007
 
#define p0(x) cout <<std::fixed<<std::setprecision(0)<<x <<" "
#define p1(x) cout <<x <<endl
#define p2(x,y) cout <<x <<" " <<y <<endl
#define p3(x,y,z) cout <<x <<" " <<y <<" " <<z <<endl
#define p4(w,x,y,z) cout <<w <<" " <<x <<" " <<y <<" " <<z <<endl
#define nL cout<<endl
 
# define pb push_back
#define mp make_pair
 
# define vi vector<int>
# define vll vector<ll>
#define vpii vector <pair<int,int>>
#define vpll vector <pair<ll,ll>>
# define vvi vector< vector <int> >
# define vvll vector< vector <ll> >
#define ss second
#define ff first
 
# define srt(a) sort(a.begin(),a.end())
# define f(i,a,b) for(ll i=a;i<b;i++)
# define frev(i,a,b) for(ll  i=a;i>=b;i--)
# define srtrev(a) sort(a.begin(),a.end(),cmp)
#define gcd(a,b) __gcd(a,b);
#define lcm(a,b)   (a/gcd(a,b))*b;
 
using namespace std;
 
#define Map map<ll, ll >
#define umap unordered_map<ll,ll >
ll limit = 1e9+7 ;
#define fast  ios_base::sync_with_stdio(false); cin.tie(0);  cout.tie(0);
 
//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
bool cmp(ll a,ll b)
{
  return a>b;
}
ll myceil(ll a, ll b)
{
  return a/b +bool(a%b);
}
ll mylog(ll num,ll base)
{
  ll ans=0;
  while(num)
  {
    ans++;
    num/=base;
  }
  return ans-1;
}
ll Pow(ll a,ll b )  //for modulus power
{
  ll ans=1,mul=a;
  while(b)
  {
    if(b&1)ans=(ans*mul)%limit;
    mul=(mul*mul)%limit;
    b/=2;
  }
  return ans;
}
//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
 
int main()
{
    //fast;
    ll t=1;
    cin>>t;
  
    while(t--)
    {
         int n;
         cin>>n;
         string s,t;
         cin>>s>>t;
         //cout<<n<<" "<<s<<" "<<t<<'\n';
         int cnt[26][2];
         f(i,0,26)
         f(j,0,2)
         cnt[i][j]=0;
         f(i,0,n)
         {
			 cnt[s[i]-'a'][0]++;
			 cnt[t[i]-'a'][1]++;
		 }
		 bool eq=true;
		 f(i,0,26)
		 if(abs(cnt[i][0]-cnt[i][1])%2!=0)
		  eq=false;
		 if(eq==false)
		 { cout<<"No\n";  continue;}
		 vpii ans;
	     f(i,0,n)
         {
            char ch=s[i];
            if(s[i]!=t[i])
            {
               
                f(j,i+1,n)
                {if(s[j]==ch)
                {
                     ans.pb({j+1,i+1});
                     swap(t[i],s[j]);
                     //cout<<s<<" "<<t<<"\n";
                     break;
                }
                //cout<<s<<" "<<t<<"\n";
			}

            }
            if(s[i]!=t[i])
            {
			
                f(j,i+1,n)
                if(t[j]==ch)
                {
				
					
				
                     ans.pb({j+1,j+1});
                     swap(s[j],t[j]);
			   //cout<<s<<" "<<t<<"\n";
                     ans.pb({j+1,i+1});
                     swap(s[j],t[i]);
                    // cout<<s<<" "<<t<<"\n";
                     break;
                }
                
            }
         }
         cout<<"Yes\n"<<ans.size()<<"\n";
         for(auto u: ans)
            cout<<u.ff<<" "<<u.ss<<"\n";
     }
    return 0;
}
