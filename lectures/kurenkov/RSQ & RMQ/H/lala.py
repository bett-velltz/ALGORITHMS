s = input().strip()
if s == '':
    print(0)
else:
    stack = []
    closes = 0
    for i in range(len(s)):
        if s[i] == '(':
            stack.append(s[i])
        else:
            if len(stack) == 0:
                closes = closes + 1
            else:
                stack.pop()
    size = len(stack)
    if closes == size:
        print(closes)