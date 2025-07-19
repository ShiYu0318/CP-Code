# 第一部分
## 題目一

### [start:stop:step]
```py
print(input()[::-1])
```

## 題目二
```py
a = input().split(',')
b = input().split(',')
print(','.join(a + b))
```

## 題目三
```py
a = list(map(int,input().split(',')))
mx = a[0]
mi = a[0]
for i in a:
    mx = max(mx, i)
    mi = min(mi, i)
print(f'最大值：{mx}, 最小值：{mi}, 差值：{mx - mi}')
```

# 第二部分
## 題目一
```py
n = int(input())
sum = 0
for i in range(n):
    sum += i+1
print(sum)
```

## 題目二
```py
n = int(input())
is_prime = True
for i in range(2,int(n**0.5)+1):
    if n % i == 0:
        is_prime = False
        break
if is_prime:
    print(f'{n} 是質數')
else:
    print(F'{n} 不是質數')
```

## 題目三
```py
import random

ans = random.randint(1, 100)

while True:
    guess = int(input('請輸入你的猜測：'))

    if guess < ans:
        print('太小了！')
    elif guess > ans:
        print('太大了！')
    else:
        print(f'恭喜, 你猜對了！')
        break
```

# 第三部分
## 題目一
```py
def add(a, b):
    return a + b

print(add(3, 5))
```

## 題目二
```py
import math

class Circle:
    def __init__(self, radius):
        self.radius = radius

    def area(self):
        return math.pi * self.radius ** 2

circle = Circle(10)
print(circle.area())
```

## 題目三
```py
class Playlist:
    def __init__(self):
        self.songs = []

    def add_song(self, song):
        self.songs.append(song)
        print(f'已添加歌曲：{song}')

    def remove_song(self, song):
        if song in self.songs:
            self.songs.remove(song)
            print(f'已刪除歌曲：{song}')
        else:
            print(f'歌曲 "{song}" 不在播放清單中')

    def show_songs(self):
        if self.songs:
            print('播放清單：')
            for index, song in enumerate(self.songs, 1):
                print(f'{index}. {song}')
        else:
            print('播放清單是空的')

    def song_count(self):
        return len(self.songs)

playlist = Playlist()
playlist.add_song('A')
playlist.add_song('B')
playlist.show_songs()
print(f'總共有 {playlist.song_count()} 首歌曲')
playlist.remove_song('A')
playlist.show_songs()
print(f'總共有 {playlist.song_count()} 首歌曲')
```