#include<bits/stdc++.h>
#define fastio ios_base::sync_with_stdio(false); cin.tie(0);
using namespace std;
long long mod=1000000007;

int main()
{
    fastio;
    int t;
    cin>>t;
    while(t--){
        int n;
        cin>>n;
        string s1,s2;
        cin>>s1>>s2;
        int cnt=0;
        char first,second;
        for(int i=0;i<n;i++){
            if(s1[i]!=s2[i]){
                cnt++;
                first=s1[i],second=s2[i];
            }
        }
        if(cnt!=2)
        cout<<"No \n";
        else {
            bool poss=true;
            for(int i=0;i<n;i++)
            if(s1[i]!=s2[i]){
                if(s1[i]!=first||s2[i]!=second)
                poss=false;
            }
            if(poss)
            cout<<"Yes \n";
            else 
            cout<<"No \n";
        }
    }
   

}