#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N =1e3+7;
int n;
int ans,al,ar;
char s[N];
int l1[N],r1[N],l2[N],r2[N];
void cal(int l,int r)
{
    int now=0;
    for(int i=1;i<=n;i++){
        if(s[i]=='('){
            l1[i]=l1[i-1]+1;
            r1[i]=r1[i-1];
        }
        else{
            if(l1[i-1]>=1){
                l1[i]=l1[i-1]-1;
                r1[i]=r1[i-1];
            }
            else{
                l1[i]=l1[i-1];
                r1[i]=r1[i-1]+1;
            }
        }
    }
    for(int i=n;i>=1;i--){
        if(s[i]=='('){
            if(r2[i+1]>=1){
                r2[i]=r2[i+1]-1;
                l2[i]=l2[i+1];
            }
            else{
                r2[i]=r2[i+1];
                l2[i]=l2[i+1]+1;
            }
        }
        else{
            r2[i]=r2[i+1]+1;
            l2[i]=l2[i+1];
        }
    }
    if(l1[n]==0&&r2[1]==0)now++;
    for(int i=1;i<n;i++){
        if(l1[i]==0&&r2[i+1]==0&&r1[i]==l2[i+1])now++;
    }
    if(now>ans){
        ans=now;
        al=l;ar=r;
    }
}
int main()
{
    scanf("%d",&n);
    scanf("%s",s+1);
    ans=0;al=1;ar=1;
    cal(1,1);
    for(int i=1;i<n;i++){
        for(int j=i+1;j<=n;j++){
            if(s[i]==s[j])continue;
            swap(s[i],s[j]);
            cal(i,j);
            swap(s[i],s[j]);
        }
    }
    printf("%d\n",ans);
    printf("%d %d",al,ar);
}
