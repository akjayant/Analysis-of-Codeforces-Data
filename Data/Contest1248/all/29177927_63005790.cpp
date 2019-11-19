#include <bits/stdc++.h>
using namespace std;

pair<int,int> findMaxLen(string s)
{
    if (s.size() <= 1) return make_pair(0,0);

    //Initialize curMax to zero
    pair<int,int> curMax = make_pair(0,0);

    vector<int> longest(s.size(), 0);

    //Iterate over the string starting from second index
    for (int i = 1; i < s.size(); i++) {
        if (s[i] == ')' && i - longest[i - 1] - 1 >= 0 &&
            s[i - longest[i - 1] - 1] == '(') {
                longest[i] = longest[i - 1] + 2 +
                ((i - longest[i - 1] - 2 >= 0)
                ? longest[i - longest[i - 1] - 2] : 0);
                    curMax = max(make_pair(longest[i],-(i-longest[i]+1)), curMax);
        }
    }
    //cout<<s<<" "<<curMax.first<<" "<<curMax.second<<endl;
    return curMax;
}

int bruteforce(string s) {
    int best = 0;
    for(int c=0;c<s.size();c++) {
        for(int c2=0;c2<s.size();c2++) {
            string stmp = s;
            int res = 0;
            if(c!=c2) swap(stmp[c],stmp[c2]);
            for(int c3=0;c3<stmp.size();c3++) {
                int equilibre = 0;
                for(int c4=0;c4<stmp.size();c4++) {
                    if(stmp[c4]=='(') equilibre++;
                    else equilibre--;
                    if(equilibre<0) break;
                }
                if(equilibre==0) {
                    res++;
                }
                stmp = stmp.substr(1)+stmp[0];
            }
            if(res > best) {
                cout<<c<<" "<<c2<<endl;
            }
            best = max(best, res);
        }
    }
    return best;
}

string randomGeneration(int n) {
    string res;
    res.resize(n);
    int equilibre1 = 0;
    int equilibre2 = 0;
    for(int c=0;c<res.size();c++) {
        if(equilibre1*2 >= n) {
            res[c] = ')';
            continue;
        } else if(equilibre2*2 >= n){
            res[c]='(';
            continue;
        }
        res[c]=rand()%2==0?'(':')';
        if(res[c]=='(') equilibre1++;
        else equilibre2++;
    }
    return res;
}


int main(){
    ios_base::sync_with_stdio(false);
    int n;
    cin>>n;
    string s;
    cin>>s;

    pair<int,pair<int,int> > res=make_pair(0,make_pair(0,0));

    for(int c=0;c<s.size();c++){
           for(int c2=c;c2<s.size();c2++) {
            if(c!=c2)swap(s[c],s[c2]);



            pair<int,int> p =findMaxLen(s+s);
            int gauche = (-p.second)%s.size();
            //cout<<p.first<<" "<<(-p.second)<<endl;
            int groups = 0;
            int equilibre = 0;
            for(int c3=0;c3<s.size();c3++) {
                if(s[(c3+gauche+s.size())%s.size()] == '(') equilibre++;
                else equilibre--;
                if(equilibre < 0) break;
                if(equilibre==0) groups++;
            }
            if(equilibre==0){
                res = max(res, make_pair(groups,make_pair(c,c2)));
                /*cout<<"ok tier"<<endl;
                for(int c3=0;c3<s.size();c3++) {
                    cout<<s[(c3+gauche+s.size())%s.size()];
                }
                                cout<<endl;
                */
            }
            if(c!=c2) swap(s[c],s[c2]);
        }
    }
    cout<<res.first<<endl<<res.second.first+1<<" "<<res.second.second+1;
}
