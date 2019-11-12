/*
  user: sky48
  language: c++
  for dream for young
*/
#include<iostream>
#include <cmath>
#include <cstdio>
#include <cstdlib>
#include <algorithm>
#include <cstring>
#define rep(i,a,b) for(int i=a;i<=b;i++)
#define mod 234
typedef long long ll;
using namespace std;
int T,a,b,c,ans;
int gets()
{
	int v=0; char ch;bool f=0;
	while(!isdigit(ch=getchar())) if(ch=='-') f=1; v=ch-48;
	while( isdigit(ch=getchar())) v=(v<<1)+(v<<3)+ch-48;
	return f?-v:v;
}
int main ()
{
//  freopen("tt.txt","r",stdin);
	T=gets();  
	while(T--){
		a=gets(), b=gets(), c=gets();
		ans=min(b,c/2);
		b-=ans;
		ans+=min(a,b/2);
		cout<<3*ans<<endl; 
	}
	return 0;
}
