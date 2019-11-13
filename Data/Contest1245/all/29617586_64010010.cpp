#include<bits/stdc++.h>
using namespace std;
int ans[1000];
int main(){
    ios::sync_with_stdio(0);
    int t,i,t1,t2,t3,a,b,c,n;
    cin>>t;
    while (t--){
        cin>>n;
        cin>>a>>b>>c;
        string s;
        cin>>s;
        t1=t2=t3=0;
        for (i=0;i<s.size();i++){
            if (s[i]=='R')
                t1++;
            if (s[i]=='P')
                t2++;
            if (s[i]=='S')
                t3++;
        }
        int m=min(a,t3)+min(b,t1)+min(c,t2);
        if (m*2>=n)
        {
            cout<<"YES\n";
            memset(ans,0,sizeof(ans));
            for (i=0;i<s.size();i++){
                if (s[i]=='R'&&b){
                    ans[i]=2;
                    b--;
                }
                if (s[i]=='P'&&c){
                    ans[i]=3;
                    c--;
                }
                if (s[i]=='S'&&a){
                    ans[i]=1;
                    a--;
                }
            }
            for (i=0;i<s.size();i++){
                if (!ans[i]){
                    if (a){
                        ans[i]=1;
                    a--;
                    }else if (b)
                        {
                            ans[i]=2;
                    b--;
                    }else ans[i]=3;
                }
            }
            for (i=0;i<s.size();i++){
                if(ans[i]==1)
                    cout<<"R";
                else if (ans[i]==2)
                    cout<<"P";
                else cout<<"S";
            }
            cout<<"\n";
        }
        else cout<<"NO\n";
    }
}
