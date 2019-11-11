#include <bits/stdc++.h>
#define mk make_pair
#define fs first
#define sc second
using namespace std;
typedef long long ll;
typedef long double ld;
int main(){
    int n, t;
    cin>>t;
    while(t--){
        int a, b, c;
        cin>>n>>a>>b>>c;
        char s[111], st[111];
        scanf("%s",s);
        int ans=0;
        for(int i=0; i<n; ++i){
            st[i]='.';
            if(s[i]=='R'){
                if(b>0){
                    --b;
                    ++ans;
                    st[i]='P';
                }
            }
            else if(s[i]=='P'){
                if(c>0){
                    --c;
                    ++ans;
                    st[i]='S';
                }
            }
            else{
                if(a>0){
                    --a;
                    ++ans;
                    st[i]='R';
                }
            }
        }
        for(int i=0; i<n; ++i){
            if(st[i]=='.'){
                if(a>0){
                    st[i]='R';
                    --a;
                    continue;
                }
                if(b>0){
                    st[i]='P';
                    --b;
                    continue;
                }
                if(c>0){
                    st[i]='S';
                    --c;
                    continue;
                }
            }
        }
        if(ans*2>=n){
            cout<<"YES"<<endl;
            for(int i=0; i<n; ++i){
                cout<<st[i];
            }
            cout<<endl;
        }
        else{
            cout<<"NO"<<endl;
        }
    }
  return 0;
}


