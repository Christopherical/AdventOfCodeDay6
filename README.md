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
