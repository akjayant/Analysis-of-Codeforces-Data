#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N = 1e5+10;
const double esp = 1e-6 ;

string a ,b ;
vector<int>q;
int main()
{
    int t ;
    cin >> t ;
    while(t--)
    {
        q.clear();
        int n ;
        cin >> n ;
        cin >> a>>b;
        for(int i = 0 ; i < a.size() ; i++)
        {
            if(a[i]!=b[i])
            {
                q.push_back(a[i]-'a');
                q.push_back(b[i]-'a');
            }
        }
        if(q.size()==0)
        {
            cout << "Yes"<<endl;
            continue;
        }
        if(q.size()!=4)
        {
            cout << "No" <<endl;
        }
        else
        {
           // cout << "Dsa" <<endl;
            //sort(q.begin() , q.end());
            if(q[0]==q[2]&&q[1]==q[3])
            {
                cout << "Yes" <<endl;
            }
            else
                cout << "No" <<endl;
        }
    }
}

/*
4
5
souhe
house
3
cat
dog
2
aa
az
3
abc
bca
*/
