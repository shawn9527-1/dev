#include <stdio.h>

#define LOG(fmt, args...) printf("[%s:%s:%d] " fmt "\n", __FILE__, __func__, __LINE__, ##args)
