class MinStack {
public:

    // int m_min = MIN_INT;
    stack<int> m_stk;
    stack<int> m_minstk;

    MinStack() {
        
    }
    
    void push(int val) {
        if(!m_stk.empty() && val>m_minstk.top())
        {
            m_minstk.push(m_minstk.top());
        }
        else
        {
            m_minstk.push(val);
        }
        m_stk.push(val);
    }
    
    void pop() {
        m_stk.pop();
        m_minstk.pop();
    }
    
    int top() {
        return m_stk.top();
    }
    
    int getMin() {
        return m_minstk.top();
    }
};
