def main():
    n = int(input())
    heights = list(map(int, input().split()))

    energy = [[0, 0], [abs(heights[1] - heights[0]), 1]]
    steps = []

    for i in range(2, n):
        small_jump = abs(heights[i] - heights[i - 1]) + energy[i - 1][0]
        big_jump = 3 * abs(heights[i] - heights[i - 2]) + energy[i - 2][0]
        if small_jump < big_jump:
            energy.append([small_jump, 1])
        else:
            energy.append([big_jump, 2])

    i = n - 1
    while i > 0:
        steps.append(i + 1)
        i -= energy[i][1]
    steps.append(1)
    steps.reverse()

    print(energy[-1][0])
    print(len(steps))
    print(*steps)


main()
