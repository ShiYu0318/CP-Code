#include<bits/stdc++.h>
using namespace std;

struct Model
{
    string Name;
    double P_in, P_out, R_qd;
};

const vector<Model> tb = 
{
    {"GPT-4.1", 5.00, 15.00, 0.0500},
    {"GPT-4.1-Mini", 0.15, 0.60, 0.2500},
    {"GPT-4.1-Nano", 0.05, 0.20, 1.0000},
    {"GPT-4o", 5.00, 15.00, 0.0400},
    {"GPT-4o-Mini", 0.15, 0.60, 0.6667},
    {"GPT-5", 1.25, 10.00, 0.6667},
    {"GPT-5-Mini", 0.25, 2.00, 0.6667},
    {"GPT-5-Nano", 0.05, 0.40, 0.6667},
    {"GPT-5-Pro", 1.25, 10.00, 0.6667},
    {"GPT-5-Thinking", 1.25, 10.00, 0.6667},
    {"o3", 60.00, 240.00, 0.0100},
    {"o3-mini", 1.10, 4.40, 0.0909},
    {"o3-Pro", 120.00, 480.00, 0.0050},
    {"Claude-3", 3.00, 15.00, 0.0267},
    {"Claude-3.5", 3.00, 15.00, 0.0267},
    {"Claude-4.1-Opus", 15.00, 75.00, 0.0053},
    {"Gemini-2", 1.25, 2.50, 0.0667},
    {"Gemini-2.5", 1.25, 5.00, 0.0667},
    {"Gemini-2.5-Pro", 3.50, 10.50, 0.0667},
    {"Gemini-2.5-Pro-Deep-Think", 7.00, 21.00, 0.0667},
    {"LLaMA-4-Scout", 0.27, 0.81, 0.6780},
    {"LLaMA-4-Maverick", 0.27, 0.85, 0.4706},
    {"Perplexity-Sonar", 0.20, 0.80, 0.4000},
    {"Grok-2", 5.00, 15.00, 0.0267},
    {"Grok-3", 3.00, 15.00, 0.0267},
    {"Grok-3-Mini", 0.30, 0.50, 0.8000},
    {"Grok-4", 3.00, 15.00, 0.0267},
    {"DeepSeek-R1", 0.55, 2.19, 0.0571},
    {"DeepSeek-R2", 0.55, 2.19, 0.0571},
    {"DeepSeek-V3", 0.07, 0.14, 0.0571}
};

const double eps = 1e-6;

bool cmp(const pair<string, double> &a, const pair<string, double> &b)
{
    if(fabs(a.second - b.second) < eps) return a.first > b.first;
    return a.second < b.second;
}

int main()
{
    vector< pair<string, double> > pre;
    for(int i=0; i < tb.size(); ++i)
    {
        pre.push_back(make_pair(tb[i].Name, tb[i].P_in + tb[i].P_out));
    }
    sort(pre.begin(), pre.end(), cmp);

    int op;
    while(cin >> op && op)
    {
        if(op == 1)
        {
            int n; double T_in, T_out;
            cin >> n >> T_in >> T_out;
            cout << fixed << setprecision(2) << (T_in / 1e6 * tb[n-1].P_in + T_out / 1e6 * tb[n-1].P_out) << '\n';
        }
        else if(op == 2)
        {
            double P, T_in, mx = INT_MIN;
            string m; cin >> P >> T_in;
            for(int i=0; i < tb.size(); ++i)
            {
                double T_out = (P - T_in / 1e6 * tb[i].P_in) / tb[i].P_out * 1e6;
                // cout <<  fixed << setprecision(2) << T_out << '\n';
                if(T_out < 0) continue;
                // double T_ef = T_out * max(0.0, 1 - tb[i].R_qd * (T_out / 1e6));
                double T_ef = T_out * exp(-tb[i].R_qd * (T_out / 1e6));
                cout <<  fixed << setprecision(0) << T_ef  << '\n';
                // cout <<  fixed << setprecision(10) << exp(-tb[i].R_qd * (T_out / 1e6))  << '\n';
                if(T_ef > mx + eps || (fabs(T_ef - mx) < eps && tb[i].Name > m))
                {
                    mx = T_ef;
                    m = tb[i].Name;
                }
            }
            // cout << m << " " << fixed << setprecision(0) << mx << '\n';
        }
        else
        {
            int K; cin >> K;
            cout << pre[K-1].first << " " << fixed << setprecision(2) << pre[K-1].second << '\n';
        }
    }
}