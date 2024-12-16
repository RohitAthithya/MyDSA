# a,b,c = 1,2,3
# a,b,c = 1,3,2
a,b,c = 3,2,1


if a>b and a>c:
    print("a is the greatest")
elif a<b and b>c:
    print("b is the greatest")
elif a<b and b<c:
    print("c is the greatest")



if a>b and a>c:
    print(" a is the greatest")
else:
    if a<b and b>c:
        print("b is the greatest")
    else:
        if a<b and b<c:
            print(' c is the greatest')