class Solution:
    def multiply(self, num1: str, num2: str) -> str:
        n3 = int(num1)
        n4 = int(num2)
        n5 = n3 * n4
        n6 = str(n5)
        return n6

sol = Solution()
print(sol.multiply("123", "456"))  # Output: "56088"
