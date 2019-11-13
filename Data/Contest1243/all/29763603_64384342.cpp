/*
सत्यान्न प्रमदितव्यम्  || 
*/
 
#include<bits/stdc++.h>
using namespace std;
 
typedef long long int ll;
#define mx 1000005
#define mod 1000000007
// #define mp make_pair
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
        ll i,n;
		cin>>n;
		ll cnt = 0;
		string str1,str2;
		cin>>str1>>str2;
		vector<ll> ar(n);
		vector<ll> br;
		for(i=0;i<n;i++)
		{
		    if(str1[i]==str2[i])
			{
			    ar[i] = 1;
			}
		}
		for(i=0;i<n;i++)cnt = cnt + !ar[i];
 
		if(!cnt)
		{
		    cout<<"Yes"<<"\n";
		}
		else if(cnt!=2)
		{
		    cout<<"No"<<"\n";
		}
		else
		{
			for(i=0;i<n;i++)
			{
			    if(!ar[i])
					br.pb(i);
			}
			swap(str1[br[0]],str2[br[1]]);
			if(str1==str2)
			{
			    cout<<"Yes"<<"\n";
			}
			else
			{
			    cout<<"No"<<"\n";
			}
		}
    }
}