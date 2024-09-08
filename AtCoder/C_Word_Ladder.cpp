#include <bits/stdc++.h> 

#define endl '\n'
#define vi vector<int> 
#define f first 
#define s second

using namespace std;

typedef long long ll;
typedef pair<int, int> pii;

int main(){

    string s, t;
    cin >> s >> t;

    int n = s.size();

    vector<string> x;

    vector<int> order;

    for(int i=0; i < n; i++){

        if(s[i] > t[i]){    
            s[i] = t[i];
            x.push_back(s);
        }
        if(s[i] != t[i]){
            order.push_back(i);
        }
    }

    for(int i = order.size()-1; i >= 0; i--){
        s[order[i]] = t[order[i]];
        x.push_back(s);
    }

    cout << x.size() << endl;
    for(auto i: x){
        cout << i << endl;
    }
}