#include<bits/stdc++.h>
using namespace std;
int main()
{
	ios::sync_with_stdio(false);
	int t;
	int a,b,c,d,k;
	cin>>t;
	while(t--)
	{
		cin>>a>>b>>c>>d>>k;
		int tp1=(a+c-1)/c,tp2=(b+d-1)/d;
		int tot=tp1+tp2;
		if(tot<=k)
		{
			cout<<tp1<<' '<<tp2<<endl;
		}
		else cout<<-1<<endl;
	}
}