#include<bits/stdc++.h>
using namespace std;
using ll=long long;
char s[11111],t[11111];
int main(){
	int T;scanf("%d",&T);
    while(T--){
        int n;scanf("%d",&n);
        string a="",b="";
        scanf("%s",s);scanf("%s",t);
        for (int i=0;i<n;i++)
            if (s[i]!=t[i])a+=s[i],b+=t[i];
        if (a.size()!=2||b.size()!=2){puts("No");continue;}
        swap(a[0],b[1]);
        if (a==b)puts("Yes");
        else puts("No");
    }
}
