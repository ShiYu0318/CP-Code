import numpy as np
import matplotlib.pyplot as plt
from mpl_toolkits.mplot3d import Axes3D
import ipywidgets as widgets
from IPython.display import display

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

# 計算 R_qd：便宜模型衰退大，log 映射均勻分散
R_min, R_max = 0.001, 0.999
P_out_values = np.array([x[2] for x in models])
log_P = np.log(P_out_values)
R_qd_values = R_min + (R_max - R_min) * (log_P.max() - log_P) / (log_P.max() - log_P.min())

names = [x[0] for x in models]
colors = plt.cm.tab20(np.linspace(0, 1, len(names)))

# T_out 範圍
T_out = np.logspace(1, 7, 100)  # 10^1 ~ 10^7

# 指數衰退公式
def T_ef_func(T_out, R_qd):
    return T_out * np.exp(-R_qd * T_out / 1e6)

# 建立互動式圖形
fig = plt.figure(figsize=(10,7))
ax = fig.add_subplot(111, projection='3d')

lines = []
for i, name in enumerate(names):
    T_ef = T_ef_func(T_out, R_qd_values[i])
    line, = ax.plot(T_out, [R_qd_values[i]]*len(T_out), T_ef, color=colors[i], label=name)
    lines.append(line)

ax.set_xlabel("T_out")
ax.set_ylabel("R_qd")
ax.set_zlabel("T_ef")
ax.set_xscale('log')
ax.set_title("模型 T_ef 曲面 (指數衰退)")

# 互動滑桿
def update(elev=30, azim=45):
    ax.view_init(elev=elev, azim=azim)
    fig.canvas.draw_idle()

elev_slider = widgets.IntSlider(min=0, max=180, value=30, description='Elevation')
azim_slider = widgets.IntSlider(min=0, max=360, value=45, description='Azimuth')

widgets.interactive(update, elev=elev_slider, azim=azim_slider)
display(elev_slider, azim_slider)

plt.legend(bbox_to_anchor=(1.05, 1), loc='upper left', fontsize=8)
plt.show()
