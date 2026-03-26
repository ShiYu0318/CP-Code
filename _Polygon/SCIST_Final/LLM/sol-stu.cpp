#include <bits/stdc++.h>
using namespace std;

struct Model {
    double price;
    string name;
};
void swap(Model &a, Model &b) {
    Model t = a;
    a = b;
    b = t;
}
int main() {
    int n = 30;
    string a[30] = {
        "GPT-3.5-Turbo","GPT-4","GPT-4-Turbo","GPT-4.1","GPT-4.1-Mini",
        "GPT-4.1-Nano","GPT-4o","GPT-4o-Mini","o3","o3-mini",
        "o3-Pro","Claude-1","Claude-2","Claude-3","Claude-3.5",
        "Claude-4","Gemini-2","Gemini-2.5","Gemini-2.5-Pro","Gemini-2.5-Pro-Deep-Think",
        "LLaMA-4-Scout","LLaMA-4-Maverick","Perplexity-Sonar","Grok-2","Grok-3",
        "Grok-3-Mini","Grok-4","DeepSeek-R1","DeepSeek-R2","DeepSeek-V3"
    };
    double b[30] = {
        0.50,30.00,10.00,2.00,0.40,
        0.10,2.50,0.15,10.00,1.10,
        20.00,0.25,0.25,3.00,3.00,
        15.00,1.25,1.25,1.25,1.25,
        0.18,0.27,1.00,5.00,3.00,
        0.30,3.00,3.00,3.00,3.00
    };
    double c[30] = {
        1.50,60.00,30.00,8.00,1.60,
        0.40,10.00,0.60,40.00,4.40,
        80.00,1.25,1.25,15.00,15.00,
        75.00,6.00,6.00,6.00,6.00,
        0.59,0.85,1.00,15.00,15.00,
        0.50,15.00,7.00,7.00,7.00
    };
    double d[30] = {
        0.2667,0.0067,0.0133,0.0500,0.2500,
        1.0000,0.0400,0.6667,0.0100,0.0909,
        0.0050,0.3200,0.3200,0.0267,0.0267,
        0.0053,0.0667,0.0667,0.0667,0.0667,
        0.6780,0.4706,0.4000,0.0267,0.0267,
        0.8000,0.0267,0.0571,0.0571,0.0571
    };
    int op;
    while (cin >> op && op != 0) {
        if (op == 1) {
            int N; long long Tin, Tout;
            cin >> N >> Tin >> Tout;
            double cost = (Tin * b[N - 1] + Tout * c[N - 1]) / 1000000.0;
            cost = round(cost * 100) / 100;
            cout << fixed << setprecision(2) << cost << '\n';
        } else if (op == 2) {
            double P; long long Tin;
            cin >> P >> Tin;
            string bestName = "";
            int bestTef = -1;
            for (int i = 0; i < n; i++) {
                double costInput = Tin * b[i] / 1000000.0;
                double remain = P - costInput;
                if (remain <= 0) continue;
                double Tout = (remain * 1000000.0 / c[i]);
                double quality = max(0.0, 1.0 - d[i] * Tout / 1000000.0);
                int Tef = (int)round(Tout * quality);
                if (Tef > bestTef || (Tef == bestTef && a[i] > bestName)) {
                    bestTef = Tef;
                    bestName = a[i];
                }
            }
            cout << bestName << " " << bestTef << '\n';
        } else if (op == 3) {
            int K; cin >> K;
            Model arr[30];
            for (int i = 0; i < n; i++) {
                arr[i].price = b[i] + c[i];
                arr[i].name = a[i];
            }
            for (int i = 0; i < n-1; i++) {
                for (int j = 0; j < n-1-i; j++) {
                    if (arr[j].price > arr[j+1].price ||
                        (fabs(arr[j].price - arr[j+1].price) < 1e-7 && arr[j].name < arr[j+1].name)) {
                        swap(arr[j], arr[j+1]);
                    }
                }
            }
            cout << fixed << setprecision(2) <<  arr[K-1].name.c_str() << " " << arr[K-1].price << '\n';
        }
    }
    return 0;
}