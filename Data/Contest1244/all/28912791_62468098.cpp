#include<bits/stdc++.h>
using namespace std;
int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        int a,b,x,y,k;
        cin>>a>>b>>x>>y>>k;
        int ans= ceil((float)a/x)+ceil((float)b/y);
        if(ans>k)
            cout<<"-1"<<endl;
        else
            cout<<ceil((float)a/x)<<" "<<ceil((float)b/y)<<endl;
    }
    return 0;
}