	#include<stdio.h>
	#include <set>
	#include<map>
	#include<string.h>
	#include <cmath>
	#include <queue>
	#include <stack>
	#include <vector>
	#include <string>
	#include <cstdio>
	#include <cstdlib>
	#include <cstring>
	#include <iomanip>
	#include <iostream>
    #include <algorithm>
using namespace std;
int n,ans;
char ch[1011];
int main()
{
      //  ll  gcd(ll a,ll b){return  !b?a:gcd(b,a%b);}
//ll i,j,k,l,n,m,sum,maxx,minn,ans,x,y,flag,cc,t;
    cin>>n;
    while(n--)
    {
        cin>>ans;
        cin>>ch;
        int len=strlen(ch);
        if(ch[0]=='1'||ch[len-1]=='1')
            cout<<ans*2<<endl;
//              while(ch<='9' && ch>='0') {
//       x=x*10+ch-'0';
//       ch=getchar();
//    }
//    return x*f;
        else
        {
            int maxx=ans;
            int sum=0;
            for(int i=0;i<len;i++)
                if(ch[i]=='1')
                {
                    sum++;
                    maxx=max(maxx,sum+ans);
                    maxx=max(maxx,i*2+2);
                    maxx=max(maxx,(len-1-i+1)*2);
                }
            cout<<maxx<<endl;
        }
    }
    return 0;
}
