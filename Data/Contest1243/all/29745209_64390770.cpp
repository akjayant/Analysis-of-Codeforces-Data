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
    ll n;
    cin>>n;
    if(n==1)
    {
        cout<<1<<endl;
        return;
    }
    vector<ll >divisor;
    ll g= n;
    for(ll i=2;i*i<=n;i++)
    {
        if(n%i==0)
        {
            divisor.push_back(i);
            g= __gcd(g,i);
            if(i!= (n/i))
            {
                divisor.push_back(n/i);
                g= __gcd(g,(n/i));
            }
        }
    }
    divisor.push_back(n);
//    sort(divisor.begin(),divisor.end());
//    for(ll i=0;i<divisor.size() -1;i++)
//    {
//        if(divisor[i+1]-divisor[i]==1)
//        {
//            cout<<1<<endl;
//            return ;
//        }
//    }
    cout<<g<<endl;
}
int main()
{
    //fastInput;
    //cout.tie(0);
    int t=1;
    //scanf("%d",&t);
    while(t--)
    {
        Solve();
    }
    return 0;
}
/*




 */
