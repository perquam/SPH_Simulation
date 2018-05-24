#include "GLWidget.h"
#include "ui_SPH.h"

#include <iostream>

void GLWidget::InitSPH(void)
{
	G(0) = 0.;
	G(1) = -12000 * g;
	// Inicjowanie polozen poczatkowych.
	for (float y = EPS; y < VIEW_HEIGHT - EPS * 2.f; y += H)
		for (float x = VIEW_WIDTH / 4; x <= VIEW_WIDTH / 2; x += H)
			if (particles.size() < DAM_PARTICLES)
			{
				float jitter = static_cast <float> (rand()) / static_cast <float> (RAND_MAX);
				particles.push_back(Particle(x + jitter, y));
			}
}

void GLWidget::Integrate(void)
{
	for (auto &p : particles)
	{
		p.v += DT * p.f / p.rho; //Zmiana predkosci.
		p.x += DT * p.v; // Zmiana polozenia.

		// Warunki brzegowe.
		if (p.x(0) - EPS < boundary_x_l)
		{
			p.v(0) *= BOUND_DAMPING;
			p.x(0) = boundary_x_l + EPS;
		}
		if (p.x(0) + EPS > boundary_x_r)
		{
			p.v(0) *= BOUND_DAMPING;
			p.x(0) = boundary_x_r - EPS;
		}
		if (p.x(1) - EPS < boundary_thickness)
		{
			p.v(1) *= BOUND_DAMPING;
			p.x(1) = EPS + boundary_thickness;
		}
		if (p.x(1) + EPS > VIEW_HEIGHT)
		{
			p.v(1) *= BOUND_DAMPING;
			p.x(1) = VIEW_HEIGHT - EPS;
		}
	}
}

void GLWidget::ComputeDensityPressure(void)
{
	for (auto &pi : particles)
	{
		pi.rho = 0.f;
		for (auto &pj : particles)
		{
			Vector2d rij = pj.x - pi.x;
			float r2 = rij.squaredNorm();

			if (r2 < HSQ)
			{
				// Obliczanie gestosci.
				pi.rho += MASS * POLY6*pow(HSQ - r2, 3.);
			}
		}
		// Obliczanie cisnienia.
		pi.p = GAS_CONST * (pi.rho - REST_DENS);
	}
}

void GLWidget::ComputeForces(void)
{
	for (auto &pi : particles)
	{
		Vector2d fpress(0.f, 0.f);
		Vector2d fvisc(0.f, 0.f);
		for (auto &pj : particles)
		{
			if (&pi == &pj)
				continue;

			Vector2d rij = pj.x - pi.x;
			float r = rij.norm();

			if (r < H)
			{
				// Wklad sil wynikajacych z cisnienia.
				fpress += -rij.normalized()*MASS*(pi.p + pj.p) / (2.f * pj.rho) * SPIKY_GRAD*pow(H - r, 2.f);
				// Wklad sil lepkosci.
				fvisc += VISC * MASS*(pj.v - pi.v) / pj.rho * VISC_LAP*(H - r);
			}
		}
		Vector2d fgrav = G * pi.rho;
		// Sila wypadkowa.
		pi.f = fpress + fvisc + fgrav;
	}
}

void GLWidget::Update(void)
{
	ComputeDensityPressure();
	ComputeForces();
	Integrate();

}

void GLWidget::Render(void)
{
	glClear(GL_COLOR_BUFFER_BIT);
	glLoadIdentity();
	glOrtho(0, VIEW_WIDTH, 0, VIEW_HEIGHT, 0, 1);
	glColor4f(0.2f, 0.6f, 1.0f, 1);
	glBegin(GL_POINTS);
	for (auto &p : particles)
		glVertex2f(p.x(0), p.x(1));

	glEnd();

	glColor3f(0.0f, 0.0f, 0.5f);
	glRectf(boundary_x_l - boundary_thickness, boundary_y_t, boundary_x_l, 0);
	glRectf(boundary_x_r, boundary_y_t, boundary_x_r + boundary_thickness, 0);
	glRectf(boundary_x_l, boundary_thickness, boundary_x_r + boundary_thickness, 0);
}

GLWidget::GLWidget(QWidget *parent) : QGLWidget(parent)
{
	initializeGL();
	InitSPH();
}

void GLWidget::initializeGL()
{
	// Ustawianie tla oraz rozmiaru punktow.
	glClearColor(0.1f, 0.1f, 0.1f, 1);
	glEnable(GL_POINT_SMOOTH);
	glPointSize(H / 2.f);
	glMatrixMode(GL_PROJECTION);
}

void GLWidget::paintGL()
{
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
	Render();
	// Aktualizowanie.
	Update();
}

void GLWidget::resizeGL(int w, int h)
{
	glViewport(0, 0, WINDOW_WIDTH, WINDOW_HEIGHT);
	updateGL();
}

void GLWidget::add_Particle()
{
	int x = 300;
	int y = boundary_y_t - 20;
	particles.push_back(Particle(x, y));
}

int GLWidget::particles_Number()
{
	return particles.size();
}

int GLWidget::m_Value()
{
	return MASS;
}

double GLWidget::g_Value()
{
	return g;
}
void GLWidget::change_gValue(int new_g)
{
	g = new_g;
	G(1) = -12000 * g;
}
