#include<bits/stdc++.h>

using namespace std;
int t;
int a,b,c;
int main()
{
	//freopen(".in","r",stdin);
	//freopen(".out","w",stdout);
	int i,j;
	cin>>t;
	while(t--)
	{
		cin>>a>>b>>c;
		int tmp=min(c/2,b);
		b-=tmp;
		int tmp2=min(a,b/2);
		cout<<tmp*3+tmp2*3<<endl;
	}
	return 0;
}
