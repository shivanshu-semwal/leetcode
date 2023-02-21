class Solution:
    def discountPrices(self, s: str, d: int) -> str:
        l = s.split(' ')
        for i in range(len(l)):
            if l[i][0] == '$':
                try:
                    a = int(l[i][1:])
                    ans = a  -  a * d / 100
                    # print(ans)
                    l[i] = '$' + f'{ans:.2f}'
                except:
                    pass
        return ' '.join(l)
                
