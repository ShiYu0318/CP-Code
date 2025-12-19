#include <bits/stdc++.h>
using namespace std;

int main()
{
    
}












#include <iostream>
#include <vector>
using namespace std;

int main()
{
    int times;
    cin >> times;

    for (int z = 0; z < times; z++)
    {
        int number;
        int temp;
        vector<int> fib_seq = {1, 2};

        cin >> number;
        int subtraction = number;

        if (number == 1)
        {
            cout << "1 = 1 (fib)\n";
        }

        else if (number == 2)
        {
            cout << "2 = 10 (fib)\n";
        }

        else
        {
            int x = 0;
            while (x == 0)
            {
                temp = fib_seq.at(fib_seq.size() - 1) + fib_seq.at(fib_seq.size() - 2);
                if (temp > number)
                {
                    break;
                }
                else
                {
                    fib_seq.push_back(temp);
                }
            }

            string answer = "";
            int times = fib_seq.size();
            for (int i = 0; i < times; i++)
            {
                int temp = fib_seq.at(fib_seq.size() - 1);
                fib_seq.pop_back();
                if (subtraction >= temp)
                {
                    subtraction = subtraction - temp;
                    answer = answer + "1";
                }
                else
                {
                    answer = answer + "0";
                }
            }

            cout << number << " = " << answer << " (fib)\n";
        }
    }
}

















#include <iostream>
#include <vector>
using namespace std;

int steps(int a, int b)
{
    if (a == 0 && b == 0)
    {
        return 1;
    }
    else if (a == 1 && b == 0)
    {
        return 1;
    }
    else if (a - b >= 2)
    {
        return 0;
    }
    else if (a == 0 && b == 1)
    {
        return 1;
    }
    else if (a == 0)
    {
        return steps(a, b - 1) + steps(a, b - 2);
    }
    else if (a == 1 && b == 1)
    {
        return 2;
    }
    else if (a == 2 && b == 1)
    {
        return 1;
    }
    else
    {
        return steps(a, b - 1) + steps(a, b - 2) + steps(a - 1, b - 1) + steps(a - 1, b - 2);
    }
}

int main()
{
    int total = 0;
    int a, b;
    cin >> a >> b;

    total = steps(a, b);
    cout << total;
}









#include <iostream>
#include <vector>
using namespace std;

int main()
{
    int largest = 0;
    int times;
    vector<int> trees = {};

    cin >> times;
    for (int i = 0; i < times; i++)
    {
        int temp;
        cin >> temp;
        trees.push_back(temp);
    }

    int rp, lp;
    lp = 0;
    rp = trees.size() - 1;

    while (lp < rp)
    {
        largest = max(largest, min(trees.at(rp), trees.at(lp)) * (rp - lp));
        if (trees.at(rp) > trees.at(lp))
        {
            lp++;
        }
        else
        {
            rp--;
        }
    }

    cout << largest;
}