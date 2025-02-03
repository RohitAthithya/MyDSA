from heapq import heapify, heappop, heappush


def solve(N, X, HP_arr):
    max_heap = [-hp for hp in HP_arr]
    heapify(max_heap)

    AP = 0
    global_offset = 0

    for _ in range(N):
        curr_max_hp = -heappop(max_heap)
        AP = max(AP, curr_max_hp + global_offset)
        global_offset += X
        if (
            curr_max_hp + global_offset > 0
        ):
            heappush(max_heap, -(curr_max_hp - X))

    print(AP)


def main():
    T = int(input())
    for _ in range(T):
        N, X = map(int, input().split())
        HP_arr = list(map(int, input().split()))
        solve(N, X, HP_arr)


main()
