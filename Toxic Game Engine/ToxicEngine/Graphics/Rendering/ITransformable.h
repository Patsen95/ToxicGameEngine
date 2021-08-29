#pragma once

#include "../../Config.h"
#include "../../Math/Math.h"
#include "../../Math/Vec2.h"
#include "TransformMatrix.h"


namespace toxic
{
	class TOXIC_API ITransformable
	{
	public:
		ITransformable();
		~ITransformable();
		
		void SetPosition(float x, float y);
		void SetPosition(const Vec2f& point);
		void SetScale(float factor);
		void SetScale(float facX, float facY);
		void SetScale(const Vec2f& factor);
		void SetRotation(float angle);
		void SetOrigin(float x, float y);
		void SetOrigin(const Vec2f& point);

		void Move(float dx, float dy);
		void Move(const Vec2f& offset);
		void Scale(float df);
		void Scale(float dfx, float dfy);
		void Scale(const Vec2f& factor);
		void Rotate(float angle);
				
		const Vec2f& GetPosition() const;
		const Vec2f& GetScale() const;
		const Vec2f& GetOrigin() const;
		float GetRotation() const;
		const TransformMatrix& GetTransfrom() const;
		const TransformMatrix& GetInverseTransform() const;

	private:
		Vec2f _origin;
		Vec2f _position;
		Vec2f _scale;
		float _rotation;
		mutable TransformMatrix _transform;
		mutable TransformMatrix _inverseTransform;
		mutable bool _needUpdate;
		mutable bool _inverseNeedUpdate;
	};
}
