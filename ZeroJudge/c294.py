a,b,c = map(int,input().split())

if a > c:
    a,c = c,a
if a > b:
    a,b = b,a
if b > c:
    b,c = c,b

print(a,b,c)

if a + b <= c:
    print("No\n")
elif a*a + b*b < c*c:
    print("Obtuse\n")
elif a*a + b*b == c*c:
    print("Right\n")
else:
    print("Acute\n")