import numpy as np
import matplotlib.pyplot as plt

# 模型名稱與 P_in, P_out
models = [
    ("GPT-4.1",5.00,15.00),("GPT-4.1-Mini",0.15,0.60),("GPT-4.1-Nano",0.05,0.20),
    ("GPT-4o",5.00,15.00),("GPT-4o-Mini",0.15,0.60),("GPT-5",1.25,10.00),
    ("GPT-5-Mini",0.25,2.00),("GPT-5-Nano",0.05,0.40),("GPT-5-Pro",1.25,10.00),
    ("GPT-5-Thinking",1.25,10.00),("o3",60.00,240.00),("o3-mini",1.10,4.40),
    ("o3-Pro",120.00,480.00),("Claude-3",3.00,15.00),("Claude-3.5",3.00,15.00),
    ("Claude-4.1-Opus",15.00,75.00),("Gemini-2",1.25,2.50),("Gemini-2.5",1.25,5.00),
    ("Gemini-2.5-Pro",3.50,10.50),("Gemini-2.5-Pro-Deep-Think",7.00,21.00),
    ("LLaMA-4-Scout",0.27,0.81),("LLaMA-4-Maverick",0.27,0.85),("Perplexity-Sonar",0.20,0.80),
    ("Grok-2",5.00,15.00),("Grok-3",3.00,15.00),("Grok-3-Mini",0.30,0.50),
    ("Grok-4",3.00,15.00),("DeepSeek-R1",0.55,2.19),("DeepSeek-R2",0.55,2.19),
    ("DeepSeek-V3",0.07,0.14)
]

# 計算 R_qd：便宜模型衰退大
R_min, R_max = 0.001, 0.999
P_out_values = np.array([x[2] for x in models])
P_max, P_min = P_out_values.max(), P_out_values.min()
R_qd_values = R_min + (R_max - R_min) * (P_max - P_out_values) / (P_max - P_min)

# --- 輸出 C++ 初始化列表 ---
print("// C++ 初始化列表")
for i, (name, pin, pout) in enumerate(models):
    print(f'    {{"{name}", {pin:.2f}, {pout:.2f}, {R_qd_values[i]:.4f}}},')

# --- 繪圖 ---
names = [x[0] for x in models]
colors = plt.cm.tab20(np.linspace(0, 1, len(names)))

plt.figure(figsize=(14,6))
for i in range(len(names)):
    plt.scatter(P_out_values[i], R_qd_values[i], color=colors[i], s=100)
    plt.text(P_out_values[i]*1.05, R_qd_values[i], names[i], fontsize=8, verticalalignment='center')

plt.title('模型 P_out 對應 R_qd (便宜模型衰退大)')
plt.xlabel('P_out (USD)')
plt.ylabel('R_qd')
plt.xscale('log')  # 對數軸
plt.grid(True, which='both', linestyle='--', alpha=0.5)
plt.show()

