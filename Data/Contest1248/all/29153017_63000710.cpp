#include <bits/stdc++.h>
#define FOR(i,a,b) for(int i=a;i<=b;++i)
using namespace std;
const int _=520;
int n,res,ans=-1,id[2];
char S[_], tmp[_];
int main() {
    scanf("%d%s",&n,S+1);    
    FOR(i,1,n) FOR(j,i,n) {
        FOR(t,1,n) tmp[t] = S[t];
        swap(tmp[i], tmp[j]);
        int poi=1,lim=n,top=0;
        FOR(nb,1,0);
        while(poi<=lim){
            if(tmp[poi] == ')'){
                if(top > 0)--top;
                else {
                    --top,res=0;
                    while(poi<=lim&&top<0){
                        if(tmp[lim]==')')--top;
                        else ++top;
                        --lim;
                    }
                }
            } else ++top;
            ++poi;
            if(top==0) ++res;
        }
        if(top) res=0;
        if(res>ans) id[0]=i,id[1]=j,ans=res;
        res=0;
    }
     printf("%d\n%d %d\n",ans,id[0],id[1]);
    return 0;
}