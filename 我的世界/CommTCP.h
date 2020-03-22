#include <iostream>
#include <vector>
#include <conio.h>
#include <windows.h>
#include <winsock.h>

#include <glm/glm.hpp>
#include <glm/gtc/matrix_transform.hpp>
#include <glm/gtc/type_ptr.hpp>

#include "CreateWorld.h"

using namespace std;

// ��ͼ�ֽڴ�С
constexpr int RECV_SIZE = WORLD_WIDTH * WORLD_HEIGHT * WORLD_WIDTH * sizeof(CubeType);

// �ͻ������ӷ�������IP
#define IP "127.0.0.1"

// ���ﶯ��
enum class PlaceStatus
{
	Normal,			// ����
	Place,			// ����
	Eliminate,		// ����
};

// ����״̬�ṹ��
struct PlayerData
{
	float eyeRadians;
	float bodyRadians;
	bool placeAnimtaion;
	CubeType cubeType;
	PlaceStatus placeStatus;
	glm::vec3 playerPos;
	glm::vec3 placePos;
};

// TCPͨ����
class CommTCP
{
public:
	static CommTCP* getInstantiate();
	// ��ʼ���ӻ����
	void start();
	bool get_isServer();
	bool get_isMapRecvTrue();
	// �����Լ��ĵ�ͼ����
	void sendMap();
	// ���նԷ���ͼ����
	void recvMap();
	// �Լ���״̬���ݷ���
	void sendPlayer(PlayerData pd);
	// �Է����״̬���ݽ���
	void recvPlayer();

	// ���նԷ���ҵ�״̬����
	PlayerData playerData;
private:
	CommTCP();
	~CommTCP();
	CommTCP(const CommTCP&) = delete;
	CommTCP& operator = (const CommTCP&) = delete;

	// �Լ��ǲ��Ƿ�����
	bool isServer = false;
    SOCKET sockServer;
    SOCKET sockClient;
    sockaddr_in addr = { 0 };

	// �������ݻ�����
	vector<char> recvVec;
	// ��ͼ�Ƿ������
	bool isMapRecvTrue = false;

	// ���͵�ͼ����
	void sendData(vector<vector<vector<CubeType>>> *vec);
	// ���յ�ͼ����
	void recvData(vector<vector<vector<CubeType>>>* vec);
	// �ͻ���ģʽ
	bool client();
	// ������ģʽ
    void server();
};

