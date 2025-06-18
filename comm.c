#define _CRT_SECURE_NO_WARNINGS .1 
#include <stdio.h>
#include <string.h>
#include "comm.h"

// 全局变量定义
Sight sights[MAX];
int count = 0;

// 从指定文件加载景点数据
void loadFromFile(const char* filename) {
    FILE* fp = fopen(filename, "r");
    if (fp == NULL) {
        printf("无法打开文件 %s\n", filename);
        count = 0;
        return;
    }
	//读取文件内容到sights数组，count为实际读取的景点数量
    while (count < MAX && fscanf(fp, "%19s %49s %199s %f", sights[count].name, sights[count].location, sights[count].description, &sights[count].price) == 4) {
        count++;
    }
    fclose(fp);
}

// 将景点数据保存到指定文件
void saveToFile(const char* filename) {
    FILE* fp = fopen(filename, "w");
    if (fp == NULL) return;
    //将sights数组中的数据写入文件
	for (int i = 0; i < count; i++) {
        fprintf(fp, "%s\n%s\n%s\n%.2f\n\n", sights[i].name, sights[i].location, sights[i].description, sights[i].price);
    }
    fclose(fp);
}

// 添加新景点信息（不要加入特殊符号）
void addSight() {
    if (count >= MAX) {
        printf("已达最大存储容量！\n");
        return;
    }
    printf("景点名称：");
    scanf("%s", sights[count].name);
    printf("景点位置：");
    scanf("%s", sights[count].location);
    printf("简介：");                    
    scanf("%s", sights[count].description);
    printf("门票价格：");
    scanf("%f", &sights[count].price);
    count++;
    printf("添加成功！\n");
}

// 显示所有景点信息
void showSights() {
    if (count == 0) {
        printf("暂无景点信息。\n");
        return;
    }
    //printf("编号\t名称\t\t\t位置\t\t\t价格\t\t简介\n");
    for (int i = 0; i < count; i++) {
        printf("编号：%d\n名称：%s\n位置：%s\n价格：%.2f\n简介：%s\n\n", i + 1, sights[i].name, sights[i].location, sights[i].price, sights[i].description);
    }
}

// 按名称查找景点信息
void searchSight() {
    char name[20];
    printf("输入要查找的景点名称：");
    scanf("%s", name);
    int found = 0;
    for (int i = 0; i < count; i++) {
		//寻找与输入名称匹配的景点
        if (strcmp(name, sights[i].name) == 0) {
            printf("编号：%d\n名称：%s\n位置：%s\n价格：%.2f\n简介：%s\n", i + 1, sights[i].name, sights[i].location, sights[i].price, sights[i].description);
            found = 1;
        }
    }
    if (!found) printf("未找到该景点。\n");
}

// 修改指定景点信息
void modifySight() {
    char name[20];
    printf("输入要修改的景点名称：");
    scanf("%s", name);
    for (int i = 0; i < count; i++) {
        if (strcmp(name, sights[i].name) == 0) {
            printf("新名称：");
            scanf("%s", sights[i].name);
            printf("新位置：");
            scanf("%s", sights[i].location);
            printf("新简介：");
            scanf("%s", sights[i].description);
            printf("新门票价格：");
            scanf("%f", &sights[i].price);
            printf("修改成功！\n");
            return;
        }
    }
    printf("未找到该景点。\n");
}

// 删除指定景点信息
void deleteSight() {
    char name[20];
    printf("输入要删除的景点名称：");
    scanf("%s", name);
    for (int i = 0; i < count; i++) {
        if (strcmp(name, sights[i].name) == 0) {
            // 将后续元素前移覆盖
            for (int j = i; j < count - 1; j++) {
                sights[j] = sights[j + 1];
            }
            count--;
            printf("删除成功！\n");
            return;
        }
    }
    printf("未找到该景点。\n");
}