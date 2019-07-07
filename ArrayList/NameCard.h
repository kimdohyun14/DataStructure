#pragma once
#define NAME_LEN 30
#define PHONE_LEN 30

typedef struct __namecard {
	char name[NAME_LEN];
	char phone[PHONE_LEN];
}NameCard;

//NameCard ����ü ������ ���� �Ҵ� �� �ʱ�ȭ �� �ּ� �� ��ȯ
NameCard * MakeNameCard(const char * name, const char * phone);

//NameCard ����ü ������ ���� ���
void ShowNameCardInfo(NameCard * pcard);

//�̸��� ������ 0, �ٸ��� 0�� �ƴ� �� ��ȯ
int NameCompare(NameCard *pcard, const char * name);

//��ȭ��ȣ ������ ����
void ChangePhoneNum(NameCard * pcard, const char * phone);