# basic
# y = 3
# print (y)

#Tuples
tu = (2, 'abc', 4.51, (8,4,5,6), "def")
tu1 = tu[1]
print(tu1)
print(tu)

#Lists
this_is_a_list = ["abc", (1,2,3), (123), 'bcf']
print(this_is_a_list[1:])

#Strings
str = "hello world"
str_edit = str + " everyone"
print(str_edit)

#Accessing
print(tu[2]) #note that it automatically adds a new line
print(this_is_a_list[3])

#strings are unchangeable
#str[4] = "P"
print(str[4]) #count from left to right start at 0!
print(str[-5]) #count from right to left start at -1!

#Slicing
print(tu[1:3]) #first index to before index
print(this_is_a_list[2:]) #include from index 2 to include end index
print(this_is_a_list[:-2]) #include from index 2 to include end index

#List manipulations
# Mutability = Operations not as fast as tuples
this_is_another_list = this_is_a_list
this_is_another_list[1] = ("edit list")
print(this_is_another_list)
print(this_is_a_list)

#in operator
if ("w" in str):
    print("yes" * 3)

#Converting tuples to list, vice versa
convert_to_list = list(tu)
convert_to_list[1] = 100
print(convert_to_list)

#Dictionaries
d = {"username": "Allan", "password": "King Allan123"}
d["username"] = "Thanos"
print(d["username"])
print(d)

del d["password"]
print(d)

convert_dict = list(d.keys())
print(convert_dict)

x = "the answer is:"
y = "123"
answer = x + y
print(answer)

#Functions
def test():
    x, y, z = 1, 1, 1
    if(x and y and z == 1):
        return z
print(test())

# string1 = "Hello" + str(2)
# print(string1)

uppercase = "testing".upper()
print(uppercase, end = " ")
print("no newline")

for i in range(3, 11):
    print(i)

def functionA (m, n):
    return (m* 10) - n
list1 = [(12,10,5), (5,2,-22), (5,5,1)]
list2 = [functionA(r,s) for (r,t,s) in list1]
print(list2)

abc = functionA(2, 3)
print(abc)

this_is_a_list = ["abc", (1,2,3), (123), 'bcf']
print(this_is_a_list)
another_list = this_is_a_list
print(another_list)
another_list[0] = 999
print(another_list)
print(this_is_a_list)

b = 1
c = 2

print("%04d %04d" % (c, b))