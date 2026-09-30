class MinStack {
public:


    stack<int> st;
    stack<int> min_term;
    MinStack() {
    }
    
    void push(int val) {

        st.push(val);
        if(min_term.empty())
        {
            min_term.push(val);
        }
        else
        {
            min_term.push(min(val, min_term.top()));
        }
    }
    
    void pop() {
        st.pop();
        min_term.pop();
    }
    
    int top() {
        return st.top();
    }
    
    int getMin() {
        return min_term.top();
    }
};
