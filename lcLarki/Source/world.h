#ifndef WORLD_H
#define WORLD_H
#include <vector>
#include "layer.h"

class World
{
private:
	int mTileResolution;
	anima::graphics::ImageGPU mImage;
	int mCurrentLayer;

public:
	World();

	std::vector<Layer> mLayers;
	int layerCount() const;
	Layer& createLayer();
	Layer& getLayer(int index);
	void deleteLayer(int index);
	void clear();

	math::vec2i getCoordinatesInTile(const math::vec2& worldPos, const math::vec2i& tileIndex) const;
	math::vec2i getTileIndex(math::vec2 worldPos) const;

	int tileResolution();

	void applyBrush(const math::vec2& worldPos, float radius);
};

#endif // WORLD_H
