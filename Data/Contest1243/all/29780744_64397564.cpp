#include<bits/stdc++.h>
//#define m 1000000007
using namespace std;
 
#define IOS ios_base::sync_with_stdio(false);cin.tie(NULL); 
 
#define ff first
#define ss second
#define pb push_back
#define pf push_front
#define mp make_pair
#define pu push
#define pp pop_back
#define in insert
#define ld long double
#define endl '\n'
#define debug cout << "Hold right there sparky.....\n";
#define forn(low,high,i) for(i=low;i<high;i++)
#define forrev(high,low,i) for(i = high; i>= low;i--)
#define trace(x) cerr << #x << ": " << x << " " << endl;
 
typedef long long int ll;
 
typedef vector<int> vi;
typedef vector<ll> vl;
typedef vector<vi> vvi;
typedef vector<vl> vvl;
typedef pair<int,int> pii;
typedef pair<ll,ll> pll;
typedef vector<pii> vpii;
typedef vector<pll> vpll;

 #define int ll
ll mod=1e12;
        ll mod1=1e9+5;
        ll power(ll a,ll b)
        {
            if(b==0) return 1;
            else if(b%2==0)
                return power((((a%mod)*(a%mod))%mod),b/2)%mod;
            else return ((a%mod)*(power((((a%mod)*(a%mod))%mod),b/2)%mod))%mod;
        }
      

int32_t main()
{
    #ifndef ONLINE_JUDGE
   
    freopen("input.txt", "r", stdin);
   
    freopen("output.txt", "w", stdout);
#endif
        
int k;
           cin>>k;
           while(k--)
           {
                int n;
                cin>>n;
                string s,s1;
                cin>>s>>s1;
                int freq[26];
                memset(freq,0,sizeof(freq));
                vector<pair<int,int>>v;
                for(int i=0;i<n;++i)
                {
                    freq[s[i]-'a']++;
                    freq[s1[i]-'a']++;
                }
                int check=0;
                for(int i=0;i<26;++i)
                {
                    if(freq[i]%2)
                    {
                        check=1;
                        break;
                    }
                }
                if(check)
                {
                    cout<<"No"<<endl;
                    continue;
                }
                int c=0;
                for(int i=n-1;i>=0;--i)
                {
                    if(s[i]!=s1[i])
                    {
                        int index=-1;
                        for(int j=i-1;j>=0;--j)
                        {
                            if(s1[i]==s1[j])
                            {
                                index=j;
                                break;
                            }
                        }
                        if(index!=-1)
                        {
                            swap(s1[index],s[i]);
                            c++;
                            v.push_back({i+1,index+1});
                            continue;
                        }
                        else
                        {
                            //cout<<i<<endl;
                            for(int j=i-1;j>=0;--j)
                            {
                                if(s1[i]==s[j])
                                {
                                    index=j;
                                    break;
                                }
                            }
                            //cout<<index<<endl;
                            c+=2;
                            v.push_back({index+1,index+1});
                            v.push_back({i+1,index+1});
                            swap(s[index],s1[index]);
                            swap(s1[index],s[i]);
 
 
                        }
                    }
                }
                cout<<"Yes"<<endl;
                cout<<c<<endl;
                for(int i=0;i<v.size();++i)
                {
                    cout<<v[i].first<<" "<<v[i].second<<endl;
                }
           }
        


      
}

