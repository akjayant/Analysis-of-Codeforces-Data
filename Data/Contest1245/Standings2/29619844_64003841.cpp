#include<bits/stdc++.h>
using namespace std;
int main(){
    int t;
    scanf("%d",&t);
    while(t--){
        int n;
        scanf("%d",&n);
        int r,p,s;
        scanf("%d%d%d",&r,&p,&s);
        string b;
        string res;
        cin>>b;
        int hail=0;
        for(char c:b){
            if(c=='R'){
                if(p)hail++,p--,res.push_back('P');
                else res.push_back(' ');
            }
            else if(c=='P'){
                if(s)hail++,s--,res.push_back('S');
                else res.push_back(' ');
            }
            else if(c=='S'){
                if(r)hail++,r--,res.push_back('R');
                else res.push_back(' ');
            }
        }
        for(int i=0;i<n;i++)if(res[i]==' '){
            if(r)res[i]='R',r--;
            else if(p)res[i]='P',p--;
            else res[i]='S',s--;
        }
        if(hail*2>=n)printf("Yes\n%s\n",res.c_str());
        else printf("No\n");
    }
}