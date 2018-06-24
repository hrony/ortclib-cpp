
#pragma once

#include "types.h"
#include "generated/org_ortc_RTCIceCandidate.h"

#include <ortc/IICETypes.h>

namespace wrapper {
  namespace impl {
    namespace org {
      namespace ortc {

        struct RTCIceCandidate : public wrapper::org::ortc::RTCIceCandidate
        {
          ZS_DECLARE_TYPEDEF_PTR(::ortc::IICETypes::Candidate, NativeType);
          ZS_DECLARE_TYPEDEF_PTR(RTCIceCandidate, WrapperImplType);
          ZS_DECLARE_TYPEDEF_PTR(wrapper::org::ortc::RTCIceCandidate, WrapperType);
          RTCIceCandidateWeakPtr thisWeak_;
          NativeTypePtr native_;

          RTCIceCandidate() noexcept;
          virtual ~RTCIceCandidate() noexcept;

          // methods RTCIceGathererCandidate
          wrapper::org::ortc::JsonPtr toJson() noexcept override;
          String hash() noexcept override;

          // properties RTCIceGathererCandidate
          wrapper::org::ortc::RTCIceComponent get_component() noexcept override;
          void wrapper_init_org_ortc_RTCIceCandidate() noexcept override;

          // properties RTCIceCandidate
          String get_interfaceType() noexcept override;
          String get_foundation() noexcept override;
          uint32_t get_priority() noexcept override;
          uint32_t get_unfreezePriority() noexcept override;
          wrapper::org::ortc::RTCIceProtocol get_protocol() noexcept override;
          String get_ip() noexcept override;
          uint16_t get_port() noexcept override;
          wrapper::org::ortc::RTCIceCandidateType get_candidateType() noexcept override;
          wrapper::org::ortc::RTCIceTcpCandidateType get_tcpType() noexcept override;
          String get_relatedAddress() noexcept override;
          uint16_t get_relatedPort() noexcept override;

          static WrapperImplTypePtr toWrapper(NativeTypePtr native) noexcept;
          static NativeTypePtr toNative(WrapperTypePtr wrapper) noexcept;
          static NativeTypePtr toNative(wrapper::org::ortc::RTCIceGathererCandidatePtr wrapper) noexcept;
        };

      } // ortc
    } // org
  } // namespace impl
} // namespace wrapper

