#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int maxn=105;
char s[maxn],s1[maxn];
int main(){
    int n;
    cin>>n;
    scanf("%s",s+1);
    int s1=0,s2=0;
    for(int i=1;i<=n;i++){
        if(s[i]=='(')s1++;
        else s2++;
    }
    if(s1!=s2){
        printf("0\n1 1\n");
        return 0;
    }
    int ans=0,pi,pj;

    int p=1,ss=0,maxs=0;
    for(int l=n;l>=1;l--){
        if(s[l]=='(') ss++;
        else ss--;
        if(ss>maxs){
            p=l;
            maxs=ss;
        }
    }
    int temp=0,cnt=0;
    for(int l=p;l<=n;l++){
        if(s[l]=='(')
            temp++;
        else temp--;
        if(temp==0)cnt++;
    }
    for(int l=1;l<=p-1;l++){
        if(s[l]=='(')
            temp++;
        else temp--;
        if(temp==0)cnt++;
    }
    if(cnt>ans){
        pi=1;pj=1;
        ans=cnt;
    }
    for(int i=1;i<=n;i++){
        for(int j=i+1;j<=n;j++){
            swap(s[i],s[j]);
                int p=1,ss=0,maxs=0;
                for(int l=n;l>=1;l--){
                    if(s[l]=='(') ss++;
                    else ss--;
                    if(ss>maxs){
                        p=l;
                        maxs=ss;
                    }
                }
                int temp=0,cnt=0;
                for(int l=p;l<=n;l++){
                    if(s[l]=='(')
                        temp++;
                    else temp--;
                    if(temp==0)cnt++;
                }
                for(int l=1;l<=p-1;l++){
                    if(s[l]=='(')
                        temp++;
                    else temp--;
                    if(temp==0)cnt++;
                }
//                printf("%d %d:p=%d cnt=%d\n",i,j,p,cnt);
                if(cnt>ans){
                    pi=i;pj=j;
                    ans=cnt;
                }
            swap(s[i],s[j]);
        }
    }
    printf("%d\n%d %d\n",ans,pi,pj);
}





