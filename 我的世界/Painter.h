#ifndef PAINTER_H
#define PAINTER_H

#include "PersonModel.h"
#include "CubeModel.h"
#include "PlantModel.h"
#include "LeafModel.h"
#include "CreateWorld.h"

#define VISION_WIDTH	100		// ��Ұ
#define VISION_HEIGHT	30		// ��Ұ

class Painter
{
public:
	static Painter* getInstance();
	// ����ͼ
	void drawMap(glm::vec3 vec);
	// �ֳַ����ʼ��
	void takeCubeInit();

	CubeModel cube1 = CubeModel("����.png", "����.png");
	CubeModel cube2 = CubeModel("ɳ��.png", "ɳ��.png");
	CubeModel cube3 = CubeModel("ʯͷ.png", "ʯͷ.png");
	CubeModel cube4 = CubeModel("��ש.png", "��ש.png");
	CubeModel cube5 = CubeModel("ľͷ.png", "ľͷ.png");
	CubeModel cube6 = CubeModel("����.png", "����.png");
	CubeModel cube7 = CubeModel("��ʯ.png", "��ʯ.png");
	CubeModel cube8 = CubeModel("ʯש.png", "ʯש.png");
	CubeModel cube9 = CubeModel("��ש.png", "��ש.png");
	CubeModel cube10 = CubeModel("�ݵ�.png", "�ݽ�.png");
	CubeModel cube11 = CubeModel("����.png", "��ľ.png");
	CubeModel cube12 = CubeModel("ѩ��.png", "ѩ��.png");


	PlantModel plant1 = PlantModel("�칽.png");
	PlantModel plant2 = PlantModel("Ģ��.png");
	PlantModel plant3 = PlantModel("С��.png");
	PlantModel plant4 = PlantModel("��1.png");
	PlantModel plant5 = PlantModel("��2.png");
	PlantModel plant6 = PlantModel("��3.png");

	LeafModel leafRed = LeafModel("����Ҷ.png");
	LeafModel leafYellow = LeafModel("����Ҷ.png");
	LeafModel leafWhite = LeafModel("����Ҷ.png");
	LeafModel leafGreen = LeafModel("����Ҷ.png");

	PersonModel person1 = PersonModel("1.png");
	PersonModel person2 = PersonModel("2.png");
private:
	Painter() = default;

	Painter(const Painter&) = delete;
	Painter& operator = (const Painter&) = delete;

	// ����ͼ������Ԫ��
	void drawAll();
	// ��ջ���
	void clearAll();
	// �������
	void push(CubeType ct, int i, int j, int k);
	// �жϷ����Ƿ�¶���Ⲣ����
	inline bool isDrawCube(int x, int y, int z);
};

#endif // !PAINTER_H