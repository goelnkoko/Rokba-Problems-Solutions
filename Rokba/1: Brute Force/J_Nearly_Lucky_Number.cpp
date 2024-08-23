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

    string s;
    cin >> s;

    int c =0;
    for(int i=0; i < s.size(); i++){
        if(s[i] == '4' || s[i] == '7'){
            c++;
        }
    }

    auto islucky = [](int a) -> bool {
        while(a > 0){
            if(!(a%10 == 7 || a%10 == 4)){
                return false;
            }
            a/=10;
        }
        return true;
    };

    bool res;
    if(c > 0) res = islucky(c);
    else res = false;


    cout << (res? "YES":"NO") << endl;
}