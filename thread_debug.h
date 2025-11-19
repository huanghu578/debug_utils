#ifndef DEBUG_UTILS_H
#define DEBUG_UTILS_H
typedef enum {
    DEBUG_LEVEL_NONE,
    DEBUG_LEVEL_DEBUG,      //用于追踪代码执行流程、变量状态等
    DEBUG_LEVEL_INFO,       //记录程序正常运行的关键事件
    DEBUG_LEVEL_WARN,       //提示潜在问题（如资源不足、非致命异常），不影响当前操作。
    DEBUG_LEVEL_ERROR,      //记录已发生错误（如功能部分失效），程序仍可继续运行。
    DEBUG_LEVEL_CRITICAL,   //严重错误（如系统崩溃、数据丢失），需立即处理。
    DEBUG_LEVEL_ALL
} debug_level_t;

// 全局调试级别设置
#ifndef CURRENT_DEBUG_LEVEL
#define CURRENT_DEBUG_LEVEL DEBUG_LEVEL_ALL
#endif

#define ENABLE_DEBUG 1  //1:on; 0:off

#if ENABLE_DEBUG
    // 带级别的调试输出宏
    #define DEBUG_DEBUG(fmt, ...) \
        do { \
            if (CURRENT_DEBUG_LEVEL >= DEBUG_LEVEL_DEBUG) \
                printf("[DEBUG][%s:%d] " fmt, __FILE__, __LINE__, ##__VA_ARGS__); \
        } while(0)

    #define DEBUG_INFO(fmt, ...) \
        do { \
            if (CURRENT_DEBUG_LEVEL >= DEBUG_LEVEL_INFO) \
                printf("[INFO][%s:%d] " fmt, __FILE__, __LINE__, ##__VA_ARGS__); \
        } while(0)

    #define DEBUG_WARN(fmt, ...) \
        do { \
            if (CURRENT_DEBUG_LEVEL >= DEBUG_LEVEL_WARN) \
                printf("[WARN][%s:%d] " fmt, __FILE__, __LINE__, ##__VA_ARGS__); \
        } while(0)

    #define DEBUG_ERROR(fmt, ...) \
        do { \
            if (CURRENT_DEBUG_LEVEL >= DEBUG_LEVEL_ERROR) \
                printf("[ERROR][%s:%d] " fmt, __FILE__, __LINE__, ##__VA_ARGS__); \
        } while(0)

    #define DEBUG_CRITICAL(fmt, ...) \
        do { \
            if (CURRENT_DEBUG_LEVEL >= DEBUG_LEVEL_CRITICAL) \
                printf("[CRITICAL][%s:%d] " fmt, __FILE__, __LINE__, ##__VA_ARGS__); \
        } while(0)
    // 简化的调试宏（不带级别）
    #define DEBUG_PRINT(fmt, ...) DEBUG_INFO(fmt, ##__VA_ARGS__)
#else    
    #define DEBUG_DEBUG(fmt, ...) 
    #define DEBUG_INFO(fmt, ...) 
    #define DEBUG_WARN(fmt, ...) 
    #define DEBUG_ERROR(fmt, ...) 
    #define DEBUG_CRITICAL(fmt, ...)     
    #define DEBUG_PRINT(fmt, ...)     
#endif
/*
此文件只能用在普通线程里debug输出，不能用在中断里。
1.可选定义调试级别，有效值见debug_level_t枚举，默认DEBUG_LEVEL_ALL。(mbed里建议用内置的debug API。)
在编译时设置调试级别（在编译器选项中）
    -D CURRENT_DEBUG_LEVEL=XXX
或者直接定义 #define CURRENT_DEBUG_LEVEL XXX
    */
#endif // DEBUG_UTILS_H