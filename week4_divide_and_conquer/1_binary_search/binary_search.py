# Uses python3
import sys

def binary_search(A, findex, tindex, search):
    # write your code here
    if tindex < findex:
        return -1
    mid = findex + (tindex - findex) // 2
    if search == A[mid]:
        return mid
    elif search < A[mid]:
        return binary_search(A, findex, mid - 1, search)
    else:
        return binary_search(A, mid + 1, tindex, search)

def linear_search(a, x):
    for i in range(len(a)):
        if a[i] == x:
            return i
    return -1

def initial_array(array, target):
    array.sort()
    index = []
    for search in target:
        index.append(str(binary_search(array, 0, len(array) - 1, search)))
    return index

if __name__ == '__main__':
    input = sys.stdin.read()
    data = list(map(int, input.split()))
    n = data[0]
    m = data[n + 1]
    a = data[1 : n + 1]
    y = data[n + 2:]
    # replace with the call to binary_search when implemented
    print(' '.join(initial_array(a,x)))
