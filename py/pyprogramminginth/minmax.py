num = int(input("Number of numbers: "))
list_num = []
for i in range(num):
    list_num.append(int(input(f"Input number {i+1}: ")))    

print(min(list_num))
print(max(list_num))