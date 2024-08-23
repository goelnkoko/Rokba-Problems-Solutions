#include <bits/stdc++.h>

using namespace std;

int main(){

    int t; 
    cin >> t;

    while(t--){
        int n; 
        cin >> n;

        string s1, s2;
        cin >> s1 >> s2;

        int c = 0;

        for(int i=1; i < s1.size()-1; i++){
            if(s1[i] == '.' && s1[i-1] == 'x' && s1[i+1] == 'x' && s2[i] == '.' && s2[i-1] == '.' && s2[i+1] == '.')
                c++;

            if(s2[i] == '.' && s2[i-1] == 'x' && s2[i+1] == 'x' && s1[i] == '.' && s1[i-1] == '.' && s1[i+1] == '.')
                c++;
        }

        cout << c << endl;
    }
}