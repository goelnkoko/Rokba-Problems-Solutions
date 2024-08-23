#include <bits/stdc++.h>
#define Nkumbo ios_base::sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL);
#define f first
#define s second
#define endl '\n'
#define ll long long
#define all(x) x.begin(), x.end()
#define compareBySecond [](const pair<int, int>& a, const pair<int, int>& b) { return a.second < b.second; }

using namespace std;

bool cbs(const pair<char, int>& a, const pair<char, int>& b){
    return a.second > b.second;
}

int main(){

    Nkumbo

    int n; 
    cin >> n;

    vector<string> a(n);
    for(int i=0; i < n; i++){
        cin >> a[i];
    }

    set<char> z;
    map<char, int> p; 

    for(string s: a){
        z.insert(s[0]);
        for(int j=0; j < s.size(); j++){
            p[s[j]] += pow(10, s.size() - (j+1));
        }
    }    

    vector<pair<char, int>> p2(all(p));
    sort(all(p2), cbs);

    int val = 1;
    map<char, int> v;

    bool zero = true;
    for(auto i: p2){
        if(z.find(i.f) == z.end() && zero){
            v[i.f] = 0;
            zero = false;
        } else {
            v[i.f] = val;
            val++;
        }
    }

    int total = 0;
    for(auto s: a){
        string res = "";
        for(int j=0; j < s.size(); j++){
            res.append(to_string(v[s[j]]));
        }
        total += stoi(res);
    }

    cout << total << endl;

}