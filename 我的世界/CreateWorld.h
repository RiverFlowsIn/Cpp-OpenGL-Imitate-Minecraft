#ifndef CREATEWORLD_H
#define CREATEWORLD_H

#include <glad/glad.h>
#include <vector>
#include <iostream>

// ��ͼ�����
#define WORLD_WIDTH	600
#define WORLD_HEIGHT 200
// ѩ�����
#define SNOW_RADIUS 250

using namespace std;

// ��������
enum class CubeType
{
	Null,				// ��
	MapLand,			// ����
	MapSand,			// ɳ��
	MapStone,			// ʯͷ
	MapRedBrick,		// ��ש
	MapWood,			// ľͷ
	MapBedrock,			// ����
	MapGem,				// ��ʯ
	MapStoneBrick,		// ʯש
	MapGround,			// ��ש

	MapGrassland,		// �ݵ�
	MapTree,			// ��ľ
	MapSnow,			// ѩ��

	MapLeaveGreen,		// ����Ҷ
	MapLeaveRed,		// ����Ҷ
	MapLeaveYellow,		// ����Ҷ
	MapLeaveWhite,		// ����Ҷ

	PatMushroom,		// Ģ��
	PatRedMushroom,		// ��Ģ��
	PatFlower,			// С��
	PatGrass_1,			// ��1
	PatGrass_2,			// ��2
	PatGrass_3,			// ��3
};

using vec3 = vector<vector<vector<CubeType>>>;

// ���������ͼ��
class CreateWorld
{
public:
	static CreateWorld* getInstance();
	// ��ʼ����ͼ����
	void initMapVec();
	// ��������
	void CreateCubeMap();
	// ����ֲ��
	void CreatePlantMap();
	// ������
	void CreateTreeMap();
	// ���ڵ�ͼλ�õĺ���
	int getAltitude(int x, int z, int y);
public:
	// ����λ������
	vec3 mapData;
	// ֲ��λ������
	vec3 plantData;
	// ��Ҷλ������
	vec3 leafData;
private:
	CreateWorld();
	CreateWorld(const CreateWorld&) = delete;
	CreateWorld& operator = (const CreateWorld&) = delete;

	// ǰ���� (���������ͼʱʹ��)
	vector<int> beforeAltitudeVec;
	// ��ͼ���� (���������ͼʱʹ��)
	vector<vector<int>> altitudeMapVec;

	// ��ͼ��һ�еĺ��������ʼ��
	void randInitAltitude();
	// ��ͼ��һ�к������ݵĳ�ʼ��
	void randLineAltitude();
	// �����ʼ����ͼ�����к���
	void randAllAltitude();
	// ��ͼ����ƽ����
	void avgAltitude();
	// ���ݵ�
	void fillingGrasslandCube();
	// �������ѩ��
	void RandSnowCubeMap();
	// ��Χ�Ƿ������
	bool isAroundTree(int x, int z);
	// �����Ҷ
	void fillingLeave(int x, int z, int height, CubeType ct);
};



#endif // !CREATEWORLD_H