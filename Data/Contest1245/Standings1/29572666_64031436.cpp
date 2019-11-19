#include<bits/stdc++.h>
using namespace std;
int a[101];
double f[101][2];
inline int id(int x,int y){
    if(x&1)return 10*(x-1)+y-1;
    return 10*x-y;
}
inline int X(int x){
    return x/10+1;
}
inline int Y(int x){
    if((x/10)&1)return 10-x%10;
    return x%10+1;
}
inline int up(int x,int y){
    return id(X(x)-y,Y(x));
}
int main(){
    for(int i=1;i<=10;++i)
        for(int j=1;j<=10;++j)
            cin>>a[id(i,j)];
    for(int i=1;i<100;++i){
        f[i][0]=6;
        for(int j=max(0,i-6);j<i;++j)
            f[i][0]+=f[j][1];
        f[i][0]/=min(i,6);
        f[i][1]=min(f[i][0],f[up(i,a[i])][0]);
    }
    printf("%.10lf",f[99][1]);
}