#include <bits/stdc++.h>

#define Nkumbo ios_base::sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL);
#define compareBySecond [](const pair<int, int>& a, const pair<int, int>& b) { return a.second < b.second; }
#define MAX 1e9
#define MOD 100000000
#define ll long long

using namespace std;

int main() {

    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);

    Nkumbo

    int n, k;
    cin >> n >> k;

    vector<int> a(n);

    set<pair<int, int>> lf, rh; 

    for(int i =0; i < n; i++){
        cin >> a[i];
    }

    if(k == 1) {
        for(int i=0; i < n; i++){
            cout << a[i] << " ";
        }
    } else if(k == 2) {
        for(int i=0; i < n-1; i++){
            cout << min(a[i], a[i+1]) << " ";
        }
    } else {

        for(int i = 0; i < k; i++){
            lf.insert({a[i], i});
        }

        auto it = --lf.end();

        for(int i = 0; i < k/2; i++){
            rh.insert(*it);
            auto temp = it;
            --it;
            lf.erase(temp);
        }

        int mid = (--lf.end())->first;
        cout << mid << " ";

        for(int i=k; i < n; i++){

            auto it2 = lf.find({a[i-k], i-k});
            if(it2 != lf.end()){
                lf.erase(it2);
            } else {
                rh.erase(rh.find({a[i-k], i-k}));
            }

            if(a[i] < mid) {
                lf.insert({a[i], i});
            } else {
                rh.insert({a[i], i});
            }

            if(rh.size() > lf.size()) {
                auto it = *(rh.begin());
                lf.insert(it);
                rh.erase(it);
            } else if(lf.size() > rh.size()+1){
                auto it = *(--lf.end());
                rh.insert(it);
                lf.erase(it);
            }

            int mid = (--lf.end())->first;
            cout << mid << " ";
        }
    }

    cout << endl;


    return 0;
}