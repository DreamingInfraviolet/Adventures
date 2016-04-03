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
		};

		typedef Sprite<int> ISprite;
		typedef Sprite<float> FSprite;
	}
}