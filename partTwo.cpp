#include <iostream>
#include <string>
#include <set>
#include <chrono>
#include <ctime>



/*
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
*/

// 0.001098s / 0.001005s 
int messageStartIndex2(std::string code){
    std::set<char> distinctChars;
    const int MAX_CODE_LENGTH = code.size();
    int iter_count = 0;
    int loop_count = 0;

    while(true){
        iter_count += 1;
        int index = -1;
        // std::cout << iter_count << std::endl;
        for(int i = iter_count;  i <= iter_count+14; i++){
            index += 1;
            distinctChars.emplace(code[i]);
        }
        if(distinctChars.size() == 14){
            std::cout << "14 distinct chars found. Index after is: " << std::to_string(index + iter_count) << std::endl;
            return index + iter_count;
        }
        loop_count += 1;
        if((iter_count + 14) >= MAX_CODE_LENGTH){
            return 55555;
        }
    }
    return 9999;
}
// 0.000997s
int messageStartIndex3(std::string code){
    const int blocksOfFourteen = code.size() - 14;

    for(int i = 0; i <= blocksOfFourteen; i++){
        std::set<char> charCheck;
        for(int j = 0; j < 14; j++){
            charCheck.emplace(code[(j+i)]);
        }
        if(charCheck.size() == 14){
            std::cout << "The Index: " << std::to_string(i+14) << std::endl;
            return (i + 14);
        }
    }
    return 0;
}

int main(){
    std::string test6 = "mjqjpqmgbljsphdztnvjfqwrcgsmlb"; // 19
    std::string test7 = "bvwbjplbgvbhsrlpgdmjqwftvncz"; // 23
    std::string test8 = "nppdvjthqldpwncqszvftbrmjlhg"; // 23
    std::string test9 = "nznrnfrfntjfmvfwmzdfjlvtqnbhcprsg"; // 29
    std::string test10 = "zcfzfwzzqfrljwzlrfnpqdbhtmscgvjw"; // 26
    std::string tests[5] = {test6, test7, test8, test9, test10};

    auto start = std::chrono::system_clock::now();
    for(auto test : tests){
        int firstMarker = messageStartIndex3(test);
    }
    auto end = std::chrono::system_clock::now();

    std::chrono::duration<double> elapsed_seconds = end-start;
    std::time_t end_time = std::chrono::system_clock::to_time_t(end);

    std::cout << "finished computation at " << std::ctime(&end_time)
              << "elapsed time: " << elapsed_seconds.count() << "s"
              << std::endl;

    return 0;
}