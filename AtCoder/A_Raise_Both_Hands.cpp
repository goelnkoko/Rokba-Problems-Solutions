#include <bits/stdc++.h> 

#define endl '\n'
#define vi vector<int> 
#define f first 
#define s second

using namespace std;

typedef long long ll;
typedef pair<int, int> pii;

int main(){

    int l, r;
    cin >> l >> r;

    if(l && r || !l && !r) cout << "Invalid" << endl;
    else if(l) {
        cout << "Yes" << endl;
    }
    else {
        cout << "No" << endl;
    }
}