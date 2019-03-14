#include "StdAfx.h"
#include "InfoFile.h"
#include <string>

CInfoFile::CInfoFile(void)
{
}

CInfoFile::~CInfoFile(void)
{
}

void CInfoFile::Readlogin(CString &name,CString &pwd)
{
	ifstream ifs;
	ifs.open(_FILE_LOGIN);
	if(!ifs || ifs.eof())
	{
		name = "π‹¿Ì‘±";
		pwd = "123";
		ifs.close();
		return;
	}
	char buf[32];
	ifs.getline(buf,sizeof(buf));
	name = buf;
	ifs.getline(buf,sizeof(buf));
	pwd = buf;

	ifs.close();
}


void CInfoFile::WritePwd(char *name,char *pwd,bool cor)
{
	ofstream ofs;
	if(cor)
		ofs.open(_FILE_LOGIN);
	else
		ofs.open(_R_PWD);

	ofs << name << endl;
	ofs << pwd << endl;
	
	ofs.close();
}

void CInfoFile::Read_All()
{
	ifstream ifs(_F_MSG);
	if(!ifs)
	{
		return;
	}
	num = 0;
	char buf[100];
	while(!ifs.eof())
	{
		msg tmp;
		ifs.getline(buf, sizeof(buf));
		char *ss = strtok(buf,"|");
		if(ss!=NULL)
		{
			tmp.money = atoi(ss);
		}
		else
		{
			break;
		}
		ss = strtok(NULL,"|");
		tmp.more = ss;

		ss = strtok(NULL,"|");
		tmp.tm = ss;

		ss = strtok(NULL,"|");
		tmp.ty = atoi(ss);
		num++;
		ls.push_back(tmp);
	}
	ifs.close();
}

void CInfoFile::Write_All()
{
	ofstream ofs(_F_MSG);

	if(ls.size()>0)
	{
		for(list<msg>::iterator it=ls.begin(); it!=ls.end(); it++)
		{
			ofs << it->money << "|";
			ofs << it->more << "|";
			ofs << it->tm << "|";
			ofs << it->ty << endl;
		}
	}
	ofs.close();
}