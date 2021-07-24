class Solution:
    def bin2dec(self,a):
        val = 0
        for i in range(len(a)):
            num = (int)(a[len(a)-i-1])
            val+=  num*(2**i)
        return val
    def dec2bin(self,div):
        carry=[]
        if div==0:
              return "0"
        while div>0:
            carry.append(str(div%2))
            div = div//2
        return "".join(carry[::-1])
    def addBinary(self, a: str, b: str) -> str:
        sumdec = self.bin2dec(a) + self.bin2dec(b)
        return self.dec2bin(sumdec)