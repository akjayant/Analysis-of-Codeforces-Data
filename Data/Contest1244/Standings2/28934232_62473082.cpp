#include <bits/stdc++.h>

#define ll long long
using namespace std;

#define MAXN 

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	int T,a,b,c,d,k;
	cin>>T;
	while(T--)
	{
		cin>>a>>b>>c>>d>>k;
		int z = a/c + ((a%c > 0)?1:0); 
		int y = b/d + ((b%d > 0)?1:0);
		if(z+y<=k)
			cout<<z<<" "<<y<<endl;
		else
		{
			cout<<-1<<endl;
		}
		
	}
		
	return 0;
}
