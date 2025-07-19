#include "iostream"
using namespace std;
int pre[100010]={};
int main(){
    ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
    string s1,s2;
    cin>>s1>>s2;
    for(int i=0;i<s1.size();i++){
        pre[i+1]=pre[i];
        if(s1[i]==s2[i]){
            pre[i+1]+=1;
        }
    }
    int q,l,r;
    cin>>q;
    while(q--){
        cin>>l>>r;
        if(pre[r]-pre[l-1]==r-l+1){
            cout<<"Really?!\n";
        }
        else{
            cout<<"I am so weak.\n";
        }
    }
}