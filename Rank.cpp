#include "Rank.h"
#include "tinyxml.h"

void Rank::makeRankxml(char* name, char* score)
{
	//xml 선언
	TiXmlDocument doc;
	TiXmlDeclaration* pDec1 = new TiXmlDeclaration("1.0", "", "");
	doc.LinkEndChild(pDec1);

	//루트 노드 추가
	TiXmlElement* pRoot = new TiXmlElement("DB");
	doc.LinkEndChild(pRoot);

	//주석 문장 추가
	TiXmlComment* pComment = new TiXmlComment();
	pComment->SetValue("This is score DB");
	pRoot->LinkEndChild(pComment);

	// 하위노드 및 데이터 추가
	TiXmlElement* pElem = new TiXmlElement("Tetris");
	pRoot->LinkEndChild(pElem);
	TiXmlElement* pElem0 = new TiXmlElement("Ranking");
	pElem0->LinkEndChild(new TiXmlElement("System"));
	pElem->LinkEndChild(pElem0);

	TiXmlElement* pSubElem;
	//하위노드 및 속성 추가
	pSubElem = new TiXmlElement("GameRanking");
	pElem->LinkEndChild(pSubElem);
	pSubElem->SetAttribute("name", "score");
	pSubElem->SetAttribute(name, score);

	doc.SaveFile("score.xml");
}

char Rank::makeName()
{
	cout << "이름을 입력하세요 : ";
	cin >> chName;

	return chName;
}

void Rank::makeRank(char* name, char* score)
{
	char chName;
	TiXmlDocument ReadDoc;
	ReadDoc.LoadFile("score.xml");// xml 파일 로드
		//"DB"라는 노드를 찾는다
	TiXmlElement* ReadRoot = ReadDoc.FirstChildElement("DB");
	//ReadRoot("DB")노드 하위의 "class1",의 하위 "Teacher"라는 노드를 찾는다.
	TiXmlElement* sub = ReadRoot->FirstChildElement("Tetris")->FirstChildElement("Ranking");
	TiXmlHandle handle(0);// 노드를 다루기 위한 핸들

	TiXmlElement* pSubElem;
	pSubElem = new TiXmlElement("GameRanking");
	sub->LinkEndChild(pSubElem);
	pSubElem->SetAttribute("name", "score");
	pSubElem->SetAttribute(name, score);

	ReadDoc.SaveFile("score.xml");
}

void Rank::readRank()
{
	TiXmlDocument ReadDoc;
	ReadDoc.LoadFile("score.xml");// xml 파일 로드
		//"DB"라는 노드를 찾는다
	TiXmlElement* ReadRoot = ReadDoc.FirstChildElement("DB");
	//ReadRoot("DB")노드 하위의 "class1",의 하위 "Teacher"라는 노드를 찾는다.
	TiXmlElement* sub = ReadRoot->FirstChildElement("Tetris")->FirstChildElement("Ranking");
	TiXmlHandle handle(0);// 노드를 다루기 위한 핸들
	handle = TiXmlHandle(sub);
	//ReadRoot->Value() ReadRoot의 노드 명을 반환한다 "DB"
	std::cout << ReadRoot->Value() << std::endl;
	//핸들에 저장된 노드 하위에 존재하는 노드를 찾는다. 그 노드명을 반환한다.
	TiXmlElement* tmp = handle.FirstChildElement().Element();
	std::cout << tmp->Value() << std::endl;

	sub = ReadRoot->FirstChildElement("class1")->FirstChildElement("English");
	//sub(class1->english의 속성을 읽어온다.
	TiXmlAttribute* pAttrib;
	pAttrib = sub->FirstAttribute();
	while (pAttrib)
	{
		std::cout << pAttrib->Name() << "  " << pAttrib->Value() << std::endl;
		pAttrib = pAttrib->Next();
	}
}