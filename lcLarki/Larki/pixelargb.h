#ifndef PIXELABGR_H
#define PIXELABGR_H

typedef unsigned char byte;

class PixelARGB
{
private:

public:
    byte mR,mG,mB,mA;

    PixelARGB();

    PixelARGB(const byte total, const byte a = 255)
    {
        mR = total;
        mG = total;
        mB = total;
        mA = a;
    }

    PixelARGB(const byte b, const byte g, const byte r, const byte a = 255)
    {
        mR = r;
        mG = g;
        mB = b;
        mA = a;
    }

//    PixelARGB blendInFront(const PixelARGB& back)
//    {
//        float a = mA/255.f;
//        PixelARGB out;
//        int newA = (int)mA + back.mA;
//        out.mA = newA > 255 ? 255:newA;

//        out.mR = a * mR + (1.f-a) * back.mR;
//        out.mG = a * mG + (1.f-a) * back.mG;
//        out.mB = a * mB + (1.f-a) * back.mB;
//        return out;
//    }

    void operator += (const PixelARGB& px)
    {
        int a = (int)mA + px.mA;
        int r = (int)mR + px.mR;
        int g = (int)mG + px.mG;
        int b = (int)mB + px.mB;

        mA = a > 255 ? 255:a;
        mR = r > 255 ? 255:r;
        mG = g > 255 ? 255:g;
        mB = b > 255 ? 255:b;
    }
};

#endif // PIXELABGR_H
