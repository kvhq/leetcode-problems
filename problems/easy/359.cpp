// Number: 359
// Name: Logger Rate Limiter
// Tags: hash table

class Logger {
public:
    /** Initialize your data structure here. */
    Logger() {
    }
    
    /** Returns true if the message should be printed in the given timestamp, otherwise returns false.
        If this method returns false, the message will not be printed.
        The timestamp is in seconds granularity. */
    bool shouldPrintMessage(int timestamp, string message) {
        if (data.count(message)) {
            if (timestamp - data[message] < 10) return false;
            else {
                data[message] = timestamp;
                return true;
            }
        }
        else data[message] = timestamp;
        return true;
    }
    
private:
    unordered_map<string, int> data;
};

