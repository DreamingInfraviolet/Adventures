#ifndef IMAGE_H
#define IMAGE_H
#include <vector>
#include "pixelrgba.h"
namespace anima
{
	namespace graphics
	{
		class Image
		{
		protected:
			std::vector<PixelRGBA> mPixels;
			int mWidth, mHeight;


		public:
			Image();

			Image(int sizex, int sizey);

			void setSize(int sizex, int sizey);

			void fill(const PixelRGBA& colour);
			void setPixel(const int x, const int y, const PixelRGBA& colour);
			PixelRGBA& getPixelRef(const int x, const int y);

			int height() const;
			int width() const;
		};

	}
}
#endif // IMAGE_H