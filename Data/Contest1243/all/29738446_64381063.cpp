#include <bits/stdc++.h>
using namespace std;

#define ll  long long int
const ll mod = 1e9 + 7;

int main() {
	ll k,n,q,num;
	cin>>k;
	string s,t;
// 	t=1;
	while(k--)
	{
	    num=0;
	    ll a,b;
	    cin>>n>>s>>t;
	    for(int i=0;i<n;i++)
	    {
	        if(s[i]==t[i])
	        {
	            continue;
	        }
	        else
	        {
	            num++;
	            if(num==1) a=i;
	            if(num==2) b=i;
	        }
	    }
	    if(num==1 || num>2)
	    {
	        cout<<"No\n";
	        continue;
	    }
	    else
	    {
	        if(s[a]==s[b] && t[b]==t[a])
	        {
    	        cout<<"Yes\n";
    	        continue;
	        }
	        cout<<"No\n";
	        continue;
	    }
	   // vector<long long int> A(n,0);
	   // for(int i=0;i<n;i++)
	   // {
	   //     cin>>A[i];
	   // }
	   // sort(A.begin(),A.end());
	}
	return 0;
}
