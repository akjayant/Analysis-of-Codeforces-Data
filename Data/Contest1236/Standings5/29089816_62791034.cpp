// by : 信冯哥
#include<bits/stdc++.h>
using namespace std;
const int maxn = (int)1e5+5;
const int mod = (int)1e9+7;

typedef long double dl;
typedef long long ll;
//#define int ll

#define orz cout<<endl
#define debug cout<<"-------------------"<<endl
#define input freopen("in.txt","r",stdin)
#define output freopen("out.txt","w",stdout)
#define sync ios::sync_with_stdio(false)

int n,m,k,l,s,t,r,ans,T;
int a[maxn];

ll mod_exp(ll a, ll b, ll c)        //快速幂取余a^b%c
{
    ll res, t;
    res = 1 % c;
    t = a % c;
    while (b)
    {
        if (b & 1)//b的二进制和1的二进制进行位的按位与运算，其实等价于if(b%2==1)起到判断奇偶的功能，但计算机的位运算比较快。
        {
            res = res * t % c;
        }
        t = t * t % c;
        b >>= 1;//即b=b>>1 b的二进制数右移一位赋值给b，右移时高位空缺补零。类比十进制数100右移相当于100/10=10;b>>1 等价于b/2;但计算机的位运算比较快。
    }
    return res;
}


int main()
{
    cin>>n>>m;
    ll tmp=mod_exp(2,m,mod);
    cout<<mod_exp((tmp-1+mod)%mod,n,mod)<<endl;

    return 0;
}

