#include<iostream>
#include<cstring>
#include<cstdio>
#include<algorithm>
#include<vector>
#include<queue>
#include<cmath>
#include<string>
using namespace std;
#define mem(a,b) memset(a,b,sizeof(a))
#define rep(a,b,c) for(int a=b;a<c;a++)
#define repp(a,b,c) for(int a=b;a<=c;a++)
#define pb push_back
const int maxn=200005;
int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int T;
    cin>>T;
    while(T--)
    {
    	int n;
    	cin>>n;
    	int a,b,c;
    	cin>>a>>b>>c;
    	string str,str1;
    	cin>>str;
    	str1=str;
    	int a1,b1,c1;
    	a1=b1=c1=0;
    	for(int i=0;i<str.size();i++)
    	{
    		if(str[i]=='S')a1++;
    		else if(str[i]=='R')b1++;
    		else c1++;
    	}
    	int sum=min(a,a1)+min(b,b1)+min(c,c1);
    	for(int i=0;i<str.size();i++)
    	{
    		if(str[i]=='S')
    		{
    			if(a>0)
    			{
    				str1[i]='R';
    				a--;
    			}
    		}
    		else if(str[i]=='R')
    		{
    			if(b>0)
    			{
    				str1[i]='P';
    				b--;
    			}
    		}
    		else
    		{
    			if(c>0)
    			{
    				str1[i]='S';
    				c--;
    			}
    		}
    	}
    	for(int i=0;i<str1.size();i++)
    	{
    		if(str1[i]==str[i])
    		{
    			if(a>0)
    			{
    				str1[i]='R';
    				a--;
    			}
    			else if(b>0)
    			{
    				str1[i]='P';
    				b--;
    			}
    			else if(c>0)
    			{
    				str1[i]='S';
    				c--;
    			}
    		}
    	}
    	if(sum*2>=n)
    	{
    		cout<<"YES"<<endl;
    		cout<<str1<<endl;
    	}
    	else cout<<"NO"<<endl;
    }
    return 0;
}