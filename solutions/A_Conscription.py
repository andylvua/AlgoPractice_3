def main():
    n, g, h = map(int, input().split())
    strengths = [tuple(map(int, input().split())) for _ in range(n)]

    if g + h > n:
        print(-1)
        return

    grunts = []
    headhunters = []

    for strength in strengths:
        if strength[0] > strength[1]:
            grunts.append(strength)
        else:
            headhunters.append(strength)

    if len(grunts) < g:
        headhunters.sort(key=lambda x: x[0] - x[1], reverse=True)
        needed = g - len(grunts)
        grunts += headhunters[:needed]
        headhunters = headhunters[needed:]
    elif len(headhunters) < h:
        grunts.sort(key=lambda x: x[1] - x[0], reverse=True)
        needed = h - len(headhunters)
        headhunters += grunts[:needed]
        grunts = grunts[needed:]

    max_strength = sum(strength[0] for strength in grunts) + sum(strength[1] for strength in headhunters)

    print(max_strength)


main()
