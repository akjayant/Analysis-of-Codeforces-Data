#include<bits/stdc++.h>
using namespace std;
int main() {
    //do this
    int t;
    for(cin>>t;t>0;t--) {
        int n;
        cin>>n;
        string str;
        cin>>str;
        int mn = -1, mx = -1;
        for(int i = 0;i<str.length();i++) {
            if(str[i]=='1') {
                mx=i;
                if(mn==-1)
                    mn=i;
            }
        }
        int moves= (mx-mn+1)*2;
        int disl = mn;
        int disr = n-1-mx;
        moves+=(2*max(disl,disr));
        if(mn==-1) {
            cout<<n<<endl;
        }
        else
        cout<<moves<<endl;
    }

}

