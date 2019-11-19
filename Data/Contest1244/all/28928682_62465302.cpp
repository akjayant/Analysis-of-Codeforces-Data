#include<bits/stdc++.h>
using namespace std;
int t;
int main(){
    scanf("%d",&t);
    while(t--){
        int a,b,c,d,k;
        scanf("%d%d%d%d%d",&a,&b,&c,&d,&k);
        int num1=a/c+(a%c?1:0),num2=b/d+(b%d?1:0);
        if(num1+num2>k)cout<<-1<<endl;
        else cout<<num1<<' '<<num2<<endl;
    }
    return 0;
}