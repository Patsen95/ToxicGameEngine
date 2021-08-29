//#include "Object.h"
//#include "../Rendering/RenderTarget.h"
//
//
//
//namespace toxic
//{
//	Vec2f ComputeNormal(const Vec2f& p1, const Vec2f& p2)
//	{
//		Vec2f normal(p1.y - p2.y, p2.x - p1.x);
//		float len = normal.Length();
//		if(len != 0.0f)
//			normal /= len;
//		return normal;
//	}
//	//////////////////////////////////////////////////////////
//	size_t Object::GetVertexCount() const
//	{
//		return size_t();
//	}
//
//	Vec2f Object::GetVertexPosFromIndex(size_t idx) const
//	{
//		return Vec2f();
//	}
//	//////////////////////////////////////////////////////////
//	Object::Object()
//	{
//		_texture = nullptr;
//		_textureRect = AARect();
//		_fillColor = Color();
//		_outlineColor = Color();
//		_outlineWidth = 0;
//		_vertices = VertexArray(PrimitiveType::TRIANGLE_FAN);
//		_outline = VertexArray(PrimitiveType::TRIANGLE_STRIP);
//		_innerBounds = AARect();
//		_objectBounds = AARect();
//		_states = new ObjectStates();
//	}
//
//	void Object::Update()
//	{
//		size_t cnt = GetVertexCount();
//		if(cnt < 3)
//		{
//			_vertices.Resize(0);
//			_outline.Resize(0);
//			return;
//		}
//		_vertices.Resize(cnt + 2);
//
//		for(size_t i = 0; i < cnt; ++i)
//			_vertices[i + 1].SetPosition(GetVertexPosFromIndex(i));
//		_vertices[cnt + 1].SetPosition(_vertices[1].GetPosition());
//		
//		_vertices[0] = _vertices[1];
//		_innerBounds = _vertices.GetBoundingRect();
//
//		_vertices[0].SetPosition((_innerBounds.GetX() + _innerBounds.GetWidth()) / 2, (_innerBounds.GetY() + _innerBounds.GetHeight()) / 2);
//
//		UpdateFill();
//		UpdateTextureCoords();
//		UpdateOutline();
//	}
//
//	void Object::Render(RenderTarget& target) const
//	{
//		_states->SetTransform(_states->GetTransform() * GetTransfrom());
//		_states->SetTexture(_texture);
//		// TODO - render
//
//		// target.Render(_vertices);
//		if(_outlineWidth != 0)
//		{
//			_states->SetTexture(nullptr);
//
//			// TODO - render
//			// target.Render(_outline);
//		}
//	}
//
//	void Object::UpdateFill()
//	{
//	}
//
//	void Object::UpdateOutline()
//	{
//	}
//
//	void Object::UpdateOutlineColor()
//	{
//	}
//
//	void Object::UpdateTextureCoords()
//	{
//	}
//	//////////////////////////////////////////////////////////
//	Object::~Object() { }
//
//	void Object::SetTexture(const Texture* texture, bool resize)
//	{
//		if(texture)
//		{
//			if(resize || (!_texture && (_textureRect == AARect())))
//				TrimTexture(AARect(0, 0, texture->GetSize().x, texture->GetSize().y));
//		}
//		_texture = texture;
//	}
//
//	void Object::TrimTexture(int x, int y, int w, int h)
//	{
//		_textureRect = AARect(x, y, w, h);
//		UpdateTextureCoords();
//	}
//
//	void Object::TrimTexture(const Vec2f& position, const Vec2f& size)
//	{
//		_textureRect = AARect(position, size);
//		UpdateTextureCoords();
//	}
//
//	void Object::TrimTexture(const AARect& trimRect)
//	{
//		_textureRect = trimRect;
//		UpdateTextureCoords();
//	}
//
//	void Object::FillColor(const Color& color)
//	{
//		_fillColor = color;
//		UpdateFill();
//	}
//
//	void Object::OutlineColor(const Color& color)
//	{
//		_outlineColor = color;
//		UpdateOutlineColor();
//	}
//
//	void Object::OutlineWidth(float width)
//	{
//		_outlineWidth = width;
//		Update();
//	}
//
//	const Texture* Object::GetTexture() const
//	{
//		return _texture;
//	}
//
//	const AARect& Object::GetTextureBounding() const
//	{
//		return _textureRect;
//	}
//
//	const Color& Object::GetFillColor() const
//	{
//		return _fillColor;
//	}
//
//	const Color& Object::GetOutlineColor() const
//	{
//		return _outlineColor;
//	}
//
//	float Object::GetOutlineWidth() const
//	{
//		return _outlineWidth;
//	}
//
//	AARect Object::GetLocalBounding() const
//	{
//		return _objectBounds;
//	}
//
//	AARect Object::GetGlobalBounding() const
//	{
//		return GetTransfrom().TransformRect(_objectBounds);
//	}
//
//}
