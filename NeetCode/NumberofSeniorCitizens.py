class Solution:
    def countSeniors(self, details: List[str]) -> int:
        age = 0
        c = 0
        i_gender = 10
        for i in details:
            age = i[i_gender + 1: i_gender + 3]
            age = int(age)
            if age > 60:
                c += 1
        return c
