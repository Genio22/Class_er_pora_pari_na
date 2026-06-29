def linear_search (list, target):
    index = 0
    for i in list:
        index += 1
        if target == i:
            return index 

    return -1

if __name__ == "__main__":
    file_path = "try.txt"

    target = int(input("Enter a number from 2 - 300, to find it's index\n> ").strip())

    index = -1
    with open(file_path, "r", encoding="utf-8") as f:
        data = f.readlines()
        index = linear_search (int(data), target)


    if index != -1:
        print(f"{target} is found at \n> {index} index/line")

    else:
        print("Sorry")
        print(f"{target} is not found!")