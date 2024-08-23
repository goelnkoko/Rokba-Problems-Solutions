#include <bits/stdc++.h>

#define Nkumbo ios_base::sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL);
#define compareBySecond [](const pair<int, int>& a, const pair<int, int>& b) { return a.second < b.second; }
#define desc greater<int>()
#define all(x) x.begin(), x.end()
#define MAX 500
#define ll long long
#define vi vector<int> 
#define endl '\n'
#define f first 
#define s second

using namespace std;


int main() {

    Nkumbo

    int n, k;
    cin >> n >> k;

    vector<int> r(n);
    for(auto& i: r) cin >> i;

    int ini = 0, fim = 0;

    for(int i=0; i < n; i++){
        ini += pow(10, i);
        fim += 5 * pow(10, i);
    }

    vector<string> res;

    for(int i=ini; i <= fim; i++){
        string s = to_string(i);
        bool ans = true;
        int sum = 0;
        for(int j=0; j < n; j++){
            if(!((s[j]-'0') <= r[j] && (s[j]-'0') >= 1)) {ans = false; break;}
            sum += (s[j]-'0');
        }
        if(ans && sum % k == 0)
            res.push_back(s);
    }

    for(auto& a: res){
        for(auto& i: a){
            cout << i << " ";
        }
        cout << endl;
    }

    return 0;
}