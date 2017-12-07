#include <Game.h>

Game::Game() : window(VideoMode(800, 600), "OpenGL")
{
}

Game::~Game() {}

void Game::run()
{

	initialize();

	Event event;

	while (isRunning) {

		cout << "Game running..." << endl;

		while (window.pollEvent(event))
		{
			if (event.type == Event::Closed)
			{
				isRunning = false;
			}
		}
		update();
		draw();
	}

}

void Game::initialize()
{
	isRunning = true;
	glClearColor(0.0f, 0.0f, 0.0f, 0.0f); 
	glMatrixMode(GL_PROJECTION); 
	glLoadIdentity(); 
	gluPerspective(100.0, window.getSize().x / window.getSize().y, 1.0, 500.0); 
	glMatrixMode(GL_MODELVIEW);
	//
}

void Game::update()
{
	cout << "Update up" << endl;
}

void Game::draw()
{
	cout << "Draw up" << endl;
	//TRIANGLE
	//glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
	//glBegin(GL_TRIANGLES); 
	//{
	//	glVertex3f(0.0, 2.0, -5.0); 
	//	glVertex3f(-2.0, -2.0, -5.0); 
	//	glVertex3f(2.0, -2.0, -5.0); 
	//} 
	//glEnd(); 
	//POINTS
	//glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
	//glBegin(GL_POINTS);
	//{
	//	glVertex3f(0.0, 2.0, -5.0); //TOP
	//	glVertex3f(-2.0, -2.0, -5.0); //LEFT
	//	glVertex3f(2.0, -2.0, -5.0);//RIGHT
	//}
	//glEnd();
	//LINES
	//glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
	//glBegin(GL_LINES);
	//{
	//	glVertex3f(0.0, 2.0, -5.0);
	//	glVertex3f(-2.0, -2.0, -5.0);
	//	glVertex3f(2.0, -2.0, -5.0);

	////}
	//glEnd();

	//LINESTRIP
	//glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
	//glBegin(GL_LINE_STRIP);
	//{

	//	glVertex3f(-4.00, 0.00, -5.00);
	//	glVertex3f(-3.00, 2.00, -5.00);
	//	glVertex3f(-2.00, 0.00, -5.00);
	//	glVertex3f(-1.00, 2.00, -5.00);
	//	glVertex3f(0.0, 0.00, -5.00);
	//	glVertex3f(1.00, 2.00, -5.00);
	//	glVertex3f(2.00, 0.00, -5.00);
	//	glVertex3f(3.00, 2.00, -5.00);
	//	glVertex3f(4.00, 0.00, -5.00);
	//}
	//glEnd();

	//LINE LOOP
	//glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
	//glBegin(GL_LINE_LOOP);
	//{
	//		glVertex3f(0.00, 2.00, -5.00);
	//		glVertex3f(-3.00, -2.00, -1.00);
	//		glVertex3f(-2.00, -5.00, -2.00);
	//		glVertex3f(0.0, 0.00, -5.00);
	//		glVertex3f(1.00, 2.00, -2.00);
	//		glVertex3f(2.00, 0.00, -3.00);
	//		glVertex3f(3.00, 2.00, -3.00);
	//		glVertex3f(4.00, 0.00, -1.00);



	//}
	//glEnd();

	//TRIANGLESTRIP
	//glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
	//glBegin(GL_TRIANGLE_STRIP);
	//{
	//	glVertex3f(0.0, 2.0, -5.0); //TOP
	//	glVertex3f(-2.0, -2.0, -5.0); //LEFT
	//	glVertex3f(2.0, -2.0, -5.0);//RIGHT

	//	glVertex3f(0.0, 2.0, -5.0); //TOP
	//	glVertex3f(1.00, 1.00, -1.00);
	//	glVertex3f(2.0, -2.0, -5.0);//RIGHT

	//	glVertex3f(2.0, -2.0, -5.0);//RIGHT
	//	glVertex3f(1.00, 1.00, -1.00);
	//	glVertex3f(-1.0, 2.0, -3.0); //TOP
	//}
	//glEnd();

	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
	glBegin(GL_TRIANGLE_FAN);
	{

	}
	glEnd();
	window.display();
}

void Game::unload()
{
	cout << "Cleaning up" << endl;
}

