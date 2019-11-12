#include <bits/stdc++.h>
using namespace std;
static const int MAXN=1000;
int a[MAXN+10];
bool cmp(int a,int b)
{
    return a>b;
}
int main()
{
    int K;
    cin>>K;
    while(K--)
    {
        int n;
        cin>>n;
        for(int i=1;i<=n;i++)
            cin>>a[i];
        sort(a+1,a+n+1);
        int cnt=0;
        for(int i=1;i<=n;i++)
            cnt=max(cnt,min(a[i],n-i+1));
        cout<<cnt<<endl;
    }
    return 0;
}