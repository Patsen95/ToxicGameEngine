#include "ITransformable.h"



namespace toxic
{
	ITransformable::ITransformable()
	{
		_origin = Vec2f();
		_position = Vec2f();
		_scale = Vec2f(1, 1);
		_transform = TransformMatrix();
		_inverseTransform = TransformMatrix();
		_needUpdate = true;
		_inverseNeedUpdate = true;
	}

	ITransformable::~ITransformable() {}

	void ITransformable::SetPosition(float x, float y)
	{
		_position = Vec2f(x, y);
		_needUpdate = true;
		_inverseNeedUpdate = true;
	}

	void ITransformable::SetPosition(const Vec2f& point)
	{
		_position = point;
		_needUpdate = true;
		_inverseNeedUpdate = true;
	}

	void ITransformable::SetScale(float factor)
	{
		_scale = Vec2f(factor, factor);
		_needUpdate = true;
		_inverseNeedUpdate = true;
	}

	void ITransformable::SetScale(float facX, float facY)
	{
		_scale = Vec2f(facX, facY);
		_needUpdate = true;
		_inverseNeedUpdate = true;
	}

	void ITransformable::SetScale(const Vec2f& factor)
	{
		_scale = factor;
		_needUpdate = true;
		_inverseNeedUpdate = true;
	}

	void ITransformable::SetRotation(float angle)
	{
		_rotation = angle;
		_needUpdate = true;
		_inverseNeedUpdate = true;
	}

	void ITransformable::SetOrigin(float x, float y)
	{
		_origin = Vec2f(x, y);
		_needUpdate = true;
		_inverseNeedUpdate = true;
	}

	void ITransformable::SetOrigin(const Vec2f& point)
	{
		_origin = point;
		_needUpdate = true;
		_inverseNeedUpdate = true;
	}

	void ITransformable::Move(float dx, float dy)
	{
		SetPosition(_position.x + dx, _position.y + dy);
	}

	void ITransformable::Move(const Vec2f& offset)
	{
		SetPosition(_position.x + offset.x, _position.y + offset.y);
	}

	void ITransformable::Scale(float df)
	{
		SetScale(_scale.x + df, _scale.y + df);
	}

	void ITransformable::Scale(float dfx, float dfy)
	{
		SetScale(_scale.x + dfx, _scale.y + dfy);
	}

	void ITransformable::Scale(const Vec2f& factor)
	{
		SetScale(_scale.x * factor.x, _scale.y * factor.y);
	}

	void ITransformable::Rotate(float angle)
	{
		SetRotation(_rotation + angle);
	}

	const Vec2f& ITransformable::GetPosition() const
	{
		return this->_position;
	}

	const Vec2f& ITransformable::GetScale() const
	{
		return this->_scale;
	}

	const Vec2f& ITransformable::GetOrigin() const
	{
		return this->_origin;
	}

	float ITransformable::GetRotation() const
	{
		return this->_rotation;
	}

	const TransformMatrix& ITransformable::GetTransfrom() const
	{
		if(_needUpdate)
		{
			float rangle = Math::ToRadians(-_rotation);
			float sine = Math::Sin(rangle);
			float cosine = Math::Cos(rangle);
			float sxc = _scale.x * cosine;
			float syc = _scale.y * cosine;
			float sxs = _scale.x * sine;
			float sys = _scale.y * sine;
			float tx = -_origin.x * sxc - _origin.y * sys + _position.x;
			float ty = _origin.x * sxs - _origin.y * syc + _position.y;
			_transform = TransformMatrix(sxc, sys, tx, -sxs, syc, ty, 0.0f, 0.0f, 1.0f);
			_needUpdate = false;
		}
		return _transform;
	}

	const TransformMatrix& ITransformable::GetInverseTransform() const
	{
		if(_inverseNeedUpdate)
		{
			_inverseTransform = GetTransfrom().GetInverse();
			_inverseNeedUpdate = false;
		}
		return _inverseTransform;
	}

}
