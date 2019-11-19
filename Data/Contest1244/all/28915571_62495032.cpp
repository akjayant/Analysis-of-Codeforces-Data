#include <bits/stdc++.h>
using namespace std;
long long n,k;
pair<long long,long long> a[100100];
int main()
{
    cin>>n>>k;
    for(long long i=0;i<n;i++)
    {
        scanf("%lld",&a[i].first);
        a[i].second=1;
    }
    sort(a,a+n);
    int low=0;
    int high=n-1;
    while(low!=high)
    {
        if(a[low].second<a[high].second)
        {
            long long change=a[low].second*(a[low+1].first-a[low].first);
            if(change>k)
            {
                cout<<(a[high].first-a[low].first-k/a[low].second);
                return 0;
            }
            a[low+1].second+=a[low].second;
            k-=change;
            low++;
        }
        else
        {
            long long change=a[high].second*(a[high].first-a[high-1].first);
            if(change>k)
            {
                cout<<(a[high].first-a[low].first-k/a[high].second);
                return 0;
            }
            a[high-1].second+=a[high].second;
            k-=change;
            high--;
        }
    }
    cout<<"0";
}
