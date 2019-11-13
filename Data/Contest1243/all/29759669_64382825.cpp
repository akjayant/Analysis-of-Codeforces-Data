#include <iostream>
#include<bits/stdc++.h>
using namespace std;

int main() {
	long int t1;
	cin>>t1;
	while(t1--)
	{
	    long int n;
	    cin>>n;
	    string s,t;
	    cin>>s>>t;
	    vector<pair<int,int>> x;
	    int b[26]={0};
	    for(long int i=0;i<n;i++)
	    b[s[i]-'a']++,b[t[i]-'a']++;
	    bool pp=0;
	    for(long int i=0;i<26;i++)
	    {
	        if(b[i]%2==1)
	        {
	            cout<<"NO"<<endl;
	            pp=1;
	            break ;
	        }
	    }
	    if(pp==0)
	    {
	        long int ans=0;
	    for(long int i=0;i<n;i++)
	    {
	        if(s[i]!=t[i])
	        {
	            long int j;
	            pp=0;
	            for(j=i+1;j<n;j++)
	            {
	                if(s[j]==s[i])
	                {
	                    pp=1;
	                    break ;
	                }
	            }
	            if(pp==1)
	            {
	               x.push_back({j+1,i+1});
	               ans++;
	               swap(s[j],t[i]);
	            }
	            else
	            {
	                for(j=i+1;j<n;j++)
	                {
	                    if(t[j]==s[i])
	                    {
	                        break ;
	                    }
	                }
	                x.push_back({j+1,j+1});
	                swap(s[j],t[j]);
	                x.push_back({j+1,i+1});
	                swap(s[j],t[i]);
	            }
	        }
	    }
	    
	        cout<<"YES"<<endl;
	        cout<<x.size()<<endl;
	        for(long int i=0;i<x.size();i++)
	        cout<<x[i].first<<" "<<x[i].second<<endl;
	    }
	}
}