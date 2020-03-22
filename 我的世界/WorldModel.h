#ifndef WORLDMODEL_H
#define WORLDMODEL_H

#include "Shader.h"
#include "GLWidget.h"

#include <vector>

using namespace std;

// ��պ���ģ��
class WorldModel
{
public:
	static WorldModel* getInstance();
	void initSkybox();
	void drawSkybox();

private:
	WorldModel();
	~WorldModel();
	WorldModel(const WorldModel&) = delete;
	WorldModel& operator = (const WorldModel&) = delete;

	unsigned int loadCubemap(vector<string> faces);

	int worldScale = 2000;

	Shader skyboxShader = Shader("./Shader/sky/sky.vs", "./Shader/sky/sky.fs");

	unsigned int skyboxVAO = 0;
	unsigned int cubemapTexture = 0;

	glm::mat4 projection = glm::perspective(glm::radians(45.0f), Width / Height, 0.1f, 2000.0f);
	glm::mat4 view = glm::mat4(1.0f);
};


#endif // !WORLDMODEL_H