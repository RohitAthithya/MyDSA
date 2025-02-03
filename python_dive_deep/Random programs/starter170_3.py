def solve(N, X, HP_arr):
    AP = 0
    curr_max_hp = 0

    for monster_number in range(0, N):
        curr_max_hp = HP_arr[0]
        if AP < curr_max_hp:
            AP = curr_max_hp
        HP_arr.pop(0)
        # HP_arr = update_all_elem(in_lst=HP_arr, by_amount=X)
        if HP_arr:
            HP_arr[0] += X * (monster_number + 1)

    print(AP)


def main():
    T = int(input())
    for _ in range(T):
        N, X = map(int, input().split())
        HP_arr = list(map(int, input().split()))
        HP_arr.sort(reverse=True)
        solve(N, X, HP_arr)


main()
