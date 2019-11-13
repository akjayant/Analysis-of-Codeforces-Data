#include <bits/stdc++.h>
using namespace std;

int main() {
	int t;
	cin>>t;
	while(t--)
	{
	    int a,b,c;
	    cin>>a>>b>>c;
	    int k=c/2;
	    if(b>=k)
	    {
	        b-=k;
	        int sum=k*3;
	        k=b/2;
	        if(a>=k)
	        {
	            sum+=k*3;
	            cout<<sum<<endl;
	        }
	        else
	        {
	            sum+=a*3;
	            cout<<sum<<endl;
	        }
	    }
	    else
	    {
	        cout<<b*3<<endl;
	    }
	}
	return 0;
}
