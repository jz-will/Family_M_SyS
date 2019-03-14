#pragma once
#include<fstream>
#include<list>
#include<string>
using namespace std;

#define _FILE_LOGIN  "login.ini"
#define _R_PWD "r.ini"
#define _F_MSG "msg.txt"

struct msg
{
	bool ty;			//֧�������룬ֱ�Ӵ�ComboBox�ؼ���ȡ
	int money;		//���
	string tm;		//ʱ��
	string more;	//��ע
};

//�ļ��Լ����ݴ���
class CInfoFile
{
public:
	CInfoFile(void);
	~CInfoFile(void);

	//��login.ini�ļ� �˺ź�������Ϣ
	void Readlogin(CString &name,CString &pwd);

	//��д����
	void WritePwd(char *name, char *pwd,bool cor=true);

	//��ȡmsg.txt������Ŀ��Ϣ��ls
	void Read_All();

	//��list��Ϣд���ļ�msg.txt
	void Write_All();

	//�в�����Ϣ
	list<msg> ls;	
	int num;
};

