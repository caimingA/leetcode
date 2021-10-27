class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int size = s.size();
        if(size == 0){
            return 0;
        }
        map<char, int> mapWords;
        map<char, int>::iterator iter;
        int maxLen = 1;
        int tempLen = 0;
        int start = -1;
        // mapWords.insert(pair<char, int>(s[0], 0));
        for(int i = 0; i < size; i++){
            iter = mapWords.find(s[i]);
            cout << s[i] << "->" << start << "->";
            if(iter == mapWords.end()){
                tempLen = i - start;
                maxLen = tempLen > maxLen ? tempLen : maxLen;
                mapWords.insert(pair<char, int>(s[i], i));
            }else{
                int index = iter -> second;
                cout << index << "->";
                if(index >= start){
                    tempLen = i - index;
                    maxLen = tempLen > maxLen ? tempLen : maxLen;
                    start = index;
                    mapWords[s[i]] = i;                    
                }else{
                    tempLen = i - start;
                    cout << "["<<tempLen << "]";
                    maxLen = tempLen > maxLen ? tempLen : maxLen;
                    mapWords[s[i]] = i;
                }                
            }
            cout << maxLen;
            cout << endl;    
        }
        return maxLen;
    }
};