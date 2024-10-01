def count(plate_nr, mask):
    if plate_nr == n:
        if '.' in mask:
            return 1
        else:
            return 0

    total_count = 0
    for offset in range(m):
        new_mask = ''
        for i in range(m):
            if mask[i] == '.' and plates[plate_nr][(i+offset)%m] == '.':
                new_mask += '.'
            else:
                new_mask += '#'
        total_count += count(plate_nr+1, new_mask)

    return total_count


n, m = map(int, input().split())
plates = [input() for _ in range(n)]

print(count(0, '.' * m))
