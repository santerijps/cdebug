#ifndef CDEBUG_H

  #define CDEBUG_H

  #ifndef _INC_STDIO
    #include <stdio.h>
  #endif

  #ifndef _TIME_H_
    #include <time.h>
  #endif

  #define debugf(...)\
    fprintf(stderr, "[%s :: ln:%d :: %s] ", __FILE__, __LINE__, __FUNCTION__);\
    fprintf(stderr, __VA_ARGS__)

  #define logf(t, ...){\
    time_t rt = time(NULL);\
    struct tm *lt = localtime(&rt);\
    fprintf(stderr, "[%d-%02d-%02d %02d:%02d:%02d %s - %s] ",\
      lt->tm_year + 1900, lt->tm_mon + 1, lt->tm_mday, lt->tm_hour, lt->tm_min, lt->tm_sec, __FUNCTION__, t);\
    fprintf(stderr, __VA_ARGS__);}

  #define infof(...) logf("INFO", __VA_ARGS__)
  #define warnf(...) logf("WARN", __VA_ARGS__)
  #define errorf(...) logf("ERROR", __VA_ARGS__)

#endif