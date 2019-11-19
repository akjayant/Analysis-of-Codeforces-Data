#include <iostream>
#include <cstdio>
#include <cstring>
#include <cstdlib>
#include <algorithm>

using namespace std;
typedef long long ll;
const int MAXN = 100005;
int t,n,m,pc1,pc2,qc1,qc2;

int main()
{
    cin >> t;
    while(t--)
    {
        cin >> n;
        pc1 = pc2 = qc1 = qc2 = 0;
		int x;
		for(int i = 1; i<=n; i++)
		{
	        cin >> x;
	        if(x&1)
	            pc1++;
	        else
	            pc2++;
		}
		cin >> m;
		for(int i = 1; i<=m; i++)
		{
	        cin >> x;
	        if(x&1)
	            qc1++;
	        else
	            qc2++;
		}
		cout << 1ll*pc1*qc1+1ll*pc2*qc2 << endl; 
	}
	return 0;
}
