#include "Rank.h"
#include "tinyxml.h"
#include <algorithm>

void Rank::makeRankxml()
{
	//xml 선언
	TiXmlDocument doc;
	TiXmlDeclaration* pDec1 = new TiXmlDeclaration("1.0", "", "");
	doc.LinkEndChild(pDec1);

	//루트 노드 추가
	TiXmlElement* pRoot = new TiXmlElement("RANK");
	doc.LinkEndChild(pRoot);

	//주석 문장 추가
	TiXmlComment* pComment = new TiXmlComment();
	pComment->SetValue("This is score DB");
	pRoot->LinkEndChild(pComment);

	// 하위노드 및 데이터 추가
	TiXmlElement* pElem = new TiXmlElement("Ranking");
	pRoot->LinkEndChild(pElem);
	TiXmlElement* pElem0 = new TiXmlElement("System");
	pElem0->LinkEndChild(new TiXmlElement("TETRIS"));
	pElem->LinkEndChild(pElem0);

	//하위노드 및 속성 추가
	TiXmlElement* pSubElem = new TiXmlElement("GameRanking");
	pElem->LinkEndChild(pSubElem);

	doc.SaveFile("score.xml");
}

char* Rank::makeName()
{
	system("cls");
	cout << "\t\t\t\t\t\t\t\t이름을 입력하세요(10자 이내)" << endl;
	cout << "======================================================================================================================================================" << endl;
	cout << "\t\t\t\t\t\t\t >>>>"; cin >> chName;

	return chName;
}

void Rank::makeRank(char* name, char* score)
{
	TiXmlDocument ReadDoc;
	ReadDoc.LoadFile("score.xml");// xml 파일 로드
		//"RANK"라는 노드를 찾는다
	TiXmlElement* ReadRoot = ReadDoc.FirstChildElement("RANK");
	//ReadRoot("RANK")노드 하위의 "class1",의 하위 "Teacher"라는 노드를 찾는다.
	TiXmlElement* sub = ReadRoot->FirstChildElement("Ranking")->FirstChildElement("GameRanking");
	TiXmlHandle handle(0);// 노드를 다루기 위한 핸들

	sub->SetAttribute(name, score);

	ReadDoc.SaveFile("score.xml");
}

void Rank::readRank()
{
	int nC = 0;
	system("cls");
	TiXmlDocument ReadDoc;
	ReadDoc.LoadFile("score.xml");// xml 파일 로드
		//"RANK"라는 노드를 찾는다
	TiXmlElement* ReadRoot = ReadDoc.FirstChildElement("RANK");
	//ReadRoot("DB")노드 하위의 "class1",의 하위 "Teacher"라는 노드를 찾는다.
	TiXmlElement* sub = ReadRoot->FirstChildElement("Ranking")->FirstChildElement("System");
	TiXmlHandle handle(0);// 노드를 다루기 위한 핸들
	handle = TiXmlHandle(sub);
	//ReadRoot->Value() ReadRoot의 노드 명을 반환한다 "DB"
	cout << "\t\t\t\t\t\t\t\t\t" << ReadRoot->Value() << endl;
	//핸들에 저장된 노드 하위에 존재하는 노드를 찾는다. 그 노드명을 반환한다.
	TiXmlElement* tmp = handle.FirstChildElement().Element();
	cout << "\t\t\t\t\t\t\t\t       " << tmp->Value() << endl;

	sub = ReadRoot->FirstChildElement("Ranking")->FirstChildElement("GameRanking");
	//sub(Tetris->GameRanking의 속성을 읽어온다.
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
	ReadDoc.LoadFile("score.xml");// xml 파일 로드
		//"RANK"라는 노드를 찾는다
	TiXmlElement* ReadRoot = ReadDoc.FirstChildElement("RANK");
	//ReadRoot("DB")노드 하위의 "class1",의 하위 "Teacher"라는 노드를 찾는다.
	TiXmlElement* sub = ReadRoot->FirstChildElement("Ranking")->FirstChildElement("System");
	TiXmlHandle handle(0);// 노드를 다루기 위한 핸들
	handle = TiXmlHandle(sub);
	//핸들에 저장된 노드 하위에 존재하는 노드를 찾는다. 그 노드명을 반환한다.
	TiXmlElement* tmp = handle.FirstChildElement().Element();

	sub = ReadRoot->FirstChildElement("Ranking")->FirstChildElement("GameRanking");
	//sub(Tetris->GameRanking의 속성을 읽어온다.
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