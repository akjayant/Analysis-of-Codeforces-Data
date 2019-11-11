#include <bits/stdc++.h>

using namespace std;
int gcd (int a, int b) {
	return b ? gcd (b, a % b) : a;
}
int main(){
    int t;
    cin>>t;
    while(t){
        t--;
        int n,a,b,c;
        cin>>n>>a>>b>>c;
        string s;
        vector<char>ans(n);
        vector<int>free;
        cin>>s;
        int cnt1=0,cnt2=0,cnt3=0,win=0;
        for(int i=0;i<n;i++){
            if(s[i]=='R'){
                if(b){
                    b--;
                    win++;
                    ans[i]='P';
                }
                else
                    free.push_back(i);
            }
            else if(s[i]=='P'){
                if(c){
                    c--;
                    win++;
                    ans[i]='S';
                }
                else
                    free.push_back(i);
            }
            else{
                if(a){
                    a--;
                    win++;
                    ans[i]='R';
                }
                else
                    free.push_back(i);
            }
        }
        for(int i=0;i<free.size();i++){
            if(a){
                ans[free[i]]='R';
                a--;
            }
            else if(b){
                ans[free[i]]='P';
                b--;
            }
            else{
                ans[free[i]]='S';
                c--;
            }
        }
        if(win>=n/2+n%2){
            cout<<"YES"<<endl;
            for(int i=0;i<n;i++)
                cout<<ans[i];
            cout<<endl;
        }
        else{
            cout<<"NO"<<endl;
        }
    }
    return 0;
}