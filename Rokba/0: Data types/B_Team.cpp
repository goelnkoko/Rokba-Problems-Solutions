#include <bits/stdc++.h>

using namespace std;

int main(){

    int n; 
    cin >> n;

    int total = 0; 

    while(n--){
        int c = 0;
        for(int i=0; i < 3; i++){
            int a; cin >> a;
            c += a;
        }

        if(c >= 2) total++;        
    }

    cout << total << endl;
}