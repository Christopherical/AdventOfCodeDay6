# AdventOfCodeDay6
Christmas coding challenges for optimization.

https://observablehq.com/@mbostock/advent-of-code-2022-day-6
https://www.youtube.com/watch?v=U16RnpV48KQ

Part 2
Your device's communication system is correctly detecting packets, but still isn't working.
It looks like it also needs to look for messages.
A start - of - message marker is just like a start - of - packet marker, 
except it consists of 14 distinct characters rather than 4.

Here are the first positions of start - of - message markers for all of the above examples :
test6 = `mjqjpqmgbljsphdztnvjfqwrcgsmlb` // first marker after character 19
test7 = `bvwbjplbgvbhsrlpgdmjqwftvncz` // first marker after character 23
test8 = `nppdvjthqldpwncqszvftbrmjlhg` // first marker after character 23
test9 = `nznrnfrfntjfmvfwmzdfjlvtqnbhcprsg` // first marker after character 29
test10 = `zcfzfwzzqfrljwzlrfnpqdbhtmscgvjw` // first marker after character 26
How many characters need to be processed before the first start - of - message marker is detected ?

class Timer
{
public:
    Timer()
    {
        m_StartTimePoint = std::chrono::high_resolution_clock::now();
    }
    ~Timer()
    {
        Stop();
    }
    void Stop(){
        auto endTimepoint = std::chrono::high_resolution_clock::now();

        auto start = std::chrono::time_point_cast<std::chrono::nanoseconds>(m_StartTimePoint).time_since_epoch().count();
        auto end = std::chrono::time_point_cast<std::chrono::nanoseconds>(endTimepoint).time_since_epoch().count();

        auto duration = end - start;
        double ms = duration * 0.001;

        std::cout << duration << "na (" << ms << "us)\n";
    }
private:
    std::chrono::time_point<std::chrono::high_resolution_clock> m_StartTimePoint;
};
struct Vector2
    {
        float x, y;
    };
