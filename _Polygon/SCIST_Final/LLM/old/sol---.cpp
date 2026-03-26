#include<bits/stdc++.h>
using namespace std;

const vector<string> model = {"GPT-3.5-Turbo", "GPT-4", "GPT-4-Turbo", "GPT-4.1", "GPT-4.1-Mini", "GPT-4.1-Nano", "GPT-4o", "GPT-4o-Mini", "o3", "o3-mini", "o3-Pro", "Claude-1", "Claude-2", "Claude-3", "Claude-3.5", "Claude-4", 
                "Gemini-2", "Gemini-2.5", "Gemini-2.5-Pro", "Gemini-2.5-Pro-Deep-Think", "LLaMA-4-Scout", "LLaMA-4-Maverick", "Perplexity-Sonar", "Grok-2", "Grok-3", "Grok-3-Mini", "Grok-4", "DeepSeek-R1", "DeepSeek-R2", "DeepSeek-V3"};
const vector<double> input = {0.50, 30.00, 10.00, 2.00, 0.40, 0.10, 2.50, 0.15, 10.00, 1.10, 20.00, 0.25, 0.25, 3.00, 3.00, 15.00, 1.25, 1.25, 1.25, 1.25, 0.18, 0.27, 1.00, 5.00, 3.00, 0.30, 3.00, 3.00, 3.00, 3.00};
const vector<double> output = {1.50, 60.00, 30.00, 8.00, 1.60, 0.40, 10.00, 0.60, 40.00, 4.40, 80.00, 1.25, 1.25, 15.00, 15.00, 75.00, 6.00, 6.00, 6.00, 6.00, 0.59, 0.85, 1.00, 15.00, 15.00, 0.50, 15.00, 7.00, 7.00, 7.00};

bool cmp(const pair<string, double> &a, const pair<string, double> &b)
{
    if(a.first == b.first) return a.second > b.second;
    return a.first < b.first;
}

int main()
{
    vector<pair<string, double>> pre;

    for(int i=0; i < model.size(); ++i)
    {
        pre.push_back(make_pair(model[i], input[i] + output[i]));
    }
    sort(pre.begin(), pre.end(), cmp);
    
    int op;
    while(cin >> op && op)
    {
        if(op == 1)
        {
            int n;
            double in, out;
            cin >> n >> in >> out;
            cout << fixed << setprecision(2) << (in / 1000000 * input[n-1] + out / 1000000 * output[n-1]) << '\n';
        }
        else if(op == 2)
        {
            double budget, in_t, mx = INT_MIN;
            string m;
            cin >> budget >> in_t;
            for(int i=0; i < model.size(); ++i)
            {
                double r = (budget - in_t/1000000 * input[i]) / output[i] * 1000000;
                if(r >= mx && model[i] > m)
                {
                    mx = r;
                    m = model[i];
                }
            }
            cout << m << " " << fixed << setprecision(0) << mx << '\n';
        }
        else
        {
            int k; cin >> k;
            cout << pre[k-1].first << " " << fixed << setprecision(2) << pre[k-1].second << '\n';
        }
    }
}