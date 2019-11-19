#include <bits/stdc++.h>
#define mk make_pair
#define fs first
#define sc second
using namespace std;
typedef long long ll;
typedef long double ld;
int a[100010];
int main(){
    int n, t, a, b, c, d, k;
    cin>>t;
    while(t--){
        cin>>a>>b>>c>>d>>k;
        int tmp1=(a+c-1)/c, tmp2=(b+d-1)/d;
        if(tmp1+tmp2<=k){
            cout<<tmp1<<" "<<tmp2<<endl;
        }
        else{
            cout<<-1<<endl;
        }

    }
  return 0;
}


