/*
 * HardFire.h
 *
 *  Created on: 13 янв. 2018 г.
 *      Author: vadim
 */

#ifndef CORE_HARDFIRE_H_
#define CORE_HARDFIRE_H_

// code from web site hardfire.ru

#include <iostream>
#include <cmath>
#include <list>
#include <cstdio>
#include <vector>
#include <algorithm>
using namespace std;

// Алгоритмы для работы с вычислительной геометрией

// наибольший общий делитель двух чисел
long long gcd (long long a, long long b);

#define eps 1e-8

//*********************** Структуры данных ************************************
// Точка
class point
{
public:
    double x, y, z;
    // дополнительный параметр - индекс точки
    int i;
    // Создание точки (_x, _y)
    point( double _x, double _y ) : i( 0 )
    {
        x = _x;
        y = _y;
        z = 0;
    }
    point( double _x, double _y, double _z ) : i( 0 )
	{
		x = _x;
		y = _y;
		z = _z;
	}
    // Создание точки (0, 0)
    point() : x( 0 ), y( 0 ), z( 0 ), i( 0 )
    {
    }
};

// Прямая
class line
{
public:
    double a, b, c;
    // Создание прямой ax + by + c = 0
    line(double _a = 0, double _b = 0, double _c = 0)
    {
        a = _a;
        b = _b;
        c = _c;
    }
};
// Окружность
class circle
{
public:
    point c;
    double r;
    // Дополнительные данные
    double alpha;

    // Создание окружности с центром (x, y) и радиусом _r
    circle (double x, double y, double _r) : alpha( 0 )
    {
       c = point(x, y);
       r = _r;
    }
    // Создание окружности с центром p и радиусом _r
    circle (point p, double _r) : alpha( 0 )
    {
        c = p;
        r = _r;
    }
    circle () : r( 0 ), alpha( 0 )
    {
    }
};
// сравнение двух точек по принципу самая нижняя из самых левых
class less_of_posXY
{
public :
    bool operator () (point a, point b)
    {
        if ( std::abs (a.x - b.x) > eps)
            return a.x < b.x;

        if ( std::abs (a.y - b.y) <= eps) return false;
        return a.y < b.y;
    }
};
// равенство двух точек
class equal_point
{
public :
    bool operator () (point a, point b)
    {
        return std::abs( ( double )( a.x - b.x ) ) <= eps && std::abs( ( double )( a.y - b.y ) ) <= eps;
    }
};

#define sqr(x) ((x) * (x))
#define eq(a, b) (abs ((a) - (b)) <= eps)

// определитель второго порядка
double det (double a11, double a12, double a21, double a22);

// точка в трёхмерном пространстве
class gpoint
{
public :
    double x, y, z;
    gpoint (double _x = 0, double _y = 0, double _z = 0) : x (_x), y (_y), z (_z) {};
};

// вектор в трёхмерном пространстве
class gvector
{
public :
    double x, y, z;
    gvector (double _x = 0, double _y = 0, double _z = 0) : x (_x), y (_y), z (_z) {};
    gvector (gpoint a, gpoint b) : x (b.x - a.x), y (b.y - a.y), z (b.z - a.z) {};
    // абсолютная длина вектора
    double length ()
    {
        return sqrt (x * x + y * y + z * z);
    }
    // нормированный вектор
    gvector norm ()
    {
        double d = length ();
        if (! eq (d, 0))
            return gvector (x / d, y / d, z / d);
        else
            return gvector (x, y, z);
    }
    // умножение вектора на число
    gvector mul (double a)
    {
        return gvector (a * x, a * y, a * z);
    }
};

double scalar_mul (gvector a, gvector b);

// векторное произведение векторов
gvector vector_mul (gvector a, gvector b);

gpoint add_vector (gpoint p, gvector v, double k);

// прямая в трёхмерном пространстве
class gline
{
public :
    gpoint p;
    gvector v;
    gline () : p (gpoint (0, 0)), v (gvector (0, 0)) {};
    gline (gpoint _p, gvector _v) : p (_p), v (_v) {};
    gline (gpoint a, gpoint b) : p (a), v (gvector (a, b)) {};
    // лежит ли точка на прямой
    bool in_line (gpoint t)
    {
        return eq ((t.x - p.x) * v.y, (t.y - p.y) * v.x) &&
               eq ((t.x - p.x) * v.z, (t.z - p.z) * v.x) &&
               eq ((t.y - p.y) * v.z, (t.z - p.z) * v.y);
    }
};

// плоскость в трёхмерном пространстве
class gplane
{
public :
    double A, B, C, D;
    gplane (double _A = 0, double _B = 0, double _C = 0, double _D = 0) : A (_A), B (_B), C (_C), D (_D) {};
    gplane (gpoint a, gpoint b, gpoint c)
    {
        gvector N = vector_mul (gvector (a, b), gvector (a, c));
        A = N.x;
        B = N.y;
        C = N.z;
        D = - A * a.x - B * a.y - C * a.z;
    }
    // знак точки относительно плоскости
    int sign (gpoint a)
    {
        double s = A * a.x + B * a.y + C * a.z + D;
        if (eq (s, 0)) return 0;
        if (s < 0) return - 1;
        return 1;
    }
};


//-----------------------------------------------------------------------------
//*********************** Функции для работы с точками ************************
//-----------------------------------------------------------------------------

double dist (gpoint a, gpoint b);

double dist (gpoint a, gplane p);

double dist (gplane a, gplane b);

gpoint part_segment (gpoint a, gpoint b, double m, double n);

gpoint closest_point (gline l, gpoint p);

bool is_parallel (gline l1, gline l2);
//bool equal_lines (gline l1, gline l2)
//{
//    return is_parallel (l1, l2) && eq (dist (l1, l2), 0);
//}

// a1*x + b1*y = c1
// a2*x + b2*y = c2
bool system2 (double a1, double b1, double c1, double a2, double b2, double c2, gpoint &p);
// пересечение прямых
bool cross_lines (gline l1, gline l2, gpoint & p);


// положение двух прямых в пространстве
// 0 - совпадают
// 1 - параллельны
// 2 - срещивающиеся
// 3 - пересекаются (p - точка пересечения)
int type_of_position_lines (gline l1, gline l2, gpoint & p);

// расстояние между двумя точками
double dist(point a, point b);
// лежит ли точка в прямоугольнике, который образуют заданные точки
bool point_in_box (point t, point p1, point p2);
// наиболее левая из двух точек
point min_px (point a, point b);
// наиболее правая из двух точек
point max_px (point a, point b);
// наиболее низкая из двух точек
point min_py (point a, point b);
// наиболее высокая из двух точек
point max_py (point a, point b);

// полярный угол точки
double polar_angle (point p);
// полярное расстояние
double polar_dist (double alpha, double r1, double betta, double r2);
// отрезки :: деление отрезка в заданном отношении
point part_segment (point p1, point p2, double m, double n);
// поворот точки на заданный угол вокруг начала координат
point turn (point p, double alpha);
// поворот точки на заданный угол вокруг заданной точки
point turn_of (point p, double alpha, point c);
// добавление заданной части вектора к точке
point add_vector (point p, point p1, point p2, double k);
//-----------------------------------------------------------------------------
//*********************** Функции для работы с прямыми ************************
//-----------------------------------------------------------------------------
// уравнение прямой, проходящей через две точки
line toline (point p1, point p2);
// знак точки при подставлении в уравнение прямой
int point_in_line (line l, point p);
// параллельны ли прямые?
bool is_parallel_line (line l1, line l2);
// совпадают ли прямые?
bool is_equal_line (line l1, line l2);
// пересечение двух прямых
int cross_line (line l1, line l2, point &p);
// перпендикуляр к прямой, проходящий через заданную точку
line perp_line (line l, point p);
// проекция точки на прямую
point closest_point (line l, point p);
// расстояние от точки до прямой
double dist_point_to_line (point p, line l);
// прямая параллельная данной и лежащая на расстоянии d от неё
line parallel_line_of_dist (line l, double d);
// расстояние между параллельными прямыми
double dist_between_line (line l1, line l2);
//-----------------------------------------------------------------------------
//*********************** Функции для работы с отрезками **********************
//-----------------------------------------------------------------------------
// принадлежит ли точка на отрезку?
bool point_in_segment (point t, point p1, point p2);

// пересекаются ли отрезки?
bool is_cross_segment (point p1, point p2, point p3, point p4);
// пересечение отрезков
bool cross_segment (point p1, point p2, point p3, point p4, point &t);
// расстояние от точки до отрезка
double dist_point_to_segment (point p, point p1, point p2);

// пересечение отрезка с прямой
int cross_segment_line (point p1, point p2, line l, point &p);
//-----------------------------------------------------------------------------
//*********************** Функции для работы с треугольниками *****************
//-----------------------------------------------------------------------------
// ориентированная площадь треугольника
double area_triangle (point a, point b, point c);
// угол между тремя точками - через произведение векторов
double angle_point (point a, point b, point c);
//Лежит ли точка справа от отрезка в обходе против часовой стрелки?
bool ccw (point a, point b, point c);
// высота угла
line height_line (point a, point b, point c);
// медиана угла
line median_line (point a, point b, point c);
// биссектриса угла
line bisector_line (point a, point b, point c);
// вписанная в треугольник окружность
circle entered_circle (point a, point b, point c);
// описанная около треугольника окружность
circle described_circle (point a, point b, point c);
//-----------------------------------------------------------------------------
//*********************** Функции для работы с окружностями *******************
//-----------------------------------------------------------------------------
// положение точки относительно окружности
int point_in_circle (point p, circle c);
// минимальная окружность покрывающая три любые точки
circle min_circle_for_three_point (point a, point b, point c);
// точки пересечения касательной с окружностью, решение основанное на повороте точек
int tangent_points (point p, circle c, point &p1, point &p2);

// пересечение прямой с окружностью
int cross_line_circle (line l, circle c, point &p1, point &p2);
// пересечение окружностей
int cross_circle (double x1, double y1, double r1,
                  double x2, double y2, double r2, point &p1, point &p2);
// точки касания касательной с окружностью
int contact_points (point p, circle c, point &p1, point &p2);
//-----------------------------------------------------------------------------
//*********************** Функции для работы с лучами *************************
//-----------------------------------------------------------------------------
// принадлежит ли точка лучу?
bool point_in_ray (point p, point p1, point p2);
// расстояние от точки до луча
double dist_point_to_ray (point p, point p1, point p2);
// пересение луча с окружностью
int cross_ray_circle (point p, point t, circle c, point &p1, point &p2);
// поиск луча с известным началом, который не пересекает ни одну из заданных окружностей
class less_of_polar_angle
{
public :
    bool operator () (circle c1, circle c2)
    {
        return c1.alpha < c2.alpha;
    }
};
bool ray_nocross_for_circset (point p, vector < circle > v, point &t);
//-----------------------------------------------------------------------------
//*********************** Функции для работы с многоугольниками ***************
//-----------------------------------------------------------------------------
// ориентированная площадь многоугольника
double area_polygon (vector < point > p);

// периметр многоугольника
double perimeter_polygon (vector < point > p);
// принадлежит ли точка в многоугольнику?
bool point_in_polygon (point t, vector < point > p);
// количество точек на границе многоугольника
long long count_B (vector < point > p);
// количество точек внутри многоугольника
long long count_I (vector < point > p);
// выпуклый ли многоугольник?
bool is_convex (vector < point > p);
// выпуклая оболочка - алгоритм Джарвиса
void hull_jarvis (vector < point > p, vector < int > &ip);
// выпуклая оболочка - алгоритм Грехема
void hull_graham (vector < point > p, vector < int > &ip);
// минимальная окружность, покрывающая множество точек
circle min_described_circle (vector < point > p);
// расположение многоугольника отосительно прямой
//        1 - находится с положительной стороны
//        - 1 - находится с отрицательной стороны
//        0 - прямая пересекает одну из сторон многоугольника (сторону а не вершину)
int polygon_for_line (vector < point > p, line l);

// разрезание многоугольника по диагонали
void cut_polygon_for_edge (vector < point > p, int i1, int i2, vector < point > &p1, vector < point > &p2);
// разрезание выпуклого многоугольника по прямой
//        функция возвращает два многоугольника
//        первый многоугольник лежит с положительной стороны от прямой
//        второй - с отрицательной
void cut_convex_for_line (vector < point > p, line l, vector < point > &v1, vector < point > &v2, point &p1, point &p2);

// разрезание выпуклого многоугольника в отношении площадей m:n
point part_convex (vector < point > v, double m, double n);
// разрезание выпуклого многоугольника на k равных частей
void npart_convex (std::vector < point > v, int k, vector < point > &s);


#endif /* CORE_HARDFIRE_H_ */
