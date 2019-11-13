#include<bits/stdc++.h>
#define ll long long
#define mod 1000000007
using namespace std;

int main()
{
    ll num,i,j,k,l;
    cin>>num;
    ll arr[num][num];
    ll flag=0;
    l=1;
    for(i=0;i<num;i++)
    {
    	if(flag==0)
    	{
    		flag=1;
    		for(j=0;j<num;j++)
    		{
    			arr[j][i]=l;
    			l++;
    		}
    	}
    	else
    	{
    		flag=0;
    		for(j=num-1;j>=0;j--)
    		{
    			arr[j][i]=l;
    			l++;
    		}
    	}
    }
    for(i=0;i<num;i++)
    {
    	for(j=0;j<num;j++)
    	{
    		cout<<arr[i][j]<<" ";

    	}
    	cout<<endl;
    }

    return 0;
}