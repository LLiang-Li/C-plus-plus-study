#ifndef _MY_LOG_
#define _MY_LOG_
  #include<iostream>
  #include<vector>
  #include<string>
  #include<map>
  #include<unordered_map>
  #define LOG_TAG(TAG, FORMAT, ...) ::fprintf(stdout, "[" TAG "](%s:%s:%d): \n" FORMAT "\r\n", __TIME__, __FILE__, __LINE__, ##__VA_ARGS__)
  #define LOG(FORMAT, ...) ::fprintf(stdout, FORMAT , ##__VA_ARGS__)
  #define LOG_INFO(FORMAT, ...) LOG_TAG("INFO", FORMAT, ##__VA_ARGS__)
#endif