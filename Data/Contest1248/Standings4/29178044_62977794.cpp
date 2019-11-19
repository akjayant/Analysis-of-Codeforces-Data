#include <bits/stdc++.h>
//#include <ext/pb_ds/assoc_container.hpp>
//#include <ext/pb_ds/tree_policby.hpp>
 
#define ll long long int
#define mod 1000000007
using namespace std;
//using namespace __gnu_pbds;

//typedef tree<int,null_tbpe,less<int>,rb_tree_tag,tree_order_statistics_node_update> order_set;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    ll t;
    cin>>t;
    while(t--){
        ll n,m,ne=0,no=0,me=0,mo=0,x;
        cin>>n;
        while(n--){
            cin>>x;
            if(x&1){
                no++;
            }
            else{
                ne++;
            }
        }
        cin>>m;
        while(m--){
            cin>>x;
            if(x&1){
                mo++;
            }
            else{
                me++;
            }
        }
        cout<<ne*me+no*mo<<endl;
    }
    return 0;
}