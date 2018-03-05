/*
 * [412] Fizz Buzz
 *
 * https://leetcode.com/problems/fizz-buzz/description/
 *
 * algorithms
 * Easy (58.19%)
 * Total Accepted:    107.6K
 * Total Submissions: 185K
 * Testcase Example:  '1'
 *
 * Write a program that outputs the string representation of numbers from 1 to
 * n.
 * 
 * But for multiples of three it should output “Fizz” instead of the number and
 * for the multiples of five output “Buzz”. For numbers which are multiples of
 * both three and five output “FizzBuzz”.
 * 
 * Example:
 * 
 * n = 15,
 * 
 * Return:
 * [
 * ⁠   "1",
 * ⁠   "2",
 * ⁠   "Fizz",
 * ⁠   "4",
 * ⁠   "Buzz",
 * ⁠   "Fizz",
 * ⁠   "7",
 * ⁠   "8",
 * ⁠   "Fizz",
 * ⁠   "Buzz",
 * ⁠   "11",
 * ⁠   "Fizz",
 * ⁠   "13",
 * ⁠   "14",
 * ⁠   "FizzBuzz"
 * ]
 * 
 * 
 */
class Solution {
public:
    vector<string> fizzBuzz(int n) {
        int i=1;
        vector<string> temp;
        while(i<=n)
        {
            if(i%5==0 && i%3==0)
            {
                temp.push_back("FizzBuzz");
            }
            else if(i%5==0)
            {
                temp.push_back("Buzz");
            }
            else if(i%3==0)
            {
                temp.push_back("Fizz");
            }
            else
            {
                temp.push_back(std::to_string(i));
            }
            ++i;
        }
        return temp;
    }
};
