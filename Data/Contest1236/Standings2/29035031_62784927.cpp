#include<bits/stdc++.h>
//#include <ext/pb_ds/assoc_container.hpp>
//#include <ext/pb_ds/tree_policy.hpp>
//using namespace __gnu_pbds;
#define eps 1e-8
#define eq(x,y) (fabs((x)-(y)) < eps)
using namespace std;
typedef long long ll;
typedef long double ld;
typedef pair<int,int>pii;
const ll mod= 1e9+7;
long double PI = acosl(-1);
const ll inf = 1e15;
const int nmax = 1e5+5;
const int MAXLG = log2(nmax)+1;
//mt19937 rng(chrono::system_clock::now().time_since_epoch().count());
//typedef tree< int, null_type, less<int>, rb_tree_tag, tree_order_statistics_node_update> ost;



int main(){
    ios::sync_with_stdio(false); cin.tie(0);

    int t;
    cin>>t;
    while(t--){
        int a,b,c;

        cin>>a>>b>>c;
        int sam = a+b+c;
        while(b and c>=2){
            b--, c-=2;
        }
        while(a and b>=2){
            a--, b-=2;
        }
        cout<<sam-a-b-c<<"\n";
    }



}