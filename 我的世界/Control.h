#ifndef CONTROL_H
#define CONTROL_H

#include <glad/glad.h>
#include <GLFW/glfw3.h>

#include "CreateWorld.h"

#include <glm/glm.hpp>
#include <glm/gtc/matrix_transform.hpp>
#include <glm/gtc/type_ptr.hpp>

#include <iostream>

// ��һ�˳�
#define EYE_HEIGHT 1

// �����˳� (�������⣬�������޸�)
//#define EYE_HEIGHT 3

// ����״̬
enum class PeopleStatus
{
	Normal,		// ����
	JumpUp,		// ����
	Eecline		// �½�
};

// OpenGL������¼�
void mousePress(GLFWwindow* window, int button, int action, int mods);
// OpenGL����ƶ��¼�
void mouseMove(GLFWwindow* window, double xpos, double ypos);

// ��ҿ�����
class Control
{
public:
	static Control* getInstance();
	// ���̰����¼�
	void keyPress();
	// �������ʱ�����ڵĺ���
	void eyeInit(int altitude);
	// �й��������ں��εĴ�����(��Ծ,�½�)
	void eyeHeight();
	// ����
	void mouseLeft();
	// ����
	void mouseRight();

	// ����Ƕ�
	float bodyRadians = -270;
	// �ӽǽǶ�
	float eyeRadians = 0.0f;
	// ���ö���
	bool placeAnimation = false;

	// �ֳַ���
	CubeType nowTakeCube = CubeType::MapLand;

	// ����״̬
	PeopleStatus ps = PeopleStatus::Normal;	
	// ��������
	float beginJumpAltitude = 0;

	// �ӽǺ���
	float eyeAltitude = 0;	
	glm::vec3 eyePos = glm::vec3(WORLD_WIDTH / 2, eyeAltitude, WORLD_WIDTH / 2);
	glm::vec3 cameraPos = glm::vec3(WORLD_WIDTH / 2, eyeAltitude, WORLD_WIDTH / 2 + 0.25f);

	// ���ǰ����
	glm::vec3 cameraFront = glm::vec3(0.0f, 0.0f, 1.0f);
	// ����Ϸ���
	glm::vec3 cameraUp = glm::vec3(0.0f, 1.0f, 0.0f);

	// ����ʱ��
	float elapseTime = 0.0f;
	// �ϴ�ʱ��
	float oldTime = 1.0f;

	// ��겶��
	bool isCursorDisabled = true;

private:
	Control();
	Control(const Control&) = delete;
	Control& operator = (const Control&) = delete;

	// �����¼�
	void windowKey();
	// �����ƶ�
	void cameraMoveKey();
	// ������Ծ
	void cameraJumpKey();
	// �л��ֳַ���
	void takeCubeKey();
	// ��ײ���
	bool isCollision(float x, float y, float z);
};


#endif // !CONTROL_H

