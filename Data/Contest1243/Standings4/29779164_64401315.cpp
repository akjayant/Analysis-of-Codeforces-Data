#include <bits/stdc++.h>
//#include <ext/pb_ds/assoc_container.hpp>
using namespace std;
//using namespace __gnu_pbds;

//typedef tree<int,null_type,less<int>,rb_tree_tag, tree_order_statistics_node_update> indexed_set;
typedef long long int ll ;
typedef vector<long long int> vi;
typedef pair<ll,ll> pi;

#define PB push_back
#define EB emplace_back
#define REP(i,a,b) for(long long int i=a ; i<=b ; i++)
#define REV(i,a,b) for(long long int i=a ; i>=b ; i--)
#define F first
#define S second
#define MP make_pair
#define INF 100000000000000000
#define MOD 1000000007
#define MT make_tuple

int main () {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    ll t=-1,n,q;
    cin>>n;
    q=n;
    ll i=2;
    while(n%i==0){
        t=i;
        n/=i;
    }
    for(i=3;i*i<=n;i+=2){
        if(n%i==0){
            if(t!=-1){
                cout<<"1 ";
                return 0;
            }
            else{
                t=i;
            }
            while(n%i==0)
                n/=i;
        }
    }
    if(n==q){
        cout<<q;
    }
    else if(n==1)
        cout<<t;
    else
        cout<<"1";
    return 0;
}
