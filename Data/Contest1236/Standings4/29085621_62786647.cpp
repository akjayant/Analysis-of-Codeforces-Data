#include<bits/stdc++.h>
#define sd(a) scanf("%d",&a)
#define sld(a) scanf("%I64d",&a)
using namespace std;
typedef long long ll;
const int maxn=1e5+50;
int main()
{
	ios::sync_with_stdio(false);
	int n;
	cin>>n;
	int a,b,c;
	while(n--)
	{
		int fin=0;
		cin>>a>>b>>c;
		int cc=c/2;
		int mi=min(cc,b);
		fin+=mi*3;
		b=b-mi;
		b=b/2;
		int zz=min(b,a);
		fin+=zz*3;
		cout<<fin<<endl;
	}
	return 0;
}
