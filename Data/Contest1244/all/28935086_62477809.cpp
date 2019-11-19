#include <bits/stdc++.h> 
using namespace std;
typedef unsigned long long int ull;
typedef long long int ll;
typedef long double ld;
typedef vector<ll> vl;
typedef pair<ll,ll> pll;
#define MOD 1000000007
#define mp make_pair
#define pb push_back
#define ss second
#define ff first
void fast() { ios_base::sync_with_stdio(false); cin.tie(NULL);cout.tie(NULL); }
#define all(v) v.begin(),v.end()
#define rall(v) v.rbegin(),v.rend()
#define gcd(a,b) __gcd((a), (b))
#define lcm(a,b) ((a)*(b))/gcd((a),(b))

int main() 
{
    int t;
    cin>>t;
    for (int i = 0; i < t; i++)
    {
        int n;
        cin>>n;
        string s;
        cin>>s;
        int temp=-1;
        for (int j = 0; j < n; j++)
        {
            if(s[j]=='1')
            {
                temp=j;
                break;
            }
            if(s[n-j-1]=='1')
            {
                temp=j;
                break;
            }
        }
        if(temp == -1)
        {
            cout<<n<<endl;
        }
        else
        {
            int ans=(n-temp)*2;
            cout<<ans<<endl;
        }
    }
    return 0;
}