#ifndef CUBEMODEL_H
#define CUBEMODEL_H

#include "Shader.h"

#include <glad/glad.h>
#include <glm/glm.hpp>
#include <glm/gtc/matrix_transform.hpp>
#include <glm/gtc/type_ptr.hpp>

#include <vector>

// ����ģ����
class CubeModel
{
public:
	CubeModel(const char* textureStrH, const char* textureStrV);
	~CubeModel();
	
	// ��ʼ���л���
	static void drawStart();

	// OpenGL��Ⱦ��ʼ������
	void init();
	// OpenGL Instantiate��Ⱦ����
	void draw();
	// ����ɹ۲쵽�ķ��������Ⱦ����
	void push(int x, int y, int z);
	// ��Ⱦ�������
	void clear();

private:

	static Shader shader;
	static glm::mat4 projection;
	static glm::mat4 view;

	// ��ֱ����
	const char* textureStrH;
	// ˮƽ����
	const char* textureStrV;

	// ��ֱ
	unsigned int VAO_V = 0, VBO_V = 0, EBO_V = 0;
	// ˮƽ
	unsigned int VAO_H = 0, VBO_H = 0, EBO_H = 0;
	// ����
	unsigned int textureH = 0, textureV = 0;
	// ��Ҫ��Ⱦ�ĸ���
	int painterCount = 50000;
	// ���㻺��������
	unsigned int painterVBO_H = 0, painterVBO_V = 0;
	// OpenGL Instantiate ��Ⱦ����
	std::vector<glm::mat4> painterVec;

	unsigned int loadTexture(const char* path);
};

#endif // !CUBEMODEL_H