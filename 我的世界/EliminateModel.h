#ifndef ELIMINATEMODEL_H
#define ELIMINATEMODEL_H

#include "Shader.h"

// OpenGL ������Ⱦ��ʽ

// ����������ըģ����
class EliminateModel
{
public:
	EliminateModel(const char* textureStr);
	~EliminateModel();

	static void drawStart();

	void init();
	void draw(const glm::vec3& pos);

private:
	const char* textureStr;
	bool isH = false;

	unsigned int texture = 0;

	static Shader shader;
	static unsigned int VAO;
	static unsigned int painterVBO;

	static glm::mat4 projection;
	static glm::mat4 view;

	unsigned int loadTexture(const char* path);

};


#endif // !ELIMINATEMODEL_H