#include <bits/stdc++.h>  
#define N 100005
#define pb push_back
#define fi first
#define se second
#define fastio ios_base::sync_with_stdio(false);cin.tie(0)
using namespace std;
typedef long long ll;
typedef pair<int,int> pii;
int t,n,a[N];

int main(){
    cin>>t;
    while(t--){
        cin>>n;
        for(int i=0;i<n;i++) cin>>a[i];
        sort(a,a+n);
        for(int i=n;i>=1;i--){
            bool chk=true;
            for(int j=n-1;j>=n-i;j--){
                if(a[j]<i) chk=false; 
            }
            if(chk){
                cout<<i<<"\n";
                break;
            }
        }
    }
    return 0;
}