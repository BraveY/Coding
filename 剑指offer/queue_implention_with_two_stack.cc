/*
https://www.nowcoder.com/practice/54275ddae22f475981afa2244dd448c6?tpId=13&tqId=11158&tPage=1&rp=1&ru=/ta/coding-interviews&qru=/ta/coding-interviews/question-ranking
 */
class Solution
{
public:
    void push(int node) {
        stack1.push(node);  // 使用第一个栈来实现队列入队
    }

    int pop() {
        int rtn;
        // 将第一个栈的元素去除压入到第二个，实现首尾互换
        while(!stack1.empty()){
            stack2.push(stack1.top());
            stack1.pop();
        }
        rtn = stack2.top();
        stack2.pop();
        // 为了能够继续实现入队操作，再将第二个队列的元素压回到第
        // 一个，等待下次操作。
        while(!stack2.empty()){
            stack1.push(stack2.top());
            stack2.pop();
        }
        return rtn;
    }

private:
    stack<int> stack1;
    stack<int> stack2;
};