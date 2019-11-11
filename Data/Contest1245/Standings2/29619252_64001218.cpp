#include <bits/stdc++.h>
#define ll long long
using namespace std;
const int N=2e5+5;
int main()
{
    int t;
    scanf("%d",&t);
    for(int br=1;br<=t;br++){
        int n,a,b,c,wins=0;
        scanf("%d",&n);
        scanf("%d%d%d",&a,&b,&c);
        string s,s2="";
        cin>>s;
        for(int i=0;i<s.size();i++){
            if(s[i]=='R'){
                if(b>0){
                    s2+='P';
                    b--;
                    wins++;
                }
                else{
                    s2+='N';
                }
            }
            if(s[i]=='P'){
                if(c>0){
                    s2+='S';
                    c--;
                    wins++;
                }
                else{
                    s2+='N';
                }
            }
            if(s[i]=='S'){
                if(a>0){
                    s2+='R';
                    a--;
                    wins++;
                }
                else{
                    s2+='N';
                }
            }
        }
        if(2*wins>=n){
            printf("YES\n");
            for(int i=0;i<s.size();i++){
                if(s2[i]=='N'){
                    if(a>0){
                        s2[i]='R';
                        a--;
                    }
                    else if(b>0){
                        s2[i]='P';
                        b--;
                    }
                    else{
                        s2[i]='S';
                        c--;
                    }
                }
            }
            cout<<s2<<endl;
        }
        else{
            printf("NO\n");
        }

    }
    return 0;
}
