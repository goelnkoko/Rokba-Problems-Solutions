#include <bits/stdc++.h>

#define Nkumbo ios_base::sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL);
#define compareBySecond [](const pair<int, int>& a, const pair<int, int>& b) { return a.second < b.second; }
#define MAX 1e9
#define MOD 1000000007
#define ll long long

using namespace std;

vector<string> res; 

void perm (string s) {

    sort(s.begin(), s.end());

    do {
        res.push_back(s);
    } while(next_permutation(s.begin(), s.end()));
}

int main() {

    Nkumbo

    ll n, k;
    string s; 

    cin >> n >> k >> s;

    perm(s);

    int npal = res.size();

    for(int i =0; i < res.size(); i++){
        bool pal = false;

        for(int j=0; j < n-k+1; j++){
            bool non = false;
            for(int l =j; l < j+k/2; l++){
                if(res[i][l] != res[i][2*j+k-1-l]) {non = true; break;}
            }
            if(!non) {pal = true; break;}
        }
        if(pal) npal--;
    }

    cout << npal << endl;

    return 0;
}
