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
    vector<ll>v;
    void  find(ll n)
    {
    	  for(i=2;i*i<=n;i++)
    	  {
    	  	if(n%i==0)
    	  	{
    	  		if(n/i==i)
    	  		{
    	  			v.pb(i);
    	  		}
    	  		else
    	  		{
    	  			v.pb(i);
    	  			v.pb(n/i);
    	  		}
    	  	}
    	  }
    	  
    	  ll gc=n;
    	  for(auto x:v)
    	  {
    	  	gc=__gcd(gc,x);
    	  }
    	  cout<<gc;
    }
    signed main()
    {
                   
        FAST;
        ll n;
        cin>>n;
        if(n==1)
        cout<<1;
        else
        find(n);
    }