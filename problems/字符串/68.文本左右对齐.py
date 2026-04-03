#!/usr/bin/env python3
"""
68. 文本左右对齐
"""


def full_justify(words: list[str], max_width: int) -> list[str]:
    result = []
    i = 0
    while i < len(words):
        line_words = [words[i]]
        line_len = len(words[i])
        j = i + 1
        while j < len(words) and line_len + 1 + len(words[j]) <= max_width:
            line_len += 1 + len(words[j])
            line_words.append(words[j])
            j += 1

        if j - i == 1:
            # 只有一个词，左对齐
            result.append(line_words[0] + ' ' * (max_width - len(line_words[0])))
        else:
            # 多个词，左右对齐
            spaces = max_width - line_len + (j - i - 1)
            extra = spaces % (j - i - 1)
            base = spaces // (j - i - 1)
            line = line_words[0]
            for k in range(1, j - i):
                line += ' ' * (base + (1 if k <= extra else 0)) + line_words[k]
            result.append(line)
        i = j
    return result


if __name__ == "__main__":
    # 测试用例
    words = ["This", "is", "an", "example", "of", "text", "justification."]
    for line in full_justify(words, 16):
        print(f"'{line}'")

    print("---")
    words2 = ["What", "must", "be", "acknowledgment", "shall", "be"]
    for line in full_justify(words2, 16):
        print(f"'{line}'")
