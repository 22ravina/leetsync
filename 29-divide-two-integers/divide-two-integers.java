class Solution {
    public int divide(int dividend, int divisor) {
       if (dividend == Integer.MIN_VALUE && divisor == -1) {
            return Integer.MAX_VALUE;
        }
        if (dividend == Integer.MIN_VALUE && divisor == 1) {
            return Integer.MIN_VALUE;
        }
        
        // Determine if the result should be negative
        boolean isNegative = (dividend < 0) ^ (divisor < 0);
        
        // Convert dividend and divisor to positive long values to avoid overflow
        long dividendd = Math.abs((long) dividend);
        long divisorr = Math.abs((long) divisor);
        
        int quotient = 0;
        
        // Use bitwise shifting to speed up the subtraction
        while (dividendd >= divisorr) {
            long tempDivisor = divisorr;
            int multiple = 1;
            
            // Keep doubling the divisor until it exceeds the dividend
            while (dividendd >= (tempDivisor << 1)) {
                tempDivisor <<= 1;  // Double the divisor
                multiple <<= 1;     // Double the multiple
            }
            
            dividendd -= tempDivisor;  // Subtract the largest possible multiple
            quotient += multiple;      // Add the multiple to the quotient
        }
        
        // Apply the correct sign to the result
        return isNegative ? -quotient : quotient;
    }
}
