/* 
 * Author: Imagine_I
 * Time: 2019-10-17 21:37:50
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
int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);
    int t;
    cin>>t;
    while(t--)
    {
        int a,b,c;
        cin>>a>>b>>c;
        int ans=0;
        int num=c/2;
        if(b>num)
        {
            ans+=3*num;
            b-=num;
        }
        else ans+=3*b,b=0;
        num=b/2;
        if(a>num) ans+=num*3;
        else ans+=a*3;
        cout<<ans<<'\n';
    }
	return 0;
}
