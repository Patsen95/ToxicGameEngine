//#pragma once
//
//#include "../Config.h"
//#include "Vertex.h"
//#include "Primitive.h"
//#include "../Graphics/AARect.h"
//#include "IDrawable.h"
//
//#include <vector>
//
//
//
//namespace toxic
//{
//	class TOXIC_API VertexArray : public IDrawable
//	{
//	public:
//		VertexArray();
//		explicit VertexArray(PrimitiveType type, size_t vertCnt = 0);
//
//		Vertex& operator[](std::size_t index);
//		const Vertex& operator[](std::size_t index) const;
//
//		void Add(const Vertex& vert);
//		void Resize(size_t newSize);
//		void Remove(long index);
//		void Clear();
//		void SetPrimitiveType(const PrimitiveType& type);
//
//		size_t GetVertexCount() const;
//		AARect GetBoundingRect() const;
//		PrimitiveType GetPrimitiveType() const;
//
//	protected:
//		std::vector<Vertex> _vertices;
//		PrimitiveType _primType;
//
//		virtual void Render(RenderTarget& target) const;
//	};
//}
