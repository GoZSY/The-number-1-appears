/***********************************************************************
使用递归的思想实现，对给出的数字进行分段处理，这里以21345进行分析
首先将21345分成两段，1~1345；1346~21345

对于最高位来说，当最高位为大于1的数时。如2，那么
10000~19999所有的数字均含有数字1，那么数字1出现了10^4次，
当最高位为1时，1出现的次数取决于后边的四位数字，次数为1345+1次

这里最高位的1出现次数统计完成后，对于后边的后四位，1出现的次数可以固定其中一位为1，
其余的三位从0到9十个数中任选，总共有2*4*3^10,2为最高位的数字，4为除最高位外其余位的
位数，3为除确定为1的位以外的位数

接下来递归计算1~1345之间1的个数
************************************************************************/
class Solution {
public:
    int NumberOf1Between1AndN_Solution(int n)
    {
    	if(n < 0)
            return 0;
        char str[50];
        sprintf(str,"%d",n);
        return NumberOf1(str);
    }
private:
    int NumberOf1(char* str)
    {
        if(str == NULL || *str < '0' || *str > '9' || *str == '/0')
            return 0;
        int length = static_cast<int>(strlen(str));
        int first = *str - '0';
        if(length == 1 && first == 0)
            return 0;
        if(length == 1 && first > 0)
            return 1;
        
        //以21345为例，先求最高位为1的时候的数字个数
        int theFirst = 0;
        if(first > 1)
            theFirst = powOf10(length-1);
        else if(first == 1)
        {
            theFirst = atoi(str+1) + 1;
        }
        int theOther = 0;
        //1346~21345的其余四位为1的个数
        theOther = first*powOf10(length-2)*(length - 1);
        //1~1345
        int thelast = NumberOf1(str+1);
        return theFirst + theOther + thelast;
            
    }
    int powOf10(int n)
    {
        int result = 1;
        for(int i = 0; i < n; ++i)
            result *= 10;
        return result;
    }
};
