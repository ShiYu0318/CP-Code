import matplotlib.pyplot as plt
import numpy as np
import pandas as pd

# 模型資料
models = [
    ("GPT-3.5-Turbo", 1.50),
    ("GPT-4", 60.00),
    ("GPT-4-Turbo", 30.00),
    ("GPT-4.1", 8.00),
    ("GPT-4.1-Mini", 1.60),
    ("GPT-4.1-Nano", 0.40),
    ("GPT-4o", 10.00),
    ("GPT-4o-Mini", 0.60),
    ("o3", 40.00),
    ("o3-mini", 4.40),
    ("o3-Pro", 80.00),
    ("Claude-1", 1.25),
    ("Claude-2", 1.25),
    ("Claude-3", 15.00),
    ("Claude-3.5", 15.00),
    ("Claude-4", 75.00),
    ("Gemini-2", 6.00),
    ("Gemini-2.5", 6.00),
    ("Gemini-2.5-Pro", 6.00),
    ("Gemini-2.5-Pro-Deep-Think", 6.00),
    ("LLaMA-4-Scout", 0.59),
    ("LLaMA-4-Maverick", 0.85),
    ("Perplexity-Sonar", 1.00),
    ("Grok-2", 15.00),
    ("Grok-3", 15.00),
    ("Grok-3-Mini", 0.50),
    ("Grok-4", 15.00),
    ("DeepSeek-R1", 7.00),
    ("DeepSeek-R2", 7.00),
    ("DeepSeek-V3", 7.00),
]

# decay rate 公式參數
D_max = 0.6
delta = 0.005
k = 1.5
gamma = 0.3
epsilon = 0.2

# 計算 decay rate
model_names = [m[0] for m in models]
P_out_values = [m[1] for m in models]
decay_rates = [min(D_max, delta + k / (p + epsilon) ** gamma) for p in P_out_values]

# 繪製 DecayRate 分布圖
plt.figure(figsize=(12, 6))
plt.barh(model_names, decay_rates)
plt.xlabel("Decay Rate")
plt.title("各模型的 Decay Rate 分布")
plt.tight_layout()
plt.gca().invert_yaxis()
plt.show()
