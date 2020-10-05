class Solution:
    def bitwiseComplement(self, N: int) -> int:
        if N==0 :
            return 1
        else:
            num_bits = (log(N)/log(2))+1
            max_num = (2**int(num_bits))-1
            complement = max_num - N
            return complement
