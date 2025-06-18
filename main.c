#define _CRT_SECURE_NO_WARNINGS .1 
#include <stdio.h>
#include "comm.h"
#include "menu.h"

int main() {
    int choice;
    const char* filename = "file.txt"; // 数据文件名
    loadFromFile(filename);      // 启动时加载数据

    while (1) {
        menu(); // 显示主菜单
        if (scanf("%d", &choice) != 1) {
            printf("输入无效，请输入数字。\n");
            // 清空输入缓冲区
            int ch;
            while ((ch = getchar()) != '\n' && ch != EOF);
            continue;
		}//防止输入非数字字符导致死循环
        switch (choice) {
        case 1: addSight(); break;
        case 2: showSights(); break;
        case 3: searchSight(); break;
        case 4: modifySight(); break; 
        case 5: deleteSight(); break;
        case 6: saveToFile(filename); printf("数据已保存\n"); break;
        case 0: saveToFile(filename); printf("已退出\n"); return 0;
        default: printf("无效选择，请重新输入。\n");
        }
    }
    return 0;
}