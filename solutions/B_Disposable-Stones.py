def main():
    w, l = map(int, input().split())
    stones = list(map(int, input().split()))

    jumps = [0]
    jumps.extend(jumps[-1] + stone for stone in stones)

    result = jumps[l]

    for i in range(l + 1, w):
        result = min(result, jumps[i] - jumps[i - l])

    print(result)


main()
