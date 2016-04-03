#pragma once
#include <vector>
namespace anima
{
	namespace graphics
	{
		class Image
		{
		protected:
			uint32_t* mPixels;
			int mWidth, mHeight;


		public:
			Image();
			Image(int sizex, int sizey);
			virtual ~Image();

			void setSize(int sizex, int sizey);

			void fill(const uint8_t r, uint8_t g, uint8_t b, uint8_t a);
			void setPixel(const int x, const int y, const uint32_t colour);
			uint32_t* getPixelRef(const uint32_t x, const uint32_t y);

			int height() const;
			int width() const;
		};

	}
}