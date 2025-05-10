def permutations(n):
    A = []
    for i in range(n):
        A.append(i+1)
    helper(A, 0)

def helper(A,i):
    if i == len(A):
        print(A)
    else:
        for j in range(i, len(A)):
            A[i], A[j] = A[j], A[i]
            helper(A, i+1)
            A[i], A[j] = A[j], A[i]
            
if __name__ == '__main__':
    permutations(3)
