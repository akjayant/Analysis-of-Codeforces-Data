#include <iostream>
#include <string>
#include <algorithm>
#define max(a,b) (a>b?a:b)
#define M 1000000007
#define N 1003
#define ll long long
#define f first
#define s second
using namespace std;
ll a[N];
int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

    ll t, n,m,i;
    cin>>t;
    while(t--){
        cin>>n;
        m=0;
        for(i=1; i<=n; ++i)
            cin>>a[i];
        sort(a+1, a+n+1);
        for(i=n; i>=1; --i)
            m=max(m, min(a[i], n-i+1));
        cout<<m<<"\n";
    }
	return 0;
}
