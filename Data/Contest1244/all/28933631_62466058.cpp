#include<bits/stdc++.h>
using namespace std;
int main()
{
	ios::sync_with_stdio(false);
	int T;
	cin>>T;
	while(T--)
	{
		int a,b,c,d,k;
		cin>>a>>b>>c>>d>>k;
		int Pen=(a-1+c)/c;
		int Pencel=(b-1+d)/d;
		if(Pen+Pencel<=k) cout<<Pen<<" "<<Pencel<<endl;
		else cout<<-1<<endl;
	}
}

