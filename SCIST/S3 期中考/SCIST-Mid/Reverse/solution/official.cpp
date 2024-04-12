#include "iostream"
using namespace std;
string s;
int ary[2000]={},ed=0;
void push(int num){
	ary[ed++]=num;
	return ;
}
void reverse(int beg,int end){
	for(int i=beg,j=end;i<j;i++,j--){
		swap(ary[i],ary[j]);
	}
	return ;
}
int recur(int pos,int bg,int inl){ //return endpoint
	int i;
	for(i=pos;i<s.size();i++){
		if(s[i]=='['){
			i=recur(i+2,ed,1);
		}
		else if(s[i]==']'){
			i++;
			break;
		}
		else{
			int ret=0;
			while (s[i]==' '){
				i++;
			}
			
			while(i<s.size()&&s[i]!=' '){
				ret*=10;
				ret+=s[i]-'0';
				i++;
			}
			push(ret);
		}
	}
	if(inl)reverse(bg,ed-1);
	return i;
}
int main(){
    int n;
    getline(cin,s);
	getline(cin,s);
	s+=' ';
	recur(0,0,0);
	for(int i=0;i<ed;i++)cout<<ary[i]<<' ';
	cout<<'\n';
}	