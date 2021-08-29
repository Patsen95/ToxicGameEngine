//#include <Toxic.h>
//
//
//#define PRINT(x) (std::cout << x << std::endl)
//
//using namespace toxic;
//
/////////////////////////////////////////////
//void DisplayScene();
//void Reshape(int w, int h);
//void InitScene();
//void DeleteScene();
//
//
//int deltaTime;
//
//ShaderProgram* prog;
//Shader* vShader;
//Shader* fShader;
//
/////////////////////////////////////////////
//void MainMenu(int value)
//{
//	switch(value)
//	{
//		case 0:
//			exit(0);
//		case 1:
//			PRINT("Twoja stara");
//			break;
//	}
//}
//
//void SubMenu(int value)
//{
//	static bool toggle = false;
//	switch(value)
//	{
//		case 0:
//			prog->SetFloat("red", 0.1f);
//			prog->SetFloat("green", 0.0f);
//			prog->SetFloat("blue", 0.0f);
//			break;
//		case 1:
//			prog->SetFloat("red", 0.0f);
//			prog->SetFloat("green", 1.0f);
//			prog->SetFloat("blue", 0.0f);
//			break;
//		case 2:
//			prog->SetFloat("red", 0.0f);
//			prog->SetFloat("green", 0.0f);
//			prog->SetFloat("blue", 1.0f);
//			break;
//		case 3:
//			PRINT("COLOR");
//			prog->SetFloat("red", 0.0f);
//			prog->SetFloat("green", 0.0f);
//			prog->SetFloat("blue", 0.0f);
//			break;
//		case 4:
//			//glutFullScreen();
//
//			break;
//		case 5:
//			//glutReshapeWindow(800, 600);
//			break;
//	}
//	PRINT("R: " << prog->ReadFloat("red"));
//	PRINT("G: " << prog->ReadFloat("green"));
//	PRINT("B: " << prog->ReadFloat("blue"));
//	glutPostRedisplay(); // Wymuszenie odrysowania sceny
//}
//
//int lastTime = 0;
//
//#include <sys/types.h>
//#include <sys/stat.h>
//
//struct stat result;
//
//void Display()
//{
//	int time = glutGet(GLUT_ELAPSED_TIME);
//	deltaTime = time - lastTime;
//	lastTime = time;
//
//	DisplayScene(); // Rendering sceny
//
//	// Sprawdzanie błędów
//	GLenum error = glGetError();
//	switch(error)
//	{
//		case GL_CONTEXT_LOST:
//			PRINT("GL_CONTEXT_LOST");
//			exit(1);
//		case GL_INVALID_ENUM:
//			PRINT("GL_INVALID_ENUM");
//			exit(1);
//		case GL_INVALID_VALUE:
//			PRINT("GL_INVALID_VALUE");
//			exit(1);
//		case GL_INVALID_OPERATION:
//			PRINT("GL_INVALID_OPERATION");
//			exit(1);
//		case GL_INVALID_FRAMEBUFFER_OPERATION:
//			PRINT("GL_INVALID_FRAMEBUFFER_OPERATION");
//			exit(1);
//		case GL_OUT_OF_MEMORY:
//			PRINT("GL_OUT_OF_MEMORY");
//			exit(1);
//		case GL_STACK_OVERFLOW:
//			PRINT("GL_STACK_OVERFLOW");
//			exit(1);
//		case GL_STACK_UNDERFLOW:
//			PRINT("GL_STACK_UNDERFLOW");
//			exit(1);
//		case GL_NO_ERROR:
//			break;
//	}
//	glutSwapBuffers(); // Zamiana buforów koloru
//
//
//	//////////////////////////////////
//	if(stat("square.frag", &result) == 0)
//	{
//		auto mod_time = result.st_ctime;
//		PRINT(mod_time);
//	}
//}
//
/////////////////////////////////////////////
//int main(int argc, char** argv)
//{
//	// =========== INICJALIZACJA FREEGLUT ===========
//	glutInit(&argc, argv);
//
//	// Inicjalizacja bufora ramki
//	glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGB);
//
//	// Utworzenie kontekstu renderingu OpenGL
//	glutInitContextVersion(3, 2);
//	glutInitContextProfile(GLUT_CORE_PROFILE);
//
//	// Rozmiary głównego okna
//	glutInitWindowSize(800, 600);
//
//	// Utworzenie okna
//	glutCreateWindow("Kwadrat");
//
//	// =========== INICJALIZACJA GLEW ===========
//	glewExperimental = GL_TRUE;
//	GLenum err = glewInit();
//	if(err != GLEW_OK)
//	{
//		PRINT("Blad inicjalizacji GLEW");
//		return 1;
//	}
//
//	// Sprawdzenie dostępności wersji OpenGL
//	if(!GLEW_VERSION_3_2)
//	{
//		PRINT("Brak OpenGL 3.2");
//		return 1;
//	}
//	glGetError();
//
//	// =========== UTWORZENIE MENU KONTEKSTOWEGO ===========
//	// Utworzenie menu kontekstowego
//	ContextMenu subMenu(SubMenu);
//	subMenu.AddEntry("Red");
//	subMenu.AddEntry("Green");
//	subMenu.AddEntry("Blue");
//	subMenu.AddEntry("CLEAR");
//	subMenu.AddEntry("Fullscreen");
//	subMenu.AddEntry("Normal");
//
//	ContextMenu menu(MainMenu);
//	menu.AddEntry("Exit");
//	menu.AddEntry("Reload shaders");
//
//	menu.AddSubMenu("Colors", subMenu);
//
//	ContextMenu::Register(GLUT_RIGHT_BUTTON);
//
//	// =========== OBSŁUGA RENDERINGU ===========
//	InitScene(); // Inicjalizacja sceny 3D
//	
//	// Rejestracja funkcji generującej scenę 3D
//	glutDisplayFunc(Display);
//
//	// Dołączenie funkcji wywoływanej przy zmianie rozmiarów okna
//	glutReshapeFunc(Reshape);
//
//	// Obsługa pętli komunikatów
//	glutMainLoop();
//
//	// Sprątanie sceny
//	DeleteScene();
//
//	//cin.get();
//	return 0;
//}
/////////////////////////////////////////////
//GLfloat position[12] = // Wierzchołki kwadratu
//{
//	// Pierwszy "trójkąt"
//	-0.5f, -0.5f,
//	0.5f, -0.5f,
//	// Drugi "trójkąt"
//	0.5f, 0.5f,
//	-0.5f, 0.5f
//};
//
//GLuint indices[6] = 
//{
//	0, 1, 2,
//	0, 2, 3
//};
//
//GLuint indicesBuffer; // Tablica z danymi indeksów wierzchołków
//GLuint vertexBuffer; // Tablica współrzędnych wierzchołków kwadratu - VBO
//GLuint vertexArray; // Tablica atrybutów VBO - VAO
//
//// Numery indeksów poszczególnych atrybutów wierzchołków
//#define POSITION 0
//
//
/////////////////////////////////////////////
//void DisplayScene()
//{
//	// Czyszczenie bufora koloru
//	glClear(GL_COLOR_BUFFER_BIT);
//
//	// Włączenie VAO
//	glBindVertexArray(vertexArray);
//
//	// Włączenie shaderów
//	prog->Run();
//
//	// Narysowanie danych w VAO
//	//glDrawArrays(GL_TRIANGLES, 0, 6);
//
//	// Narysowanie danych w tablicy wierzchołków
//	glDrawElements(GL_TRIANGLES, 6, GL_UNSIGNED_INT, NULL);
//
//	// Wyłączenie shadera
//	prog->Stop();
//
//	// Wyłączenie VAO
//	glBindVertexArray(0);
//}
//
//void Reshape(int w, int h)
//{
//	glViewport(0, 0, w, h);
//}
//
//void InitScene()
//{
//	// Kolor tła - zawartość bufora kolorów
//	glClearColor(0, 0, 0, 1);
//
//	// Wczytanie shaderów
//	prog = new ShaderProgram();
//	vShader = new Shader("square.vert", Shader::VERTEX);
//	fShader = new Shader("square.frag", Shader::FRAGMENT);
//
//	prog->AttachShader(vShader);
//	prog->AttachShader(fShader);
//
//	// Generowanie identyfikatora VAO
//	glGenVertexArrays(1, &vertexArray);
//
//	// Utworzenie VAO
//	glBindVertexArray(vertexArray);
//
//	// Generowanie identyfikatora VBO
//	glGenBuffers(1, &vertexBuffer);
//
//	// Utworzenie VBO
//	glBindBuffer(GL_ARRAY_BUFFER, vertexBuffer);
//
//	// Załadowanie danych do VBO
//	glBufferData(GL_ARRAY_BUFFER, sizeof(position), position, GL_STATIC_DRAW);
//
//	//// Pobranie indeksu atrybutu wierzchołka o nazwie "inPos" (z shadera)
//	//GLuint positionLoc = glGetAttribLocation(program, "inPos");
//	
//	// Zdefiniowanie tablicy wierzchołków
//	glVertexAttribPointer(POSITION, 2, GL_FLOAT, GL_FALSE, 0, NULL);
//
//	// Włączenie tablic wierzchołków (VAO)
//	glEnableVertexAttribArray(POSITION);
//
//	// Utworzenie obiektu bufora indeksów wierzchołków i załadowanie danych
//	glGenBuffers(1, &indicesBuffer);
//	glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, indicesBuffer);
//	glBufferData(GL_ELEMENT_ARRAY_BUFFER, sizeof(indices), indices, GL_STATIC_DRAW);
//
//	// Wyłączenie VAO (używane przy wielu VAO)
//	glBindVertexArray(0);
//}
//
//void DeleteScene()
//{
//	// Usunięcie obiektu programu
//	prog->DetachShader(vShader);
//	prog->DetachShader(fShader);
//	vShader->Delete();
//	fShader->Delete();
//	prog->Delete();
//
//	// Usunięcie VBO
//	glDeleteBuffers(1, &vertexBuffer);
//
//	// Usunięcie bufora indeksów
//	glDeleteBuffers(1, &indicesBuffer);
//
//	// Usunięcie VAO
//	glDeleteVertexArrays(1, &vertexArray);
//}

#include <Toxic.h>
#include <iostream>

using namespace toxic;

#define PRINT(x) (std::cout << x << std::endl)

Toxic* engine;
Window* window;

int main(int argc, char** argv)
{
	window = new Window();
	engine = new Toxic();

	engine->Init(argc, argv);
	engine->SetDisplayMode(DisplayMode::RGB | DisplayMode::DOUBLE);

	engine->SetRenderWindow(*window);

	GetVer();

	std::cin.get();
	return 0;
}