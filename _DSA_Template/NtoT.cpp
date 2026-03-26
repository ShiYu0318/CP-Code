int NtoT(string s,int radix)
{
    int ans=0;
    for(int i=0;i<s.size();i++)
    {
        char t = s[i];
        if(t >= '0' && t <= '9') ans = ans * radix + t - '0';
        else ans = ans * radix + t - 'a' + 10;
    }
    return ans;
}

// int num = 10;  
// char str[100];  
// iota(num, str, 2);

