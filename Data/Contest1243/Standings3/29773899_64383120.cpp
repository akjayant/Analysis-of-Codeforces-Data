                    #include<bits/stdc++.h>
                    using namespace std;
                     
                    typedef long long int ll;
                    typedef vector<ll> vec;
                     
                    #define int long long int
                    #define LM LLONG_MAX
                     
                    #define ff first
                    #define ss second
                     
                    #define FAST ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
                    #define endl "\n"
                    #define pb push_back
                     
                    #define MOD 1000000007
                    #define MAX 200005
                    #define sz size()
                     
                    
                     
                    template <typename T, typename S>
                    ostream& operator<<(ostream& out, const pair<T, S>& x) {
                        out << x.first << ' ' << x.second;
                        return out;
                    }
                     
                    template <typename T>
                    ostream& operator<<(ostream& out, const vector<T>& x) {
                        for (const T& a : x) {
                            out << a << ' ';
                        }
                        return out;
                    }
                     
                    template <typename T>
                    istream& operator>>(istream& in, vector<T>& x) {
                        for (T& a : x) {
                            in >> a;
                        }
                        return in;
                    }
                     
                    template <typename T, typename S>
                    istream& operator>>(istream& in, pair<T, S>& x) {
                        in >> x.first >> x.second;
                        return in;
                    }
                    bool prime(ll n)
                    {
                    	if(n==2)
                    	return true;
                    		if(n==1  || n%2==0)
                    	return false;
                    	for(ll i=3;i*i<=n;i+=2)
                    	{
                    		if(n%i==0)
                    		return false;
                    	}
                    	return true;
                    }
                    ll power(ll a,ll n)
                    {
                        if(n==0 )
                        {
                            return 1;
                        }
                        if(n%2==0)
                        {
                            return power(a*a,n/2);
                            
                        }
                        else
                        return a*power(a*a,n/2);
                    }
    ll i,j;
  
    signed main()
    {
                   
        FAST;
        ll q;
        cin>>q;
        while(q--)
        {
        	ll n;
        	ll temp=0;
        	cin>>n;
            string s,t;
            cin>>s>>t;
            map<char,ll>mp;
            for(auto x:s)
             mp[x]++;
             for(auto x:t)
             mp[x]++;
             for(auto x:mp)
             {
             	if(x.ss%2==1)
             	{
             		temp=1;
             		break;
             	}
             }
             if(s!=t)
             {
             	 vector<ll>m;
             	 ll cnt=0;
             	for(i=0;i<n;i++)
             	{
             		if(s[i]!=t[i])
             		{cnt++;
             		m.pb(i);}
             	}
             if(cnt==2)
             {
             	  if(s[m[0]]==s[m[1]] &&  t[m[0]]==t[m[1]])
             	  {
             	  	
             	  }
             	  else
             	  temp=1;
             }
             else
             temp=1;
             }
             if(temp==0)
             cout<<"yes"<<endl;
             else
             cout<<"no"<<endl;
             
        }
        
    }