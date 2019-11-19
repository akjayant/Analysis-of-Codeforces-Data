#include<bits/stdc++.h>
#define int long long
using namespace std;
int T;
signed main()
{
    ios::sync_with_stdio(false);
    cin>>T;
    while(T--)
    {
    	int n, m, p[100005], q[100005], cnt1 = 0, cnt2 = 0, CNT1 = 0, CNT2 = 0;
    	cin>>n;
    	for(int i = 1; i <= n; i++)
    	{
			cin>>p[i];
			if(p[i] % 2 == 0) CNT1++;
			else CNT2++;
		}
    	cin>>m;
    	for(int i = 1; i <= m; i++)
    	{
			cin>>q[i];
			if(q[i] % 2 == 0) cnt1++;
			else cnt2++;
		}
    	cout<<cnt1 * CNT1 + cnt2 * CNT2<<endl;
    }
    return 0;
}