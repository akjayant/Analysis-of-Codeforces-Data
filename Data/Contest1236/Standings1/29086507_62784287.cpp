#include <bits/stdc++.h>

using namespace std;

int main()
{
    int T;
    scanf("%d",&T);
    while(T--)
    {
        int a,b,c;
        cin>>a>>b>>c;
        int t=min(b,c/2);
        int sum=t*3;
        b=b-t;
        sum=sum+3*min(a,b/2);
        cout<<sum<<endl;
    }
    return 0;
}
