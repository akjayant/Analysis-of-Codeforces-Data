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
        int f1[26]={0};  
        for(i=0;i<n;i++){
            f1[str[i]-'a']++;  f1[ptr[i]-'a']++;
        }
        int fg=0;
        for(i=0;i<26;i++)
        {
            if(f1[i]%2){
                fg=1;  break;
            }
        }
        vector <pii> v;
        if(fg){
            cout<<"No"<<endl;  continue;
        }
        for(i=0;i<n;i++)
        {
            if(str[i]!=ptr[i]){
                char x;
                for(j=i+1;j<n;j++)
                {
                    if(str[j]==str[i]){
                        v.pb({j,i});
                        x=str[j];  
                        str[j]=ptr[i];
                        ptr[i]=x;
                        break;
                    }
                }
                if(j==n)  {
                    for(j=i+1;j<n;j++)
                    {
                        if(ptr[i]==ptr[j]){
                            v.pb({i,j});
                            x=str[i];
                            str[i]=ptr[j];
                            ptr[j]=x;
                            break;
                        }
                    }
                    if(j==n){
                        char x=str[i];
                        str[i]=ptr[i];
                        ptr[i]=x;
                        v.pb({i,i});
                        for(j=i+1;j<n;j++)
                        {
                            if(str[j]==str[i]){
                                v.pb({j,i});
                                x=str[j];  
                                str[j]=ptr[i];
                                ptr[i]=x;
                                break;
                            }
                        }
                        if(j==n)   {
                            for(j=i+1;j<n;j++)
                            {
                                if(ptr[i]==ptr[j]){
                                    v.pb({i,j});
                                    x=str[i];
                                    str[i]=ptr[j];
                                    ptr[j]=x;
                                    break;
                                }
                            }
                            if(j==n){
                                fg=1;  break;
                            }
                        }
                    }
                }
            }
        }
        if(fg){
            cout<<"No"<<endl;  continue;
        }
        cout<<"Yes"<<endl;
        cout<<v.size()<<endl;
        for(auto pk : v)  cout<<pk.first+1<<" "<<pk.second+1<<endl;
    }
    return 0;
}

