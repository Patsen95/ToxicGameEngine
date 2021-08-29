#include "TransformMatrix.h"
#include "../../Math/Math.h"



namespace toxic
{
	const TransformMatrix TransformMatrix::Identity;

	TransformMatrix::TransformMatrix()
	{
		_m = Matrix_f(4, 4);
		_m.SetIdentity();
	}

	TransformMatrix::TransformMatrix(const Matrix_f& matrix)
	{
		_m = matrix;
	}

	TransformMatrix::TransformMatrix(float c00, float c01, float c02,
									float c10, float c11, float c12,
									float c20, float c21, float c22)
	{
		_m(0, 0) = c00; _m(1, 0) = c01; _m(2, 0) = 0.0f; _m(3, 0) = c02;
		_m(0, 1) = c10; _m(1, 1) = c11; _m(2, 1) = 0.0f; _m(3, 1) = c12;
		_m(0, 2) = 0.f; _m(1, 2) = 0.f; _m(2, 2) = 1.0f; _m(3, 2) = 0.f;
		_m(0, 3) = c20; _m(1, 3) = c21; _m(2, 3) = 0.0f; _m(3, 3) = c22;
	}

	TransformMatrix::TransformMatrix(const TransformMatrix& tMatrix)
	{
		this->_m = tMatrix._m;
	}

	TransformMatrix TransformMatrix::operator*(const TransformMatrix& other)
	{
		return TransformMatrix((*this)).Combine(other);
	}

	Vec2f TransformMatrix::operator*(const Vec2f& other)
	{
		return this->TransformPoint(other);
	}

	TransformMatrix& TransformMatrix::operator*=(const TransformMatrix& other)
	{
		return this->Combine(other);
	}

	bool TransformMatrix::operator==(const TransformMatrix& other)
	{
		const float* a = this->_m.GetRawMatrix();
		const float* b = other._m.GetRawMatrix();
		return ((a[0] == b[0]) && (a[1] == b[1]) && (a[3] == b[3]) &&
				(a[4] == b[4]) && (a[5] == b[5]) && (a[7] == b[7]) &&
				(a[12] == b[12]) && (a[13] == b[13]) && (a[15] == b[15]));
	}

	bool TransformMatrix::operator!=(const TransformMatrix& other)
	{
		return !((*this) == other);
	}

	const Matrix_f& TransformMatrix::GetMatrix() const
	{
		return this->_m;
	}

	TransformMatrix TransformMatrix::GetInverse() const
	{
		float det = _m(0, 0) * (_m(1, 1) * _m(3, 3) - _m(1, 3) * _m(1, 3)) -
					_m(0, 1) * (_m(1, 0) * _m(3, 3) - _m(3, 0) * _m(1, 3)) +
					_m(0, 3) * (_m(1, 0) * _m(3, 1) - _m(3, 0) * _m(1, 1));
		if(det != 0.0f)
		{
			float c0 = (_m(1, 1) * _m(3, 3) - _m(1, 3) * _m(1, 3)) / det;
			float c1 = -(_m(1, 0) * _m(3, 3) - _m(3, 0) * _m(1, 3)) / det;
			float c2 = (_m(1, 0) * _m(3, 1) - _m(3, 0) * _m(1, 1)) / det;
			float c3 = -(_m(0, 1) * _m(3, 3) - _m(0, 2) * _m(3, 1)) / det;
			float c4 = (_m(0, 0) * _m(3, 3) - _m(0, 3) * _m(3, 0)) / det;
			float c5 = -(_m(0, 0) * _m(3, 1) - _m(0, 1) * _m(3, 0)) / det;
			float c6 = (_m(1, 3) * _m(0, 1) - _m(0, 3) * _m(1, 1)) / det;
			float c7 = -(_m(0, 0) * _m(2, 3) - _m(0, 3) * _m(1, 0)) / det;
			float c8 = (_m(0, 0) * _m(1, 1) - _m(0, 3) * _m(1, 0)) / det;
			return TransformMatrix(c0, c1, c2, c3, c4, c5, c6, c7, c8);
		}
		return Identity;
	}

	Vec2f TransformMatrix::TransformPoint(float x, float y) const
	{
		return Vec2f(_m(0, 0) * x + _m(1, 0) * y + _m(3, 0),
			_m(0, 1) * x + _m(1, 1) * y + _m(3, 1));
	}

	Vec2f TransformMatrix::TransformPoint(const Vec2f& dvec) const
	{
		return TransformPoint(dvec.x, dvec.y);
	}

	AARect TransformMatrix::TransformRect(const AARect& drect) const
	{
		const Vec2f points[] =
		{
			TransformPoint(drect.GetX(), drect.GetY()),
			TransformPoint(drect.GetX(), drect.GetY() + drect.GetHeight()),
			TransformPoint(drect.GetX() + drect.GetWidth(), drect.GetY()),
			TransformPoint(drect.GetX() + drect.GetWidth(), drect.GetY() + drect.GetHeight()),
		};

		float x = points[0].x;
		float y = points[0].y;
		float w = points[0].x;
		float h = points[0].y;
		for(unsigned i = 1; i < 4; ++i)
		{
			if(points[i].x < x)
				x = points[i].x;
			if(points[i].x > w)
				w = points[i].x;
			if(points[i].y < y)
				y = points[i].y;
			if(points[i].y > h)
				h = points[i].y;
		}
		return AARect(x, y, w - x, h - y);
	}

	TransformMatrix& TransformMatrix::Combine(const TransformMatrix& transform)
	{
		const float* a = _m.GetRawMatrix();
		const float* b = transform._m.GetRawMatrix();

		float c0 = a[0] * b[0] + a[4] * b[1] + a[12] * b[3];
		float c1 = a[0] * b[4] + a[4] * b[5] + a[12] * b[7];
		float c2 = a[0] * b[12] + a[4] * b[13] + a[12] * b[15];
		float c3 = a[1] * b[0] + a[5] * b[1] + a[13] * b[3];
		float c4 = a[1] * b[4] + a[5] * b[5] + a[13] * b[7];
		float c5 = a[1] * b[12] + a[5] * b[13] + a[13] * b[15];
		float c6 = a[3] * b[0] + a[7] * b[1] + a[15] * b[3];
		float c7 = a[3] * b[4] + a[7] * b[5] + a[15] * b[7];
		float c8 = a[3] * b[12] + a[7] * b[13] + a[15] * b[15];
		(*this) = TransformMatrix(c0, c1, c2, c3, c4, c5, c6, c7, c8);
		return (*this);
	}

	TransformMatrix & TransformMatrix::Combine(const Matrix_f& transform)
	{
		const float* a = _m.GetRawMatrix();
		const float* b = transform.GetRawMatrix();

		float c0 = a[0] * b[0] + a[4] * b[1] + a[12] * b[3];
		float c1 = a[0] * b[4] + a[4] * b[5] + a[12] * b[7];
		float c2 = a[0] * b[12] + a[4] * b[13] + a[12] * b[15];
		float c3 = a[1] * b[0] + a[5] * b[1] + a[13] * b[3];
		float c4 = a[1] * b[4] + a[5] * b[5] + a[13] * b[7];
		float c5 = a[1] * b[12] + a[5] * b[13] + a[13] * b[15];
		float c6 = a[3] * b[0] + a[7] * b[1] + a[15] * b[3];
		float c7 = a[3] * b[4] + a[7] * b[5] + a[15] * b[7];
		float c8 = a[3] * b[12] + a[7] * b[13] + a[15] * b[15];
		(*this) = TransformMatrix(c0, c1, c2, c3, c4, c5, c6, c7, c8);
		return (*this);
	}

	TransformMatrix& TransformMatrix::Translate(float dx, float dy)
	{
		TransformMatrix _tr(1, 0, dx, 0, 1, dy, 0, 0, 1);
		return Combine(_tr);
	}

	TransformMatrix& TransformMatrix::Translate(const Vec2f& dvec)
	{
		return Translate(dvec.x, dvec.y);
	}

	TransformMatrix& TransformMatrix::Rotate(float angle)
	{
		float cos = Math::Cos(Math::ToRadians(angle));
		float sin = Math::Sin(Math::ToRadians(angle));

		TransformMatrix _rot(cos, -sin, 0, sin, cos, 0, 0, 0, 1);
		return Combine(_rot);
	}

	TransformMatrix& TransformMatrix::Rotate(float angle, float centerX, float centerY)
	{
		float cos = Math::Cos(Math::ToRadians(angle));
		float sin = Math::Sin(Math::ToRadians(angle));

		TransformMatrix _rot(cos, -sin, centerX * (1 - cos) + centerY * sin,
			sin, cos, centerY * (1 - cos) - centerX * sin, 0, 0, 1);
		return Combine(_rot);
	}

	TransformMatrix& TransformMatrix::Rotate(float angle, const Vec2f& center)
	{
		return Rotate(angle, center.x, center.y);
	}

	TransformMatrix& TransformMatrix::Scale(float dx, float dy)
	{
		TransformMatrix _scale(dx, 0, 0, 0, dy, 0, 0, 0, 1);
		return Combine(_scale);
	}

	TransformMatrix& TransformMatrix::Scale(float dx, float dy, float centerX, float centerY)
	{
		TransformMatrix _scale(dx, 0, centerX * (1 - centerX), 0, dy, centerY* (1 - centerY), 0, 0, 1);
		return Combine(_scale);
	}

	TransformMatrix& TransformMatrix::Scale(const Vec2f& factor)
	{
		return Scale(factor.x, factor.y);
	}

	TransformMatrix& TransformMatrix::Scale(const Vec2f& factor, const Vec2f& center)
	{
		return Scale(factor.x, factor.y, center.x, center.y);
	}
}
