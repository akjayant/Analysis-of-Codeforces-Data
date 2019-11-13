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
    ll t,n,ans=0,t1,t2,tt;
    string s1,s2;
    char c;
    cin>>t;
    while (t--){
        cin>>n;
        cin>>s1>>s2;
        t1=t2=-1;
        tt=0;
        REP(i,0,n-1){
            if(s1[i]!=s2[i]){
                if(t1==-1){
                    t1=i;
                }
                else if(t2==-1){
                    t2=i;
                }
                else{
                    tt=1;
                    break;
                }
            }
        }
        if(tt==1){
            cout<<"No\n";
            continue;
        }
        if(t1==-1){
            cout<<"Yes\n";
        }
        else if(t2==-1){
            cout<<"No\n";
        }
        else{
            if((s1[t1]==s1[t2]) && (s2[t1]==s2[t2]))
                cout<<"Yes\n";
            else
                cout<<"No\n";
        }
    }
    return 0;
}
