#include <bits/stdc++.h> 

#define endl '\n'
#define all(x) x.begin(), x.end()
#define ff first
#define ss second

using namespace std;

typedef long long ll;
typedef pair<int, int> pii;

const ll MOD = 1e9+7;
const int MAX = 1001;

vector<int> color(MAX, MAX);

void crive(){
    for(int i=2; i * i <= MAX; i++){
        if(color[i] == MAX)
            for(int j=i; j < MAX; j+=i)
                color[j] = min(color[j], i);
    }
}

int main(){

    crive();

    int t; cin >> t;

    while(t--){
        int n; cin >> n;
        int tb[n]; 
        map<int, int> num;
        for(auto& i: tb) {
            cin >> i;
            i = color[i];
            num[i] = 0;
        }   

        int c = 1;
        for(auto& i: num) i.ss = c++; 

        cout << num.size() << endl;
        for(int i=0; i < n; i++)
            cout << num[tb[i]] << ' '; cout << endl;
    }
}

