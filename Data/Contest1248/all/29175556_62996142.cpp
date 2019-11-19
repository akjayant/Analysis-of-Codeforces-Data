#include <iostream>
#include <vector>
#include <map>
using namespace std;
int beauty(string s){
    int len, l = 0;
    vector<int> p;
    len = s.length();
    p.assign(600, 0);
    for(int i=0;i<len;i++){
        if(s[i] == '('){
            l++;
        }else{
            l--;
        }
        p[l+300]++;
    }
    for(int i=0;i<600;i++){
        if(p[i] > 0)return p[i];
    }
    return 0;
}
int main(void){
    int n;
    string s;
    vector<int> lft, rit;
    cin >> n >> s;
    for(int i=0;i<n;i++){
        if(s[i] == '(')lft.push_back(i);
        else rit.push_back(i);
    }
    if(lft.size() != rit.size()){
        puts("0");
        puts("1 1");
        return 0;
    }
    int ans = 0, ai = 0, aj = 0;
    ans = beauty(s);
    for(int i=0;i<n/2;i++){
        for(int j=0;j<n/2;j++){
            string t = s;
            t[lft[i]] = s[rit[j]];
            t[rit[j]] = s[lft[i]];
            int res = beauty(t);
            if(res > ans){
                ans = res;
                ai = lft[i];
                aj = rit[j];
            }
        }
    }
    cout << ans << endl;
    cout << ai+1 << " " << aj+1 << endl;
    return 0;
}
