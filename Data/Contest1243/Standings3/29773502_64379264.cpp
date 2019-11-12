    /*
    |___________________________Arshit Mangukiya_____________________________|
    |_______________________________DA-IICT__________________________________|
    |_____________________________201801173__________________________________|
    */
    /*______________________WRITE  YOUR  CODE  HERE_________________________*/
     
    #include <bits/stdc++.h>
    using namespace std;
    #define ll long long 
    #define ld long double
    #define ff first
    #define ss second
     typedef vector<ll> vec;
    #define pb push_back
    #define mp make_pair
    #define MOD 1000000007
    #define FAST ios_base::sync_with_stdio(false),cin.tie(0),cout.tie(0);srand(time(NULL))
     ll i,j;
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