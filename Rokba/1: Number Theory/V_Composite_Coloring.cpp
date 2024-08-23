#include <bits/stdc++.h>

#define Nkumbo ios_base::sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL);
#define compareBySecond [](const pair<int, int>& a, const pair<int, int>& b) { return a.second < b.second; }
#define desc greater<int>()
#define all(x) x.begin(), x.end()
#define MAX 1010
#define ll long long
#define vi vector<int> 
#define endl '\n'
#define f first 
#define s second

using namespace std;

vector<int> divs(MAX, 1);
map<int, int> colors;

void divisores(){
    int c = 0;
    for(int i=2; i < MAX; i++){
        if(divs[i] == 1){
            for(int j=i+i; j < MAX; j += i){
                if(divs[j] == 1) divs[j] = i;        
            }   
        }
    }   

    set<int> a;

    for(int i=0; i < 1001; i++)
        if(divs[i] != 1) a.insert(divs[i]);

    int j = 1;
    for(auto i: a){
        colors[i] = j;
        j++;
    }
}

int main() {

    Nkumbo

    divisores();
	
	int t;
    cin >> t;

    while(t--){
        int n;
        cin >> n;

        vector<int> a(n);
        for(auto& i: a) cin >> i;

        vector<int> res;
        for(auto& i: a){
            res.push_back(colors[divs[i]]);
        }

        set<int> b;
        for(auto i: res) b.insert(i);
        
        int j = 1;
        for(auto i: b){
            for(auto& k: res) if(k == i) k = j;
            j++;
        }    


        cout << b.size() << endl;
        for(auto i: res) cout << i << " ";
        cout << endl;
    }

    return 0;
}