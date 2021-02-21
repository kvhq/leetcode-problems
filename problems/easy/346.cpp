// Number: 346
// Name: Moving Average from Data Stream
// Tags: Queue, array

class MovingAverage {
public:
    /** Initialize your data structure here. */
    MovingAverage(int size) {
        d_size = (size_t)size;
        d_sum = 0;
    }
    
    double next(int val) {
        if (d_data.size() < d_size) {
            d_data.push(val);
            d_sum += val;
            return (double) d_sum / d_data.size();
        }
        d_sum -= d_data.front();
        d_data.pop();
        d_sum += val;
        d_data.push(val);
        return (double) d_sum / d_size;
    }
private:
    size_t d_size;
    queue<int> d_data;
    int d_sum;
};

