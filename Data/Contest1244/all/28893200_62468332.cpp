#include <bits/stdc++.h>
#define mk make_pair
#define fs first
#define sc second
using namespace std;
typedef long long ll;
typedef long double ld;
int a[100010];
char s[100010];
int main(){
    int n, t;
    cin>>t;
    while(t--){
        cin>>n;
        int ans=0;
        scanf("%s",s);
        ans=n;
        for(int i=0; i<n; ++i){
            if(s[i]=='1'){
                ans=max(ans, (n-i)*2);
                ans=max(ans, (i+1)*2);
            }
        }
        cout<<ans<<endl;
    }
  return 0;
}


