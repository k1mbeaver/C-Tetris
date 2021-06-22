#include "Rank.h"
#include "tinyxml.h"

void Rank::makeRankxml(char* name, char* score)
{
	//xml ����
	TiXmlDocument doc;
	TiXmlDeclaration* pDec1 = new TiXmlDeclaration("1.0", "", "");
	doc.LinkEndChild(pDec1);

	//��Ʈ ��� �߰�
	TiXmlElement* pRoot = new TiXmlElement("DB");
	doc.LinkEndChild(pRoot);

	//�ּ� ���� �߰�
	TiXmlComment* pComment = new TiXmlComment();
	pComment->SetValue("This is score DB");
	pRoot->LinkEndChild(pComment);

	// ������� �� ������ �߰�
	TiXmlElement* pElem = new TiXmlElement("Tetris");
	pRoot->LinkEndChild(pElem);
	TiXmlElement* pElem0 = new TiXmlElement("Ranking");
	pElem0->LinkEndChild(new TiXmlElement("System"));
	pElem->LinkEndChild(pElem0);

	TiXmlElement* pSubElem;
	//������� �� �Ӽ� �߰�
	pSubElem = new TiXmlElement("GameRanking");
	pElem->LinkEndChild(pSubElem);
	pSubElem->SetAttribute("name", "score");
	pSubElem->SetAttribute(name, score);

	doc.SaveFile("score.xml");
}

char Rank::makeName()
{
	cout << "�̸��� �Է��ϼ��� : ";
	cin >> chName;

	return chName;
}

void Rank::makeRank(char* name, char* score)
{
	char chName;
	TiXmlDocument ReadDoc;
	ReadDoc.LoadFile("score.xml");// xml ���� �ε�
		//"DB"��� ��带 ã�´�
	TiXmlElement* ReadRoot = ReadDoc.FirstChildElement("DB");
	//ReadRoot("DB")��� ������ "class1",�� ���� "Teacher"��� ��带 ã�´�.
	TiXmlElement* sub = ReadRoot->FirstChildElement("Tetris")->FirstChildElement("Ranking");
	TiXmlHandle handle(0);// ��带 �ٷ�� ���� �ڵ�

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
	ReadDoc.LoadFile("score.xml");// xml ���� �ε�
		//"DB"��� ��带 ã�´�
	TiXmlElement* ReadRoot = ReadDoc.FirstChildElement("DB");
	//ReadRoot("DB")��� ������ "class1",�� ���� "Teacher"��� ��带 ã�´�.
	TiXmlElement* sub = ReadRoot->FirstChildElement("Tetris")->FirstChildElement("Ranking");
	TiXmlHandle handle(0);// ��带 �ٷ�� ���� �ڵ�
	handle = TiXmlHandle(sub);
	//ReadRoot->Value() ReadRoot�� ��� ���� ��ȯ�Ѵ� "DB"
	std::cout << ReadRoot->Value() << std::endl;
	//�ڵ鿡 ����� ��� ������ �����ϴ� ��带 ã�´�. �� ������ ��ȯ�Ѵ�.
	TiXmlElement* tmp = handle.FirstChildElement().Element();
	std::cout << tmp->Value() << std::endl;

	sub = ReadRoot->FirstChildElement("class1")->FirstChildElement("English");
	//sub(class1->english�� �Ӽ��� �о�´�.
	TiXmlAttribute* pAttrib;
	pAttrib = sub->FirstAttribute();
	while (pAttrib)
	{
		std::cout << pAttrib->Name() << "  " << pAttrib->Value() << std::endl;
		pAttrib = pAttrib->Next();
	}
}