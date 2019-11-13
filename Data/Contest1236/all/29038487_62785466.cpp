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
    long long t;
    cin>>t;
    while(t--)
    {
        long long a,b,c;
        cin>>a>>b>>c;
        long long ans=0;
        while(c>=2 && b>=1)
        {
            c=c-2;
            b--;
            ans++;

        }
        while(b>=2 && a>=1)
        {
            b=b-2;
            a--;
            ans++;
        }
        cout<<ans*3<<endl;
    }







    return 0;
}