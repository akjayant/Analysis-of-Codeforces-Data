      #pragma comment(linker, "/stack:200000000")
        #pragma GCC optimize ("Ofast")
        #pragma GCC target ("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,tune=native")
        #include <iostream>
        #include <iomanip>
        #include <sstream>
        #include <cstring>
        #include <vector>
        #include <deque>
        #include <queue>
        #include <set>
        #include <map>
        #include <valarray>
        #include <iterator>
        #include <functional>
        #include <limits>
        #include <algorithm>
        #include <numeric>
        #include <cmath>
        #include <cassert>
        #include <unordered_map>
        #include <unordered_set>
        #include <stack>
        using namespace std;
        #define IOS ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
         #define trace(x) cerr << #x << ": " << x << " " << endl;
     
        typedef int64_t ll;
     
        #define endl '\n'
        #define int ll
        ll mod=1e9+7;
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
            IOS
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
                vector<pair<int,int>>v;
                for(int i=0;i<n;++i)
                {
                    if(s[i]!=s1[i])
                    {
                        v.push_back({s[i],s1[i]});
                    }
                }
                if((int)v.size()==0)
                {
                    cout<<"YES"<<endl;
                }
                else if((int)v.size()>2)
                {
                    cout<<"NO"<<endl;
                }
                else
                {
                    if(v[0].first==v[1].first and v[0].second==v[1].second)
                    {
                        cout<<"YES"<<endl;
                    }
                    else
                    {
                        cout<<"NO"<<endl;
                    }
                }
           }


        }