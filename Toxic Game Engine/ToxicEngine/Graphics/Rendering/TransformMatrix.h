#pragma once

#include "../../Config.h"
#include "../../Graphics/AARect.h"
#include "../../Math/Matrix.h"
#include "../../Math/Vec2.h"



namespace toxic
{
	class TOXIC_API TransformMatrix
	{
	public:
		TransformMatrix();
		TransformMatrix(const Matrix_f& matrix);
		TransformMatrix(float c00, float c01, float c02,
						float c10, float c11, float c12,
						float c20, float c21, float c22);
		TransformMatrix(const TransformMatrix& tMatrix);

		TransformMatrix operator*(const TransformMatrix& other);
		Vec2f operator*(const Vec2f& other);
		TransformMatrix& operator*=(const TransformMatrix& other);
		bool operator==(const TransformMatrix& other);
		bool operator!=(const TransformMatrix& other);

		const Matrix_f& GetMatrix() const;
		TransformMatrix GetInverse() const;
		Vec2f TransformPoint(float x, float y) const;
		Vec2f TransformPoint(const Vec2f& dvec) const;
		AARect TransformRect(const AARect& drect) const;
		TransformMatrix& Combine(const TransformMatrix& transform);
		TransformMatrix& Combine(const Matrix_f& transform);
		TransformMatrix& Translate(float dx, float dy);
		TransformMatrix& Translate(const Vec2f& dvec);
		TransformMatrix& Rotate(float angle);
		TransformMatrix& Rotate(float angle, float centerX, float centerY);
		TransformMatrix& Rotate(float angle, const Vec2f& center);
		TransformMatrix& Scale(float dx, float dy);
		TransformMatrix& Scale(float dx, float dy, float centerX, float centerY);
		TransformMatrix& Scale(const Vec2f& factor);
		TransformMatrix& Scale(const Vec2f& factor, const Vec2f& center);

		static const TransformMatrix Identity;

	private:
		Matrix_f _m;		
	};
}
