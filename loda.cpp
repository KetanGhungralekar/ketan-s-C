#include <bits/stdc++.h>
using namespace std;
int main(){
    int t;
    cin>>t;
    while(t--){
        int x,y,n;
        cin>>x>>y>>n;
        vector <int> v(n);
        v[n-1] = y;
        v[0] = x;
        for (int i=n-2;i>=0;i--){
            v[i] = v[i+1]-(n-i-1);
        }
        if (v[0] < x){
            cout<<-1<<endl;
        }
        else{
            v[0] = x;
            for (int i=0;i<n;i++){
                cout<<v[i]<<" ";
            }
            cout<<endl;
        }
    }
}