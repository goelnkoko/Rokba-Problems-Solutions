#include <bits/stdc++.h>

using namespace std;

int main(){

    int t; 
    cin >> t;

    while(t--){
        string s;
        cin >> s;

        string res; 
        int c = 1;
        for(int i=1; i < s.size(); i++){
            if(s[i] == s[i-1]){
                char mid;
                if(s[i] != 'z') {
                    mid = s[i] + 1;
                } else {
                    mid = 'a';
                }

                string m(1, mid);

                res = s.substr(0, i) + m + s.substr(i, s.size()-i);
                break;
            }
            c++;
        }

        if(c == s.size()) {

            char mid;
            if(s[s.size()-1] != 'z') {
                mid = s[s.size()-1] + 1;
            } else {
                mid = 'a';
            }

            string m(1, mid);

            res = s + mid;
        }

        cout << res << endl;
    }
}