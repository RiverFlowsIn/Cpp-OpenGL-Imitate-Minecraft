#ifndef ELIMINATEANIMA_H
#define ELIMINATEANIMA_H

#include "EliminateModel.h"
#include "CreateWorld.h"

#include <list>
#include <vector>
#include <glm/glm.hpp>
#include <glm/gtc/matrix_transform.hpp>
#include <glm/gtc/type_ptr.hpp>

using namespace std;

// ����������ը����
class EliminateAnima
{
public:
	static EliminateAnima* getInstance();
	// EliminateModel ���ʼ��
	void init();
	// ��ը������λ��
	void push(glm::vec3 vec, CubeType cubeType);
	// ��Ⱦ���еı�ը����
	void draw();

private:
	EliminateAnima();
	EliminateAnima(const EliminateAnima&) = delete;
	EliminateAnima& operator = (const EliminateAnima&) = delete;

	// ������ĩ�ṹ��
	struct OffscumStruct
	{
		// ��ĩλ��
		glm::vec3 pos;
		// �ƶ��Ƕ�
		int angle;
		// �ƶ��ٶ�
		float speed;
		// ��ĩ��ʼ�߶�
		float begin;

		// �����ƶ�
		bool isUp;
		// �Ƿ����
		bool isDraw;
		// ��ը�ķ���
		CubeType cubeType;

		OffscumStruct(glm::vec3 vec, int angle, float speed, CubeType cubeType):
			pos(std::move(vec)),
			angle(angle),
			speed(speed),
			isUp(true),
			isDraw(true),
			cubeType(cubeType)
		{
			begin = vec.y + 1;
		}

	};

	// ��ը�ķ���λ�ü���
	using OffscumVec = vector<vector<OffscumStruct>>;
	list<OffscumVec> offscumVecList;

	EliminateModel eliminate1 = EliminateModel("����.png");
	EliminateModel eliminate2 = EliminateModel("ɳ��.png");
	EliminateModel eliminate3 = EliminateModel("ʯͷ.png");
	EliminateModel eliminate4 = EliminateModel("��ש.png");
	EliminateModel eliminate5 = EliminateModel("ľͷ.png");
	EliminateModel eliminate6 = EliminateModel("����.png");
	EliminateModel eliminate7 = EliminateModel("��ʯ.png");
	EliminateModel eliminate8 = EliminateModel("ʯש.png");
	EliminateModel eliminate9 = EliminateModel("��ש.png");
	EliminateModel eliminate10 = EliminateModel("�ݵ�.png");
	EliminateModel eliminate11 = EliminateModel("��ľ.png");
	EliminateModel eliminate12 = EliminateModel("ѩ��.png");
	EliminateModel eliminate13 = EliminateModel("����Ҷ.png");
	EliminateModel eliminate14 = EliminateModel("����Ҷ.png");
	EliminateModel eliminate15 = EliminateModel("����Ҷ.png");
	EliminateModel eliminate16 = EliminateModel("����Ҷ.png");

	float offscumPosRand();
	void switchDraw(OffscumStruct &offstr);
};

#endif // !ELIMINATEANIMA_H