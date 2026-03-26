#include<bits/stdc++.h>
using namespace std;

struct Model
{
    string Name;
    double P_in, P_out, R_qd;
};

vector<Model> tb = 
{
    {"GPT-4.1", 5.00, 15.00, 0.0219},
    {"GPT-4.1-Mini", 0.15, 0.60, 0.0412},
    {"GPT-4.1-Nano", 0.05, 0.20, 0.0479},
    {"GPT-4o", 5.00, 15.00, 0.0219},
    {"GPT-4o-Mini", 0.15, 0.60, 0.0412},
    {"GPT-5", 1.25, 10.00, 0.0243},
    {"GPT-5-Mini", 0.25, 2.00, 0.0340},
    {"GPT-5-Nano", 0.05, 0.40, 0.0437},
    {"GPT-5-Pro", 1.25, 10.00, 0.0243},
    {"GPT-5-Thinking", 1.25, 10.00, 0.0243},
    {"o3", 60.00, 240.00, 0.0052},
    {"o3-mini", 1.10, 4.40, 0.0292},
    {"o3-Pro", 120.00, 480.00, 0.0010},
    {"Claude-3", 3.00, 15.00, 0.0219},
    {"Claude-3.5", 3.00, 15.00, 0.0219},
    {"Claude-4.1-Opus", 15.00, 75.00, 0.0122},
    {"Gemini-2", 1.25, 2.50, 0.0326},
    {"Gemini-2.5", 1.25, 5.00, 0.0285},
    {"Gemini-2.5-Pro", 3.50, 10.50, 0.0240},
    {"Gemini-2.5-Pro-Deep-Think", 7.00, 21.00, 0.0198},
    {"LLaMA-4-Scout", 0.27, 0.81, 0.0394},
    {"LLaMA-4-Maverick", 0.27, 0.85, 0.0391},
    {"Perplexity-Sonar", 0.20, 0.80, 0.0395},
    {"Grok-2", 5.00, 15.00, 0.0219},
    {"Grok-3", 3.00, 15.00, 0.0219},
    {"Grok-3-Mini", 0.30, 0.50, 0.0423},
    {"Grok-4", 3.00, 15.00, 0.0219},
    {"DeepSeek-R1", 0.55, 2.19, 0.0334},
    {"DeepSeek-R2", 0.55, 2.19, 0.0334},
    {"DeepSeek-V3", 0.07, 0.14, 0.0500}
};

const double eps = 1e-6;

// bool cmp(const pair<string, double> &a, const pair<string, double> &b)
// {
//     if(fabs(a.second - b.second) < eps) return a.first > b.first;
//     return a.second < b.second;
// }

int main()
{
    // vector< pair<string, double> > pre;
    // for(int i=0; i < tb.size(); ++i)
    // {
    //     pre.push_back(make_pair(tb[i].Name, tb[i].P_in + tb[i].P_out));
    // }
    // sort(pre.begin(), pre.end(), cmp);

    int op, tt=1, pp, inin;
    vector<pair<double,double>> input_pair;
    while(cin >> op && op)
    {
        cin >> pp >> inin;
        input_pair.push_back(make_pair(pp,inin));
    }
    double max_R_min=-1,max_R_max=-1;
    int maxS = -1;
    for(double R_min = 0.001 ;R_min < 0.999; R_min+=0.001)
    {
        for(double R_max = R_min ;R_max < 0.999; R_max+=0.001)
        {

            vector<double> log_P;
            for (Model md : tb) log_P.push_back(log(md.P_out));
            double log_P_max = *max_element(log_P.begin(), log_P.end());
            double log_P_min = *min_element(log_P.begin(), log_P.end());
            for (int i = 0; i < tb.size(); i++)
            {
                double R_qd = R_min + (R_max - R_min) * (log_P_max - log_P[i]) / (log_P_max - log_P_min);
                tb[i].R_qd = R_qd;
            }

            set<string> s;
            for(int k = 0;k<input_pair.size();++k)
            {
                vector<double> T_out_v, T_ef_v; //
                double mxtout = -1, mxtef = -1; //

                double P = input_pair[k].first, T_in = input_pair[k].second, mx = INT_MIN;
                string m;
                for(int i=0; i < tb.size(); ++i)
                {
                    double T_out = (P - T_in / 1e6 * tb[i].P_in) / tb[i].P_out * 1e6;
                    T_out_v.push_back(T_out); //
                    mxtout = max(mxtout, T_out); //
                    
                    if(T_out < 0) continue;
                    
                    double T_ef = T_out * max(0.0, 1 - tb[i].R_qd * (T_out / 1e6));
                    T_ef_v.push_back(T_ef); //
                    mxtef = max(mxtef, T_ef); //

                    if(T_ef > mx + eps || (fabs(T_ef - mx) < eps && tb[i].Name > m))
                    {
                        mx = T_ef;
                        m = tb[i].Name;
                    }
                }
                s.insert(m);
                // cout << m << " " << fixed << setprecision(0) << mx << '\n';

            }
            if((int)s.size() >= maxS)
            {
                maxS = (int)s.size();
                max_R_min = R_min;
                max_R_max = R_max;
            }
        }
        cout << max_R_min << " " << max_R_max << " " << maxS << '\n';
    }
}