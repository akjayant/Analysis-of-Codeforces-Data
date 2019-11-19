	#include<bits/stdc++.h>
	using namespace std;
	#define IOS ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	#define trace1(x)                cerr<<#x<<": "<<x<<endl
	#define trace2(x, y)             cerr<<#x<<": "<<x<<" | "<<#y<<": "<<y<<endl
	#define trace3(x, y, z)          cerr<<#x<<":" <<x<<" | "<<#y<<": "<<y<<" | "<<#z<<": "<<z<<endl
	#define trace4(a, b, c, d)       cerr<<#a<<": "<<a<<" | "<<#b<<": "<<b<<" | "<<#c<<": "<<c<<" | "<<#d<<": "<<d<<endl
	#define trace5(a, b, c, d, e)    cerr<<#a<<": "<<a<<" | "<<#b<<": "<<b<<" | "<<#c<<": "<<c<<" | "<<#d<<": "<<d<<" | "<<#e<< ": "<<e<<endl
	#define trace6(a, b, c, d, e, f) cerr<<#a<<": "<<a<<" | "<<#b<<": "<<b<<" | "<<#c<<": "<<c<<" | "<<#d<<": "<<d<<" | "<<#e<< ": "<<e<<" | "<<#f<<": "<<f<<endl
	#define endl '\n'

	int32_t main()
	{
	    IOS;
	    int n;
	    cin>>n;
	    string s;
	    cin>>s;
	    s=" "+s;
	    int l=-1;
	    int r=-1;
	    int ans=-1;
	    for(int i=1;i<=n;i++)
	    {
	    	for(int j=1;j<=n;j++)
	    	{
	    		swap(s[i],s[j]);
	    		int pre1[n+3],pre2[n+3];
	    		memset(pre1,0,sizeof(pre1));
	    		for(int k=1;k<=n;k++)
	    		{
	    			if(s[k]=='(')
	    				pre1[k]=1;
	    			else
	    				pre1[k]=-1;
	    			pre1[k]+=pre1[k-1];
	    		}
	    		swap(s[i],s[j]);
	    		int tmp=0;
	    		int mi1[n+2];
	    		int mi2[n+2];
	    		mi1[1]=pre1[1];
	    		mi2[n]=pre1[n];
	    		for(int k=2;k<=n;k++)
	    			mi1[k]=min(mi1[k-1],pre1[k]);
	    		for(int k=n-1;k>=0;k--)
	    			mi2[k]=min(mi2[k+1],pre1[k]);
	    		int neg=0;
	    		if(mi1[n]>=0&&pre1[n]==0)
	    		tmp++;
	    		for(int k=n-1;k>=1;k--)
	    		{
	    			int add1=pre1[n]-pre1[k];
	    			int add2=-pre1[k];
	    			int x=mi1[k];
	    			int y=mi2[k+1];
	    			if((pre1[k]+add1==0)&&((x+add1)>=0)&&(y+add2>=0))
	    				tmp++;
	    		}
	    		if(ans<=tmp)
	    		{
	    			ans=tmp;
	    			l=i;
	    			r=j;
	    			continue;
	    		}
	    	}
	    }
	    cout<<ans<<endl;
	    cout<<l<<" "<<r;
	}
	    
	    