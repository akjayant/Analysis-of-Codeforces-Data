#include <bits/stdc++.h>
using namespace std;
const int N=1e5;
int a[N],n;
bool ok(char c1,char c2,char c3,char c4){
    if((c1==c2)&&(c3==c4)){
        return true;
    }
    return false;
}
int main()
{
    int te;
    scanf("%d",&te);
    for(int tst=1;tst<=te;tst++){
        int n;
        scanf("%d",&n);
        string s,t;
        cin>>s>>t;
        if(s==t){
            printf("Yes\n");
            continue;
        }
        bool used=false,used2=false,cant=false;
        char c1,c2,c3,c4;
        for(int i=0;i<s.size();i++){
            if(s[i]!=t[i]){
                if(!used){
                   c1=s[i];
                   c3=t[i];
                   used=true;
                }
                else if(!used2){
                    c2=s[i];
                    c4=t[i];
                    used2=true;
                    if(!ok(c1,c2,c3,c4)){
                        printf("No\n");
                        cant=true;
                        break;
                    }
                }
                else{
                    printf("No\n");
                    cant=true;
                    break;
                }
            }
        }
        if(!used||!used2){
            printf("No\n");
        }
        else if(!cant){
            printf("Yes\n");
        }
    }
    return 0;
}
