#include <bits/stdc++.h>
using namespace std;

const double D_max = 0.6, // 放大便宜模型的衰退上限，使其品質掉更快
            delta = 0.005, //讓貴模型在輸出大量時也有一點點衰退
            k = 1.5, //讓 decay rate 整體變大，拉開模型間差距
            gamma = 0.3, // 降冪較低（比原先 sqrt=0.5 小），讓 decay rate 對 P_out 變化更敏感
            epsilon = 0.2; // 防止 P_out = 0 的錯誤，同時減緩極小值模型的不穩定性
// const double D_max = 0.99, // 放大便宜模型的衰退上限，使其品質掉更快
//             delta = 0.01, //讓貴模型在輸出大量時也有一點點衰退
//             k = 3.5, //讓 decay rate 整體變大，拉開模型間差距
//             gamma = 0.2, // 降冪較低（比原先 sqrt=0.5 小），讓 decay rate 對 P_out 變化更敏感
//             epsilon = 0.05; // 防止 P_out = 0 的錯誤，同時減緩極小值模型的不穩定性




// vector<double> calcDecayRate(const vector<double>& P_out) {
//     size_t n = P_out.size();
//     vector<double> DecayRate(n);

//     // 你可以自行調整的參數：
//     const double DecayRate_min = 0.001; // 最高價模型的最低衰減率（穩定）
//     const double DecayRate_max = 0.999;  // 最低價模型的最高衰減率（快速衰減）
//     const double power = 1.0;           // 指數 k，可調整曲線形狀

//     // 找最大最小價格
//     double maxP = *max_element(P_out.begin(), P_out.end());
//     double minP = *min_element(P_out.begin(), P_out.end());

//     for (size_t i = 0; i < n; ++i) {
//         // 標準化價格（[0,1]）
//         double normalized = (P_out[i] - minP) / (maxP - minP);

//         // 反比映射，價格越大衰減率越小
//         double inv = 1.0 - normalized; // 0~1，價格越低，inv 越大

//         // 可用指數調整曲線
//         double val = std::pow(inv, power);

//         // 線性插值到範圍內
//         DecayRate[i] = DecayRate_min + val * (DecayRate_max - DecayRate_min);
//     }

//     return DecayRate;
// }


int main()
{
    string n,c,m; double in, out, r;
    int i=1;
    while(cin >> n >> c >> m >> in >> out >> r)
    {
        double q = min(D_max, delta + k / pow((out + epsilon), gamma));
        cout << fixed << setprecision(2) << i++ << " & " << c << " & " << m << " & " << in << " & " << out << '\n';//<< " & " << fixed << setprecision(4) << q << " \\\\\n";

    }



    // vector<string> model;
    // vector<double> input, output, rqd;
    // string n,m;
    // double in, out, d;
    // while(cin >> n >> m >> in >> out >> d)
    // {
    //     model.push_back(m);
    //     input.push_back(in);
    //     output.push_back(out);
    //     rqd.push_back(d);
    // }
    // for(int i=0; i < model.size(); ++i) cout << "\"" << model[i] << "\", ";
    // cout << '\n';
    // for(int i=0; i < input.size(); ++i) cout << input[i] << ", ";
    // cout << '\n';
    // for(int i=0; i < output.size(); ++i) cout << output[i] << ", ";
    // cout << '\n';
    // for(int i=0; i < rqd.size(); ++i) cout << rqd[i] << ", ";
    // cout << "\n\n\n";


    // vector<double> ddd;
    // for(int i=0; i < output.size(); ++i)
    // {
    //     double k = min(D_max, delta + k / pow((output[i] + epsilon), gamma));
    //     // double k = 0.4 / output[i];
    //     ddd.push_back(k);
    // }

    // // vector<double> rrr = calcDecayRate(ddd);
    // // sort(ddd.begin(),ddd.end());

    // for(int i=0; i < ddd.size(); ++i)
    // {
    //     cout << fixed << setprecision(4) << ddd[i] << ", ";
    // }
    // cout << '\n';

}
