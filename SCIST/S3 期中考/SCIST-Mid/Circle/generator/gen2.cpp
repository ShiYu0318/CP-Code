#include "testlib.h"
#include <iostream>
using namespace std;
int main(int argc, char* argv[]){
    registerGen(argc, argv, 1);
    long long int n =rnd.next(9800,10000);
    long long int k=rnd.next((long long)909000000,(long long)1000000000);
    k-=n%k;
    k+=n-1;
    cout<<n<<' '<<k<<endl;
    for(int i=0;i<n;i++){
        cout<<rnd.next((long long)4930,(long long)5000);
        if(i!=n-1)cout<<" ";
    }
    cout<<endl;
    return 0;
}
