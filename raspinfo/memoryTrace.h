//-------------------------------------------------------------------------
//
// The MIT License (MIT)
//
// Copyright (c) 2015 Andrew Duncan
//
// Permission is hereby granted, free of charge, to any person obtaining a
// copy of this software and associated documentation files (the
// "Software"), to deal in the Software without restriction, including
// without limitation the rights to use, copy, modify, merge, publish,
// distribute, sublicense, and/or sell copies of the Software, and to
// permit persons to whom the Software is furnished to do so, subject to
// the following conditions:
//
// The above copyright notice and this permission notice shall be included
// in all copies or substantial portions of the Software.
//
// THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS
// OR IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF
// MERCHANTABILITY, FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT.
// IN NO EVENT SHALL THE AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY
// CLAIM, DAMAGES OR OTHER LIABILITY, WHETHER IN AN ACTION OF CONTRACT,
// TORT OR OTHERWISE, ARISING FROM, OUT OF OR IN CONNECTION WITH THE
// SOFTWARE OR THE USE OR OTHER DEALINGS IN THE SOFTWARE.
//
//-------------------------------------------------------------------------

#ifndef MEMORY_TRACE_H
#define MEMORY_TRACE_H

//-------------------------------------------------------------------------

#include <cstdint>

#include "framebuffer565.h"
#include "image565.h"
#include "rgb565.h"

//-------------------------------------------------------------------------

struct SMemoryStats
{
    uint32_t total;
    uint32_t free;
    uint32_t buffers;
    uint32_t cached;
    uint32_t used;
};

//-------------------------------------------------------------------------

class CMemoryTrace
{
public:

    CMemoryTrace(int16_t width,
                 int16_t traceHeight,
                 int16_t yPosition,
                 int16_t gridHeight = 20);

    virtual ~CMemoryTrace();

    int16_t getBottom() const { return m_yPosition + m_image.getHeight(); }

    void show(const CFrameBuffer565& fb, time_t now);

private:

    int16_t m_traceHeight;
    int16_t m_yPosition;
    int16_t m_gridHeight;
    uint16_t m_values;
    int8_t* m_used;
    int8_t* m_buffers;
    int8_t* m_cached;
    int8_t* m_time;
    CImage565 m_image;
    CRGB565 m_usedColour;
    CRGB565 m_usedGridColour;
    CRGB565 m_buffersColour;
    CRGB565 m_buffersGridColour;
    CRGB565 m_cachedColour;
    CRGB565 m_cachedGridColour;
    CRGB565 m_foreground;
    CRGB565 m_background;
    CRGB565 m_gridColour;

    static void getMemoryStats(SMemoryStats& memoryStats);
};

//-------------------------------------------------------------------------

#endif
