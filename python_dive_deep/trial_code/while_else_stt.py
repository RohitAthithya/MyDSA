# region: while loop with an else statement

""" How useful is the else block for a while statement

The else block runs only if the while loop completes without a break.
It helps in scenarios where you need to detect whether a condition was never met inside the loop.
It makes logic clearer compared to using flags or additional variables.

"""

lst = [1, 2, 3]
val = 2
idx = 0
while idx < len(lst):
    if lst[idx] == val:
        break
    idx += 1
else:
    print("visited here: ", idx)
    lst.append(val)

print(*lst)
# endregion:


# from re import findall as re_findall

# rtxy_res = "[NULL,49.977,34.000,-89.545,NULL,-140.432,-25.432]"

# choice = 2
# try:
#     _output = ""
#     if "[" in rtxy_res:
#         pattern  =r"\[(.*?)\]"
#         _output = re_findall(pattern=pattern, string=rtxy_res)[0]
#     else:
#         _output = rtxy_res.partition(",")[-1]

#     if choice == 1:
#         print( _output)
#     else:
#         print (_output.split(","))
# except:
#     print (False, "Unkown error")
