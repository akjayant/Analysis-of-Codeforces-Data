#include <bits/stdc++.h>
#define mk make_pair
#define fs first
#define sc second
using namespace std;
typedef long long ll;
typedef long double ld;
int l[200010];
vector <pair<int, int> > v;
char s[200010];
int main(){
    int n, k;
    while(cin>>n>>k){
        ll ans=0;
        scanf("%s",s);
        int p1, p2;
        bool full = 1;
        for(int i=0; i+1<n; ++i){
            if(s[i]!=s[i+1]){
                full=0;
            }
        }
        if(full){
            printf("%s\n",s);
            continue;
        }
        for(int i=0; i<n; ++i){
            if(l[i])
                continue;
            p1=i;
            while(1){
                if(s[p1]==s[(p1+1)%n] && (p1+1)%n!=i){
                    p1=(p1+1)%n;
                }
                else{
                    break;
                }
            }
            p2=i;
            while(1){
                if(s[p2]==s[(p2-1+n)%n] && (p2+n-1)%n!=i){
                    p2=(p2-1+n)%n;
                }
                else{
                    break;
                }
            }
            if(p1<p2 || p1-p2+1>=2){
                v.push_back(mk(p2, p1));
                for(int j=p2; j!=p1; j=(j+1)%n){
                    l[j]=1;
                }
                l[p1]=1;
            }
        }
        bool b=1;
        int tmp1, tmp2;
        for(int j=0; j<k && b; ++j){
            b=0;
            for(int i=0; i<v.size(); ++i){
                tmp1=(v[i].fs-1+n)%n;
                tmp2=(v[i].sc+1)%n;
                if(!l[tmp1]){
                    l[tmp1]=1;
                    s[tmp1]=s[v[i].fs];
                    b=1;
                    v[i].fs=tmp1;
                }
                if(!l[tmp2]){
                    l[tmp2]=1;
                    s[tmp2]=s[v[i].fs];
                    b=1;
                    v[i].sc=tmp2;
                }
            }
        }
        for(int i=0; i<n; ++i){
            if(l[i]){
                printf("%c",s[i]);
            }
            else{
                if(k%2){
                    if(s[i]=='W'){
                        printf("B");
                    }
                    else{
                        printf("W");
                    }
                }
                else{
                    printf("%c",s[i]);
                }
            }
        }
    }
  return 0;
}


