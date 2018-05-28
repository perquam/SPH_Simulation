#pragma once
#include <QGLWidget>
#include <QTimer>
#include <vector>

#include "C:\Users\Filip\source\repos\OpenGLnew\OpenGLnew\eigen3\Eigen\Dense"
using namespace Eigen;
using namespace std;

class GLWidget : public QGLWidget
{
	Q_OBJECT
public:
	explicit GLWidget(QWidget *parent = 0);

	void initializeGL();
	void paintGL();
	void resizeGL(int w, int h);

	void InitSPH();
	void Integrate();
	void ComputeDensityPressure();
	void ComputeForces();
	void Update();
	void Render();

	// Funkcje zwracajace wartosci, ktore wyswietlamy.
	int particles_Number();
	int m_Value();
	double g_Value();

	struct Particle {
		Particle(float _x, float _y) : x(_x, _y), v(0.f, 0.f), f(0.f, 0.f), rho(0), p(0.f) {}
		Vector2d x, v, f;
		float rho, p;
	};

public slots:
	void add_Particle();
	void change_gValue(int);

private:

	Vector2d G;

	// Parametry fizyczne.
	const float REST_DENS = 1000.; // Stala potrzebna do rownania stanu gazu doskonalego.
	const float GAS_CONST = 2000.; // Stala potrzebna do rownania stanu gazu doskonalego.
	const float H = 15.; // Promien, wokol ktorego uwzgledniamy czastki.
	const float HSQ = H * H; // Promien^2.
	const float MASS = 30.; // Masa czastek.
	const float VISC = 250.; // Stala(potrzeba do sily lepkosci).
	float g = 9.8;

	const float DT = 0.0008f; // Odstep calkowania.
	const float M_PI = 1;

	// smoothing kernels defined in Müller and their gradients
	const float POLY6 = 315.f / (65.f*M_PI*pow(H, 9.f));
	const float SPIKY_GRAD = -45.f / (M_PI*pow(H, 6.f));
	const float VISC_LAP = 45.f / (M_PI*pow(H, 6.f));

	// Parametry symulacji.
	const float EPS = 1; // boundary epsilon
	const float BOUND_DAMPING = -0.5f;
	const static int MAX_PARTICLES = 2500;
	const static int DAM_PARTICLES = 200; // Poczatkowa liczba czastek.
	const static int BLOCK_PARTICLES = 250;
	const int WINDOW_WIDTH = 400;
	const int WINDOW_HEIGHT = 400;
	const double VIEW_WIDTH = 1.5*400.f;
	const double VIEW_HEIGHT = 1.5*400.f;

	// Stale dotyczace warunkow brzegowych(naczynie).
	const int boundary_x_l = 250;
	const int boundary_x_r = 400;
	const int boundary_thickness = 15;
	const int boundary_y_t = 300;

	// Kontener na czasteczki.
	vector<Particle> particles;
};

