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
	    vector<ll> A(26,0),B(26,0),S(n,0),T(n,0);
	    for(int i=0;i<n;i++)
	    {
	        A[s[i]-'a']++;S[i]=s[i]-'a';
	        B[t[i]-'a']++;T[i]=t[i]-'a';
	    }
	    bool y = true;
	    for(int i=0;i<26;i++)
	    {
	        y = y && ((A[i]+B[i])%2==0);
	    }
	    if(!y)
	    {
	        cout<<"No\n";
	        continue;
	    }
	    cout<<"Yes\n";
	    cout<<2*n<<endl;
	    int ans=0;
	   // cout<<2*n<<endl;
	    for(int i=0;i<n;i++)
	    {
	        int j;
	        for(j=i;j<n;j++)
	        {
	            if(T[i]==S[j]) break;
	        }
	        if(j<n)
	        {
	            ans+=2;
    	        cout<<j+1<<" "<<j+1<<endl;
    	        cout<<i+1<<" "<<j+1<<endl;
    	        S[j]=T[j];
    	        T[j]=S[i];
    	        S[i]=T[i];	            
	        }
	        else
	        {
	            for(j=i+1;j<n;j++)
    	        {
    	            if(T[i]==T[j]) break;
    	        }
    	        if(j<n)
    	        {
    	            ans+=1;
        	        cout<<i+1<<" "<<j+1<<endl;
        	       // cout<<i+1<<" "<<j+1<<endl;
        	        T[j]=S[i];
        	        S[i]=T[i];	            
    	        }
	        }
	       // for(int i=0;i<n;i++)
	       // {
	       //     cout<<S[i];
	       // }
	       // cout<<endl;
	       // for(int i=0;i<n;i++)
	       // {
	       //     cout<<T[i];
	       // }
	       // cout<<endl;
	    }
	    for(int i=0;i<2*n-ans;i++)
	    {
	        cout<<"1 1 \n";
	    }
	}
	return 0;
}
