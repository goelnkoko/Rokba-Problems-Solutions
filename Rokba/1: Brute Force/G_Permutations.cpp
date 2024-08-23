#include <bits/stdc++.h>
#define Nkumbo ios_base::sync_with_stdio(false), cin.tie(nullptr), cout.tie(nullptr);

using namespace std;

vector<string> res;

void perm(int n, string s){

    if(s.size() == n) {
        res.push_back(s);
        return;
    }

    for(int j=0; j < n; j++){
        if(s.find(to_string(j)) == -1){
            perm(n, s + to_string(j));
        }
    }
}

int main(){

    Nkumbo

    int n, k;
    cin >> n >> k;

    perm(k, "");

    vector<string> a(n);

    for(int i=0; i < n; i++){
        cin >> a[i];
    }

    string r;
    int ans = INT_MAX;
    for(string s: res){
        
        int m = INT_MAX, M = 0;

        for(int i=0; i < n; i++){
            r = "";
            for(int j=0; j < k; j++){
                r += (a[i][s[j] - '0']);
            }
            int p = stoi(r);
            m = min(m, p);
            M = max(M, p);
        }

        ans = min(ans, M-m);
    }

    cout << ans << endl;
}