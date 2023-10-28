#include <bits/stdc++.h>
using namespace std;
int main(){
    int t;
    cin>>t;
    while(t--){
        int n;
        cin>>n;
        unordered_map <int,int> s;
        for (int i=0;i<n;i++){
            int x;
            cin>>x;
            s[x]++;
        }
        if (s.size() == 2){
            auto it = s.begin();
            int c = it->second;
            it++;
            int d = it->second;
            if (abs(c-d) == 0 || abs(c-d) == 1)
            {
                cout<<"YES"<<endl;
                continue;
            }
            else{
                cout<<"NO"<<endl;
                continue;
            }
        }
        else if(s.size() == 1){
            cout<<"YES"<<endl;
        }
        else{
            cout<<"NO"<<endl;
        }
    }
}