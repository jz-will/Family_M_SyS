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
	bool ty;			//支出或收入，直接从ComboBox控件获取
	int money;		//金额
	string tm;		//时间
	string more;	//备注
};

//文件以及数据处理
class CInfoFile
{
public:
	CInfoFile(void);
	~CInfoFile(void);

	//读login.ini文件 账号和密码信息
	void Readlogin(CString &name,CString &pwd);

	//重写密码
	void WritePwd(char *name, char *pwd,bool cor=true);

	//读取msg.txt所有条目信息到ls
	void Read_All();

	//把list信息写进文件msg.txt
	void Write_All();

	//列操作信息
	list<msg> ls;	
	int num;
};

