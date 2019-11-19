#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace std;
using namespace __gnu_pbds;
 
#define mod -1000000000000007
#define pb push_back
#define mp make_pair
#define PI 3.1415926535
#define pf push_front
#define ll long long int
#define ull unsigned long long int 
typedef pair<int,int>  pii;  
uint64_t seed = reinterpret_cast<uint64_t>(new char);
mt19937_64 rd(seed);
//uniform_int_distribution<int> rg(1, n);
//int RandomNumber = rg(rd);
// vector < int > v(N,-1);   sqrtl for square root of ll
// vector of size N with initial value -1 
typedef tree<int, null_type, less<int>, rb_tree_tag, tree_order_statistics_node_update> pbds;
typedef tree<int, null_type, less<int>, rb_tree_tag, tree_order_statistics_node_update> OST;
#define gc getchar_unlocked
 
const int N=2505;

int main ()     
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int t;
    t=1;
    long double xd=2;
    while(t--)
    {
        ll n,i,j,k,l,m,p;
        cin>>n;
        ll ans=n;
        for(i=2;(i*i)<=n;i++)
        {
            if(n%i==0){
                //fg=1;
                //cout<<i<<" "<<n/i<<endl;
                ans=__gcd(ans,i);
                ans=__gcd(ans,n/i);
            }
        }
        cout<<ans<<endl;
    }
    return 0;
}