N=0
K=0
currency=0
count=0
while True:
    N, K = input().split()
    N=int(N)
    K=int(K)
    if N<=10 and N>=1:
        break
    else:
        print("1≤N≤10\n")
A = list(range(0, N))
for i in range(len(A)):
    while True:
        currency=int(input())
        if i==0 and currency==1:
            A[i] = currency
            break
        elif i==0 and currency!=1:
            print("A₁= 1")
        elif i>=1:
            A[i] = currency;
            if A[i] % A[i-1] == 0:
                break
            else:
                print("A[%d]는 A[%d]의 배수\n", i, i-1)
        else:
            print("1≤K≤100,000,000\n")
A.reverse()
for i in range(len(A)):
    if K>=A[i]:
        count+=int(K/A[i])
        #print(A[i],"원 짜리 동전",K/A[i],"개")
        K=K%A[i]
        #print("나머지", K, "원\n");
print("동전 개수의 최솟값은", int(count),"개")
