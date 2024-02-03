class Solution {
public:
    int totalMoney(int n) {
        int weeks = n / 7;

        // complete weeks
        int tot = 28 * (weeks) + ((weeks-1) * weeks) / 2 * 7;
    
        // values in last week
        int remainDays = n % 7;
        for (int i = 1; i <= remainDays; i++)
            tot += weeks + i;

        return tot;
    }
};