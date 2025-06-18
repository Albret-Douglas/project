#define _CRT_SECURE_NO_WARNINGS .1 
#include <stdio.h>
#include <string.h>
#include "comm.h"

// ȫ�ֱ�������
Sight sights[MAX];
int count = 0;

// ��ָ���ļ����ؾ�������
void loadFromFile(const char* filename) {
    FILE* fp = fopen(filename, "r");
    if (fp == NULL) {
        printf("�޷����ļ� %s\n", filename);
        count = 0;
        return;
    }
	//��ȡ�ļ����ݵ�sights���飬countΪʵ�ʶ�ȡ�ľ�������
    while (count < MAX && fscanf(fp, "%19s %49s %199s %f", sights[count].name, sights[count].location, sights[count].description, &sights[count].price) == 4) {
        count++;
    }
    fclose(fp);
}

// ���������ݱ��浽ָ���ļ�
void saveToFile(const char* filename) {
    FILE* fp = fopen(filename, "w");
    if (fp == NULL) return;
    //��sights�����е�����д���ļ�
	for (int i = 0; i < count; i++) {
        fprintf(fp, "%s\n%s\n%s\n%.2f\n\n", sights[i].name, sights[i].location, sights[i].description, sights[i].price);
    }
    fclose(fp);
}

// ����¾�����Ϣ����Ҫ����������ţ�
void addSight() {
    if (count >= MAX) {
        printf("�Ѵ����洢������\n");
        return;
    }
    printf("�������ƣ�");
    scanf("%s", sights[count].name);
    printf("����λ�ã�");
    scanf("%s", sights[count].location);
    printf("��飺");                    
    scanf("%s", sights[count].description);
    printf("��Ʊ�۸�");
    scanf("%f", &sights[count].price);
    count++;
    printf("��ӳɹ���\n");
}

// ��ʾ���о�����Ϣ
void showSights() {
    if (count == 0) {
        printf("���޾�����Ϣ��\n");
        return;
    }
    //printf("���\t����\t\t\tλ��\t\t\t�۸�\t\t���\n");
    for (int i = 0; i < count; i++) {
        printf("��ţ�%d\n���ƣ�%s\nλ�ã�%s\n�۸�%.2f\n��飺%s\n\n", i + 1, sights[i].name, sights[i].location, sights[i].price, sights[i].description);
    }
}

// �����Ʋ��Ҿ�����Ϣ
void searchSight() {
    char name[20];
    printf("����Ҫ���ҵľ������ƣ�");
    scanf("%s", name);
    int found = 0;
    for (int i = 0; i < count; i++) {
		//Ѱ������������ƥ��ľ���
        if (strcmp(name, sights[i].name) == 0) {
            printf("��ţ�%d\n���ƣ�%s\nλ�ã�%s\n�۸�%.2f\n��飺%s\n", i + 1, sights[i].name, sights[i].location, sights[i].price, sights[i].description);
            found = 1;
        }
    }
    if (!found) printf("δ�ҵ��þ��㡣\n");
}

// �޸�ָ��������Ϣ
void modifySight() {
    char name[20];
    printf("����Ҫ�޸ĵľ������ƣ�");
    scanf("%s", name);
    for (int i = 0; i < count; i++) {
        if (strcmp(name, sights[i].name) == 0) {
            printf("�����ƣ�");
            scanf("%s", sights[i].name);
            printf("��λ�ã�");
            scanf("%s", sights[i].location);
            printf("�¼�飺");
            scanf("%s", sights[i].description);
            printf("����Ʊ�۸�");
            scanf("%f", &sights[i].price);
            printf("�޸ĳɹ���\n");
            return;
        }
    }
    printf("δ�ҵ��þ��㡣\n");
}

// ɾ��ָ��������Ϣ
void deleteSight() {
    char name[20];
    printf("����Ҫɾ���ľ������ƣ�");
    scanf("%s", name);
    for (int i = 0; i < count; i++) {
        if (strcmp(name, sights[i].name) == 0) {
            // ������Ԫ��ǰ�Ƹ���
            for (int j = i; j < count - 1; j++) {
                sights[j] = sights[j + 1];
            }
            count--;
            printf("ɾ���ɹ���\n");
            return;
        }
    }
    printf("δ�ҵ��þ��㡣\n");
}