#include "Rank.h"
#include "tinyxml.h"
#include <algorithm>

void Rank::makeRankxml()
{
	//xml ����
	TiXmlDocument doc;
	TiXmlDeclaration* pDec1 = new TiXmlDeclaration("1.0", "", "");
	doc.LinkEndChild(pDec1);

	//��Ʈ ��� �߰�
	TiXmlElement* pRoot = new TiXmlElement("RANK");
	doc.LinkEndChild(pRoot);

	//�ּ� ���� �߰�
	TiXmlComment* pComment = new TiXmlComment();
	pComment->SetValue("This is score DB");
	pRoot->LinkEndChild(pComment);

	// ������� �� ������ �߰�
	TiXmlElement* pElem = new TiXmlElement("Ranking");
	pRoot->LinkEndChild(pElem);
	TiXmlElement* pElem0 = new TiXmlElement("System");
	pElem0->LinkEndChild(new TiXmlElement("TETRIS"));
	pElem->LinkEndChild(pElem0);

	//������� �� �Ӽ� �߰�
	TiXmlElement* pSubElem = new TiXmlElement("GameRanking");
	pElem->LinkEndChild(pSubElem);

	doc.SaveFile("score.xml");
}

char* Rank::makeName()
{
	system("cls");
	cout << "\t\t\t\t\t\t\t\t�̸��� �Է��ϼ���(10�� �̳�)" << endl;
	cout << "======================================================================================================================================================" << endl;
	cout << "\t\t\t\t\t\t\t >>>>"; cin >> chName;

	return chName;
}

void Rank::makeRank(char* name, char* score)
{
	TiXmlDocument ReadDoc;
	ReadDoc.LoadFile("score.xml");// xml ���� �ε�
		//"RANK"��� ��带 ã�´�
	TiXmlElement* ReadRoot = ReadDoc.FirstChildElement("RANK");
	//ReadRoot("RANK")��� ������ "class1",�� ���� "Teacher"��� ��带 ã�´�.
	TiXmlElement* sub = ReadRoot->FirstChildElement("Ranking")->FirstChildElement("GameRanking");
	TiXmlHandle handle(0);// ��带 �ٷ�� ���� �ڵ�

	sub->SetAttribute(name, score);

	ReadDoc.SaveFile("score.xml");
}

void Rank::readRank()
{
	int nC = 0;
	system("cls");
	TiXmlDocument ReadDoc;
	ReadDoc.LoadFile("score.xml");// xml ���� �ε�
		//"RANK"��� ��带 ã�´�
	TiXmlElement* ReadRoot = ReadDoc.FirstChildElement("RANK");
	//ReadRoot("DB")��� ������ "class1",�� ���� "Teacher"��� ��带 ã�´�.
	TiXmlElement* sub = ReadRoot->FirstChildElement("Ranking")->FirstChildElement("System");
	TiXmlHandle handle(0);// ��带 �ٷ�� ���� �ڵ�
	handle = TiXmlHandle(sub);
	//ReadRoot->Value() ReadRoot�� ��� ���� ��ȯ�Ѵ� "DB"
	cout << "\t\t\t\t\t\t\t\t\t" << ReadRoot->Value() << endl;
	//�ڵ鿡 ����� ��� ������ �����ϴ� ��带 ã�´�. �� ������ ��ȯ�Ѵ�.
	TiXmlElement* tmp = handle.FirstChildElement().Element();
	cout << "\t\t\t\t\t\t\t\t       " << tmp->Value() << endl;

	sub = ReadRoot->FirstChildElement("Ranking")->FirstChildElement("GameRanking");
	//sub(Tetris->GameRanking�� �Ӽ��� �о�´�.
	TiXmlAttribute* pAttrib;
	pAttrib = sub->FirstAttribute();
	cout << "======================================================================================================================================================" << endl;
	while (pAttrib)
	{
		cout << "\t\t\t\t\t\t" << pAttrib->Name() << "\t\t\t\t\t\t" << pAttrib->Value() << endl;
		pAttrib = pAttrib->Next();
	}
	cout << "======================================================================================================================================================" << endl;
	while (nC != Enter)
	{
		if (_kbhit()) {
			nC = _getch();
		}
	}
}

int Rank::HighScore()
{
	int nC = 0;
	int nValue = 0;
	int nValue1 = 0;
	system("cls");
	TiXmlDocument ReadDoc;
	ReadDoc.LoadFile("score.xml");// xml ���� �ε�
		//"RANK"��� ��带 ã�´�
	TiXmlElement* ReadRoot = ReadDoc.FirstChildElement("RANK");
	//ReadRoot("DB")��� ������ "class1",�� ���� "Teacher"��� ��带 ã�´�.
	TiXmlElement* sub = ReadRoot->FirstChildElement("Ranking")->FirstChildElement("System");
	TiXmlHandle handle(0);// ��带 �ٷ�� ���� �ڵ�
	handle = TiXmlHandle(sub);
	//�ڵ鿡 ����� ��� ������ �����ϴ� ��带 ã�´�. �� ������ ��ȯ�Ѵ�.
	TiXmlElement* tmp = handle.FirstChildElement().Element();

	sub = ReadRoot->FirstChildElement("Ranking")->FirstChildElement("GameRanking");
	//sub(Tetris->GameRanking�� �Ӽ��� �о�´�.
	TiXmlAttribute* pAttrib;
	pAttrib = sub->FirstAttribute();
	while (pAttrib)
	{
		if (pAttrib->Name() == NULL)
		{
			nValue = 0;
			break;
		}
		if (nC == 0)
		{
			nValue = atoi(pAttrib->Value());
			pAttrib = pAttrib->Next();
			nC++;
			continue;
		}
		nValue1 = atoi(pAttrib->Value());
		if (nValue < nValue1)
		{
			nValue = nValue1;
		}
		pAttrib = pAttrib->Next();
		nC++;
	}

	return nValue;
}