def compress_string(word):
    comp = ""
    i = 0
    while i < len(word):
        char = word[i]
        count = 1
        while i + 1 < len(word) and word[i + 1] == char and count < 9:
            count += 1
            i += 1
        comp += f"{count}{char}"
        i += 1
    return comp
