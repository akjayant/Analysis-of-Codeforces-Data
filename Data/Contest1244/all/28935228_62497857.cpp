#include <bits/stdc++.h>

using namespace std;

#define int long long 
#define N 100005

int pref[N];
int suff[N];

int32_t main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n, k;
    cin>>n>>k;

    vector < int > a;
    a.push_back(0);
    for(int i=1;i<=n;i++)
    {
        int temp;
        cin>>temp;
        a.push_back(temp);
    }

    sort(a.begin(), a.end());

    int ans = a[n] - a[1];

    int pre = 0;
    for(int i=0;i<=n;i++)
    {
        pre+=a[i];
        int c1 = a[i]*i - pre;
        pref[i] = c1;
        
    }

    int suf = 0;
    for(int i=n;i>=1;i--)
    {
        suf+=a[i];
        int c1 = - a[i]*(n-i+1) + suf;
        suff[i] = c1;
        if( c1 > k) 
            continue;
        
        int l = 1, r = n;
        int maxk = k - c1;
        int maxi = 1;
        while(l<=r)
        {
            int mid = (l+r)/2;

            if( pref[mid] > maxk)
            {
                r = mid - 1;
            }
            else 
            {
                maxi = max(maxi, mid);
                l = mid + 1;
            }
        }

        if( maxi > i)
        {
            ans = 0;
            continue;
        }

        int extra = (maxk-pref[maxi])/maxi;

        int y = a[i] - a[maxi] - extra;
        y = max(0ll, y);
        ans = min(ans, y);
    }

    for(int i=1;i<=n;i++)
    {
        int c1 = pref[i];
        if( c1 > k) 
            continue;
        
        int l = 1, r = n;
        int maxk = k - c1;
        int maxi = n;
        while(l<=r)
        {
            int mid = (l+r)/2;

            if( suff[mid] > maxk)
            {
                l = mid + 1;
            }
            else 
            {
                maxi = min(maxi, mid);
                r = mid - 1;
            }
        }

        if( maxi < i)
        {
            ans = 0;
            continue;
        }

        int extra = (maxk-suff[maxi])/(n-maxi+1);
        int y = a[maxi] - a[i] - extra;
        y = max(0ll, y);
        ans = min(ans, y);
    }
    cout<<ans<<endl;
    return 0;
}
