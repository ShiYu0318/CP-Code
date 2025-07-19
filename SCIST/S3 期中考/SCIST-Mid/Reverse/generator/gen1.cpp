#include "testlib.h"
#include "iostream"
using namespace std;
int main(signed argc, char* argv[]){
    registerGen(argc, argv, 1);
 
    int maxsize = rnd.next(1500,1900);
    string res;
    int n=0;
    int mustu=0;
    for(int i=0;i<maxsize;i++){
        int stu = rnd.next(1,5);
        if(stu==1){
            if(mustu){
                mustu--;
                res += "] ";
                n++;
            }
            else{
                mustu++;
                res += "[ ";
                i++;
                n++;
            }
        }
        else{
            int now = rnd.next(1,1000);
            res += to_string(now);
            res+=' ';
            n++;
        }
    }
    while(mustu--){
        res += "] ";
        n++;
    }
	if(rnd.next(1,3)==1){
		res+= "123 ";
	    n++;
	}
    res.pop_back();
    cout<<n<<endl<<res<<endl;
    return 0;
}
