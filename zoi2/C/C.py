
a=1

l=""
"""
s="cacabac"
ans = [0, 1,2,1,2, 3, 2,3]
"""
"""
s="abcccbabccba"
ans=[0,1,2,3,3,3,2,1,2,3,3,2,3]
"""

"""incorrect
s="abababcbab"
ans=[0,1,2,1,2,3,2,3,2]
"""
""" correct
s="abcaac"
ans=[0,1,2,3,4,4,3]
s="abbaabb"
ans=[0, 1, 2, 2, 1, 2, 3,2]
"""
#aba babc bab
#ans=[0,1, 2, 1, 2, 1, 2, 3, 2, 3, 2, 3, 4, 3, 4, 3, 4, 3, 4, 4, 5, 6, 7, 7, 6, 7, 8, 7, 8, 8, 8, 9, 9, 9, 10, 11]

#s="abababcbabcacacbabbcabbabcbabacabca"
#ababa bcb abcacacbabbcabbabcbabacabca
#ababa bcb a b
#abababc bab
#abababcbab
#aba bcb ab
#a baab
#aba baab
#ababcbab
#aabba
"""incorrect
ans=[0,1,1,2,2,2]
s="aabba"

"""
"""
a
b <- row

a+b | 
"""
res=[""]*30
row = -1

for i in range(1, len(ans)):
    d = (ans[i]-ans[i-1])  # difference
    if d == 1:
        row +=1
        res[row] = s[i-1] 
    elif d == 0:
        res[row] += s[i-1]
    elif d == -1:
        row -= 1
        res[row] += res[row+1]
        """
        s = 'aba', r
        a
        b
        """
        res[row+1] = ""  # clear next row
        res[row] += s[i-1]
    print(d, res, ans[i])
