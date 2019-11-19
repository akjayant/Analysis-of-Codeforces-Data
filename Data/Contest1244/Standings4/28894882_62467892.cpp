#include<bits/stdc++.h>
using namespace std;
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    int t;
    cin>>t;
    while(t--){
        int a,b,c,d,k;
        cin>>a>>b>>c>>d>>k;
        int l1=(a/c)+(a%c!=0);
        int l2=(b/d)+(b%d!=0);
        if (l1+l2>k) cout<<-1;
        else cout<<l1<<' '<<l2;
        cout<<endl;
    }

}
