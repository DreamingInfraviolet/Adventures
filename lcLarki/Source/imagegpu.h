#pragma once
#include "image.h"
namespace anima
{
	namespace graphics
	{
		class ImageGPU : public Image
		{

		public:

			bool mUploaded;
			unsigned gpuId;

			ImageGPU();
			ImageGPU(const ImageGPU&) = delete;
			ImageGPU(ImageGPU&& im)
			{
				moveIntoSelf(std::move(im));
			}

			ImageGPU& operator = (ImageGPU&& im)
			{
				if (this != &im)
					ImageGPU::moveIntoSelf(std::move(im));
				return *this;
			}
			void moveIntoSelf(ImageGPU&& im)
			{
				Image::moveIntoSelf(std::move(im));
				mUploaded = im.mUploaded;
				gpuId = im.gpuId;
				im.mUploaded = false;
				im.gpuId = 0;
			}

			void upload();
			void deupload();
			void set();
		};
	}
}