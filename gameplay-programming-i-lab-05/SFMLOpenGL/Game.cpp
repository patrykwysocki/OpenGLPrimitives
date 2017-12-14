#include <Game.h>

// // Uncomment for Part 2
// // ********************
bool flip = false;
int current = 1;
// // ********************

Game::Game() : window(VideoMode(800, 600), "OpenGL"), primatives(2)
{
	// // Uncomment for Part 2
	// // ********************
	index = glGenLists(primatives);
	// // ********************
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

	// // Uncomment for Part 2
	// // ********************
	glClearColor(0.0f, 0.0f, 0.0f, 0.0f);
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();


	gluPerspective(45.0, window.getSize().x / window.getSize().y, 1.0, 500.0);
	glMatrixMode(GL_MODELVIEW);


	//glNewList(index, GL_COMPILE);
	//glBegin(GL_TRIANGLES);
	//{
	//	glColor3f(0.0f, 0.0f, 1.0f);
	//	glVertex3f(0.0, 2.0, -5.0);
	//	glVertex3f(-2.0, -2.0, -5.0);
	//	glVertex3f(2.0, -2.0, -5.0);
	//}
	//glEnd();
	//glEndList();

	//glNewList(index + 1, GL_COMPILE);
	//glBegin(GL_TRIANGLES);
	//{
	//	glColor3f(0.0f, 1.0f, 0.0f);
	//	glVertex3f(0.2, 0.0, -2.0);
	//	glVertex3f(-2.0, -2.0, -2.0);
	//	glVertex3f(2.0, -2.0, -2.0);
	//}
	glEnd();
	glEndList();

	// // Uncomment for Part 2
	// // ********************
}

void Game::update()
{

	// // Uncomment for Part 2
	// // ********************
	elapsed = clock.getElapsedTime();

	if (elapsed.asSeconds() >= 1.0f)
	{
		clock.restart();

		if (!flip)
		{
			flip = true;
			current++;
			if (current > primatives)
			{
				current = 1;
			}
		}
		else
			flip = false;
	}

	if (flip)
	{
		rotationAngle += 0.0005f;

		if (rotationAngle > 360.0f)
		{
			rotationAngle -= 360.0f;
		}
	}
	// // ********************

	cout << "Update up" << endl;
}

void Game::draw()
{

	// // Uncomment for Part 2
	// // ********************
	cout << "Draw up" << endl;

	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
	glBegin(GL_TRIANGLES);
	{
		glVertex3f(0.0, 0.50, -5.0);
		glVertex3f(-0.5, -0.50, -5.0);
		glVertex3f(1.5, -0.10, -5.0);
	}
	glEnd();

	glBegin(GL_POINTS);
	{
		glVertex3f(-1.7, -1.7, -5.0);
	}
	glEnd();

	glBegin(GL_LINES);
	{
		glVertex3f(-1.6, 1.7, -5.0);
		glVertex3f(-1.2, -1.3, -5.0);
	}
	glEnd();

	glBegin(GL_LINE_STRIP);
	{
		glVertex3f(-0.7, 1.0, -5.0);
		glVertex3f(-0.7, 2.0, -5.0);
		glVertex3f(-0.3, 2.0, -5.0);
		glVertex3f(-0.3, 1.0, -5.0);
		glVertex3f(-0.7, 2.0, -5.0);
	}
	glEnd();
	glBegin(GL_LINE_LOOP);
	{
		glVertex3f(0.7, -1, -5.0);
		glVertex3f(-0.7, 1, -5.0);
		glVertex3f(0.3, 2, -5.0);
	}
	glEnd();
	glBegin(GL_TRIANGLE_STRIP);
	{
		glVertex3f(0.35, -1.7, -5.0);
		glVertex3f(-0.8, -1.6, -5.0);
		glVertex3f(-0.35, -2.4, -5.0);
	}
	glEnd();
	glBegin(GL_TRIANGLE_FAN);
	{
		glVertex3f(0, 0, -5.0);
		glVertex3f(0.5, 0, -5.0);
		glVertex3f(0, 0.5, -5.0);
		glVertex3f(-0.5, 0, -5.0);
	}
	glEnd();
	glBegin(GL_QUADS);
	{
		glVertex3f(-2, 0.5, -5.0);
		glVertex3f(-1, 0.5, -5.0);
		glVertex3f(-1, -0.5, -5.0);
		glVertex3f(-2, -0.5, -5.0);
	}
	glEnd();
	glBegin(GL_QUAD_STRIP);
	{
		glVertex3f(0.9, 1.2, -5.0);
		glVertex3f(-0.6, 1.2, -5.0);
		glVertex3f(-0.3, -0.8, -5.0);
		glVertex3f(-0.6, -0.8, -5.0);
		glVertex3f(-0.3, -0.8, -5.0);
		glVertex3f(-0.6, -0.8, -5.0);
	}
	glEnd();
	glBegin(GL_POLYGON);
	{
		glVertex3f(-0.2, -0.6, -5.0);
		glVertex3f(0.2, -0.6, -5.0);
		glVertex3f(0.6, -1, -5.0);
		glVertex3f(0.6, -1.4, -5.0);
		glVertex3f(0.2, -1.8, -5.0);
		glVertex3f(-0.2, -1.8, -5.0);
		glVertex3f(-0.6, -1.4, -5.0);
		glVertex3f(-0.6, -1, -5.0);
	}
	glEnd();
	//Investigate Here!!!!!
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::A))
	{
		glRotatef(rotationAngle, 0.0f, 0.0f, 1.0f);
	}
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::B))
	{
		glTranslatef(0.0010f, 0.0010f, 0.0010f);
	}
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::D))
	{
		glTranslatef(-0.0010f, -0.0010f, -0.0010f);
	}
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::C))
	{
		glScalef(1.0001f, 1.0f, 1.0f);
	}
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::F))
	{
		glScalef(0.9999f, 1.0f, 1.0f);
	}

	//moves triangles to the right

	cout << "Drawing Primative " << current << endl;
	glCallList(current);
	// // Uncomment for Part 2
	// // ********************

	window.display();

}

void Game::unload()
{
	cout << "Cleaning up" << endl;
}

