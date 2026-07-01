def quick_sort(arr):
    
    if len(arr) <= 1:
        return arr

    pivot = arr[0]
    left = []
    for x in arr:
        if x < pivot:
            left.append(x)

    right = []
    for x in arr:
        if x > pivot:
            right.append(x)
    
    mid = []
    for x in arr:
        if x == pivot:
            mid.append(x)
    
    return quick_sort(left) + mid + quick_sort(right)

def file_access(file_path):

    arr = []
    with open (file_path, "r", encoding="utf-8") as f:

        arr = [int(x.strip()) for x in f ]
    
    return arr


file_path = "sequence.txt"
arr = file_access(file_path)

print(f"Before sort \n{arr}")
arr_after = quick_sort(arr)
print(f"After sort \n{arr_after}")

