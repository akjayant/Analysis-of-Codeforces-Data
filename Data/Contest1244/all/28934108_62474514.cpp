#include <bits/stdc++.h>
using namespace std;

int t, st, fn, n;
bool u;
string s;

int main(){

    cin>>t;
    while(t--){

        u = 0;
        st = -1;
        fn = -1;
        cin>>n;
        cin>>s;
        for(int i=0;i<n;i++){
            if(s[i] == '1'){
               // a[i] = 1;
                if(!u){
                    u = 1;
                    st = i;
                }
                fn = n - i - 1;
            }
            //else a[i] =0;
        }
        if(st == -1)
            cout<<n<<'\n';
        else {
            if(st>fn){
                cout<<(n - fn)*2;
            }
            else cout<<(n - st)*2;
            cout<<'\n';
        }

    }

    return 0;
}


