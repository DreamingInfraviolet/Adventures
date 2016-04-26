#pragma once
#include "stdafx.h"

namespace canvas_helper
{
	static math::vec2i getTileIndex(math::vec2 worldPos)
	{
		worldPos += 0.5f;
		return math::vec2i((int)floor(worldPos.x), (int)floor(worldPos.y));
	}

	static math::vec2i getCoordinatesInTile(const math::vec2& worldPos, const math::vec2i& tileIndex, float tileResolution)
	{
		return math::vec2i(
			((worldPos.x + 0.5f) - tileIndex.x)* tileResolution,
			((worldPos.y + 0.5f) - tileIndex.y)* tileResolution);
	}
}