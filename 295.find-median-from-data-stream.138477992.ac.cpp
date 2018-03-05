/*
 * [295] Find Median from Data Stream
 *
 * https://leetcode.com/problems/find-median-from-data-stream/description/
 *
 * algorithms
 * Hard (29.14%)
 * Total Accepted:    56.8K
 * Total Submissions: 194.8K
 * Testcase Example:  '["MedianFinder","addNum","addNum","findMedian","addNum","findMedian"]\n[[],[1],[2],[],[3],[]]'
 *
 * Median is the middle value in an ordered integer list. If the size of the
 * list is even, there is no middle value. So the median is the mean of the two
 * middle value.
 * Examples: 
 * [2,3,4] , the median is 3
 * [2,3], the median is (2 + 3) / 2 = 2.5 
 * 
 * 
 * Design a data structure that supports the following two operations:
 * 
 * 
 * void addNum(int num) - Add a integer number from the data stream to the data
 * structure.
 * double findMedian() - Return the median of all elements so far.
 * 
 * 
 * 
 * For example:
 * 
 * addNum(1)
 * addNum(2)
 * findMedian() -> 1.5
 * addNum(3) 
 * findMedian() -> 2
 * 
 * 
 * Credits:Special thanks to @Louis1992 for adding this problem and creating
 * all test cases.
 */
class MedianFinder {
    int large_size,small_size;
    priority_queue<int> large,small;
public:
    /** initialize your data structure here. */
    MedianFinder() {
        large_size=0;
        small_size=0;
    }
    
    void addNum(int num) {
        small.push(num);
        large.push(-1*small.top());
        large_size++;
        small.pop();
        if(small_size< large_size)
        {
            small.push(-1*large.top());
            small_size++;
            large.pop();
            large_size--;
        }
    }
    
    double findMedian() {
        return (small_size>large_size)?small.top():(small.top()-large.top())/2.0;
    }
};

/**
 * Your MedianFinder object will be instantiated and called as such:
 * MedianFinder obj = new MedianFinder();
 * obj.addNum(num);
 * double param_2 = obj.findMedian();
 */
