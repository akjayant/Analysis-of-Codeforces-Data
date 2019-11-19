#include<bits/stdc++.h>

using namespace std;
const int N = 2000;
int par[N];
int find(int x){
    return x==par[x]?x:par[x]=find(par[x]);
}
void unite(int x,int y){
    x=find(x);y=find(y);
    if(x==y) return ;
    par[x]=y;
}
int main(){
    long long n;
    scanf("%lld",&n);
    long long ss=0;
    long long res;
    for(long long i=2;i*i<=n;i++){
        if(n%i==0){
            ss++;
            res=i;
            while(n%i==0){
                n/=i;
            }
        }
    }
    if(n!=1){
        ss++;
        res=n;
    }
    if(ss==1){
        cout<<res<<endl;
    }else{
        cout<<1<<endl;
    }
    return 0;
}