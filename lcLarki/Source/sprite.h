#pragma once

#include "imagegpu.h"
#include "matrixd.h"
namespace anima
{
	namespace graphics
	{
		template <class CoordType>
		class Sprite : public ImageGPU
		{
		private:
		public:
			math::tmp::_vec2<CoordType> mPos;
			Sprite() {}
			Sprite(const Sprite&) = delete;
			Sprite(Sprite&& s)
			{
				Sprite::moveIntoSelf(std::move(s));
			}

			Sprite& operator = (Sprite&& sprite)
			{
				if (this != &sprite)
					Sprite::moveIntoSelf(std::move(sprite));
			}

			void moveIntoSelf(Sprite&& sprite)
			{
				ImageGPU::moveIntoSelf(std::move(sprite));
				mPos = sprite.mPos;
			}
		};

		typedef Sprite<int> ISprite;
		typedef Sprite<float> FSprite;
	}
}