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
int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

    ll t, n,m,i,x,j;
    string a, b;
    bool g;
    cin>>t;
    while(t--){
        cin>>n>>a>>b;
        x=0;
        g=0;
        for(i=0; i<n && !g; ++i)
            if(a[i]!=b[i]){
                if(x==2)
                    g=1;
                if(!x)
                    j=i;
                else if(!(a[j]==a[i] && b[j]==b[i]))
                    g=1;
                ++x;
            }
        if(g || x!=2)
            cout<<"No\n";
        else cout<<"Yes\n";
    }
	return 0;
}
