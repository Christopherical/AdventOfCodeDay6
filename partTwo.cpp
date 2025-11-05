#include <iostream>
#include <string>
#include <set>

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

int main(){
    std::string message = "nznrnfrfntjfmvfwmzdfjlvtqnbhcprsg";
    int firstMarker = messageStartIndex2(message);

    return 0;
}