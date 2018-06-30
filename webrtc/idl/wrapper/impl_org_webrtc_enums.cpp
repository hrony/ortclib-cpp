
#include "impl_org_webrtc_enums.h"

#include "impl_org_webrtc_pre_include.h"
#include "api/rtcerror.h"
#include "rtc_base/sslidentity.h"
#include "impl_org_webrtc_post_include.h"

#include <zsLib/Stringize.h>

using ::zsLib::String;
using ::zsLib::Optional;
using ::zsLib::Any;
using ::zsLib::AnyPtr;
using ::zsLib::AnyHolder;
using ::zsLib::Promise;
using ::zsLib::PromisePtr;
using ::zsLib::PromiseWithHolder;
using ::zsLib::PromiseWithHolderPtr;
using ::zsLib::eventing::SecureByteBlock;
using ::zsLib::eventing::SecureByteBlockPtr;
using ::std::shared_ptr;
using ::std::weak_ptr;
using ::std::make_shared;
using ::std::list;
using ::std::set;
using ::std::map;

ZS_DECLARE_TYPEDEF_PTR(wrapper::impl::org::webrtc::IEnum, UseEnum);

namespace wrapper { namespace impl { namespace org { namespace webrtc { ZS_DECLARE_SUBSYSTEM(wrapper_org_webrtc); } } } }

//-----------------------------------------------------------------------------
wrapper::org::webrtc::RTCErrorType UseEnum::toWrapper(::webrtc::RTCErrorType value) noexcept
{
  switch (value) {
    case ::webrtc::RTCErrorType::NONE:                      return wrapper::org::webrtc::RTCErrorType::RTCErrorType_none;
    case ::webrtc::RTCErrorType::UNSUPPORTED_OPERATION:     return wrapper::org::webrtc::RTCErrorType::RTCErrorType_unsupportedOperation;
    case ::webrtc::RTCErrorType::UNSUPPORTED_PARAMETER:     return wrapper::org::webrtc::RTCErrorType::RTCErrorType_unsupportedParameter;
    case ::webrtc::RTCErrorType::INVALID_PARAMETER:         return wrapper::org::webrtc::RTCErrorType::RTCErrorType_invalidParameter;
    case ::webrtc::RTCErrorType::INVALID_RANGE:             return wrapper::org::webrtc::RTCErrorType::RTCErrorType_invalidRange;
    case ::webrtc::RTCErrorType::SYNTAX_ERROR:              return wrapper::org::webrtc::RTCErrorType::RTCErrorType_syntaxError;
    case ::webrtc::RTCErrorType::INVALID_STATE:             return wrapper::org::webrtc::RTCErrorType::RTCErrorType_invalidState;
    case ::webrtc::RTCErrorType::INVALID_MODIFICATION:      return wrapper::org::webrtc::RTCErrorType::RTCErrorType_invalidModification;
    case ::webrtc::RTCErrorType::NETWORK_ERROR:             return wrapper::org::webrtc::RTCErrorType::RTCErrorType_networkError;
    case ::webrtc::RTCErrorType::RESOURCE_EXHAUSTED:        return wrapper::org::webrtc::RTCErrorType::RTCErrorType_resourceExhausted;
    case ::webrtc::RTCErrorType::INTERNAL_ERROR:            return wrapper::org::webrtc::RTCErrorType::RTCErrorType_internalError;
  }
  ZS_ASSERT_FAIL("unknown type");
  return wrapper::org::webrtc::RTCErrorType::RTCErrorType_none;
}

//-----------------------------------------------------------------------------
::webrtc::RTCErrorType UseEnum::toNative(wrapper::org::webrtc::RTCErrorType value) noexcept
{
  switch (value) {
    case wrapper::org::webrtc::RTCErrorType::RTCErrorType_none:                   return ::webrtc::RTCErrorType::NONE;
    case wrapper::org::webrtc::RTCErrorType::RTCErrorType_unsupportedOperation:   return ::webrtc::RTCErrorType::UNSUPPORTED_OPERATION;
    case wrapper::org::webrtc::RTCErrorType::RTCErrorType_unsupportedParameter:   return ::webrtc::RTCErrorType::UNSUPPORTED_PARAMETER;
    case wrapper::org::webrtc::RTCErrorType::RTCErrorType_invalidParameter:       return ::webrtc::RTCErrorType::INVALID_PARAMETER;
    case wrapper::org::webrtc::RTCErrorType::RTCErrorType_invalidRange:           return ::webrtc::RTCErrorType::INVALID_RANGE;
    case wrapper::org::webrtc::RTCErrorType::RTCErrorType_syntaxError:            return ::webrtc::RTCErrorType::SYNTAX_ERROR;
    case wrapper::org::webrtc::RTCErrorType::RTCErrorType_invalidState:           return ::webrtc::RTCErrorType::INVALID_STATE;
    case wrapper::org::webrtc::RTCErrorType::RTCErrorType_invalidModification:    return ::webrtc::RTCErrorType::INVALID_MODIFICATION;
    case wrapper::org::webrtc::RTCErrorType::RTCErrorType_networkError:           return ::webrtc::RTCErrorType::NETWORK_ERROR;
    case wrapper::org::webrtc::RTCErrorType::RTCErrorType_resourceExhausted:      return ::webrtc::RTCErrorType::RESOURCE_EXHAUSTED;
    case wrapper::org::webrtc::RTCErrorType::RTCErrorType_internalError:          return ::webrtc::RTCErrorType::INTERNAL_ERROR;
  }
  ZS_ASSERT_FAIL("unknown type");
  return ::webrtc::RTCErrorType::INTERNAL_ERROR;
}

//-----------------------------------------------------------------------------
wrapper::org::webrtc::RTCIceTransportPolicy UseEnum::toWrapper(::webrtc::PeerConnectionInterface::IceTransportsType value) noexcept
{
  switch (value)
  {
    case ::webrtc::PeerConnectionInterface::IceTransportsType::kNone:   return wrapper::org::webrtc::RTCIceTransportPolicy::RTCIceTransportPolicy_none;
    case ::webrtc::PeerConnectionInterface::IceTransportsType::kRelay:  return wrapper::org::webrtc::RTCIceTransportPolicy::RTCIceTransportPolicy_relay;
    case ::webrtc::PeerConnectionInterface::IceTransportsType::kNoHost: return wrapper::org::webrtc::RTCIceTransportPolicy::RTCIceTransportPolicy_noHost;
    case ::webrtc::PeerConnectionInterface::IceTransportsType::kAll:    return wrapper::org::webrtc::RTCIceTransportPolicy::RTCIceTransportPolicy_all;
  }
  ZS_ASSERT_FAIL("unknown type");
  return wrapper::org::webrtc::RTCIceTransportPolicy::RTCIceTransportPolicy_all;
}

//-----------------------------------------------------------------------------
::webrtc::PeerConnectionInterface::IceTransportsType UseEnum::toNative(wrapper::org::webrtc::RTCIceTransportPolicy value) noexcept
{
  switch (value)
  {
    case wrapper::org::webrtc::RTCIceTransportPolicy::RTCIceTransportPolicy_none:   return ::webrtc::PeerConnectionInterface::IceTransportsType::kNone;
    case wrapper::org::webrtc::RTCIceTransportPolicy::RTCIceTransportPolicy_relay:  return ::webrtc::PeerConnectionInterface::IceTransportsType::kRelay;
    case wrapper::org::webrtc::RTCIceTransportPolicy::RTCIceTransportPolicy_noHost: return ::webrtc::PeerConnectionInterface::IceTransportsType::kNoHost;
    case wrapper::org::webrtc::RTCIceTransportPolicy::RTCIceTransportPolicy_all:    return ::webrtc::PeerConnectionInterface::IceTransportsType::kAll;
  }
  ZS_ASSERT_FAIL("unknown type");
  return ::webrtc::PeerConnectionInterface::IceTransportsType::kAll;
}

//-----------------------------------------------------------------------------
wrapper::org::webrtc::RTCBundlePolicy UseEnum::toWrapper(::webrtc::PeerConnectionInterface::BundlePolicy value) noexcept
{
  switch (value)
  {
    case ::webrtc::PeerConnectionInterface::BundlePolicy::kBundlePolicyBalanced:    return wrapper::org::webrtc::RTCBundlePolicy::RTCBundlePolicy_balanced;
    case ::webrtc::PeerConnectionInterface::BundlePolicy::kBundlePolicyMaxBundle:   return wrapper::org::webrtc::RTCBundlePolicy::RTCBundlePolicy_maxBundle;
    case ::webrtc::PeerConnectionInterface::BundlePolicy::kBundlePolicyMaxCompat:   return wrapper::org::webrtc::RTCBundlePolicy::RTCBundlePolicy_maxCompat;
  }
  ZS_ASSERT_FAIL("unknown type");
  return wrapper::org::webrtc::RTCBundlePolicy::RTCBundlePolicy_balanced;
}

//-----------------------------------------------------------------------------
::webrtc::PeerConnectionInterface::BundlePolicy UseEnum::toNative(wrapper::org::webrtc::RTCBundlePolicy value) noexcept
{
  switch (value)
  {
    case wrapper::org::webrtc::RTCBundlePolicy::RTCBundlePolicy_balanced:   return ::webrtc::PeerConnectionInterface::BundlePolicy::kBundlePolicyBalanced;
    case wrapper::org::webrtc::RTCBundlePolicy::RTCBundlePolicy_maxBundle:  return ::webrtc::PeerConnectionInterface::BundlePolicy::kBundlePolicyMaxBundle;
    case wrapper::org::webrtc::RTCBundlePolicy::RTCBundlePolicy_maxCompat:  return ::webrtc::PeerConnectionInterface::BundlePolicy::kBundlePolicyMaxCompat;
  }
  ZS_ASSERT_FAIL("unknown type");
  return ::webrtc::PeerConnectionInterface::BundlePolicy::kBundlePolicyBalanced;
}

//-----------------------------------------------------------------------------
wrapper::org::webrtc::RTCRtcpMuxPolicy UseEnum::toWrapper(::webrtc::PeerConnectionInterface::RtcpMuxPolicy value) noexcept
{
  switch (value)
  {
    case ::webrtc::PeerConnectionInterface::RtcpMuxPolicy::kRtcpMuxPolicyNegotiate:   return wrapper::org::webrtc::RTCRtcpMuxPolicy::RTCRtcpMuxPolicy_negotiate;
    case ::webrtc::PeerConnectionInterface::RtcpMuxPolicy::kRtcpMuxPolicyRequire:     return wrapper::org::webrtc::RTCRtcpMuxPolicy::RTCRtcpMuxPolicy_require;
  }
  ZS_ASSERT_FAIL("unknown type");
  return wrapper::org::webrtc::RTCRtcpMuxPolicy::RTCRtcpMuxPolicy_require;
}

//-----------------------------------------------------------------------------
::webrtc::PeerConnectionInterface::RtcpMuxPolicy UseEnum::toNative(wrapper::org::webrtc::RTCRtcpMuxPolicy value) noexcept
{
  switch (value)
  {
    case wrapper::org::webrtc::RTCRtcpMuxPolicy::RTCRtcpMuxPolicy_negotiate:  return ::webrtc::PeerConnectionInterface::RtcpMuxPolicy::kRtcpMuxPolicyNegotiate;
    case wrapper::org::webrtc::RTCRtcpMuxPolicy::RTCRtcpMuxPolicy_require:    return ::webrtc::PeerConnectionInterface::RtcpMuxPolicy::kRtcpMuxPolicyRequire;
  }
  ZS_ASSERT_FAIL("unknown type");
  return ::webrtc::PeerConnectionInterface::RtcpMuxPolicy::kRtcpMuxPolicyRequire;
}


//-----------------------------------------------------------------------------
wrapper::org::webrtc::RTCTcpCandidatePolicy UseEnum::toWrapper(::webrtc::PeerConnectionInterface::TcpCandidatePolicy value) noexcept
{
  switch (value)
  {
    case ::webrtc::PeerConnectionInterface::TcpCandidatePolicy::kTcpCandidatePolicyEnabled:   return wrapper::org::webrtc::RTCTcpCandidatePolicy::RTCTcpCandidatePolicy_enabled;
    case ::webrtc::PeerConnectionInterface::TcpCandidatePolicy::kTcpCandidatePolicyDisabled:  return wrapper::org::webrtc::RTCTcpCandidatePolicy::RTCTcpCandidatePolicy_disabled;
  }
  ZS_ASSERT_FAIL("unknown type");
  return wrapper::org::webrtc::RTCTcpCandidatePolicy::RTCTcpCandidatePolicy_disabled;
}

//-----------------------------------------------------------------------------
::webrtc::PeerConnectionInterface::TcpCandidatePolicy UseEnum::toNative(wrapper::org::webrtc::RTCTcpCandidatePolicy value) noexcept
{
  switch (value)
  {
    case wrapper::org::webrtc::RTCTcpCandidatePolicy::RTCTcpCandidatePolicy_enabled:    return ::webrtc::PeerConnectionInterface::TcpCandidatePolicy::kTcpCandidatePolicyEnabled;
    case wrapper::org::webrtc::RTCTcpCandidatePolicy::RTCTcpCandidatePolicy_disabled:   return ::webrtc::PeerConnectionInterface::TcpCandidatePolicy::kTcpCandidatePolicyDisabled;
  }
  ZS_ASSERT_FAIL("unknown type");
  return ::webrtc::PeerConnectionInterface::TcpCandidatePolicy::kTcpCandidatePolicyDisabled;
}

//-----------------------------------------------------------------------------
wrapper::org::webrtc::RTCCandidateNetworkPolicy UseEnum::toWrapper(::webrtc::PeerConnectionInterface::CandidateNetworkPolicy value) noexcept
{
  switch (value)
  {
    case ::webrtc::PeerConnectionInterface::CandidateNetworkPolicy::kCandidateNetworkPolicyAll:       return wrapper::org::webrtc::RTCCandidateNetworkPolicy::RTCCandidateNetworkPolicy_all;
    case ::webrtc::PeerConnectionInterface::CandidateNetworkPolicy::kCandidateNetworkPolicyLowCost:   return wrapper::org::webrtc::RTCCandidateNetworkPolicy::RTCCandidateNetworkPolicy_lowCost;
  }
  ZS_ASSERT_FAIL("unknown type");
  return wrapper::org::webrtc::RTCCandidateNetworkPolicy::RTCCandidateNetworkPolicy_all;
}

//-----------------------------------------------------------------------------
::webrtc::PeerConnectionInterface::CandidateNetworkPolicy UseEnum::toNative(wrapper::org::webrtc::RTCCandidateNetworkPolicy value) noexcept
{
  switch (value)
  {
    case wrapper::org::webrtc::RTCCandidateNetworkPolicy::RTCCandidateNetworkPolicy_all:      return ::webrtc::PeerConnectionInterface::CandidateNetworkPolicy::kCandidateNetworkPolicyAll;
    case wrapper::org::webrtc::RTCCandidateNetworkPolicy::RTCCandidateNetworkPolicy_lowCost:  return ::webrtc::PeerConnectionInterface::CandidateNetworkPolicy::kCandidateNetworkPolicyLowCost;
  }
  ZS_ASSERT_FAIL("unknown type");
  return ::webrtc::PeerConnectionInterface::CandidateNetworkPolicy::kCandidateNetworkPolicyLowCost;
}


//-----------------------------------------------------------------------------
wrapper::org::webrtc::RTCContinualGatheringPolicy UseEnum::toWrapper(::webrtc::PeerConnectionInterface::ContinualGatheringPolicy value) noexcept
{
  switch (value)
  {
    case ::webrtc::PeerConnectionInterface::ContinualGatheringPolicy::GATHER_ONCE:        return wrapper::org::webrtc::RTCContinualGatheringPolicy::RTCContinualGatheringPolicy_once;
    case ::webrtc::PeerConnectionInterface::ContinualGatheringPolicy::GATHER_CONTINUALLY: return wrapper::org::webrtc::RTCContinualGatheringPolicy::RTCContinualGatheringPolicy_continually;
  }
  ZS_ASSERT_FAIL("unknown type");
  return wrapper::org::webrtc::RTCContinualGatheringPolicy::RTCContinualGatheringPolicy_once;
}

//-----------------------------------------------------------------------------
::webrtc::PeerConnectionInterface::ContinualGatheringPolicy UseEnum::toNative(wrapper::org::webrtc::RTCContinualGatheringPolicy value) noexcept
{
  switch (value)
  {
    case  wrapper::org::webrtc::RTCContinualGatheringPolicy::RTCContinualGatheringPolicy_once:        return ::webrtc::PeerConnectionInterface::ContinualGatheringPolicy::GATHER_ONCE;
    case  wrapper::org::webrtc::RTCContinualGatheringPolicy::RTCContinualGatheringPolicy_continually: return ::webrtc::PeerConnectionInterface::ContinualGatheringPolicy::GATHER_CONTINUALLY;
  }
  ZS_ASSERT_FAIL("unknown type");
  return ::webrtc::PeerConnectionInterface::ContinualGatheringPolicy::GATHER_ONCE;
}


//-----------------------------------------------------------------------------
wrapper::org::webrtc::RTCAdapterType UseEnum::toWrapper(::rtc::AdapterType value) noexcept
{
  switch (value)
  {
    case ::rtc::AdapterType::ADAPTER_TYPE_UNKNOWN:    return wrapper::org::webrtc::RTCAdapterType::RTCAdapterType_unknown;
    case ::rtc::AdapterType::ADAPTER_TYPE_ETHERNET:   return wrapper::org::webrtc::RTCAdapterType::RTCAdapterType_ethernet;
    case ::rtc::AdapterType::ADAPTER_TYPE_WIFI:       return wrapper::org::webrtc::RTCAdapterType::RTCAdapterType_wifi;
    case ::rtc::AdapterType::ADAPTER_TYPE_CELLULAR:   return wrapper::org::webrtc::RTCAdapterType::RTCAdapterType_cellular;
    case ::rtc::AdapterType::ADAPTER_TYPE_VPN:        return wrapper::org::webrtc::RTCAdapterType::RTCAdapterType_vpn;
    case ::rtc::AdapterType::ADAPTER_TYPE_LOOPBACK:   return wrapper::org::webrtc::RTCAdapterType::RTCAdapterType_loopback;
  }
  ZS_ASSERT_FAIL("unknown type");
  return wrapper::org::webrtc::RTCAdapterType::RTCAdapterType_unknown;
}

//-----------------------------------------------------------------------------
::rtc::AdapterType UseEnum::toNative(wrapper::org::webrtc::RTCAdapterType value) noexcept
{
  switch (value)
  {
    case wrapper::org::webrtc::RTCAdapterType::RTCAdapterType_unknown:    return ::rtc::AdapterType::ADAPTER_TYPE_UNKNOWN;
    case wrapper::org::webrtc::RTCAdapterType::RTCAdapterType_ethernet:   return ::rtc::AdapterType::ADAPTER_TYPE_ETHERNET;
    case wrapper::org::webrtc::RTCAdapterType::RTCAdapterType_wifi:       return ::rtc::AdapterType::ADAPTER_TYPE_WIFI;
    case wrapper::org::webrtc::RTCAdapterType::RTCAdapterType_cellular:   return ::rtc::AdapterType::ADAPTER_TYPE_CELLULAR;
    case wrapper::org::webrtc::RTCAdapterType::RTCAdapterType_vpn:        return ::rtc::AdapterType::ADAPTER_TYPE_VPN;
    case wrapper::org::webrtc::RTCAdapterType::RTCAdapterType_loopback:   return ::rtc::AdapterType::ADAPTER_TYPE_LOOPBACK;
  }
  ZS_ASSERT_FAIL("unknown type");
  return ::rtc::AdapterType::ADAPTER_TYPE_UNKNOWN;
}


//-----------------------------------------------------------------------------
wrapper::org::webrtc::RTCSdpSemantics UseEnum::toWrapper(::webrtc::SdpSemantics value) noexcept
{
  switch (value)
  {
    case ::webrtc::SdpSemantics::kDefault:        return wrapper::org::webrtc::RTCSdpSemantics::RTCSdpSemantics_default;
    case ::webrtc::SdpSemantics::kPlanB:          return wrapper::org::webrtc::RTCSdpSemantics::RTCSdpSemantics_planB;
    case ::webrtc::SdpSemantics::kUnifiedPlan:    return wrapper::org::webrtc::RTCSdpSemantics::RTCSdpSemantics_unifiedPlan;
  }
  ZS_ASSERT_FAIL("unknown type");
  return wrapper::org::webrtc::RTCSdpSemantics::RTCSdpSemantics_default;
}

//-----------------------------------------------------------------------------
::webrtc::SdpSemantics UseEnum::toNative(wrapper::org::webrtc::RTCSdpSemantics value) noexcept
{
  switch (value)
  {
    case wrapper::org::webrtc::RTCSdpSemantics::RTCSdpSemantics_default:      return ::webrtc::SdpSemantics::kDefault;
    case wrapper::org::webrtc::RTCSdpSemantics::RTCSdpSemantics_planB:        return ::webrtc::SdpSemantics::kPlanB;
    case wrapper::org::webrtc::RTCSdpSemantics::RTCSdpSemantics_unifiedPlan:  return ::webrtc::SdpSemantics::kUnifiedPlan;
  }
  ZS_ASSERT_FAIL("unknown type");
  return ::webrtc::SdpSemantics::kDefault;
}

//-----------------------------------------------------------------------------
wrapper::org::webrtc::RTCTlsCertPolicy UseEnum::toWrapper(::webrtc::PeerConnectionInterface::TlsCertPolicy value) noexcept
{
  switch (value)
  {
    case ::webrtc::PeerConnectionInterface::TlsCertPolicy::kTlsCertPolicySecure:          return wrapper::org::webrtc::RTCTlsCertPolicy::RTCTlsCertPolicy_tlsCertPolicySecure;
    case ::webrtc::PeerConnectionInterface::TlsCertPolicy::kTlsCertPolicyInsecureNoCheck: return wrapper::org::webrtc::RTCTlsCertPolicy::RTCTlsCertPolicy_tlsCertPolicyInsecureNoCheck;
  }
  ZS_ASSERT_FAIL("unknown type");
  return wrapper::org::webrtc::RTCTlsCertPolicy::RTCTlsCertPolicy_tlsCertPolicySecure;
}

//-----------------------------------------------------------------------------
::webrtc::PeerConnectionInterface::TlsCertPolicy UseEnum::toNative(wrapper::org::webrtc::RTCTlsCertPolicy value) noexcept
{
  switch (value)
  {
    case wrapper::org::webrtc::RTCTlsCertPolicy::RTCTlsCertPolicy_tlsCertPolicySecure:          return ::webrtc::PeerConnectionInterface::TlsCertPolicy::kTlsCertPolicySecure;
    case wrapper::org::webrtc::RTCTlsCertPolicy::RTCTlsCertPolicy_tlsCertPolicyInsecureNoCheck: return ::webrtc::PeerConnectionInterface::TlsCertPolicy::kTlsCertPolicyInsecureNoCheck;
  }
  ZS_ASSERT_FAIL("unknown type");
  return ::webrtc::PeerConnectionInterface::TlsCertPolicy::kTlsCertPolicySecure;
}

//-----------------------------------------------------------------------------
wrapper::org::webrtc::RTCSdpType UseEnum::toWrapper(::webrtc::SdpType value) noexcept
{
  switch (value)
  {
    case ::webrtc::SdpType::kOffer:        return wrapper::org::webrtc::RTCSdpType::RTCSdpType_offer;
    case ::webrtc::SdpType::kPrAnswer:     return wrapper::org::webrtc::RTCSdpType::RTCSdpType_pranswer;
    case ::webrtc::SdpType::kAnswer:       return wrapper::org::webrtc::RTCSdpType::RTCSdpType_answer;
  }
  ZS_ASSERT_FAIL("unknown type");
  return wrapper::org::webrtc::RTCSdpType::RTCSdpType_rollback;
}

//-----------------------------------------------------------------------------
::webrtc::SdpType UseEnum::toNative(wrapper::org::webrtc::RTCSdpType value) noexcept
{
  switch (value)
  {
    case wrapper::org::webrtc::RTCSdpType::RTCSdpType_offer:        return ::webrtc::SdpType::kOffer;
    case wrapper::org::webrtc::RTCSdpType::RTCSdpType_pranswer:     return ::webrtc::SdpType::kPrAnswer;
    case wrapper::org::webrtc::RTCSdpType::RTCSdpType_answer:       return ::webrtc::SdpType::kAnswer;
#pragma ZS_BUILD_NOTE("LATER","webrtc does not support rollback sdp type")
    case wrapper::org::webrtc::RTCSdpType::RTCSdpType_rollback:     break;
  }
  ZS_ASSERT_FAIL("unknown type");
  return ::webrtc::SdpType::kPrAnswer;
}

//-----------------------------------------------------------------------------
wrapper::org::webrtc::MediaSourceState UseEnum::toWrapper(::webrtc::MediaSourceInterface::SourceState value) noexcept
{
  switch (value)
  {
    case ::webrtc::MediaSourceInterface::SourceState::kInitializing:    return wrapper::org::webrtc::MediaSourceState::MediaSourceState_initializing;
    case ::webrtc::MediaSourceInterface::SourceState::kLive:            return wrapper::org::webrtc::MediaSourceState::MediaSourceState_live;
    case ::webrtc::MediaSourceInterface::SourceState::kEnded:           return wrapper::org::webrtc::MediaSourceState::MediaSourceState_ended;
    case ::webrtc::MediaSourceInterface::SourceState::kMuted:           return wrapper::org::webrtc::MediaSourceState::MediaSourceState_muted;
  }
  ZS_ASSERT_FAIL("unknown type");
  return wrapper::org::webrtc::MediaSourceState::MediaSourceState_ended;
}

//-----------------------------------------------------------------------------
::webrtc::MediaSourceInterface::SourceState UseEnum::toNative(wrapper::org::webrtc::MediaSourceState value) noexcept
{
  switch (value)
  {
    case wrapper::org::webrtc::MediaSourceState::MediaSourceState_initializing:   return ::webrtc::MediaSourceInterface::SourceState::kInitializing;
    case wrapper::org::webrtc::MediaSourceState::MediaSourceState_live:           return ::webrtc::MediaSourceInterface::SourceState::kLive;
    case wrapper::org::webrtc::MediaSourceState::MediaSourceState_ended:          return ::webrtc::MediaSourceInterface::SourceState::kEnded;
    case wrapper::org::webrtc::MediaSourceState::MediaSourceState_muted:          return ::webrtc::MediaSourceInterface::SourceState::kMuted;
  }
  ZS_ASSERT_FAIL("unknown type");
  return ::webrtc::MediaSourceInterface::SourceState::kEnded;
}

//-----------------------------------------------------------------------------
wrapper::org::webrtc::MediaStreamTrackState UseEnum::toWrapper(::webrtc::MediaStreamTrackInterface::TrackState value) noexcept
{
  switch (value)
  {
    case ::webrtc::MediaStreamTrackInterface::TrackState::kLive:    return wrapper::org::webrtc::MediaStreamTrackState::MediaStreamTrackState_live;
    case ::webrtc::MediaStreamTrackInterface::TrackState::kEnded:   return wrapper::org::webrtc::MediaStreamTrackState::MediaStreamTrackState_ended;
  }
  ZS_ASSERT_FAIL("unknown type");
  return wrapper::org::webrtc::MediaStreamTrackState::MediaStreamTrackState_ended;
}

//-----------------------------------------------------------------------------
::webrtc::MediaStreamTrackInterface::TrackState UseEnum::toNative(wrapper::org::webrtc::MediaStreamTrackState value) noexcept
{
  switch (value)
  {
    case wrapper::org::webrtc::MediaStreamTrackState::MediaStreamTrackState_live:     return ::webrtc::MediaStreamTrackInterface::TrackState::kLive;
    case wrapper::org::webrtc::MediaStreamTrackState::MediaStreamTrackState_ended:    return ::webrtc::MediaStreamTrackInterface::TrackState::kEnded;
  }
  ZS_ASSERT_FAIL("unknown type");
  return ::webrtc::MediaStreamTrackInterface::TrackState::kEnded;
}

//-----------------------------------------------------------------------------
wrapper::org::webrtc::RTCConfigurationType UseEnum::toWrapper(::webrtc::PeerConnectionInterface::RTCConfigurationType value) noexcept
{
  switch (value)
  {
    case ::webrtc::PeerConnectionInterface::RTCConfigurationType::kSafe:        return wrapper::org::webrtc::RTCConfigurationType::RTCConfigurationType_safe;
    case ::webrtc::PeerConnectionInterface::RTCConfigurationType::kAggressive:  return wrapper::org::webrtc::RTCConfigurationType::RTCConfigurationType_aggressive;
  }
  ZS_ASSERT_FAIL("unknown type");
  return wrapper::org::webrtc::RTCConfigurationType::RTCConfigurationType_safe;
}

//-----------------------------------------------------------------------------
::webrtc::PeerConnectionInterface::RTCConfigurationType UseEnum::toNative(wrapper::org::webrtc::RTCConfigurationType value) noexcept
{
  switch (value)
  {
    case wrapper::org::webrtc::RTCConfigurationType::RTCConfigurationType_safe:         return ::webrtc::PeerConnectionInterface::RTCConfigurationType::kSafe;
    case wrapper::org::webrtc::RTCConfigurationType::RTCConfigurationType_aggressive:   return ::webrtc::PeerConnectionInterface::RTCConfigurationType::kAggressive;
  }
  ZS_ASSERT_FAIL("unknown type");
  return ::webrtc::PeerConnectionInterface::RTCConfigurationType::kSafe;
}

//-----------------------------------------------------------------------------
wrapper::org::webrtc::RTCDataChannelState UseEnum::toWrapper(::webrtc::DataChannelInterface::DataState value) noexcept
{
  switch (value)
  {
    case ::webrtc::DataChannelInterface::DataState::kConnecting:    return wrapper::org::webrtc::RTCDataChannelState::RTCDataChannelState_connecting;
    case ::webrtc::DataChannelInterface::DataState::kOpen:          return wrapper::org::webrtc::RTCDataChannelState::RTCDataChannelState_open;
    case ::webrtc::DataChannelInterface::DataState::kClosing:       return wrapper::org::webrtc::RTCDataChannelState::RTCDataChannelState_closing;
    case ::webrtc::DataChannelInterface::DataState::kClosed:        return wrapper::org::webrtc::RTCDataChannelState::RTCDataChannelState_closed;
  }
  ZS_ASSERT_FAIL("unknown type");
  return wrapper::org::webrtc::RTCDataChannelState::RTCDataChannelState_closed;
}

//-----------------------------------------------------------------------------
::webrtc::DataChannelInterface::DataState UseEnum::toNative(wrapper::org::webrtc::RTCDataChannelState value) noexcept
{
  switch (value)
  {
    case wrapper::org::webrtc::RTCDataChannelState::RTCDataChannelState_connecting: return ::webrtc::DataChannelInterface::DataState::kConnecting;
    case wrapper::org::webrtc::RTCDataChannelState::RTCDataChannelState_open:       return ::webrtc::DataChannelInterface::DataState::kOpen;
    case wrapper::org::webrtc::RTCDataChannelState::RTCDataChannelState_closing:    return ::webrtc::DataChannelInterface::DataState::kClosing;
    case wrapper::org::webrtc::RTCDataChannelState::RTCDataChannelState_closed:     return ::webrtc::DataChannelInterface::DataState::kClosed;
  }
  ZS_ASSERT_FAIL("unknown type");
  return ::webrtc::DataChannelInterface::DataState::kClosed;
}

//-----------------------------------------------------------------------------
wrapper::org::webrtc::RTCDegradationPreference UseEnum::toWrapper(::webrtc::DegradationPreference value) noexcept
{
  switch (value)
  {
    case ::webrtc::DegradationPreference::MAINTAIN_FRAMERATE:   return wrapper::org::webrtc::RTCDegradationPreference::RTCDegradationPreference_maintainFramerate;
    case ::webrtc::DegradationPreference::MAINTAIN_RESOLUTION:  return wrapper::org::webrtc::RTCDegradationPreference::RTCDegradationPreference_maintainResolution;
    case ::webrtc::DegradationPreference::BALANCED:             return wrapper::org::webrtc::RTCDegradationPreference::RTCDegradationPreference_balanced;
  }
  ZS_ASSERT_FAIL("unknown type");
  return wrapper::org::webrtc::RTCDegradationPreference::RTCDegradationPreference_balanced;
}

//-----------------------------------------------------------------------------
::webrtc::DegradationPreference UseEnum::toNative(wrapper::org::webrtc::RTCDegradationPreference value) noexcept
{
  switch (value)
  {
    case wrapper::org::webrtc::RTCDegradationPreference::RTCDegradationPreference_maintainFramerate:    return ::webrtc::DegradationPreference::MAINTAIN_FRAMERATE;
    case wrapper::org::webrtc::RTCDegradationPreference::RTCDegradationPreference_maintainResolution:   return ::webrtc::DegradationPreference::MAINTAIN_RESOLUTION;
    case wrapper::org::webrtc::RTCDegradationPreference::RTCDegradationPreference_balanced:             return ::webrtc::DegradationPreference::BALANCED;
  }
  ZS_ASSERT_FAIL("unknown type");
  return ::webrtc::DegradationPreference::BALANCED;
}

//-----------------------------------------------------------------------------
const char *UseEnum::toWrapper(::webrtc::FecMechanism value) noexcept
{
  switch (value)
  {
    case ::webrtc::FecMechanism::RED:             return "red";
    case ::webrtc::FecMechanism::RED_AND_ULPFEC:  return "red+ulpfec";
    case ::webrtc::FecMechanism::FLEXFEC:         return "flexfec";
  }
  ZS_ASSERT_FAIL("unknown type");
  return "unknown";
}

//-----------------------------------------------------------------------------
::webrtc::FecMechanism UseEnum::toNativeFecMechanism(const char *value) noexcept(false)
{
  const ::webrtc::FecMechanism enums[] = {
    ::webrtc::FecMechanism::RED,
    ::webrtc::FecMechanism::RED_AND_ULPFEC,
    ::webrtc::FecMechanism::FLEXFEC
  };

  String str(value);

  for (size_t loop = 0; loop < sizeof(enums) / sizeof(enums[0]); ++loop) {
    if (0 == str.compareNoCase(toWrapper(enums[loop]))) return enums[loop];
  }

  ZS_THROW_INVALID_ARGUMENT("FecMechanism is not understood: " + str);
}


//-----------------------------------------------------------------------------
wrapper::org::webrtc::RTCDtxStatus UseEnum::toWrapper(::webrtc::DtxStatus value) noexcept
{
  switch (value)
  {
    case ::webrtc::DtxStatus::DISABLED:   return wrapper::org::webrtc::RTCDtxStatus::RTCDtxStatus_disabled;
    case ::webrtc::DtxStatus::ENABLED:    return wrapper::org::webrtc::RTCDtxStatus::RTCDtxStatus_enabled;
  }
  ZS_ASSERT_FAIL("unknown type");
  return wrapper::org::webrtc::RTCDtxStatus::RTCDtxStatus_enabled;
}

//-----------------------------------------------------------------------------
::webrtc::DtxStatus UseEnum::toNative(wrapper::org::webrtc::RTCDtxStatus value) noexcept
{
  switch (value)
  {
    case wrapper::org::webrtc::RTCDtxStatus::RTCDtxStatus_disabled:   return ::webrtc::DtxStatus::DISABLED;
    case wrapper::org::webrtc::RTCDtxStatus::RTCDtxStatus_enabled:    return ::webrtc::DtxStatus::ENABLED;
  }
  ZS_ASSERT_FAIL("unknown type");
  return ::webrtc::DtxStatus::ENABLED;
}


//-----------------------------------------------------------------------------
const char *UseEnum::toWrapper(::webrtc::RtcpFeedbackType value) noexcept
{
  switch (value)
  {
    case ::webrtc::RtcpFeedbackType::CCM:           return "ccm";
    case ::webrtc::RtcpFeedbackType::NACK:          return "nack";
    case ::webrtc::RtcpFeedbackType::REMB:          return "goog-remb";
    case ::webrtc::RtcpFeedbackType::TRANSPORT_CC:  return "transport-cc";
  }
  ZS_ASSERT_FAIL("unknown type");
  return "unknown";
}

//-----------------------------------------------------------------------------
::webrtc::RtcpFeedbackType UseEnum::toNativeRtcpFeedbackType(const char *value) noexcept(false)
{
  const ::webrtc::RtcpFeedbackType enums[] = {
    ::webrtc::RtcpFeedbackType::CCM,
    ::webrtc::RtcpFeedbackType::NACK,
    ::webrtc::RtcpFeedbackType::REMB,
    ::webrtc::RtcpFeedbackType::TRANSPORT_CC
  };

  String str(value);

  for (size_t loop = 0; loop < sizeof(enums) / sizeof(enums[0]); ++loop) {
    if (0 == str.compareNoCase(toWrapper(enums[loop]))) return enums[loop];
  }

  ZS_THROW_INVALID_ARGUMENT("RtcpFeedbackType is not understood: " + str);
}

//-----------------------------------------------------------------------------
const char *UseEnum::toWrapper(::webrtc::RtcpFeedbackMessageType value) noexcept
{
  switch (value)
  {
    case ::webrtc::RtcpFeedbackMessageType::GENERIC_NACK: return "nack";
    case ::webrtc::RtcpFeedbackMessageType::PLI:          return "pli";
    case ::webrtc::RtcpFeedbackMessageType::FIR:          return "fir";
  }
  ZS_ASSERT_FAIL("unknown type");
  return "unknown";
}

//-----------------------------------------------------------------------------
::webrtc::RtcpFeedbackMessageType UseEnum::toNativeRtcpFeedbackMessageType(const char *value) noexcept(false)
{
  const ::webrtc::RtcpFeedbackMessageType enums[] = {
    ::webrtc::RtcpFeedbackMessageType::GENERIC_NACK,
    ::webrtc::RtcpFeedbackMessageType::PLI,
    ::webrtc::RtcpFeedbackMessageType::FIR
  };

  String str(value);

  for (size_t loop = 0; loop < sizeof(enums) / sizeof(enums[0]); ++loop) {
    if (0 == str.compareNoCase(toWrapper(enums[loop]))) return enums[loop];
  }

  ZS_THROW_INVALID_ARGUMENT("RtcpFeedbackMessageType is not understood: " + str);
}


//-----------------------------------------------------------------------------
wrapper::org::webrtc::RTCECCurve UseEnum::toWrapper(::rtc::ECCurve value) noexcept
{
  switch (value)
  {
    case ::rtc::ECCurve::EC_NIST_P256:   return wrapper::org::webrtc::RTCECCurve::RTCECCurve_nistP256;
  }
  ZS_ASSERT_FAIL("unknown type");
  return wrapper::org::webrtc::RTCECCurve::RTCECCurve_nistP256;
}

//-----------------------------------------------------------------------------
::rtc::ECCurve UseEnum::toNative(wrapper::org::webrtc::RTCECCurve value) noexcept
{
  switch (value)
  {
    case wrapper::org::webrtc::RTCECCurve::RTCECCurve_nistP256:   return ::rtc::ECCurve::EC_NIST_P256;
  }
  ZS_ASSERT_FAIL("unknown type");
  return ::rtc::ECCurve::EC_NIST_P256;
}

//-----------------------------------------------------------------------------
wrapper::org::webrtc::RTCKeyType UseEnum::toWrapper(::rtc::KeyType value) noexcept
{
  switch (value)
  {
    case ::rtc::KeyType::KT_RSA:    return wrapper::org::webrtc::RTCKeyType::RTCKeyType_rsa;
    case ::rtc::KeyType::KT_ECDSA:  return wrapper::org::webrtc::RTCKeyType::RTCKeyType_ecdsa;
  }
  ZS_ASSERT_FAIL("unknown type");
  return wrapper::org::webrtc::RTCKeyType::RTCKeyType_default;
}

//-----------------------------------------------------------------------------
::rtc::KeyType UseEnum::toNative(wrapper::org::webrtc::RTCKeyType value) noexcept
{
  switch (value)
  {
    case wrapper::org::webrtc::RTCKeyType::RTCKeyType_default:  return ::rtc::KeyType::KT_DEFAULT;
    case wrapper::org::webrtc::RTCKeyType::RTCKeyType_rsa:      return ::rtc::KeyType::KT_RSA;
    case wrapper::org::webrtc::RTCKeyType::RTCKeyType_ecdsa:    return ::rtc::KeyType::KT_RSA;
  }
  ZS_ASSERT_FAIL("unknown type");
  return ::rtc::KeyType::KT_DEFAULT;
}

//-----------------------------------------------------------------------------
wrapper::org::webrtc::RTCIceCandidateType UseEnum::toWrapperRTCIceCandidateType(const char *value) noexcept(false)
{
  const wrapper::org::webrtc::RTCIceCandidateType enums[] = {
    wrapper::org::webrtc::RTCIceCandidateType::RTCIceCandidateType_host,
    wrapper::org::webrtc::RTCIceCandidateType::RTCIceCandidateType_srflex,
    wrapper::org::webrtc::RTCIceCandidateType::RTCIceCandidateType_prflx,
    wrapper::org::webrtc::RTCIceCandidateType::RTCIceCandidateType_relay,
  };

  String str(value);

  for (size_t loop = 0; loop < sizeof(enums) / sizeof(enums[0]); ++loop) {
    if (0 == str.compareNoCase(toNative(enums[loop]))) return enums[loop];
  }

  ZS_THROW_INVALID_ARGUMENT("RTCIceCandidateType is not understood: " + str);
}

//-----------------------------------------------------------------------------
const char *UseEnum::toNative(wrapper::org::webrtc::RTCIceCandidateType value) noexcept
{
  switch (value)
  {
    case wrapper::org::webrtc::RTCIceCandidateType::RTCIceCandidateType_host:     return "host";
    case wrapper::org::webrtc::RTCIceCandidateType::RTCIceCandidateType_srflex:   return "srflex";
    case wrapper::org::webrtc::RTCIceCandidateType::RTCIceCandidateType_prflx:    return "prflx";
    case wrapper::org::webrtc::RTCIceCandidateType::RTCIceCandidateType_relay:    return "relay";
  }
  ZS_ASSERT_FAIL("unknown type");
  return "unknown";
}


//-----------------------------------------------------------------------------
wrapper::org::webrtc::RTCIceComponent UseEnum::toWrapperRTCIceComponent(int value) noexcept(false)
{
  switch (value)
  {
    case 1: return wrapper::org::webrtc::RTCIceComponent::RTCIceComponent_rtp;
    case 2: return wrapper::org::webrtc::RTCIceComponent::RTCIceComponent_rtcp;
  }
  ZS_THROW_INVALID_ARGUMENT("RTCIceComponent is not understood: " + zsLib::string(value));
}

//-----------------------------------------------------------------------------
int UseEnum::toNative(wrapper::org::webrtc::RTCIceComponent value) noexcept
{
  switch (value)
  {
    case wrapper::org::webrtc::RTCIceComponent::RTCIceComponent_rtp:     return 1;
    case wrapper::org::webrtc::RTCIceComponent::RTCIceComponent_rtcp:   return 2;
  }
  ZS_ASSERT_FAIL("unknown type");
  return 0;
}

//-----------------------------------------------------------------------------
wrapper::org::webrtc::RTCIceConnectionState toWrapper(::webrtc::PeerConnectionInterface::IceConnectionState value) noexcept
{
  switch (value)
  {
    case ::webrtc::PeerConnectionInterface::IceConnectionState::kIceConnectionNew:            return wrapper::org::webrtc::RTCIceConnectionState::RTCIceConnectionState_new;
    case ::webrtc::PeerConnectionInterface::IceConnectionState::kIceConnectionChecking:       return wrapper::org::webrtc::RTCIceConnectionState::RTCIceConnectionState_checking;
    case ::webrtc::PeerConnectionInterface::IceConnectionState::kIceConnectionConnected:      return wrapper::org::webrtc::RTCIceConnectionState::RTCIceConnectionState_connected;
    case ::webrtc::PeerConnectionInterface::IceConnectionState::kIceConnectionCompleted:      return wrapper::org::webrtc::RTCIceConnectionState::RTCIceConnectionState_completed;
    case ::webrtc::PeerConnectionInterface::IceConnectionState::kIceConnectionFailed:         return wrapper::org::webrtc::RTCIceConnectionState::RTCIceConnectionState_failed;
    case ::webrtc::PeerConnectionInterface::IceConnectionState::kIceConnectionDisconnected:   return wrapper::org::webrtc::RTCIceConnectionState::RTCIceConnectionState_disconnected;
    case ::webrtc::PeerConnectionInterface::IceConnectionState::kIceConnectionClosed:         return wrapper::org::webrtc::RTCIceConnectionState::RTCIceConnectionState_closed;
  }
  ZS_ASSERT_FAIL("unknown type");
  return wrapper::org::webrtc::RTCIceConnectionState::RTCIceConnectionState_closed;
}

//-----------------------------------------------------------------------------
::webrtc::PeerConnectionInterface::IceConnectionState toNative(wrapper::org::webrtc::RTCIceConnectionState value) noexcept
{
  switch (value)
  {
    case wrapper::org::webrtc::RTCIceConnectionState::RTCIceConnectionState_new:              return ::webrtc::PeerConnectionInterface::IceConnectionState::kIceConnectionNew;
    case wrapper::org::webrtc::RTCIceConnectionState::RTCIceConnectionState_checking:         return ::webrtc::PeerConnectionInterface::IceConnectionState::kIceConnectionChecking;
    case wrapper::org::webrtc::RTCIceConnectionState::RTCIceConnectionState_connected:        return ::webrtc::PeerConnectionInterface::IceConnectionState::kIceConnectionConnected;
    case wrapper::org::webrtc::RTCIceConnectionState::RTCIceConnectionState_completed:        return ::webrtc::PeerConnectionInterface::IceConnectionState::kIceConnectionCompleted;
    case wrapper::org::webrtc::RTCIceConnectionState::RTCIceConnectionState_failed:           return ::webrtc::PeerConnectionInterface::IceConnectionState::kIceConnectionFailed;
    case wrapper::org::webrtc::RTCIceConnectionState::RTCIceConnectionState_disconnected:     return ::webrtc::PeerConnectionInterface::IceConnectionState::kIceConnectionDisconnected;
    case wrapper::org::webrtc::RTCIceConnectionState::RTCIceConnectionState_closed:           return ::webrtc::PeerConnectionInterface::IceConnectionState::kIceConnectionClosed;
  }
  ZS_ASSERT_FAIL("unknown type");
  return ::webrtc::PeerConnectionInterface::IceConnectionState::kIceConnectionClosed;
}

