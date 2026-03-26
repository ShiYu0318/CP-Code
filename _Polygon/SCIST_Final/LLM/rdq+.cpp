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

// 可選方案枚舉
enum Scheme {
    INVERSE = 1,     // 反比模型: R_qd = k / pow(P_out, p)
    EXPONENTIAL,     // 指數衰退: R_qd = a * exp(-b * P_out)
    LINEAR_MAP,      // 線性映射: R_qd = R_min + (R_max-R_min)*(P_max-P_out)/(P_max-P_min)
    PIECEWISE ,       // 分段模型
    INVERSE_PROPORTION,
    LOG
};

// 全局參數，可根據不同方案調整
double k = 5, p = 1.5;                 // INVERSE
double a = 1.0, b = 0.01;              // EXPONENTIAL
double R_min = 0.001, R_max = 0.999;   // LINEAR_MAP
double P_max = 480, P_min = 0.14;      // LINEAR_MAP 用
double cc = 0.5, dd = 10;              // 

// 計算 R_qd 函數
double compute_rqd(Scheme scheme, double P_out) {
    switch(scheme) {
        case INVERSE:
            return k * pow(P_out, -p);
        case EXPONENTIAL:
            return a * exp(-b * P_out);
        case LINEAR_MAP:
            return R_min + (R_max - R_min) * (P_max - P_out) / (P_max - P_min);
        case PIECEWISE:
            if(P_out > 100) return 0.001;
            else if(P_out > 10) return 0.05;
            else return 0.5;
        case INVERSE_PROPORTION:
            return min(1.0, cc / (P_out + dd));
        case LOG:
            return log(P_out + 1) / 100.0;
        default:
            return 0.001;
    }
}

int main()
{
    Scheme scheme = LOG; // 可修改此處選擇方案
    string n, c, m; 
    double in, out, r;
    int i = 1;

    // 讀取模型資料: 名稱與價格
    vector<double> v;
    for(int i=0;i<tb.size();++i)
    {
        double rqd = compute_rqd(scheme, tb[i].P_out);
        v.push_back(rqd);
        cout << fixed << setprecision(2) << "{\"" << tb[i].Name << "\", " << tb[i].P_in << ", "  << tb[i].P_out << ", " << fixed << setprecision(4) << rqd << "},\n";
        // cout << fixed << setprecision(2)
        //     << i++ << " & " << c << " & " << m << " & " 
        //     << in << " & " << out 
        //     << " & " << fixed << setprecision(4) << rqd 
        //     << " \\\\\n";
    }
    sort(v.begin(), v.end());
    // for(auto i:v) cout << i << '\n';
}
