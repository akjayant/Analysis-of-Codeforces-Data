#include <bits/stdc++.h>
using namespace std;

int n,k;
char s[200009];
char s2;
bool notwo=1;
char ss[200009];
bool single[200009];
bool edge[200009];
int d[200009];

int main(){
    scanf("%d %d\n",&n,&k);
    scanf("%s",s);
    s2=s[0];
    for(int i=1;i<n;i++){
        if(s[i]==s2){
            notwo=0;
            break;
        }
        s2=s[i];
    }
    if(notwo){
        if(n%2) notwo=0;
    }
    if(notwo&&k%2){
        for(int i=0;i<n;i++){
            if(s[i]=='B') s[i]='W';
            else s[i]='B';
        }
    }
    if(notwo){
        printf("%s",s);
        return 0;
    }
    for(int i=0;i<n;i++){
        ss[i]=s[i];
    }
    s[n]=s[0];
    s[n+1]=ss[1];
    ss[n]=ss[0];
    ss[n+1]=ss[1];
    //cal
    for(int i=1;i<=n;i++){
        int c2=0;
        if(ss[i-1]==ss[i]) c2++;
        if(ss[i+1]==ss[i]) c2++;
        if(c2==0) single[i]=1;
        if(c2==1) edge[i]=1;
    }
    int lastedge=-1;
    for(int i=1;i<=n;i++){
        if(edge[i]) lastedge=i;
        else if(lastedge>0) d[i]=i-lastedge;
    }
    for(int i=1;i<=n;i++){
        if(edge[i]) break;
        else d[i]=i+n-lastedge;
    }
    lastedge=n+10;
    for(int i=n;i>=1;i--){
        if(edge[i]) lastedge=i;
        else if(lastedge<=n) d[i]=min(d[i],lastedge-i);
    }
    for(int i=n;i>=1;i--){
        if(edge[i]) break;
        else d[i]=min(d[i],lastedge+n-i);
    }
    for(int i=1;i<=n;i++){
        if(single[i]){
            int c2=min(d[i],k);
            if(c2%2){
                if(ss[i]=='B') ss[i]='W';
                else ss[i]='B';
            }
        }
    }
    ss[0]=ss[n];
    for(int i=0;i<n;i++){
        printf("%c",ss[i]);
    }
    return 0;
}
