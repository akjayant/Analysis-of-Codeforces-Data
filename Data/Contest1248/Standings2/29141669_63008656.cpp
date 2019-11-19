/*#include <bits/stdc++.h>
using namespace std;
int check(string s) {
    int a=0;
    for(int i=0;i<s.length();i++) {
        if(s[i]=='(')
            a++;
        else
            a--;
        if(a<0)
            return 0;
    }
    return 1;
}


int valid_rot(string a) {
    int n = a.length();
    int ans = 0;
    int cnt=0;
    for(int i=0;i<n;i++) {
        if(a[i]=='(')
            cnt++;
        else
            cnt--;
        if(cnt<0)
            return 0;
        if(cnt==0)
            ans++;
    }
    return ans;
}


pair<int,pair<int,int>> func(string s, vector<int> &op, vector<int> &cl) {
    int mx = valid_rot(s);
    int r1 = 0;
    int r2 = 0;
    for(int i=0;i<op.size();i++) {
        for(int j=0;j<cl.size();j++) {
            s[op[i]]=')';
            s[cl[j]]='(';
            //cout << op[i] << " " << cl[j] << endl; 
            if(check(s)) {
                int x = valid_rot(s);
                if(x>mx) {
                    mx = x;
                    r1 = op[i];
                    r2 = cl[j];
                }
            }
            s[op[i]]='(';
            s[cl[j]]=')';
        }
    }
    return make_pair(mx, make_pair(r1, r2));
}
int main() {
    int n;
    cin >> n;
    string s;
    cin >> s;
    vector<int> op;
    vector<int> cl;
    for(int i=0;i<n;i++)
        if(s[i]=='(')
            op.push_back(i);
        else
            cl.push_back(i);
    if(op.size()!=cl.size()) {
        cout << 0 << endl;
        cout << 1 << " " << 1 << endl;
        return 0;
    }
    pair<int,pair<int,int>> p1 = func(s, op, cl);
    cout << p1.first << "\n" << p1.second.first +1 << " " << p1.second.second +1 << endl;
    return 0;

}
*/
#include <bits/stdc++.h>
using namespace std;
int valid_rot(string a) {
    int n = a.length();
    //    int ans = 0;
    for(int i=0;i<a.length();i++) {
        int cnt = 0;
        if(a[(n-1+i)%n]=='(' || a[i]==')')
            continue;
        int c = 0;
        for(int j=i;j<(n+i);j++) {
            if(a[j%n]=='(')
                cnt++;
            else
                cnt--;
            if(cnt==0)
                c++;
            if(cnt<0)
                break;
        }
        if(cnt==0) {
            return c;   
        }
    }
    return 0;
}
 
 
pair<int,pair<int,int>> func(string s, vector<int> &op, vector<int> &cl) {
    int mx = valid_rot(s);
    int r1 = 0;
    int r2 = 0;
    for(int i=0;i<op.size();i++) {
        for(int j=0;j<cl.size();j++) {
            s[op[i]]=')';
            s[cl[j]]='(';
            //cout << op[i] << " " << cl[j] << endl; 
            int x = valid_rot(s);
            if(x>mx) {
                mx = x;
                r1 = op[i];
                r2 = cl[j];
            }
            s[op[i]]='(';
            s[cl[j]]=')';
        }
        
    }
    return make_pair(mx, make_pair(r1, r2));
 
}
 
 
int main() {
    int n;
    cin >> n;
    string s;
    cin >> s;
    vector<int> op;
    vector<int> cl;
    for(int i=0;i<n;i++)
        if(s[i]=='(')
            op.push_back(i);
        else
            cl.push_back(i);
    if(op.size()!=cl.size()) {
        cout << 0 << endl;
        cout << 1 << " " << 1 << endl;
        return 0;
    }
    pair<int,pair<int,int>> p1 = func(s, op, cl);
    cout << p1.first << "\n" << p1.second.first +1 << " " << p1.second.second +1 << endl;
    return 0;
 
}
