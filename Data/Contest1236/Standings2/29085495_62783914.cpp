#include <bits/stdc++.h>

using namespace std;
#define IOS ios::sync_with_stdio(false)
#define all(x) x.begin(),x.end()
#define pb push_back
#define mp make_pair
#define pii pair<int,int>

int main()
{
	int a,b,c;
	int t;
	cin>>t;
	while(t--){
        cin>>a>>b>>c;
        int k=min(c/2,b);
        int ans=k*3;
        b-=k;
        int k2=min(a,b/2);
        ans+=k2*3;
        cout<<ans<<endl;
	}
    return 0;
}
