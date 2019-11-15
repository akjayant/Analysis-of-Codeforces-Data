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
    ll t,n,ans=0,t1;
    string s1,s2;
    char c;
    cin>>t;
    while (t--){
        cin>>n;
        cin>>s1>>s2;
        ll a[26]={0};
        ll b[26]={0};
        REP(i,0,n-1){
            a[s1[i]-'a']++;
            b[s2[i]-'a']++;
        }
        t1=0;
        REP(i,0,25){
            if(((a[i]+b[i])%2)!=0){
                t1=1;
                continue;
            }
        }
        if(t1==1){
            cout<<"No\n";
            continue;
        }
        vector<pi> v;
        cout<<"Yes\n";
        REP(i,0,n-1){
            if(s1[i]==s2[i])
                continue;
            t1=-1;
            REP(j,i+1,n-1){
                if(s1[i]==s1[j]){
                    t1=j;
                    continue;
                }
            }
            if(t1 != -1){
                v.EB(MP(t1,i));
                c= s1[t1];
                s1[t1]=s2[i];
                s2[i]=c;
            }
            else{
                REP(j,i+1,n-1){
                    if(s1[i]==s2[j]){
                        t1=j;
                        continue;
                    }
                }
                v.EB(MP(t1,t1));
                v.EB(MP(t1,i));
                c= s1[t1];
                s1[t1]=s2[t1];
                s2[t1]=c;

                c= s1[t1];
                s1[t1]=s2[i];
                s2[i]=c;
            }
        }
        cout<<v.size()<<"\n";
        for(auto x:v){
            cout<<x.F+1<<" "<<x.S+1<<"\n";
        }
    }
    return 0;
}
