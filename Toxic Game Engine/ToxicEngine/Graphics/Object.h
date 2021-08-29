//#pragma once
//
//#include "../Config.h"
//#include "../Rendering/IDrawable.h"
//#include "../Rendering/ITransformable.h"
//#include "../Rendering/VertexArray.h"
//#include "../Rendering/ObjectStates.h"
//#include "../Math/Vec2.h"
//
//
//
//namespace toxic
//{
//	class Texture;
//
//	class TOXIC_API Object : public IDrawable, public ITransformable
//	{
//	public:
//		virtual ~Object();
//
//		void SetTexture(const Texture* texture, bool resize = false);
//		void TrimTexture(int x, int y, int w, int h);
//		void TrimTexture(const Vec2f& position, const Vec2f& size);
//		void TrimTexture(const AARect& trimRect);
//		void FillColor(const Color& color);
//		void OutlineColor(const Color& color);
//		void OutlineWidth(float width);
//		
//		const Texture* GetTexture() const;
//		const AARect& GetTextureBounding() const;
//		const Color& GetFillColor() const;
//		const Color& GetOutlineColor() const;
//		float GetOutlineWidth() const;
//		AARect GetLocalBounding() const;
//		AARect GetGlobalBounding() const;
//		virtual size_t GetVertexCount() const = 0;
//		virtual Vec2f GetVertexPosFromIndex(size_t idx) const = 0;
//
//	protected:
//		Object();
//		void Update();
//
//	private:
//		virtual void Render(RenderTarget& target) const;
//		void UpdateFill();
//		void UpdateOutline();
//		void UpdateOutlineColor();
//		void UpdateTextureCoords();
//
//		const Texture* _texture;
//		AARect _textureRect;
//		Color _fillColor;
//		Color _outlineColor;
//		float _outlineWidth;
//		VertexArray _vertices;
//		VertexArray _outline;
//		AARect _innerBounds;
//		AARect _objectBounds;
//		ObjectStates* _states;
//	};
//}
