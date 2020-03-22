#include "GLWidget.h"
#include "WorldModel.h"
#include "Control.h"
#include "Painter.h"
#include "CreateWorld.h"
#include "Interface.h"
#include "EliminateAnima.h"
#include "CommTCP.h"

#include <ctime>
#include <thread>

#pragma comment(lib, "ws2_32.lib")
#pragma comment(lib, "freetype28.lib")
#pragma comment(lib, "opencv_world412.lib")

using namespace std;

#define COUT_FPS

static clock_t fpsStart, fpsEnd;

static GLWidget* glWindow = GLWidget::getInstance();
static WorldModel* worldModel = WorldModel::getInstance();
static Control* control = Control::getInstance();
static Painter* painter = Painter::getInstance();
static CreateWorld* createWorld = CreateWorld::getInstance();
static Interface* interFace = Interface::getInstance();
static EliminateAnima* eliminateAnima = EliminateAnima::getInstance();
static CommTCP* commTCP = CommTCP::getInstantiate();

// ���ָ��
static PersonModel* player1 = nullptr;
static PersonModel* player2 = nullptr;


// ��ʼ�����е�����
void initAll();
// ���������ͼ
void createMap();
// ���ص�ͼ
void loadMap();
// �����������
void drawPlayer();
// OpenGL��Ⱦ��ʼ
void drawBegin();
// OpenGL��Ⱦ����
void drawMain();
// OpenGL��Ⱦ����
void drawEnd();
// ����FPS
void countFps();
// ����ʼ��������
void drawBeginText(const char* text);


void initAll()
{
	worldModel->initSkybox();

	interFace->init();
	eliminateAnima->init();

	painter->cube1.init();
	painter->cube2.init();
	painter->cube3.init();
	painter->cube4.init();
	painter->cube5.init();
	painter->cube6.init();
	painter->cube7.init();
	painter->cube8.init();
	painter->cube9.init();
	painter->cube10.init();
	painter->cube11.init();
	painter->cube12.init();

	painter->leafRed.init();
	painter->leafGreen.init();
	painter->leafWhite.init();
	painter->leafYellow.init();

	painter->person1.init();
	painter->person2.init();
	painter->takeCubeInit();

	painter->plant1.init();
	painter->plant2.init();
	painter->plant3.init();
	painter->plant4.init();
	painter->plant5.init();
	painter->plant6.init();

	createWorld->initMapVec();
}

void createMap()
{
	createWorld->CreateCubeMap();
	createWorld->CreatePlantMap();
	createWorld->CreateTreeMap();
}

void loadMap()
{
	thread *recvThread = new thread([=]()
	{
		commTCP->start();

		if (commTCP->get_isServer())
			commTCP->sendMap();
		else
			commTCP->recvMap();

		commTCP->recvPlayer();
	});

	drawBeginText("Load Map ...");
	this_thread::sleep_for(3s);

	if (commTCP->get_isServer())
	{
		player1 = &painter->person1;
		player2 = &painter->person2;

		createMap();
	}
	else
	{
		player1 = &painter->person2;
		player2 = &painter->person1;

		while (!commTCP->get_isMapRecvTrue())
			this_thread::sleep_for(0.2s);
	}
}

void drawPlayer()
{
	// �����Լ���״̬���Է����
	commTCP->sendPlayer({ -control->eyeRadians ,-control->bodyRadians + 90 ,control->placeAnimation ,
		control->nowTakeCube, PlaceStatus::Normal, 
		{ control->eyePos.x, control->eyePos.y - EYE_HEIGHT, control->eyePos.z }, { 0, 0, 0} });

	// ���һ״̬
	player1->eyeRadians = -control->eyeRadians;
	player1->bodyRadians = -control->bodyRadians + 90;
	player1->placeAnimtaion(control->placeAnimation);
	player1->takeCubeAnimation(control->nowTakeCube);
	player1->draw({ control->eyePos.x, control->eyePos.y - EYE_HEIGHT, control->eyePos.z }, true);


	// ��Ҷ�״̬
	player2->eyeRadians = commTCP->playerData.eyeRadians;
	player2->bodyRadians = commTCP->playerData.bodyRadians;
	player2->placeAnimtaion(commTCP->playerData.placeAnimtaion);
	player2->takeCubeAnimation(commTCP->playerData.cubeType);
	player2->draw(commTCP->playerData.playerPos, false);
}

void drawBeginText(const char* text)
{
	glClearColor(0.1f, 0.1f, 0.1f, 1.0f);
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

	interFace->drawText(text);

	glfwSwapBuffers(glWindow->getWindow());
	glfwPollEvents();
}

void drawMain()
{
	painter->drawMap(control->eyePos);

	eliminateAnima->draw();

	drawPlayer();

	control->eyeHeight();

	interFace->draw();
}

int main()
{
	initAll();
	loadMap();

	control->eyeInit(createWorld->getAltitude(WORLD_WIDTH / 2, WORLD_WIDTH / 2, WORLD_HEIGHT - 1));

	while (!glfwWindowShouldClose(glWindow->getWindow()))
	{
		drawBegin();
		drawMain();
		drawEnd();
	}

	glfwTerminate();
	exit(0);
	return 0;
}

void drawBegin()
{
	fpsStart = clock();
	float nowTime = glfwGetTime();
	control->elapseTime = nowTime - control->oldTime;
	control->oldTime = nowTime;

	glClearColor(0.1f, 0.1f, 0.1f, 1.0f);
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

	control->keyPress();
}

void drawEnd()
{
	glDisable(GL_CULL_FACE);
	worldModel->drawSkybox();

#ifdef COUT_FPS
	countFps();
#endif // COUT_FPS

	glfwSwapBuffers(glWindow->getWindow());
	glfwPollEvents();
}

void countFps()
{
	static int fps = 0;
	static int fpsNum = 0;
	static double timeLong = 0;

	fpsEnd = clock();
	double endtime = (double(fpsEnd) - fpsStart) / CLOCKS_PER_SEC;
	timeLong += endtime;
	if (timeLong >= 1.0)
	{
		timeLong = 0;
		fps = fpsNum;
		fpsNum = 0;
	}
	fpsNum++;

	interFace->drawFPS(fps);
}