#pragma once

#include <Dolphin/types.h>
#include <Dolphin/MTX.h>

struct J3DTransformInfo {
    f32 tx;
    f32 ty;
    f32 tz;
    s16 rx;
    s16 ry;
    s16 rz;
    f32 sx;
    f32 sy;
    f32 sz;
};

void J3DGetTranslationRotationMtx(s16 rx, s16 ry, s16 rz, f32 tx, f32 ty, f32 tz, Mtx out);