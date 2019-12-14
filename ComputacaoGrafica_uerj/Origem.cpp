#include <GL/freeglut.h>
// Fun��es callback
void desenha(void);
void movimento(int x, int y);
void botao(int button, int state, int x, int y);
void alteraTamanhoJanela(GLsizei w, GLsizei h);
// Vari�veis globais
float largura, altura; // tamanho da world window e do viewport
float rx, ry; // posi��o inicial do ret�ngulo vermelho

int main(int argc, char *argv[])
{
	largura = 800;
	altura = 600;
	glutInit(&argc, argv);
	glutInitDisplayMode(GLUT_RGBA | GLUT_DOUBLE);
	glClearColor(0, 0, 0, 1);
	glutCreateWindow("Exemplo 4 - Interface Movimento");
	glutPositionWindow(200, 100);
	glutReshapeWindow(largura, altura);
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	gluOrtho2D(0, largura, 0, altura);
	glMatrixMode(GL_MODELVIEW);
	glLoadIdentity();
	glutDisplayFunc(desenha);
	glutIdleFunc(desenha);
	glutMotionFunc(movimento);
	glutMouseFunc(botao);
	glutReshapeFunc(alteraTamanhoJanela);

	glutMainLoop();
	return 0;
}

// Fun��o callback chamada para fazer o desenho
void desenha(void)
{
	glClear(GL_COLOR_BUFFER_BIT);
	glColor3f(1, 1, 0); // desenha em amarelo
	glRectf(100, 100, 300, 200); // desenha ret�ngulo amarelo
	glColor3f(1, 0, 0); // desenha em vermelho
	glRectf(rx, ry, 100 + rx, 20 + ry); // desenha ret�ngulo vermelho
	glutSwapBuffers(); // buffer de cor duplo
}
// Fun��o callback para o mouse se movimentando com bot�o pressionado
void movimento(int x, int y)
{
	rx = x; ry = altura - y;
}
// Fun��o callback chamada quando o bot�o do mouse � pressionado
void botao(int button, int state, int x, int y)
{
	if (button == GLUT_LEFT_BUTTON && state == GLUT_DOWN)
		rx = x; ry = altura - y;
}

// Fun��o callback chamada quando o tamanho da janela � alterado
void alteraTamanhoJanela(GLsizei w, GLsizei h)
{
	largura = w;
	altura = h;
	// Especifica as dimens�es da Viewport
	glViewport(0, 0, largura, altura); // comando n�o necess�rio:
//comportamento default
// Inicializa o sistema de coordenadas do mundo
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	// Dimens�es da World Window (left, right, bottom, top)
	gluOrtho2D(0, largura, 0, altura);
}
