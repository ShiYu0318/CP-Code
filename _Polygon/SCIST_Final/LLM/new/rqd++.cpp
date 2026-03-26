#include <bits/stdc++.h>
using namespace std;

struct Model
{
    string Name;
    double P_in, P_out, R_qd;
};

const vector<Model> tb = 
{
    {"GPT-4.1", 5.00, 15.00},
    {"GPT-4.1-Mini", 0.15, 0.60},
    {"GPT-4.1-Nano", 0.05, 0.20},
    {"GPT-4o", 5.00, 15.00},
    {"GPT-4o-Mini", 0.15, 0.60},
    {"GPT-5", 1.25, 10.00},
    {"GPT-5-Mini", 0.25, 2.00},
    {"GPT-5-Nano", 0.05, 0.40},
    {"GPT-5-Pro", 1.25, 10.00},
    {"GPT-5-Thinking", 1.25, 10.00},
    {"o3", 60.00, 240.00},
    {"o3-mini", 1.10, 4.40},
    {"o3-Pro", 120.00, 480.00},
    {"Claude-3", 3.00, 15.00},
    {"Claude-3.5", 3.00, 15.00},
    {"Claude-4.1-Opus", 15.00, 75.00},
    {"Gemini-2", 1.25, 2.50},
    {"Gemini-2.5", 1.25, 5.00},
    {"Gemini-2.5-Pro", 3.50, 10.50},
    {"Gemini-2.5-Pro-Deep-Think", 7.00, 21.00},
    {"LLaMA-4-Scout", 0.27, 0.81},
    {"LLaMA-4-Maverick", 0.27, 0.85},
    {"Perplexity-Sonar", 0.20, 0.80},
    {"Grok-2", 5.00, 15.00},
    {"Grok-3", 3.00, 15.00},
    {"Grok-3-Mini", 0.30, 0.50},
    {"Grok-4", 3.00, 15.00},
    {"DeepSeek-R1", 0.55, 2.19},
    {"DeepSeek-R2", 0.55, 2.19},
    {"DeepSeek-V3", 0.07, 0.14}
};


double R_min = 0.001, R_max = 0.025;   // LINEAR_MAP


int main()
{
    // string n, c, m; 
    // double in, out, r;
    // int i = 1;


    vector<double> log_P;
    for (Model md : tb) log_P.push_back(log(md.P_out));
    double log_P_max = *max_element(log_P.begin(), log_P.end());
    double log_P_min = *min_element(log_P.begin(), log_P.end());
    for (int i = 0; i < tb.size(); i++)
    {
        double R_qd = R_min + (R_max - R_min) * (log_P_max - log_P[i]) / (log_P_max - log_P_min);
        // cout << fixed << setprecision(2) << "{\"" << tb[i].Name << "\", " << tb[i].P_in << ", "  << tb[i].P_out << ", " << fixed << setprecision(4) << R_qd << "},\n";
        cout << fixed << setprecision(4) << R_qd << ", ";
        // tb[i].R_qd = R_qd;
    }

    // // 讀取模型資料: 名稱與價格
    // vector<double> v;
    // for(int i=0;i<tb.size();++i)
    // {
    //     double rqd = compute_rqd(scheme, tb[i].P_out);
    //     v.push_back(rqd);
    //     // cout << fixed << setprecision(2)
    //     //     << i++ << " & " << c << " & " << m << " & " 
    //     //     << in << " & " << out 
    //     //     << " & " << fixed << setprecision(4) << rqd 
    //     //     << " \\\\\n";
    // }
    // sort(v.begin(), v.end());
    // // for(auto i:v) cout << i << '\n';
}
