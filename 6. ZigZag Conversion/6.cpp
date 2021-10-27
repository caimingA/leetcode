class Solution {
public:
    string convert(string s, int numRows) {
        if(numRows == 1)
            return s;

        string result = "";
        int SLenght = s.size();
        if(numRows == 2){
            for(int i = 0; i < SLenght; i += 2)
                result += s[i];
            for(int i = 1; i < SLenght; i += 2)
                result += s[i];
            return result;
        }
        
        int oneSet = numRows + (numRows - 2); // 一个组里的数量
        int numSet = SLenght / oneSet; // 确定有多少组
        int b = SLenght % oneSet; // 确定这个是在一组里的第几个

        int numCols = 0;
        if(b <= numRows)
            numCols = numSet * (numRows - 1) + 1;
        else
            numCols = numSet * (numRows - 1) + 1 + (b - numRows);
        
        // 定义要用的数组
        // char M[numRows][numCols] = {'\0'};
        char** M = new char* [numRows];
        for(int i = 0; i < numRows; i++){
            M[i] = new char[numCols];
        }
        for(int i = 0; i < numRows; i++){
            for(int j = 0; j < numCols; j++){
                M[i][j] = '\0';               
            }
        }

        int count = 0;
        int i = 0;
        int j = 0;
        cout << numRows << ", " << numCols << ", "<< oneSet << endl;
        while(count != SLenght){
            cout << "count=" << s[count] << " i=" << i << " j=" << j << endl;
            int a = count % oneSet;
            if(a < numRows){
                cout << a;
                M[i][j] = s[count];
                i++;
            }else if(a == numRows){
                cout << "进来了" << endl;
                i -= 2; j++;
                cout << "count=" << s[count] << " i=" << i << " j=" << j << endl;
                M[i][j] = s[count];

                i--; j++;
            }else{
                cout << "b";
                M[i][j] = s[count];
                i--; j++;
            }
            count++;
        }

        for(int i = 0; i < numRows; i++){
            for(int j = 0; j < numCols; j++){
                if(M[i][j] != '\0'){
                    result += M[i][j];
                    cout << M[i][j];
                }
            }
            // cout << endl;
        }
        // for(int i = 0; i < numRows; i++){
        //     for(int j = 0; j < numCols; j++){
        //         if(M[i][j] != '\0'){
        //             cout << M[i][j];
        //         }else{
        //             cout << '+';
        //         }
                
        //     }
        //     cout << endl;
        // }
        return result;
    }
};