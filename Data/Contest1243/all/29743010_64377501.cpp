#include<bits/stdc++.h>
using namespace std;
int a[100010],b[100010];
int main(){
    int T;
    cin>>T;
    while (T--){
        int n;
        string s,t;
        cin>>n;
        cin>>s>>t;
        int cnt=0;
        for (int i=0;i<n;i++){
            if (s[i]!=t[i]) {
                a[cnt]=s[i];
                b[cnt]=t[i];
                cnt++;
            }
        }
        if (cnt==0) puts("Yes");
        else {
            if (cnt==2){
                if (a[0]==a[1] && b[0]==b[1]) puts("Yes");
                else puts("No");
            }else puts("No");
        }
    }
}