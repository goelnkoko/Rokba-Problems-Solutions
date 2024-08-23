#include<bits/stdc++.h>
#define fast ios_base::sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL)
#define endl '\n'

using namespace std;

int main(){
    fast;

    string s;
    cin>>s;
    stack<char> p;

    int c = 0;
    for(int i = 0; i < s.size(); ++i){
        if(s[i] == '(') p.push('(');
        else if (!p.empty()){
            p.pop();
            c++;
        }
    }

    cout << c * 2 << endl;


  return 0;
}