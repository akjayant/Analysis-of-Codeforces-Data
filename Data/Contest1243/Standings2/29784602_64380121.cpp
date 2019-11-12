#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace std;
using namespace __gnu_pbds;
 
#define mod 1000000007
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
 
const int N=10000006;

int main ()     
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int t;
    cin>>t;
    while(t--)
    {
        int i,j,k,l,m,n,p;
        string str;
        cin>>n;
        string ptr;
        cin>>str>>ptr;
        vector <int> v;
        for(i=0;i<n;i++)
        {
            if(str[i]!=ptr[i]){
                v.pb(i);
            } 
        }
        if(v.size()==0)
        {
            cout<<"Yes"<<endl;  continue;
        }
        if(v.size()!=2){
            cout<<"No"<<endl;  continue;
        }
        if(str[v[0]]==str[v[1]] && ptr[v[0]]==ptr[v[1]])  cout<<"Yes"<<endl;
        else cout<<"No"<<endl;
    }
    return 0;
}

