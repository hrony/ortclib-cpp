// Generated by zsLibEventingTool

#pragma once

#include "types.h"
#include "generated/org_webrtc_AudioOptions.h"


namespace wrapper {
  namespace impl {
    namespace org {
      namespace webrtc {

        struct AudioOptions : public wrapper::org::webrtc::AudioOptions
        {
          AudioOptionsWeakPtr thisWeak_;

          AudioOptions() noexcept;
          virtual ~AudioOptions() noexcept;
          void wrapper_init_org_webrtc_AudioOptions() noexcept override;
        };

      } // webrtc
    } // org
  } // namespace impl
} // namespace wrapper

