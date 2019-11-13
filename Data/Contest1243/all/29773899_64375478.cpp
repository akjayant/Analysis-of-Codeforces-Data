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
        	cin>>n;
        	vec v(n);
        	cin>>v;
        	sort(v.begin(),v.end());
        	ll cnt=1;
        	for(i=n-1;i>=0;i--)
        	{
        		if(cnt<=v[i])
        		{
        			cnt++;
        		}
        		else
        		break;
        	}
        	cout<<cnt-1<<endl;
        }
        
    }