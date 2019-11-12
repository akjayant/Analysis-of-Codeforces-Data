#include<bits/stdc++.h>
using namespace std;

int main()
{
    int a,b,c,ans,t;
    cin >> t;
    while(t--){
        cin >> a >> b >> c;
        ans=min(c/2,b);
        b-=ans;
        ans+=min(a,b/2);
        cout << ans*3 << endl;
    }
    return 0;

}
