class Solution {
public:
    bool isValid(string s) {
        stack<char> brackets;
        for(char &c : s){
            if(brackets.empty() || c == '(' || c == '[' || c == '{'){
                brackets.push(c);
            }else if(c == ')'){
                if(brackets.top() == '('){
                    brackets.pop();
                }else{
                    brackets.push(c);
                }
            }else if(c == ']'){
                if(brackets.top() == '['){
                    brackets.pop();
                }else{
                    brackets.push(c);
                }
            }else{
                if(brackets.top() == '{'){
                    brackets.pop();
                }else{
                    brackets.push(c);
                }
            }
        }
        if(!brackets.empty()){
            return false;
        }
        return true;
    }
};