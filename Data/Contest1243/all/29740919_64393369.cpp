//
//  main.cpp
//  Contests
//
//  Created by Giga Khizanishvili on 6/11/19.
//  Copyright © 2019 Giga Khizanishvili. All rights reserved.
//


// #include <bits/stdc++.h>
#include <algorithm>
#include <cmath>
#include <fstream>
#include <iostream>
#include <map>
#include <string>
#include <vector>
#include <set>
#include <stack>
#include <sstream>
#include <unordered_map>
#include <unordered_set>

using namespace std;

/* Defines */
#define scanVector(v) for(int i = 0; i < v.size() ; i++){ cin>>v[i]; }
#define printVector(v) for(int i = 0; i < (int)v.size() ; i++){ cout<<v[i]<<" "; }
#define printlnVector(v) for(int i = 0; i < v.size(); i++){ cout<<v[i]<<endl; }
#define scanGrid(g) for(int i = 0; i < g.size(); i++){ for(int j = 0; j < g[i].size(); j++){ cin >> g[i][j]; } }
#define printGrid(g) for(int i=0; i<g.size(); i++){for(int j=0; j<g[i].size(); j++)cout<<g[i][j]<<" "; cout<<endl;}

/* Constants */
const int  MOD = 1e9 + 7;
const int  N = 1e5 + 7;
const double PI = 3.141592653589793238462643383;

/* __________________________________________________________________________________ */

int main()
{   ios::sync_with_stdio(0);  cin.tie(0); cout.tie(0);
    
    int nTests; cin >> nTests;
    while(nTests--){
        int n; cin >> n;
        string s1, s2; cin >> s1 >> s2;
        map<char, int> mp;
        
        for(char c : s1)
            mp[c]++;
        
        for(char c : s2)
            mp[c]--;
        
        bool failed = false;
        
        for(pair<char, int> pr : mp){
            if(pr.second % 2 != 0) {
                cout << "No" << endl;
                failed = true;
                break;
            }
        }
        
        if(failed) continue;
        vector< pair<int, int> > result;
        // frequences are equal
        for(int i = 0; i < n-1; i++){
            char toFind = s1[i];
            int indexInS2 = (int)s2.find(toFind, i); // ???
            
            if(indexInS2 != string::npos){
                result.push_back(make_pair(i+1, indexInS2));
                swap(s1[i+1], s2[indexInS2]);
                result.push_back(make_pair(i+1, i));
                swap(s1[i+1], s2[i]);
            } else {
                int nextIndexInS1 = (int)s1.find(toFind, i+1);
                
                result.push_back(make_pair(nextIndexInS1, i));
                swap(s1[nextIndexInS1], s2[i]);
            }
            
            
        }
        
        // print
        cout << "Yes" << endl;
        cout << result.size() << endl;
        for(pair<int, int> pr : result){
            cout << pr.first+1 << " " << pr.second+1 << endl;
        }
        
    }
    
    return 0;
}
