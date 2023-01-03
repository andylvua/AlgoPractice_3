def main():
    input()
    trees = sorted(list(map(int, input().split())), reverse=True)

    result = 0

    for day, tree in enumerate(trees):
        result = max(result, tree+1+day)

    print(result + 1)


main()
