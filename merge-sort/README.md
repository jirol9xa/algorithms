# Merge sort

--------------------------------------
## The main aim: `overtake` std::sort for std::list<int> 

--------------------------------------


### First naive implementation using a lot of temp objects:

Note: You can see all test conditions in main.cpp file.
Here in table the average results are given. 

|           | My merge-sort | std::list<int>::sort |
| --------- | ------------- | -------------------- |
|cpu-cycles |  5393735      |  2564213             |
| percents  |  100%         |        47.5%         |