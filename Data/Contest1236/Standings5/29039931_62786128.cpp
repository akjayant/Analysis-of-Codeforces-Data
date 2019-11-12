#include <bits/stdc++.h>

using namespace std;
long long T,a,b,c,kq;
int main()
{
    cin>>T;
    while (T--)
    {
        cin>>a>>b>>c;
        if (b*2<=c) {cout<<b*3<<'\n';continue;}
        kq=(c/2)*3;
        b=b-c/2;
        kq+=min(a*3,(b/2)*3);
        cout<<kq<<'\n';
    }
    return 0;
}
