class Solution:
    # @param x : integer
    # @param n : integer
    # @param d : integer
    # @return an integer
    def pow(self, x, n, d):
        res = 1
        x = x % d 
        if(x==0 and n==0):
            return 0
        while (n > 0) :
            if ((n & 1) == 1) :
                res = (res * x) % d
            n = n >> 1
            x = (x * x) % d
     
        return res

