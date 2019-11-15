/* 
 * Author: Imagine_I
 * Time: 2019-10-17 21:56:35
**/

#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define pb push_back
#define fi first
#define se second
const int maxn=1e5+10;
const int mod=1e9+7;
const int inf=0x3f3f3f3f;
int book[305][305];
int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);
    int n;
    cin>>n;
    int now=n*n;
    for(int i=1;i<=n;i++)
    {
        if(i&1)
            for(int j=1;j<=n;j++) book[j][i]=now--;
        else 
            for(int j=n;j>=1;j--) book[j][i]=now--;
    }
    for(int i=1;i<=n;i++)
    {
        for(int j=1;j<=n;j++) cout<<book[i][j]<<(j==n?'\n':' ');
    }
	return 0;
}
