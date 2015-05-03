#pragma once
#include <random>
static std::mt19937 randEngine(time(0));

static int rand(int min, int max)
{
std::uniform_int_distribution<long> dist(min,max);
return dist(randEngine);
}

static float rand(float min, float max)
{
std::uniform_real_distribution<float> dist(min,max);
return dist(randEngine);
}