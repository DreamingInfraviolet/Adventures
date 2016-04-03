#include "stdafx.h"
#include "imagegpu.h"
#include "io.h"

namespace anima
{
	namespace graphics
	{
		ImageGPU::ImageGPU() : Image()
		{
			mWidth = 0;
			mHeight = 0;
			mUploaded = false;
		}

		void ImageGPU::upload()
		{
			deupload();
			if (!mPixels)
				return;

			glGenTextures(1, &gpuId);
			glBindTexture(GL_TEXTURE_2D, gpuId);
			glTexSubImage2D(GL_TEXTURE_2D, 0, 0, 0, mWidth, mHeight, GL_RGBA, GL_UNSIGNED_BYTE, mPixels);

			mUploaded = true;
		}

		void ImageGPU::deupload()
		{
			if (!mUploaded)
				return;
			glDeleteTextures(1, &gpuId);
			mUploaded = false;
		}

		void ImageGPU::set()
		{
#ifdef _DEBUG
			if (!mUploaded)
				assert(false);
#endif
			glBindTexture(GL_TEXTURE_2D, gpuId);
		}
	}
}