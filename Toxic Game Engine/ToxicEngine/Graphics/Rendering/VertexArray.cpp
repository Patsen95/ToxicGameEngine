//#include "VertexArray.h"
//#include "RenderTarget.h"
//
//
//
//namespace toxic
//{
//	VertexArray::VertexArray()
//	{
//		_vertices = std::vector<Vertex>();
//		_primType = PrimitiveType::POINTS;
//	}
//
//	VertexArray::VertexArray(PrimitiveType type, size_t vertCnt)
//	{
//		_vertices = std::vector<Vertex>(vertCnt);
//		_primType = type;
//	}
//
//	Vertex& VertexArray::operator[](std::size_t index)
//	{
//		return _vertices[index];
//	}
//
//	const Vertex& VertexArray::operator[](std::size_t index) const
//	{
//		return _vertices[index];
//	}
//
//	void VertexArray::Add(const Vertex& vert)
//	{
//		_vertices.push_back(vert);
//	}
//
//	void VertexArray::Resize(size_t newSize)
//	{
//		_vertices.resize(newSize);
//	}
//
//	void VertexArray::Remove(long index)
//	{
//		_vertices.erase(_vertices.begin() + index);
//	}
//
//	void VertexArray::Clear()
//	{
//		_vertices.clear();
//	}
//
//	void VertexArray::SetPrimitiveType(const PrimitiveType& type)
//	{
//		_primType = type;
//	}
//
//	size_t VertexArray::GetVertexCount() const
//	{
//		return _vertices.size();
//	}
//
//	AARect VertexArray::GetBoundingRect() const
//	{
//		if(!_vertices.empty())
//		{
//			float x = _vertices[0].GetPosition().x;
//			float y = _vertices[0].GetPosition().y;
//			float w = _vertices[0].GetPosition().x;
//			float h = _vertices[0].GetPosition().y;
//
//			for(size_t i = 1; i < _vertices.size(); ++i)
//			{
//				Vec2f pos = _vertices[i].GetPosition();
//
//				if(pos.x < x)
//					x = pos.x;
//				if(pos.x > w)
//					w = pos.x;
//				if(pos.y < y)
//					y = pos.y;
//				if(pos.y > h)
//					h = pos.y;
//			}
//			return AARect(x, y, w - x, h - y);
//		}
//		else
//			return AARect();
//	}
//
//	PrimitiveType VertexArray::GetPrimitiveType() const
//	{
//		return this->_primType;
//	}
//
//	void VertexArray::Render(RenderTarget& target) const
//	{
//		if(!_vertices.empty())
//			target.Render(&_vertices[0], _vertices.size(), _primType); // TODO - render
//	}
//
//}
