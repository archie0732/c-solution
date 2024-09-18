# KMP 算法

[yt 影片教學](https://youtu.be/af1oqpnH1vA?si=oPQHbhhfxDxdvMAR)

- 簡單來說就是避免回朔(主串)的一套算法，透過`next`來知道只要跳過`子串`的幾個字可以無縫的繼續，可以達成主串不回退

```md
key word: ABC

text: ABABC
        -- 在到AB'A'時 A!= C ，這時可以透過`next`跳過子串的A直接比較B 
```

## 重點!! 當前子陣列與主陣列不品配時去將next(可以配對的陣列)長度回放，找相同

## next 算法

- 算出子串的每個前綴長度

```py
def buildNext(s: str):
    next = [0]
    prefixLen = 0
    i = 1

    while i < len(s):
        if s[prefixLen] == s[i]:
            prefixLen += 1
            next.append(prefixLen)
            i += 1
        else:
            prefixLen = next[prefixLen - 1]
            if prefixLen == 0:
                next.append(0)
                i += 1
    return next
```

[完整code]('./KMP.md') 作者:archie0732
