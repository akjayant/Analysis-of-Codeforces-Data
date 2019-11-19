#include<bits/stdc++.h>
#define ll long long
#define zp push_back
#define zm make_pair
#define zl lower_bound
#define z1 first
#define z2 second
using namespace std;
int z(){int z;scanf("%d",&z);return z;}
ll Z(){ll Z;scanf("%I64d",&Z);return Z;}

const int M = 5e5+5;
int  n, m;
int sta[M], top;
int a, b,c,d,k;

int main(){
    int t;t=z();
    while(t --){
        cin>>a>>b>>c>>d>>k;
        int x = (a+c-1)/c;
        int y = (b+d-1)/d;
        if(x+y > k)cout<<-1<<endl;
        else cout<< x << ' '<< y <<endl;
    }
}
