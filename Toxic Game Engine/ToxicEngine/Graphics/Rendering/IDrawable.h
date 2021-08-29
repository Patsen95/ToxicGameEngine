#pragma once

#include "../Config.h"



namespace toxic
{
	class RenderTarget;

	class TOXIC_API IDrawable
	{
	public:
		virtual ~IDrawable() { }

	protected:
		friend class RenderTarget;

		virtual void Render(RenderTarget& target) const = 0;
	};
}
