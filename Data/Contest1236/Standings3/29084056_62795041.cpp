#include<map>
#include<cmath>
#include<stack>
#include<queue>
#include<cstdio>
#include<vector>
#include<cstring>
#include<iostream>
#include<algorithm>
using namespace std;
typedef long long ll;
template<class Read>void in(Read &x){
    x=0;
    int f=0;
    char ch=getchar();
    while(ch<'0'||ch>'9'){
        f|=(ch=='-');
        ch=getchar();
    }
    while(ch>='0'&&ch<='9'){
        x=(x<<1)+(x<<3)+(ch^48);
        ch=getchar();
    }
    x=f?-x:x;
    return;
}
int n,a[305][305];
int main(){
	in(n);
    for(int i=1;i<=n;i++){
        int j=(i-1)*n+1;
        int num,k;
        if(i&1)num=1,k=1;
        else num=-1,k=n;
        if(num==1){
            while(k<=n){
                a[k][i]=j;
                j++;
                k++;
            }
        }
        else{
            while(k>=1){
                a[k][i]=j;
                j++;
                k--;
            }
        }
    }
    for(int i=1;i<=n;i++){
        for(int j=1;j<=n;j++){
            printf("%d ",a[i][j]);
        }
        puts("");
    }
	return 0;
}
