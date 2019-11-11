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
int gcd(int a,int b)
{
	return b == 0 ? a : gcd( b,a%b );
}

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int T;
    cin>>T;
    while(T--)
    {
    	int a,b;
    	cin>>a>>b;
    	int c=gcd(a,b);
    	if(c==1)cout<<"Finite"<<endl;
    	else cout<<"Infinite"<<endl;
    }
    return 0;
}