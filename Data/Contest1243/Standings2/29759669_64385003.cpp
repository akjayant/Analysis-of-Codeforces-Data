#include <iostream>
#include<bits/stdc++.h>
using namespace std;

int main() {
	long int t;
	cin>>t;
	while(t--)
	{
	    long int n;
	    cin>>n;
	    string a,b;
	    cin>>a>>b;
	    vector<long int> x;
	    for(long int i=0;i<n;i++)
	    {
	        if(a[i]!=b[i])
	        {
	            x.push_back(i);
	        }
	    }
	    if(x.size()!=2)
	    cout<<"NO"<<endl;
	    else
	    {
	        swap(a[x[0]],b[x[1]]);
	        if(a==b)
	        cout<<"YES"<<endl;
	        else
	        cout<<"NO"<<endl;
	    }
	}
	return 0;
}