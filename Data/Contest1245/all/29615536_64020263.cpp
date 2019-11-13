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
const int M=1000000007;
ll f[100005]={1,1,2,3},n,ans=1,a[100005],top;
string s;
int main(){
    cin>>s;
    n=s.size();
	for(int i=4;i<=100000;i++)f[i]=(f[i-1]+f[i-2])%M;
    int i=0;
	while(i<=n-2){
		int id=i+1;
		if(s[i]=='w'||s[i]=='m'){
            puts("0");
            return 0;
        }
		while(s[i]==s[id]&&(s[id]=='u'||s[id]=='n'))id++;
		a[++top]=id-i;
		i=id;
	}
	if(s[n-1]=='w'||s[n-1]=='m'){
        puts("0");
        return 0;
    }
	for(int i=1;i<=top;++i)ans=ans*f[a[i]]%M;
	cout<<ans<<endl;
	return 0;
}
