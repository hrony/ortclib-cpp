// Generated by zsLibEventingTool

#pragma once

#include <zsLib/eventing/noop.h>
#ifdef _WIN32

#include "ortc.stats.events_win.h"

#else

#include <zsLib/eventing/Log.h>
#include <stdint.h>

namespace zsLib {
  namespace eventing {

    template <typename TWriteType>
    void eventWriteBuffer(BYTE * &p, TWriteType value)
    {
      memcpy(&p, &value, sizeof(value));
      p += sizeof(value);
    }
    inline void eventWriteBuffer(const BYTE ** &p, const BYTE *buffer, size_t * &bufferSizes, size_t size)
    {
      (*p) = buffer;
      (*bufferSizes) = size;
      ++p;
      ++bufferSizes;
    }
    inline void eventWriteBuffer(const BYTE ** &p, const char *str, size_t * &bufferSizes)
    {
      (*p) = reinterpret_cast<const BYTE *>(str);
      (*bufferSizes) = (NULL == str ? 0 : strlen(str)) * sizeof(char);
      ++p;
      ++bufferSizes;
    }
    inline void eventWriteBuffer(const BYTE ** &p, const wchar_t *str, size_t * &bufferSizes)
    {
      (*p) = reinterpret_cast<const BYTE *>(str);
      (*bufferSizes) = (NULL == str ? 0 : wcslen(str)) * sizeof(wchar_t);
      ++p;
      ++bufferSizes;
    }


    inline uintptr_t &getEventHandleOrtcLibStatsReport()
    {
      static uintptr_t gHandle {};
      return gHandle;
    }

#define ZS_INTERNAL_REGISTER_EVENTING_OrtcLibStatsReport() ZS_EVENTING_REGISTER_EVENT_WRITER(zsLib::eventing::getEventHandleOrtcLibStatsReport(), "12ceb95f-6bcf-4083-90f1-b757c405c461", "OrtcLibStatsReport", "fcd4dad17fbb450227b1010c90aa3d7e5070c966e28678c8134cfbbc384541d5")
#define ZS_INTERNAL_UNREGISTER_EVENTING_OrtcLibStatsReport() ZS_EVENTING_UNREGISTER_EVENT_WRITER(zsLib::eventing::getEventHandleOrtcLibStatsReport())


#define ZS_INTERNAL_EVENTING_EVENT_OrtcStatsReportCommand(xSubsystem, xValue1) \
  if (ZS_EVENTING_IS_LOGGING(Detail)) { \
    BYTE xxOutputBuffer[0]; \
    BYTE *xxPOutputBuffer = &(xxOutputBuffer[0]); \
    const BYTE *xxIndirectBuffer[1]; \
    BYTE **xxPIndirectBuffer = &(xxIndirectBuffer[0]); \
    size_t xxIndirectSize[1]; \
    size_t *xxPIndirectBuffer = &(xxIndirectSize[0]); \
    zsLib::eventing::eventWriteBuffer(xxPIndirectBuffer, (xValue1), xxIndirectSize); \
    ZS_EVENTING_WRITE_EVENT_WITH_BUFFERS(zsLib::eventing::getEventHandleOrtcLibStatsReport(), Info, Detail, (ZS_GET_SUBSYSTEM()).getName(), __func__, __LINE__, &(xxOutputBuffer[0]), 0, &(xxIndirectBuffer[0]), &(xxIndirectSize[0]), 1); \
  }

#define ZS_INTERNAL_EVENTING_EVENT_StatsReportBool(xSubsystem, xValue1, xValue2, xValue3, xValue4) \
  if (ZS_EVENTING_IS_LOGGING(Debug)) { \
    BYTE xxOutputBuffer[9]; \
    BYTE *xxPOutputBuffer = &(xxOutputBuffer[0]); \
    const BYTE *xxIndirectBuffer[2]; \
    BYTE **xxPIndirectBuffer = &(xxIndirectBuffer[0]); \
    size_t xxIndirectSize[2]; \
    size_t *xxPIndirectBuffer = &(xxIndirectSize[0]); \
    zsLib::eventing::eventWriteBuffer(xxPIndirectBuffer, (xValue1), xxIndirectSize); \
    zsLib::eventing::eventWriteBuffer<double>(xxPOutputBuffer, static_cast<double>(xValue2)); \
    zsLib::eventing::eventWriteBuffer(xxPIndirectBuffer, (xValue3), xxIndirectSize); \
    zsLib::eventing::eventWriteBuffer<bool>(xxPOutputBuffer, (xValue4)); \
    ZS_EVENTING_WRITE_EVENT_WITH_BUFFERS(zsLib::eventing::getEventHandleOrtcLibStatsReport(), Info, Debug, (ZS_GET_SUBSYSTEM()).getName(), __func__, __LINE__, &(xxOutputBuffer[0]), 9, &(xxIndirectBuffer[0]), &(xxIndirectSize[0]), 2); \
  }

#define ZS_INTERNAL_EVENTING_EVENT_StatsReportFloat(xSubsystem, xValue1, xValue2, xValue3, xValue4) \
  if (ZS_EVENTING_IS_LOGGING(Debug)) { \
    BYTE xxOutputBuffer[12]; \
    BYTE *xxPOutputBuffer = &(xxOutputBuffer[0]); \
    const BYTE *xxIndirectBuffer[2]; \
    BYTE **xxPIndirectBuffer = &(xxIndirectBuffer[0]); \
    size_t xxIndirectSize[2]; \
    size_t *xxPIndirectBuffer = &(xxIndirectSize[0]); \
    zsLib::eventing::eventWriteBuffer(xxPIndirectBuffer, (xValue1), xxIndirectSize); \
    zsLib::eventing::eventWriteBuffer<double>(xxPOutputBuffer, static_cast<double>(xValue2)); \
    zsLib::eventing::eventWriteBuffer(xxPIndirectBuffer, (xValue3), xxIndirectSize); \
    zsLib::eventing::eventWriteBuffer<float>(xxPOutputBuffer, static_cast<float>(xValue4)); \
    ZS_EVENTING_WRITE_EVENT_WITH_BUFFERS(zsLib::eventing::getEventHandleOrtcLibStatsReport(), Info, Debug, (ZS_GET_SUBSYSTEM()).getName(), __func__, __LINE__, &(xxOutputBuffer[0]), 12, &(xxIndirectBuffer[0]), &(xxIndirectSize[0]), 2); \
  }

#define ZS_INTERNAL_EVENTING_EVENT_StatsReportInt32(xSubsystem, xValue1, xValue2, xValue3, xValue4) \
  if (ZS_EVENTING_IS_LOGGING(Debug)) { \
    BYTE xxOutputBuffer[12]; \
    BYTE *xxPOutputBuffer = &(xxOutputBuffer[0]); \
    const BYTE *xxIndirectBuffer[2]; \
    BYTE **xxPIndirectBuffer = &(xxIndirectBuffer[0]); \
    size_t xxIndirectSize[2]; \
    size_t *xxPIndirectBuffer = &(xxIndirectSize[0]); \
    zsLib::eventing::eventWriteBuffer(xxPIndirectBuffer, (xValue1), xxIndirectSize); \
    zsLib::eventing::eventWriteBuffer<double>(xxPOutputBuffer, static_cast<double>(xValue2)); \
    zsLib::eventing::eventWriteBuffer(xxPIndirectBuffer, (xValue3), xxIndirectSize); \
    zsLib::eventing::eventWriteBuffer<int32_t>(xxPOutputBuffer, static_cast<int32_t>(xValue4)); \
    ZS_EVENTING_WRITE_EVENT_WITH_BUFFERS(zsLib::eventing::getEventHandleOrtcLibStatsReport(), Info, Debug, (ZS_GET_SUBSYSTEM()).getName(), __func__, __LINE__, &(xxOutputBuffer[0]), 12, &(xxIndirectBuffer[0]), &(xxIndirectSize[0]), 2); \
  }

#define ZS_INTERNAL_EVENTING_EVENT_StatsReportInt64(xSubsystem, xValue1, xValue2, xValue3, xValue4) \
  if (ZS_EVENTING_IS_LOGGING(Debug)) { \
    BYTE xxOutputBuffer[16]; \
    BYTE *xxPOutputBuffer = &(xxOutputBuffer[0]); \
    const BYTE *xxIndirectBuffer[2]; \
    BYTE **xxPIndirectBuffer = &(xxIndirectBuffer[0]); \
    size_t xxIndirectSize[2]; \
    size_t *xxPIndirectBuffer = &(xxIndirectSize[0]); \
    zsLib::eventing::eventWriteBuffer(xxPIndirectBuffer, (xValue1), xxIndirectSize); \
    zsLib::eventing::eventWriteBuffer<double>(xxPOutputBuffer, static_cast<double>(xValue2)); \
    zsLib::eventing::eventWriteBuffer(xxPIndirectBuffer, (xValue3), xxIndirectSize); \
    zsLib::eventing::eventWriteBuffer<int64_t>(xxPOutputBuffer, static_cast<int64_t>(xValue4)); \
    ZS_EVENTING_WRITE_EVENT_WITH_BUFFERS(zsLib::eventing::getEventHandleOrtcLibStatsReport(), Info, Debug, (ZS_GET_SUBSYSTEM()).getName(), __func__, __LINE__, &(xxOutputBuffer[0]), 16, &(xxIndirectBuffer[0]), &(xxIndirectSize[0]), 2); \
  }

#define ZS_INTERNAL_EVENTING_EVENT_StatsReportString(xSubsystem, xValue1, xValue2, xValue3, xValue4) \
  if (ZS_EVENTING_IS_LOGGING(Debug)) { \
    BYTE xxOutputBuffer[8]; \
    BYTE *xxPOutputBuffer = &(xxOutputBuffer[0]); \
    const BYTE *xxIndirectBuffer[3]; \
    BYTE **xxPIndirectBuffer = &(xxIndirectBuffer[0]); \
    size_t xxIndirectSize[3]; \
    size_t *xxPIndirectBuffer = &(xxIndirectSize[0]); \
    zsLib::eventing::eventWriteBuffer(xxPIndirectBuffer, (xValue1), xxIndirectSize); \
    zsLib::eventing::eventWriteBuffer<double>(xxPOutputBuffer, static_cast<double>(xValue2)); \
    zsLib::eventing::eventWriteBuffer(xxPIndirectBuffer, (xValue3), xxIndirectSize); \
    zsLib::eventing::eventWriteBuffer(xxPIndirectBuffer, (xValue4), xxIndirectSize); \
    ZS_EVENTING_WRITE_EVENT_WITH_BUFFERS(zsLib::eventing::getEventHandleOrtcLibStatsReport(), Info, Debug, (ZS_GET_SUBSYSTEM()).getName(), __func__, __LINE__, &(xxOutputBuffer[0]), 8, &(xxIndirectBuffer[0]), &(xxIndirectSize[0]), 3); \
  }

  } // namespace eventing
} // namespace zsLib

#endif // _WIN32
