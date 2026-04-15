class Solution {
    
        public int divide(int dividend, int divisor) {
    
    if (dividend == Integer.MIN_VALUE && divisor == -1) {
        return Integer.MAX_VALUE; 
    }


    boolean negative = (dividend > 0) ^ (divisor > 0);
    
    long absDividend = Math.abs((long) dividend);
    long absDivisor = Math.abs((long) divisor);
    int quotient = 0;

    while (absDividend >= absDivisor) {
        absDividend -= absDivisor;
        quotient++;
    }

    return negative ? -quotient : quotient;
}

        
    
}