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
    #define sz size()
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
                 if(temp==1)
                 {
                 	cout<<"no\n";
                 	continue;
                 }
                 cout<<"yes"<<endl;
                 if(s.sz==1)
                 {
                 	cout<<1<<endl<<"1 1\n"<<endl;
                 	continue;
                 }
                 vector<pair <ll,ll> > v;
                    for(i=0;i<s.sz;i++)
                 	{
                        if(s[i]!=t[i])
                        {
                        	if(s[i+1]!=s[i])
                        	{
                        		ll temp=0;
                        		for(j=i+1;j<n;j++)
                        		{
                        			if(t[j]==s[i])
                        			{
                        				temp=1;
                        				swap(s[i+1],t[j]);
                        				v.pb({i+1,j});
                        				break;
                        			}
                        		}
                        		for(j=i+2;j<n;j++)
                        		{
                        			 if(s[j]==s[i] && temp==0)
                        			 {
                        			 	 v.pb({j,j});
                        			 	 v.pb({i+1,j});
                        			 	 swap(s[j],t[j]);
                        			 	 swap(s[i+1],t[j]);
                        			 	break;
                        			 }
                        		}
                        	}
                        	if(t[i+1]!=t[i])
                        	{
                        			ll temp=0;
                        		for(j=i+1;j<n;j++)
                        		{
                        			if(s[j]==t[i])
                        			{
                        				temp=1;
                        				swap(t[i+1],s[j]);
                        				v.pb({j,i+1});
                        				break;
                        			}
                        		}
                        		for(j=i+2;j<n;j++)
                        		{
                        			 if(t[j]==t[i] && temp==0)
                        			 {
                        			 	 v.pb({j,j});
                        			 	 v.pb({j,i+1});
                        			 	 swap(t[j],s[j]);
                        			 	 swap(s[j],t[i+1]);
                        			 	break;
                        			 }
                        		}
                        		
                        	}
                        	
                        	v.pb({i,i+1});
                        	swap(s[i],t[i+1]);
                        	i++;
                        }
                 	}
                // cout<<s<<endl<<t<<endl;
                 cout<<v.sz<<endl;
                 for(auto x:v)
                   cout<<x.ff+1<<" "<<x.ss+1<<endl;
                    
            }
            
        }