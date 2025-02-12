def create_arrays(lst: list[int], N: int, X: int):
    out_lst = []
    for i in range(N):
        tmp = lst[:]
        tmp[i] = tmp[i] * X
        out_lst.append(tmp)
    return out_lst


def streak_value_on2(lst: list[int], N: int, X: int) -> int:
    possible_arrays = create_arrays(lst, N, X)
    max_num = 0
    for inner_lst in possible_arrays:
        tmp = []
        for idx, elem in enumerate(inner_lst, start=1):
            if idx == N - 1:
                break
            tmp.append(elem)
            if elem < inner_lst[idx] :
                tmp.append(elem)
        curr_max = len(tmp)
        max_num = max_num if curr_max < max_num else curr_max
    return max_num


t = int(input())
for _ in range(t):
    N, X = tuple(map(int, input().split()))
    array = list(map(int, input().split()))
    print(streak_value_on2(array, N, X))
