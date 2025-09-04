#include<bits/stdc++.h>
using namespace std;
const int d=1e9;
/*int fast(int a,int b)
{
    if(b==0)    return 1;
    int c=fast(a,b/2)%d;
    if(b%2==1)  return c*c%d*a%d;
    return c*c%d;
}
int main()
{
    int a,b;
    cin>>a>>b;
    cout<<fast(a,b);
}*/
struct cat
{
    string name;
    int age,job;
};

bool cmp(cat a,cat b)//1職業 2歲數
{//appentice
    if(a.job==b.job&&a.job==4&&a.age==b.age)    return a.name<b.name;
    else if(a.job==b.job&&a.job==4)     return a.age<b.age;
    else if(a.job==b.job&&a.age!=b.age)   return a.age>b.age;
    else if(a.job==b.job&&a.age==b.age)     return a.name<b.name;
    else    return a.job<b.job;
}
const string nam[8]={"elder","nursy","kit","warrior","appentice","medicent","deputy","leader"};

int main()
{
    cat c[10005]={};
    int n,m;
    string j;
    cin >> n >> m;
    for(int i=0;i<n;i++)
    {
        cin>>c[i].name>>j>>c[i].age;
        for(int k=0;k<8;k++)
        {
            if(j==nam[k])
            {
                c[i].job=k;
                break;
            }
        }
    }
    sort(c,c+n,cmp);
    for(int i=0;i<m;i++)
    {
        cout<<c[i].name<<"\n";
    }
}