#include <bits/stdc++.h>

using namespace std;

int main(){

    int t; 
    cin >> t;

    while(t--){
        int n;
        cin >> n;

        string s; 
        cin >> s;

        s[0] = '(';

        for(int i=1; i < n-2; i+=2){
            if(s[i] != s[i+2]){
                s[i+1] = s[i+2];
            } else {
                if(s[i] == '(') s[i+1] = ')';
                else s[i+1] = '(';
            }
        }

        stack<pair<char, int>> br;

        int cost = 0;

        for(int i=0; i < n; i++){
            if(s[i] == '(')
                br.push({s[i], i+1});
            else {
                auto v = br.top();
                cost += ((i+1) - v.second);
                br.pop();
            }
        }

        cout << cost << endl;
    }
}