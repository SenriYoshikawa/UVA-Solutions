data = [0 for i in range(1001)]
data[1] = 1
for i in range(2,1001):
    for j in range(1, i - 1):
        data[i] += data[j] * data[i - j - 1]
    data[i] += data[i-1]*2

while True:
    try:
        print(data[int(input())])
    except :
        break

