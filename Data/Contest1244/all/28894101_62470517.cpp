#include<bits/stdc++.h>
#define pb push_back
#define ll long long
#define ss second
#define ff first
using namespace std;
int check(int x,int n){
   return max((n-x+1)*2,x*2);
}
int main(){

    int t;
    scanf("%d",&t);
    while(t--){
        int n;
        scanf("%d",&n);
        string s;
        cin>>s;
        int cnt=0;
        int l=n+10;
        int r=-1;
        for(int i=0;i<n;i++)
            if(s[i]=='1'){
                cnt++;
                l=min(l,i+1);
                r=max(r,i+1);
            }
        if(cnt==0){
            printf("%d\n",n);
            continue;
        }
        printf("%d\n",max(check(l,n),check(r,n)));
    }


    return 0;
}
