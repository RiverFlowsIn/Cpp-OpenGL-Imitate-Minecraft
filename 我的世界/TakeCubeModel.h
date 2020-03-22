#ifndef TAKECUBEMODEL_H
#define TAKECUBEMODEL_H

#include "Shader.h"

#include <glad/glad.h>
#include <glm/glm.hpp>
#include <glm/gtc/matrix_transform.hpp>
#include <glm/gtc/type_ptr.hpp>

// OpenGL ������Ⱦ��ʽ

// �ֳַ�����
class TakeCubeModel
{
public:
	TakeCubeModel(const char* textureStr);
	~TakeCubeModel();

	void init();
	void firstPersonDraw(float eyeRadians, float bodyRadians, float limbRadians, float placeValue, float takeValue);
	void thirdPersonDraw(const glm::vec3& pos, float eyeRadians, float bodyRadians, float limbRadians, float placeValue, float takeValue);

private:
	const char* textureStr;

	unsigned int texture = 0;

	static Shader shader;
	// ��һ�˳�����
	static unsigned int firstPersonVAO;
	static unsigned int firstPersonVBO;

	// �����˳�����
	static unsigned int thirdPersonVAO;
	static unsigned int thirdPersonVBO;

	static glm::mat4 projection;
	static glm::mat4 view;

	unsigned int loadTexture(const char* path);
};

#endif // !TAKECUBEMODEL_H