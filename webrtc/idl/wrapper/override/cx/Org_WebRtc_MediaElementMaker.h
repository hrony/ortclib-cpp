// Generated by zsLibEventingTool


#ifndef CX_USE_GENERATED_ORG_WEBRTC_MEDIAELEMENTMAKER
#include <wrapper/override/cx/Org_WebRtc_MediaElementMaker.h>
#else // CX_USE_GENERATED_ORG_WEBRTC_MEDIAELEMENTMAKER

#pragma once

#include "types.h"
#include <wrapper/generated/org_webRtc_MediaElementMaker.h>

namespace Org {
  namespace WebRtc {



    [Windows::Foundation::Metadata::WebHostHiddenAttribute]
    public ref class MediaElementMaker sealed
    {
    internal:
      wrapper::org::webRtc::MediaElementMakerPtr native_;

      struct WrapperCreate {};
      MediaElementMaker(const WrapperCreate &) {}

      static MediaElementMaker^ ToCx(wrapper::org::webRtc::MediaElementMakerPtr value);
      static wrapper::org::webRtc::MediaElementMakerPtr FromCx(MediaElementMaker^ value);



    public:
      // ::org::webRtc::MediaElementMaker

      /// <summary>
      /// Creates an event queue object from a native queue type.
      /// </summary>
      static ::Org::WebRtc::MediaElement^ Bind(Platform::Object^ element);
      /// <summary>
      /// Extracts a native queue from an event queue object.
      /// </summary>
      static Platform::Object^ Extract(::Org::WebRtc::MediaElement^ element);


    };

  } // namespace WebRtc
} // namespace Org
#endif //ifndef CX_USE_GENERATED_ORG_WEBRTC_MEDIAELEMENTMAKER