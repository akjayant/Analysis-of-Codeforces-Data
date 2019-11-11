#include <bits/stdc++.h>
using namespace std;
int n, t, a, b, c;
string st;

int main()
{
    cin>>t;
    while(t--){
        cin>>n;
        cin>>a>>b>>c;
        cin>>st;
        vector<char> ans;
        ans.resize(st.length());
        for(int i = 0; i < st.length(); i++) ans[i] = 0;
        for(int i = 0; i < st.length(); i++){
            if(st[i] == 'R'){
                if(b > 0){
                    b--;
                    ans[i] = 'P';
                }
            } else if(st[i] == 'P'){
                if(c > 0){
                    c--;
                    ans[i] = 'S';
                }
            } else {
                if(a > 0){
                    a--;
                    ans[i] = 'R';
                }
            }
        }
        if(n - (a+b+c) < (n+1)/2){
            cout<<"NO"<<endl;
        } else {
            cout<<"YES"<<endl;
            for(int i = 0; i < st.length(); i++){
                if(ans[i] == 0){
                    if(a > 0){
                        a--;
                        cout<<'R';
                    } else if(b > 0){
                        b--;
                        cout<<'P';
                    } else {
                        c--;
                        cout<<'S';
                    }
                } else cout<<ans[i];
            }
            cout<<endl;
        }
    }
    return 0;
}
