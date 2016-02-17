class Solution {
public:
    /*用空间换时间*/
    int nthUglyNumber(int n) {
        vector<int> num(n,0);
        int index2=0,index3=0,index5=0;
        int Currindex = 1;
        num[0] = 1;     //第一个丑数
        while(Currindex < n)
        {
            num[Currindex] = Min(num[index2]*2,num[index3]*3,num[index5]*5);
            while(num[index2]*2 <= num[Currindex]) //第一个大于最大的丑数的数
                index2++;
            while(num[index3]*3 <= num[Currindex]) //第一个大于最大的丑数的数
                index3++;
            while(num[index5]*5 <= num[Currindex]) //第一个大于最大的丑数的数
                index5++;
            Currindex++;
        }
        return num[n-1];
    }
    
    int Min(int a,int b,int c)
    {
        int m = a;
        if(b <= m)
            m = b;
        if(c <= m )
            m = c;
        return m;
    }
};