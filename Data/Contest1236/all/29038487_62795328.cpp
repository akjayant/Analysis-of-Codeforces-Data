#include<iostream>
#include<vector>
#include<string>
#include<map>
#include<queue>
#include<math.h>
#include<algorithm>
#include<iomanip>
#include<set>
#include<climits>
#include<utility>
using namespace std;
# define pb push_back
# define mp make_pair
# define PI 3.1415926535
# define eps 1e-9

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    long long n;
    cin>>n;
    long long ans[n][n];
    long long count=1;
    for(long long j=0;j<n;j++)
    {
        if(j%2==0)
        {
            for(long long i=0;i<n;i++)
            {
                ans[i][j]=count;
                count++;
            }
        }
        else
        {
            for(long long i=n-1;i>=0;i--)
            {
                ans[i][j]=count;
                count++;
            }
        }

    }
    for(long long i=0;i<n;i++)
    {
        for(long long j=0;j<n;j++)
        {
            cout<<ans[i][j]<<" ";
        }
        cout<<endl;
    }






    return 0;
}