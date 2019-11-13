/*
सत्यान्न प्रमदितव्यम्  || 
*/
 
#include<bits/stdc++.h>
using namespace std;
 
typedef long long int ll;
#define mx 1000005
#define mod 1000000007
#define mp make_pair
#define pb push_back
#define f first
#define s second
#define fast_as_levi ios_base::sync_with_stdio(false) , cin.tie(NULL);
#define mxi 2005
int main()
{
    fast_as_levi;
    ll t;
    cin>>t;
    while(t--)
    {
    	ll i,j,n;
    	cin>>n;
    	string str1,str2;
    	cin>>str1>>str2;
    	vector<ll> ar;
     	vector <pair<ll,ll>> vpr;
        ll ha[mx] = {0};
		ll fl = 0;
    	for(i=0;i<n;i++)
    	{
    		if(str1[i]!=str2[i])
    		{
    			ar.pb(i);
    			ha[str1[i] - '0']++;
    			ha[str2[i] - '0']++;
			}
		}
	    ll m = ar.size();
		for(i=0;i<30;i++)
		{
			if(ha[i]%2>0)
			{
				fl = 1;
				cout<<"No\n";
				continue;
			}
		}
		ll hash1[mx] = {0};
		if(!fl)
     	{	
     		ll flag = 0;
     		for(i=0;i<m;i++)
     		{
     			if(str1[ar[i]] == str2[ar[i]])
     			continue;
     			fl = 0;
     			for(j=i+1;j<m;j++)
     			{
     				if(str2[ar[i]] == str2[ar[j]])
     				{
     					fl = 1;
     					vpr.pb({ar[i],ar[j]});
     					swap(str1[ar[i]],str2[ar[j]]);
     					break;
     				}
     			}
     			if(!fl)
     			for(j =i+1;j<m;j++)
     			{
     				if(str2[ar[i]] == str1[ar[j]])
     				{
     					fl = 1;
     					vpr.pb({ar[j],ar[j]});
     					swap(str1[ar[j]],str2[ar[j]]);
     					vpr.pb({ar[i],ar[j]});
     					swap(str1[ar[i]],str2[ar[j]]);
     					break;
     				}
     			}
     			if(!fl)
     			{
     				flag=1;
     				cout <<"No\n";
     				break;
     			}
     		}
     		if(!flag)
     		{
         		ll z = vpr.size();
         		cout<<"Yes\n";
     	    	cout<<z<<"\n";
     		    for(i=0;i<z;i++)
         		{
     	    		cout<<++vpr[i].f<<" "<<++vpr[i].s<<"\n";
     		    }
     		}
     	}
	}
}