class Solution {
public:
    bool isValid(string s) {
        
        stack<char> st;

        for(char c:s)
        {
            if(c == '(' || c == '{' || c == '[')
            {
                st.push(c);
            }
            else
            {
                switch(c)
                {
                    case ')':
                        if(!st.empty() && st.top() == '(')
                            st.pop();
                        else
                            st.push(c);
                        break;
                    
                    case '}':
                        if(!st.empty() && st.top() == '{')
                            st.pop();
                        else
                            st.push(c);
                        break;
                    
                    case ']':
                        if(!st.empty() && st.top() == '[')
                            st.pop();
                        else
                            st.push(c);
                        break;
                    default :
                        return false;
                        break;
                }
            }
        }

        if(st.empty())
            return true;
        
        return false;
    }
};
