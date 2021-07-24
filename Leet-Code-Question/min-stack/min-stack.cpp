class MinStack {
public:

stack<int > s;
stack<int > s2;

MinStack() { }

void push(int val) {
    if(s.empty()){
        s.push(val);
        s2.push(val);
       }    
    else{
        s.push(val);
        s2.push(min(s2.top(),val));
    }
        

}

void pop() { s.pop();
           s2.pop();}

int top() { return s.top(); }

int getMin() { return s2.top();}
};