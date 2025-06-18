#define _CRT_SECURE_NO_WARNINGS .1 
#ifndef COMM_H
#define COMM_H
//保护头文件，防止重复包含
#define MAX 100

// 旅游景点信息结构体
typedef struct {
    char name[20];         // 景点名称
    char location[50];     // 景点位置
    char description[200]; // 景点简介
    float price;           // 门票价格
} Sight;

// 全局变量声明
extern Sight sights[MAX];  // 景点信息数组
extern int count;          // 已存储景点数量

// 功能函数声明
void loadFromFile(const char* filename);   // 从文件加载数据
void saveToFile(const char* filename);     // 保存数据到文件
void addSight();                           // 添加景点
void showSights();                         // 显示全部景点
void searchSight();                        // 按名称查找景点
void modifySight();                        // 修改景点信息
void deleteSight();                        // 删除景点信息

#endif