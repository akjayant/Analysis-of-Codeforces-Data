#include<bits/stdc++.h>
#define ll long long
#define N 100050
using namespace std;
int suf[505];
int fin(string s){
    int su=0;
    int n=s.length();
    int p=n;
    suf[p-1]=0;
    memset(suf,0,sizeof(suf));
    if(s[p-1]=='(')suf[p-1]=1;
    else suf[n-1]--;
    for(int i=n-2;i>=0;i--){
        if(s[i]=='(')suf[i]++;
        else suf[i]--;
        suf[i]+=suf[i+1];
    }
    int ma=-1;
    int in=0;
    for(int i=0;i<n;i++){
        if(ma<suf[i]){
            ma=suf[i];
            in=i;
        }
    }
    string h;
    for(int i=in;i<n;i++)
        h+=s[i];
    for(int i=0;i<in;i++)
        h+=s[i];
    int ans=0;
    int cu=0;
    int fl=0;
    for(int i=0;i<n;i++){
        if(h[i]=='('){
            cu++; continue;
           }
        if(h[i]==')'){
            cu--;
            if(cu==0)ans++;
            if(cu<0)fl=1;
        }
    }
    if(fl)ans=0;
    return ans;
}
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int n; cin>>n;
    string s;
    cin>>s;
    string a(s.begin(),s.end());
    int ma=0; int l=0; int r=0;
   // cout<<a;
   int cu=0;
   for(int i=0;i<n;i++){
    if(s[i]=='(')cu++;
    else cu--;
   }
   if(cu){
    cout<<"0\n";
    cout<<"1 1\n";
    return 0;
   }
    for(int i=0;i<n;i++){
        for(int j=i;j<n;j++){
            swap(a[i],a[j]);
            int tmp=fin(a);
            ma=max(ma,tmp);
          //  cout<<tmp<<" "<<i<<" =i and j= "<<j<<" "<<a<<"\n";
            if(tmp==ma){
                l=i; r=j;
            }
            swap(a[i],a[j]);
        }
    }
    cout<<ma<<"\n";
    cout<<l+1<<" "<<r+1<<"\n";
}