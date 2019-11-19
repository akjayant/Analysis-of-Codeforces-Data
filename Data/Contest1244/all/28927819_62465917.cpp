#define HAVE_STRUCT_TIMESPEC
#include<bits/stdc++.h>
using namespace std;
int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int t;
    cin>>t;
    while(t--){
        int a,b,c,d,k;
        cin>>a>>b>>c>>d>>k;
        int flag=0;
        for(int i=1;i<k;++i){
            if(i*c>=a&&(k-i)*d>=b){
                cout<<i<<" "<<k-i<<"\n";
                flag=1;
                break;
            }
        }
        if(!flag)
            cout<<"-1\n";
    }
    return 0;
}
