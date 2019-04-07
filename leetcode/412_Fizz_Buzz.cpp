//写一个程序，输出从 1 到 n 数字的字符串表示。
//
//1. 如果 n 是3的倍数，输出“Fizz”；
//
//2. 如果 n 是5的倍数，输出“Buzz”；
//
//3.如果 n 同时是3和5的倍数，输出 “FizzBuzz”。
//
//示例：
//
//n = 15,
//
// 返回:
//[
//"1",
//"2",
//"Fizz",
//"4",
//"Buzz",
//"Fizz",
//"7",
//"8",
//"Fizz",
//"Buzz",
//"11",
//"Fizz",
//"13",
//"14",
//"FizzBuzz"
//]

class Solution {
public:
    vector<string> fizzBuzz(int n) {
        vector<string> ret;
        if (n<1) { return ret; }

        for (int i=1; i<=n; ++i) {
            if (i%(3*5)==0) {
                ret.push_back("FizzBuzz");
            } else if (i%3==0) {
                ret.push_back("Fizz");
            } else if (i%5==0) {
                ret.push_back("Buzz");
            } else {
                ret.push_back(to_string(i));
            }
        }
        return ret;
    }
};
