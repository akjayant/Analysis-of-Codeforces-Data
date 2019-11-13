#include <iostream>
#include <string>
using namespace std;

int rock,paper,sci;

char get_rest(){
    if(rock){
        rock--;
        return 'R';
    }
    if(paper){
        paper--;
        return 'P';
    }
    if(sci){
        sci--;
        return 'S';
    }
    return '?';
}
string inp;
int main(){
    ios::sync_with_stdio(false);
    int kase;cin>>kase;
    while(kase--){
        int n;cin>>n;
        cin>>rock>>paper>>sci;
        cin>>inp;

        int win=0;
        string ans=inp;
        for(int i=0;i<ans.size();i++)ans[i]='.';
        for(int i=0;i<inp.size();i++){
            if(inp[i]=='R' && paper){
                ans[i]='P';
                win++;
                paper--;
            }
            if(inp[i]=='S' && rock){
                ans[i]='R';
                win++;
                rock--;
            }
            if(inp[i]=='P' && sci){
                ans[i]='S';
                win++;
                sci--;
            }
        }
        for(int i=0;i<ans.size();i++){
            if(ans[i]=='.')ans[i]=get_rest();
        }
        if(win>=(n+2-1)/2){
            cout<<"YES\n";
            cout<<ans<<"\n";
        }else {
            cout<<"NO\n";
        }
    }
    return 0;
}