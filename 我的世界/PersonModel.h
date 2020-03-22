#ifndef PERSONMODEL_H
#define PERSONMODEL_H

#include "Shader.h"
#include "TakeCubeModel.h"
#include "CreateWorld.h"

#include <glad/glad.h>
#include <glm/glm.hpp>
#include <glm/gtc/matrix_transform.hpp>
#include <glm/gtc/type_ptr.hpp>

#include <opencv2/core/core.hpp>
#include <opencv2/highgui/highgui.hpp>
#include <opencv2/opencv.hpp>

// ��������
constexpr int COUNT = 6;

// ����ģ����
class PersonModel
{
public:
	PersonModel(const char* textureStr);
	~PersonModel();

	// TakeCubeModel ���ʼ��
	static void takeCubeInit();
	void init();
	void draw(const glm::vec3& pos, bool isMy);
	// ���������������
	void placeAnimtaion(bool &placeAnimation);
	// �����ֳ��л�����
	void takeCubeAnimation(CubeType nowTakeCube);

	// ����
	float eyeRadians = 0;
	// ����
	float bodyRadians = 0;

	// ����״̬
	enum class Animation
	{
		GO,
		Return,
		End,
	};

	// ������������
	Animation placeAnimation = Animation::End;
	// ���ý���
	int placeValue = 0;
	// �ֳ��л�����
	Animation takeAnimation = Animation::End;
	// �л�����
	int takeValue = 0;

	// �����ֳַ���
	CubeType nowTakeCube = CubeType::MapLand;
	// �����ֳַ���
	CubeType newTakeCube = CubeType::MapLand;

private:
	const char* textureStr;
	cv::Mat img;

	// ��������
	unsigned int headTexture[COUNT]{ 0 };
	unsigned int bodyTexture[COUNT]{ 0 };
	unsigned int  armTexture[COUNT]{ 0 };
	unsigned int  legTexture[COUNT]{ 0 };

	static Shader shader;
	static unsigned int headVAO[COUNT];
	static unsigned int headVBO[COUNT];
	static unsigned int bodyVAO[COUNT];
	static unsigned int bodyVBO[COUNT];
	static unsigned int  armVAO[COUNT];
	static unsigned int  armVBO[COUNT];
	static unsigned int  legVAO[COUNT];
	static unsigned int  legVBO[COUNT];

	// �ֳַ���
	static TakeCubeModel takeCube1;
	static TakeCubeModel takeCube2;
	static TakeCubeModel takeCube3;
	static TakeCubeModel takeCube4;
	static TakeCubeModel takeCube5;
	static TakeCubeModel takeCube6;
	static TakeCubeModel takeCube7;
	static TakeCubeModel takeCube8;
	static TakeCubeModel takeCube9;

	static glm::mat4 projection;
	static glm::mat4 view;

	// �ϴ�����λ��
	glm::vec3 oldPos;
	// �ֱ۰ڶ��Ƕ�
	float limbRadians = 0.0f;
	// �ֱ۰ڶ�����
	bool isLimbDir = false;	

	// ��һ�˳��ֳַ������
	void firstPersonDrawTakeCube();

	// �����˳��������
	void thirdPersonDrawPerson(const glm::vec3& pos);
	// �����˳��ֳַ������
	void thirdPersonDrawTakeCube(const glm::vec3& pos);

	// ���ý��ȸı�
	void placeValueChange();
	// �л����ȸı�
	void takeValueChange();

	// ��Ⱦ���������
	void drawArrays(unsigned int VAO, unsigned int texture);
	// �ܲ�����
	void runAnimation(const glm::vec3& pos);
	// ������������
	unsigned int loadTexture(int rect, int i);
	// �������������
	void bindTexture(unsigned int *VAO, unsigned int *painterVBO_H, 
			const float (*vertex)[48], unsigned int *texture, int rect);
};


#endif // !PERSONMODEL_H