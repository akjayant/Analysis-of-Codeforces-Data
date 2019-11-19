#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
int main()
{
    int a, b, c, d, k;
    int t;
    cin>>t;
    while(t--)
    {
        cin>>a>>b>>c>>d>>k;
        int x, y;
        if(a%c==0) x=a/c;
        else x=a/c+1;
        if(b%d==0) y=b/d;
        else y=b/d+1;
        if(x+y<=k) cout<<x<<" "<<y<<endl;
        else cout<<-1<<endl;
    }
    return 0;
}
