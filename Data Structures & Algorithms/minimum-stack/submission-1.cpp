class MinStack {
public:
    MinStack() {
        
    }
    
    void push(int val) {
        data.push(val);

        if (minVals.empty() || val <= minVals.top())
            minVals.push(val);
    }
    
    void pop() {
        if (data.size() == 0)
            return;

        if (data.top() == minVals.top())
            minVals.pop();

        data.pop();
    }
    
    int top() {
        if (data.size() > 0)
            return data.top();

        return -1;
    }
    
    int getMin() {
        if (data.size() > 0)
            return minVals.top();

        return -1;
    }

private:
    stack<int> data;
    stack<int> minVals;
};
