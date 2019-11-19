#include<iostream>
#include<algorithm>
#include<memory.h>
#include<unordered_map>
#include<queue>
#include<ctime>
#define int long long
using namespace std;

int akari[2][2];

signed main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	
	int t,n,m;
	cin>>t;
	while(t--)
	{
		int a,b,c;
		memset(akari,0,sizeof(akari));
		
		cin>>n;
		while(n--)
		{
			cin>>a;
			akari[0][a&1]++;
		}
		cin>>m;
		while(m--)
		{
			cin>>a;
			akari[1][a&1]++;
		}
		cout<<akari[0][0]*akari[1][0]+akari[0][1]*akari[1][1]<<'\n';
	}
	
	return 0;
}
