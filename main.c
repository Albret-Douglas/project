#define _CRT_SECURE_NO_WARNINGS .1 
#include <stdio.h>
#include "comm.h"
#include "menu.h"

int main() {
    int choice;
    const char* filename = "file.txt"; // �����ļ���
    loadFromFile(filename);      // ����ʱ��������

    while (1) {
        menu(); // ��ʾ���˵�
        if (scanf("%d", &choice) != 1) {
            printf("������Ч�����������֡�\n");
            // ������뻺����
            int ch;
            while ((ch = getchar()) != '\n' && ch != EOF);
            continue;
		}//��ֹ����������ַ�������ѭ��
        switch (choice) {
        case 1: addSight(); break;
        case 2: showSights(); break;
        case 3: searchSight(); break;
        case 4: modifySight(); break; 
        case 5: deleteSight(); break;
        case 6: saveToFile(filename); printf("�����ѱ���\n"); break;
        case 0: saveToFile(filename); printf("���˳�\n"); return 0;
        default: printf("��Чѡ�����������롣\n");
        }
    }
    return 0;
}