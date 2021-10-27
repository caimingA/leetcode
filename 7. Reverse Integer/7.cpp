class Solution 
{
public:
    int reverse(int x) 
    {
        vector<int> temp;
        
        
        while(x)
        {
            temp.push_back(x % 10);
            x = x / 10;
        }
        int n = temp.size();
        long long result = 0;
        for(int i = 0; i < n; i++)
        {
            result = result + temp[i] * pow(10, n - 1 - i);
        }
        if(result > pow(2, 31) - 1 || result <  - pow(2, 31))
        {
            return 0;
        }
        else if(x >= 0)
        {
                return result;
        }
        else
        {
                return -result;
        }
        
    }
};
