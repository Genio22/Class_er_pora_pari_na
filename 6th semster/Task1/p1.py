file_path = "try.txt"

with open(file_path, "w", encoding="utf-8") as f:
    data = []
    for i in range(2, 300, 3):
        f.write(f"{str(i)}\n")


def linear_search (list, target):
    index = 0
    for i in list:
        index += 1
        if target == i:
            return index 

    return -1


def lin_ser_with_file(path):


    target = int(input("Enter a number from 2 - 300, to find it's index\n> ").strip())

    index = -1
    with open(path, "r", encoding="utf-8") as f:
        data = f.readlines()
        index = linear_search ([int(i.strip()) for i in data], target)


    if index != -1:
        print(f"{target} is found at \n> {index} index/line")

    else:
        print("Sorry")
        print(f"{target} is not found!")


def selection_sort(arr):
    n = len(arr)
    for i in range(n-1):
        min_idx = i
        
        for j in range(i+1, n):
            if arr[j]< arr[min_idx]:
                min_idx = j
        
        arr[i], arr[min_idx]= arr[min_idx], arr[i]


def binary_search(arr, target):
    low = 0
    high = len(arr)-1
    while low <= high:
        mid = low + (high - low) // 2

        if arr[mid] == target:
            return mid + 1
        elif arr[mid] < target:
            low = mid + 1
        else:
            high = mid -1
    return -1




print("\n=====Task2====")
print("=====Linear_search with from file====\n\n")
file_path = "/run/media/genio/Sahaf Software_s/ALL/Class_er_pora_pari_na/6th semster/Task1/try.txt"
lin_ser_with_file(file_path)

print("\n=====Task5====")
print("=====Selection_sort====\n\n")
arr = [64, 25, 12, 22, 11]
selection_sort(arr)
print("Sorted array is:", arr)

print("\n=====Task3====")
print("=====Binary_search====\n\n")

result = binary_search(arr, int(input("Enter a number:  "))) 
if result != -1:
    print("Element is present at index ", result)
else:
    print("Element is not present in array")
