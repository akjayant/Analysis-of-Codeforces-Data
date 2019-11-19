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
        int a,b,c,d,k;
        cin>>a>>b>>c>>d>>k;
        int pen = a/c;
        if(a%c != 0)
            pen++;
        int pencil = b/d;
        if(b%d != 0)
            pencil++;
        if((pen+pencil) <= k)
        {
            cout<<pen<<" "<<pencil<<endl;
        }
        else
            cout<<-1<<endl;
    }
    return 0;
}