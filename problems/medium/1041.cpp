// Number: 1041
// Name: Robot Bounded In Circle
// Tags: Math

class Solution {
public:
    bool isRobotBounded(string instructions) {
        // NORTH = 0
        // WEST = 1
        // SOUTH = 2
        // EAST = 3
        int state = 0;
        int x = 0;
        int y = 0;
        for (const auto& command : instructions) {
            if (command == 'G') {
                if (state == 0) y++;
                else if (state == 2) y--;
                else if (state == 1) x--;
                else if (state == 3) x++;
            } else if (command == 'L') {
                state = (state + 1) % 4;
            } else state = (state + 3) % 4;
        }
        if (x == 0 && y == 0) return true;
        if (state != 0) return true;
        return false;
    }
};

