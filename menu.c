#define _CRT_SECURE_NO_WARNINGS .1 
#include <stdio.h>
#include "menu.h"

//打印主菜单，供用户选择功能

void menu() {
    printf("\n==============================\n");
    printf("     旅游景点信息管理系统\n");
    printf("------------------------------\n");
    printf(" 1. 添加景点信息\n");
    printf(" 2. 浏览全部景点\n");
    printf(" 3. 按名称查找景点\n");
    printf(" 4. 修改景点信息\n");
    printf(" 5. 删除景点信息\n");
    printf(" 6. 保存数据到文件\n");
    printf(" 0. 退出系统\n");
    printf("------------------------------\n");
    printf(" 请选择操作：");
}