#include<bits/stdc++.h>
using namespace std;

const vector<string> model = {"GPT-3.5-Turbo", "GPT-4", "GPT-4-Turbo", "GPT-4.1", "GPT-4.1-Mini", "GPT-4.1-Nano", "GPT-4o", "GPT-4o-Mini", "o3", "o3-mini", "o3-Pro", "Claude-1", "Claude-2", "Claude-3", "Claude-3.5", "Claude-4", 
                "Gemini-2", "Gemini-2.5", "Gemini-2.5-Pro", "Gemini-2.5-Pro-Deep-Think", "LLaMA-4-Scout", "LLaMA-4-Maverick", "Perplexity-Sonar", "Grok-2", "Grok-3", "Grok-3-Mini", "Grok-4", "DeepSeek-R1", "DeepSeek-R2", "DeepSeek-V3"};
const vector<double> P_in = {0.50, 30.00, 10.00, 2.00, 0.40, 0.10, 2.50, 0.15, 10.00, 1.10, 20.00, 0.25, 0.25, 3.00, 3.00, 15.00, 1.25, 1.25, 1.25, 1.25, 0.18, 0.27, 1.00, 5.00, 3.00, 0.30, 3.00, 3.00, 3.00, 3.00};
const vector<double> P_out = {1.50, 60.00, 30.00, 8.00, 1.60, 0.40, 10.00, 0.60, 40.00, 4.40, 80.00, 1.25, 1.25, 15.00, 15.00, 75.00, 6.00, 6.00, 6.00, 6.00, 0.59, 0.85, 1.00, 15.00, 15.00, 0.50, 15.00, 7.00, 7.00, 7.00};
const vector<double> R_qd = {0.0112, 0.0207, 0.0239, 0.0112, 0.0207, 0.0124, 0.0172, 0.0219, 0.0124, 0.0124, 0.0030, 0.0148, 0.0010, 0.0112, 0.0112, 0.0065, 0.0165, 0.0145, 0.0123, 0.0102, 0.0198, 0.0197, 0.0199, 0.0112, 0.0112, 0.0212, 0.0112, 0.0169, 0.0169, 0.0250};


bool cmp(const pair<string, double> &a, const pair<string, double> &b)
{
    if(a.second == b.second) return a.first > b.first;
    return a.second < b.second;
}

int main()
{
    vector<pair<string, double>> pre;

    for(int i=0; i < model.size(); ++i)
    {
        pre.push_back(make_pair(model[i], P_in[i] + P_out[i]));
    }
    sort(pre.begin(), pre.end(), cmp);

    int op,tt=1;
    while(cin >> op && op)
    {
        if(op == 2)
        {
            double P, T_in, mx = INT_MIN;
            string m;
            cin >> P >> T_in;
            vector<double> T_out_v, T_ef_v;
            double mxtout = -1, mxtef = -1;
            for(int i=0; i < model.size(); ++i)
            {
                double T_out = (P - T_in / 1000000 * P_in[i]) / P_out[i] * 1000000;
                T_out_v.push_back(T_out);
                mxtout = max(mxtout, T_out);

                double T_ef = T_out * max(0.0, 1 - R_qd[i] * (T_out / 1000000));
                T_ef_v.push_back(T_ef);
                mxtef = max(mxtef, T_ef);

                if(T_ef >= mx && model[i] > m)
                {
                    mx = T_ef;
                    m = model[i];
                }
            }
            cout << "# Case " << tt++ <<  "  -----------------------\n";
            for(int i=0; i < model.size(); ++i)
            {
                cout << " " << (T_out_v[i] == mxtout ? "1" : " ") <<  " " << (T_ef_v[i] == mxtef ? "1" : " ") << "  " << model[i] << " " << fixed << setprecision(0) << T_out_v[i]  << " " << T_ef_v[i] << '\n';
            }
            cout << "\n\n\n\n\n";
            // cout << m << " " << fixed << setprecision(0) << mx << '\n';
        }
    }
}