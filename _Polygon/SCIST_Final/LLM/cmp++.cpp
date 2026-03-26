#include<bits/stdc++.h>
using namespace std;

struct Model {
    string Name;
    double P_in, P_out, R_qd;
};

vector<Model> base_tb = 
{
    {"GPT-4.1", 5.00, 15.00, 0.0200},
    {"GPT-4.1-Mini", 0.15, 0.60, 0.0472},
    {"GPT-4.1-Nano", 0.05, 0.20, 0.0490},
    {"GPT-4o", 5.00, 15.00, 0.0200},
    {"GPT-4o-Mini", 0.15, 0.60, 0.0472},
    {"GPT-5", 1.25, 10.00, 0.0250},
    {"GPT-5-Mini", 0.25, 2.00, 0.0417},
    {"GPT-5-Nano", 0.05, 0.40, 0.0481},
    {"GPT-5-Pro", 1.25, 10.00, 0.0250},
    {"GPT-5-Thinking", 1.25, 10.00, 0.0250},
    {"o3", 60.00, 240.00, 0.0020},
    {"o3-mini", 1.10, 4.40, 0.0347},
    {"o3-Pro", 120.00, 480.00, 0.0010},
    {"Claude-3", 3.00, 15.00, 0.0200},
    {"Claude-3.5", 3.00, 15.00, 0.0200},
    {"Claude-4.1-Opus", 15.00, 75.00, 0.0059},
    {"Gemini-2", 1.25, 2.50, 0.0400},
    {"Gemini-2.5", 1.25, 5.00, 0.0333},
    {"Gemini-2.5-Pro", 3.50, 10.50, 0.0244},
    {"Gemini-2.5-Pro-Deep-Think", 7.00, 21.00, 0.0161},
    {"LLaMA-4-Scout", 0.27, 0.81, 0.0463},
    {"LLaMA-4-Maverick", 0.27, 0.85, 0.0461},
    {"Perplexity-Sonar", 0.20, 0.80, 0.0463},
    {"Grok-2", 5.00, 15.00, 0.0200},
    {"Grok-3", 3.00, 15.00, 0.0200},
    {"Grok-3-Mini", 0.30, 0.50, 0.0476},
    {"Grok-4", 3.00, 15.00, 0.0200},
    {"DeepSeek-R1", 0.55, 2.19, 0.0410},
    {"DeepSeek-R2", 0.55, 2.19, 0.0410},
    {"DeepSeek-V3", 0.07, 0.14, 0.0493}
};

const double eps = 1e-6;

double newRqd(int method, double Pin, double Pout) {
    switch(method) {
        case 1: return Pout / 100.0;
        case 2: return sqrt(Pout) / 10.0;
        case 3: return 0.05;
        case 4: return (Pin + Pout) / 500.0;
        case 5: return max(0.001, 0.05 - Pin / 100.0);
        case 6: return Pout / (Pin + Pout) / 10.0;
        case 7: return 0.02 + fabs(Pin - Pout) / 1000.0;
        case 8: return (Pin * Pout) / 1000.0;
        case 9: return 0.03;
        case 10:return log(Pout + 1) / 100.0;
        default: return 0; 
    }
}

int run_one_method(vector<Model> tb) {
    set<string> s;
    int op;
    while(cin >> op && op) {
        if(op == 2) {
            double P, T_in, mx = INT_MIN;
            string m; 
            cin >> P >> T_in;
            for(int i=0; i < tb.size(); ++i) {
                double T_out = (P - T_in / 1e6 * tb[i].P_in) / tb[i].P_out * 1e6;
                if(T_out < 0) continue;
                double T_ef = T_out * max(0.0, 1 - tb[i].R_qd * (T_out / 1e6));
                if(T_ef > mx + eps || (fabs(T_ef - mx) < eps && tb[i].Name > m)) {
                    mx = T_ef;
                    m = tb[i].Name;
                }
            }
            s.insert(m);
        }
    }
    return (int)s.size();
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    // 先存輸入
    stringstream input_buffer;
    input_buffer << cin.rdbuf();
    string all_input = input_buffer.str();

    for(int method = 0; method <= 10; ++method) {
        vector<Model> tb = base_tb;
        if(method != 0) {
            for(auto &x : tb) {
                x.R_qd = newRqd(method, x.P_in, x.P_out);
            }
        }
        stringstream ss(all_input);
        cin.rdbuf(ss.rdbuf());
        int ans = run_one_method(tb);
        if(method == 0) cout << "原始: " << ans << '\n';
        else cout << "方法" << method << ": " << ans << '\n';
    }
}
