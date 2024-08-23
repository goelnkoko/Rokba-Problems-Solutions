#include <bits/stdc++.h>
#define Nkumbo ios_base::sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL);
#define f first
#define s second
#define endl '\n'
#define ll long long

using namespace std;

int lucky(int x) {

    string s = to_string(x);
    string y = "";

    for(int i=0; i < s.size(); i++){
        if(s[i] == '4' || s[i] == '7') y += s[i];
    }
    
    if(y.empty()) return 0;
    else return stoi(y);
}

int main(){

    Nkumbo

    int a, b; 
    cin >> a >> b;

    int c = a;

    while(true){
        c++;
        if(lucky(c) == b) break;
    }

    cout << c << endl;
}