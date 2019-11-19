#include<iostream>
#include<stdio.h>
#include<vector>
#include<cmath>
#include<queue>
#include<string.h>
#include<map>
#include<set>
#include<algorithm>
#define ll long long
#define pi pair < ll,ll >
#define mp(a,b) make_pair(a,b)
#define rep(i,a,b) for(int i = a;i < b;i++)
#define N 300004
#define INF 1e9+7

using namespace std;

ll n,k,ar[N];

int main()
{
    ios_base::sync_with_stdio(false);

    cin >> n >> k;

    rep(i,0,n)
    {
        cin >> ar[i];
    }

    sort(ar,ar+n);

    ll i = 0;
    ll j = n-1;

    while(i < j && k > 0)
    {
       // cout << i << " " << j << " " << k << endl;

        if(ar[i+1] == ar[i])
            i++;
        else if(ar[j-1] == ar[j])
            j--;
        else
        {
            if(i+1 < n-j)
            {
                if(k < i+1)
                    break;


                ll wanted = (ar[i+1]-ar[i])*(i+1);

                if(wanted <= k)
                {
                    k -= wanted;
                    i++;
                }
                else
                {
                    ar[i] += (k/(i+1));
                    break;
                }
            }
            else
            {
                if(k < n-j)
                    break;

                ll wanted = (ar[j]-ar[j-1])*(n-j);

                if(wanted <= k)
                {
                    k -= wanted;
                    j--;
                }
                else
                {
                    ar[j] -= (k/(n-j));
                    break;
                }
            }
        }
    }

    cout << ar[j] - ar[i];

    return 0;
}

