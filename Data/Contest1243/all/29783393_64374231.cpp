/*suri_kumkaran*/

#include <bits/stdc++.h>

using namespace std;

#define UB upper_bound
#define LB lower_bound
#define BS binary_search
#define MP make_pair
#define EB emplace_back
#define endl "\n"
#define PI 3.1415926535897932384626433832795
#define MOD 1000000007
#define F first
#define S second
#define ALL(a) (a).begin(),(a).end()
#define IOS ios::sync_with_stdio(0); cin.tie(0); cout.tie(0)

typedef long long int int64;
typedef vector<int64> VI64;
typedef vector<pair<int64,int64>> VII64;
typedef vector<string> VS;
typedef vector<vector<int64>> VVI;

int main()
{
    IOS;
    int64 T=1;
    cin>>T;
    while(T--)
    {
        int64 n,i,j;
        cin>>n;
        int64 a[n];
        for(i=0;i<n;i++)
        {
            cin>>a[i];
        }
        int64 ans=0;
        for(i=1;i<=1000;i++)
        {
            int64 cnt=0;
            for(j=0;j<n;j++)
            {
                if(a[j]>=i)
                    cnt++;
            }
            if(cnt>=i)
                ans=max(i,ans);
        }
        cout<<ans<<endl;
    }

    return 0;
}