def main():
    ships, bases = [int(x) for x in input().split()]
    ship = [int(x) for x in input().split()]
    base = []
    for i in range(bases):
        base.append([int(x) for x in input().split()]);
    base = sorted(base, key=lambda x:x[0])
    for x in base:
        print ' '.join(x[0])
        # print(f'{x[0]}, {x[1]}')


if __name__ == '__main__':
    main()
