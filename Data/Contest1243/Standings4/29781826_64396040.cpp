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
    //cin>>t;
  
    while(t--)
    {
      /*int n;
      cin>>n;
      string s,t;
      cin>>s>>t;
      string s1,t1;
      int arr1[26]={},arr2[26]={};
      vi pos1[26],pos2[26];
      f(i,0,n)
       {
         if(s[i]!=t[i])
         {
            s1.push_back(s[i]);
            t1.push_back(t[i]);
            arr1[s[i]-'a']++;
            arr2[t[i]-'a']++;
            pos1[s[i]-'a'].push_back(i+1);
            pos2[s[i]-'a'].push_back(i+1);
         }
       }
       vpii ans;
       bool anns=true;
       f(i,0,n)
       {
        if(s[i]!=t[i])
         {
              char ch=s[i];
              arr1[s[i]-'a']--;
              if(arr1[s[i]-'a'])
              {
                ans.push_back({i+1,pos1[s[i]-'a'][1]});
                swap(s[pos1[s[i]-'a'][1]-1],t[i]);
                //cout<<s<<" "<<t<<"\n";
              }
              else
                {
                    anns=false;
                    break;}
                    arr1[s[i]-'a']--;
                    pos1[s[i]-'a'].erase(pos1[s[i]-'a'].begin());
                    pos1[s[i]-'a'].erase(pos1[s[i]-'a'].begin()); 
         }
       }
       if(anns==false)
        cout<<"No\n";
    else
        {
            cout<<"Yes\n";
            for(auto u:ans)
                cout<<u.first<<" "<<u.second<<"\n";
            cout<<"\n";

        }*/
        ll n,hcf;
        cin>>n;
        hcf=n;
        f(i,2,sqrt(n)+1)
        {
            if(n%i==0 && n/i!=1)
            {
                {  
                    hcf=__gcd(hcf,i);
                    hcf=__gcd(hcf,n/i);
                }
            }
        }
        cout<<hcf<<"\n";
  }
    return 0;
}
