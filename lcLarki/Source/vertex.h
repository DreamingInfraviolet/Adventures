#ifndef VERTEX_H
#define VERTEX_H

#pragma once

struct Vertex2D
{
    float x, y;
    float u, v;

    /**Initialises data to zero.*/
    Vertex2D()
	{
		x = 0;
		y = 0;
		u = 0;
		v = 0;
	}

    /**Initialised data to the inputs.
    @param x_ The x position.
    @param y_ The y position.
    @param z_ The z position.
    @param u_ The u UV coordinate.
    @param v_ The v UV coordinate.
    */
    Vertex2D(float x_, float y_, float u_, float v_)
	{
		x = x_;
		y = y_;
		u = u_;
		v = v_;
	}

};

#endif // VERTEX_H
