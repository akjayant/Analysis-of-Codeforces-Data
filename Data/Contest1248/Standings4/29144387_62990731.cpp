#include<iostream>
#include<algorithm>
using namespace std;
const int maxn=100010;
long long a[maxn];
long long ans1,ans2;
int main()
{
    int n;cin>>n;
    for(int i=1;i<=n;i++) cin>>a[i];
    sort(a+1,a+n+1);
    int l=1,r=n;
    while(l<=n/2)
    {
        ans1+=a[l];ans2+=a[r];
        l++;r--;
    }
    if(!(n%2))
    {
        cout<<ans1*ans1+ans2*ans2<<endl;return 0;
    }
    else
    {
        long long err1=ans1+a[l],err2=ans2+a[l];
        cout<<max(err1*err1+ans2*ans2,ans1*ans1+err2*err2)<<endl;
        return 0;
    }
}