#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define debug(a) cout<<#a<<" --> "<<(a)<<endl;
#define fastInput ios_base::sync_with_stdio(false);cin.tie(0)
#define INPUT freopen("input.txt","r",stdin)
#define OUTPUT freopen("output.txt","w",stdout)
#define mod  1000000007
#define error  1e-7
const int N = 1005;


void Solve()
{
    int n;
    cin>>n;
    vector<int>a(n);
    for(int i=0;i<n;i++)
    {
        cin>>a[i];
    }
    sort(a.rbegin(),a.rend());
    int maxi = 0;
    for(int i=0;i<n;i++)
    {
        maxi = max(maxi , min(i+1 , a[i]));
    }
    cout<<maxi<<endl;

}
int main()
{
    //fastInput;
    //cout.tie(0);
    int t=1;
    scanf("%d",&t);
    while(t--)
    {
        Solve();
    }
    return 0;
}
/*




 */
