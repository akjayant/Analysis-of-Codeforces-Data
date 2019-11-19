#include <bits/stdc++.h>
using namespace std;

const int maxn=1e5+10;
typedef long long ll;
ll a[maxn];
int n;
ll k;

int main()
{
    cin>>n>>k;
    for(int i=0;i<n;i++)
        cin>>a[i];
    sort(a,a+n);
    int i=0,j=n-1;
    ll cnt1=1,cnt2=1;
    ll mi=a[0],ma=a[j];
    while(i<j&&mi<ma)
    {
        if(cnt1<cnt2)
        {
            ll tmp=cnt1*(a[i+1]-a[i]);
            if(k>=tmp)
            {
                k-=tmp;
                i=i+1;
                cnt1++;
                mi=a[i];
                if(k==0)
                    break;
            }
            else
            {
                ll tt=k/cnt1;
                mi+=tt;
                break;
            }
        }
        else
        {
            ll tmp=cnt2*(a[j]-a[j-1]);
            if(k>=tmp)
            {
                k-=tmp;
                j--;
                cnt2++;
                ma=a[j];
                if(k==0)
                    break;
            }
            else
            {
                ll tt=k/cnt2;
                ma-=tt;
                break;
            }
        }
    }
    cout<<ma-mi<<endl;
}