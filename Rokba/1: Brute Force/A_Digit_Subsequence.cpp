#include <bits/stdc++.h>
#define Nkumbo ios_base::sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL);
#define f first
#define s second
#define endl '\n'
#define ll long long

using namespace std;

void solve() {
    
}

int main(){

    Nkumbo

    string s; 
    cin >> s; 
    
    int i=0; 
    while(s.find(to_string(i)) != string::npos){
        i++;
    }

    cout << i << endl;
}