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