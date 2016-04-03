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

			void upload();
			void deupload();
			void set();
		};
	}
}