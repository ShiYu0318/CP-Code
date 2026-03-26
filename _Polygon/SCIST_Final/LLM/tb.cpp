#include<bits/stdc++.h>
using namespace std;

struct Model
{
    string Name;
    double P_in, P_out, R_qd;
};

const vector<Model> tb = 
{
    {"GPT-4.1", 5.00, 15.00, 0.0112},
    {"GPT-4.1-Mini", 0.15, 0.60, 0.0207},
    {"GPT-4.1-Nano", 0.05, 0.20, 0.0239},
    {"GPT-4o", 5.00, 15.00, 0.0112},
    {"GPT-4o-Mini", 0.15, 0.60, 0.0207},
    {"GPT-5", 1.25, 10.00, 0.0124},
    {"GPT-5-Mini", 0.25, 2.00, 0.0172},
    {"GPT-5-Nano", 0.05, 0.40, 0.0219},
    {"GPT-5-Pro", 1.25, 10.00, 0.0124},
    {"GPT-5-Thinking", 1.25, 10.00, 0.0124},
    {"o3", 60.00, 240.00, 0.0030},
    {"o3-mini", 1.10, 4.40, 0.0148},
    {"o3-Pro", 120.00, 480.00, 0.0010},
    {"Claude-3", 3.00, 15.00, 0.0112},
    {"Claude-3.5", 3.00, 15.00, 0.0112},
    {"Claude-4.1-Opus", 15.00, 75.00, 0.0065},
    {"Gemini-2", 1.25, 2.50, 0.0165},
    {"Gemini-2.5", 1.25, 5.00, 0.0145},
    {"Gemini-2.5-Pro", 3.50, 10.50, 0.0123},
    {"Gemini-2.5-Pro-Deep-Think", 7.00, 21.00, 0.0102},
    {"LLaMA-4-Scout", 0.27, 0.81, 0.0198},
    {"LLaMA-4-Maverick", 0.27, 0.85, 0.0197},
    {"Perplexity-Sonar", 0.20, 0.80, 0.0199},
    {"Grok-2", 5.00, 15.00, 0.0112},
    {"Grok-3", 3.00, 15.00, 0.0112},
    {"Grok-3-Mini", 0.30, 0.50, 0.0212},
    {"Grok-4", 3.00, 15.00, 0.0112},
    {"DeepSeek-R1", 0.55, 2.19, 0.0169},
    {"DeepSeek-R2", 0.55, 2.19, 0.0169},
    {"DeepSeek-V3", 0.07, 0.14, 0.0250}
};

int main()
{
    for(int i=0 ; i<tb.size(); ++i)
    {
        string cp;
        if(i<13) cp = "OpenAI";
        else if(i<16) cp = "Anthropic";
        else if(i<20) cp = "Google-DeepMind";
        else if(i<22) cp = "Meta";
        else if(i<23) cp = "Perplexity-AI";
        else if(i<27) cp = "xAI";
        else cp = "DeepSeek";
        cout << fixed << setprecision(2) << i+1 << " & " << cp << " & " << tb[i].Name << " & " << tb[i].P_in << " & " << tb[i].P_out << " & " << fixed << setprecision(4) << tb[i].R_qd << " \\\\\n";
    }
}