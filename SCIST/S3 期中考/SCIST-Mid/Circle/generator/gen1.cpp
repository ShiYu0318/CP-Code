#include "testlib.h"
#include <iostream>
using namespace std;
int main(int argc, char* argv[]){
    registerGen(argc, argv, 1);
    int n =rnd.next(900,1000);
    int k=rnd.next(1,10000);
    cout<<n<<' '<<k<<endl;
    for(int i=0;i<n;i++){
        cout<<rnd.next((long long)1,(long long)5000);
        if(i!=n-1)cout<<' ';
    }
    cout<<endl;
    return 0;
}