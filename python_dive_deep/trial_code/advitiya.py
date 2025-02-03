# cook your dish here

orig_name = "ADVITIYA"


def get_magic_num(target_letter: str, actual_letter: str) -> int:
    """
    Summary: cyclic steps required to reach from actual_letter to target_letter

    """
    # find ascii diff
    ascii_diff = ord(actual_letter) - ord(target_letter)

    # if ascii diff is -ve
    #   return abs(ascii diff)
    # if ascii diff is +solve
    #   return 26 - ascii diff
    if ascii_diff < 0:
        return abs(ascii_diff)
    else:
        return 26 - ascii_diff


def solve(inp_str: str):
    # perform solution for one test case - return printable output
    tot_steps_req: int = 0
    for idx, tst_letter in enumerate(inp_str):
        if tst_letter.upper() != orig_name[idx]:
            tot_steps_req += get_magic_num(orig_name[idx], tst_letter)
    return tot_steps_req


def main():
    test_cases = []
    for _ in range(int(input())):
        test_cases.append(input())

    for test_case in test_cases:
        print(solve(test_case))


main()
