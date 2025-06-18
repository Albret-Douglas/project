#define _CRT_SECURE_NO_WARNINGS .1 
#ifndef COMM_H
#define COMM_H
//����ͷ�ļ�����ֹ�ظ�����
#define MAX 100

// ���ξ�����Ϣ�ṹ��
typedef struct {
    char name[20];         // ��������
    char location[50];     // ����λ��
    char description[200]; // ������
    float price;           // ��Ʊ�۸�
} Sight;

// ȫ�ֱ�������
extern Sight sights[MAX];  // ������Ϣ����
extern int count;          // �Ѵ洢��������

// ���ܺ�������
void loadFromFile(const char* filename);   // ���ļ���������
void saveToFile(const char* filename);     // �������ݵ��ļ�
void addSight();                           // ��Ӿ���
void showSights();                         // ��ʾȫ������
void searchSight();                        // �����Ʋ��Ҿ���
void modifySight();                        // �޸ľ�����Ϣ
void deleteSight();                        // ɾ��������Ϣ

#endif