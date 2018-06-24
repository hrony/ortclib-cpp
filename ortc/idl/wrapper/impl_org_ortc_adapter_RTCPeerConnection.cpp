
#include "impl_org_ortc_adapter_RTCPeerConnection.h"
#include "impl_org_ortc_adapter_RTCConfiguration.h"
#include "impl_org_ortc_adapter_RTCSessionDescription.h"
#include "impl_org_ortc_adapter_RTCIceCandidate.h"
#include "impl_org_ortc_adapter_RTCCapabilityOptions.h"
#include "impl_org_ortc_adapter_RTCOfferOptions.h"
#include "impl_org_ortc_adapter_RTCAnswerOptions.h"
#include "impl_org_ortc_adapter_RTCMediaStreamTrackConfiguration.h"
#include "impl_org_ortc_adapter_RTCPeerConnectionIceEvent.h"
#include "impl_org_ortc_adapter_RTCPeerConnectionIceErrorEvent.h"
#include "impl_org_ortc_adapter_MediaStream.h"
#include "impl_org_ortc_adapter_RTCTrackEvent.h"
#include "impl_org_ortc_RTCDataChannelEvent.h"
#include "impl_org_ortc_RTCRtpSender.h"
#include "impl_org_ortc_RTCRtpReceiver.h"
#include "impl_org_ortc_RTCIceServer.h"
#include "impl_org_ortc_MediaStreamTrack.h"
#include "impl_org_ortc_RTCDataChannel.h"
#include "impl_org_ortc_RTCDataChannelParameters.h"
#include "impl_org_ortc_Helper.h"

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

namespace wrapper { namespace impl { namespace org { namespace ortc { namespace adapter { ZS_DECLARE_SUBSYSTEM(org_ortc_wrapper_adapter); } } } } }

ZS_DECLARE_TYPEDEF_PTR(wrapper::impl::org::ortc::adapter::RTCPeerConnection::NativeType, NativeType);
ZS_DECLARE_TYPEDEF_PTR(wrapper::impl::org::ortc::adapter::RTCPeerConnection::NativeTypeSubscription, NativeTypeSubscription);
ZS_DECLARE_TYPEDEF_PTR(wrapper::impl::org::ortc::adapter::RTCPeerConnection::WrapperImplType, WrapperImplType);
ZS_DECLARE_TYPEDEF_PTR(wrapper::impl::org::ortc::adapter::RTCPeerConnection::WrapperType, WrapperType);

//------------------------------------------------------------------------------
wrapper::impl::org::ortc::adapter::RTCPeerConnection::RTCPeerConnection() noexcept
{
}

//------------------------------------------------------------------------------
wrapper::org::ortc::adapter::RTCPeerConnectionPtr wrapper::org::ortc::adapter::RTCPeerConnection::wrapper_create() noexcept
{
  auto pThis = make_shared<wrapper::impl::org::ortc::adapter::RTCPeerConnection>();
  pThis->thisWeak_ = pThis;
  return pThis;
}

//------------------------------------------------------------------------------
wrapper::impl::org::ortc::adapter::RTCPeerConnection::~RTCPeerConnection() noexcept
{
}

//------------------------------------------------------------------------------
shared_ptr< PromiseWithHolderPtr< wrapper::org::ortc::RTCStatsReportPtr > > wrapper::impl::org::ortc::adapter::RTCPeerConnection::getStats(wrapper::org::ortc::RTCStatsTypeSetPtr statTypes) noexcept(false)
{
  return Helper::getStats(native_, statTypes);
}

//------------------------------------------------------------------------------
void wrapper::impl::org::ortc::adapter::RTCPeerConnection::wrapper_init_org_ortc_adapter_RTCPeerConnection() noexcept
{
  native_ = NativeType::create(thisWeak_.lock());
}

//------------------------------------------------------------------------------
void wrapper::impl::org::ortc::adapter::RTCPeerConnection::wrapper_init_org_ortc_adapter_RTCPeerConnection(wrapper::org::ortc::adapter::RTCConfigurationPtr configuration) noexcept
{
  auto native = RTCConfiguration::toNative(configuration);
  ZS_ASSERT(native);
  native_ = NativeType::create(thisWeak_.lock(), *native);
}

//------------------------------------------------------------------------------
shared_ptr< PromiseWithHolderPtr< wrapper::org::ortc::adapter::RTCSessionDescriptionPtr > > wrapper::impl::org::ortc::adapter::RTCPeerConnection::createOffer() noexcept
{
  return toWrapper(native_->createOffer());
}

//------------------------------------------------------------------------------
shared_ptr< PromiseWithHolderPtr< wrapper::org::ortc::adapter::RTCSessionDescriptionPtr > > wrapper::impl::org::ortc::adapter::RTCPeerConnection::createOffer(wrapper::org::ortc::adapter::RTCOfferOptionsPtr options) noexcept
{
  Optional< ::ortc::adapter::IPeerConnectionTypes::OfferOptions > native;
  auto convert = RTCOfferOptions::toNative(options);
  if (convert) {
    native = *convert;
  }

  return toWrapper(native_->createOffer(native));
}

//------------------------------------------------------------------------------
shared_ptr< PromiseWithHolderPtr< wrapper::org::ortc::adapter::RTCSessionDescriptionPtr > > wrapper::impl::org::ortc::adapter::RTCPeerConnection::createAnswer() noexcept
{
  return toWrapper(native_->createAnswer());
}

//------------------------------------------------------------------------------
shared_ptr< PromiseWithHolderPtr< wrapper::org::ortc::adapter::RTCSessionDescriptionPtr > > wrapper::impl::org::ortc::adapter::RTCPeerConnection::createAnswer(wrapper::org::ortc::adapter::RTCAnswerOptionsPtr options) noexcept
{
  Optional< ::ortc::adapter::IPeerConnectionTypes::AnswerOptions > native;
  auto convert = RTCAnswerOptions::toNative(options);
  if (convert) {
    native = *convert;
  }

  return toWrapper(native_->createAnswer(native));
}

//------------------------------------------------------------------------------
shared_ptr< PromiseWithHolderPtr< wrapper::org::ortc::adapter::RTCSessionDescriptionPtr > > wrapper::impl::org::ortc::adapter::RTCPeerConnection::createCapabilities() noexcept
{
  return toWrapper(native_->createCapabilities());
}

//------------------------------------------------------------------------------
shared_ptr< PromiseWithHolderPtr< wrapper::org::ortc::adapter::RTCSessionDescriptionPtr > > wrapper::impl::org::ortc::adapter::RTCPeerConnection::createCapabilities(wrapper::org::ortc::adapter::RTCCapabilityOptionsPtr options) noexcept
{
  Optional< ::ortc::adapter::IPeerConnectionTypes::CapabilityOptions > native;
  auto convert = RTCCapabilityOptions::toNative(options);
  if (convert) {
    native = *convert;
  }

  return toWrapper(native_->createCapabilities(native));
}

//------------------------------------------------------------------------------
PromisePtr wrapper::impl::org::ortc::adapter::RTCPeerConnection::setLocalDescription(wrapper::org::ortc::adapter::RTCSessionDescriptionPtr description) noexcept
{
  return Helper::toWrapper(native_->setLocalDescription(RTCSessionDescription::toNative(description)));
}

//------------------------------------------------------------------------------
PromisePtr wrapper::impl::org::ortc::adapter::RTCPeerConnection::setRemoteDescription(wrapper::org::ortc::adapter::RTCSessionDescriptionPtr description) noexcept
{
  return Helper::toWrapper(native_->setRemoteDescription(RTCSessionDescription::toNative(description)));
}

//------------------------------------------------------------------------------
void wrapper::impl::org::ortc::adapter::RTCPeerConnection::addIceCandidate(wrapper::org::ortc::adapter::RTCIceCandidatePtr candidate) noexcept
{
  auto native = RTCIceCandidate::toNative(candidate);
  ZS_ASSERT(native);
  native_->addICECandidate(*native);
}

//------------------------------------------------------------------------------
shared_ptr< list< wrapper::org::ortc::RTCIceServerPtr > > wrapper::impl::org::ortc::adapter::RTCPeerConnection::getDefaultIceServers() noexcept
{
  auto resultList = make_shared< list< wrapper::org::ortc::RTCIceServerPtr > >();
  auto nativeList = native_->getDefaultIceServers();
  if (nativeList) {
    for (auto iter = nativeList->begin(); iter != nativeList->end(); ++iter) {
      auto wrapper = RTCIceServer::toWrapper(*iter);
      if (!wrapper) continue;
      resultList->push_back(wrapper);
    }
  }
  return resultList;
}

//------------------------------------------------------------------------------
void wrapper::impl::org::ortc::adapter::RTCPeerConnection::close() noexcept
{
  native_->close();
}

//------------------------------------------------------------------------------
shared_ptr< list< wrapper::org::ortc::RTCRtpSenderPtr > > wrapper::impl::org::ortc::adapter::RTCPeerConnection::getSenders() noexcept
{
  auto resultList = make_shared< list< wrapper::org::ortc::RTCRtpSenderPtr > >();
  auto nativeList = native_->getSenders();
  if (nativeList) {
    for (auto iter = nativeList->begin(); iter != nativeList->end(); ++iter) {
      auto wrapper = RTCRtpSender::toWrapper(*iter);
      if (!wrapper) continue;
      resultList->push_back(wrapper);
    }
  }
  return resultList;
}

//------------------------------------------------------------------------------
shared_ptr< list< wrapper::org::ortc::RTCRtpReceiverPtr > > wrapper::impl::org::ortc::adapter::RTCPeerConnection::getReceivers() noexcept
{
  auto resultList = make_shared< list< wrapper::org::ortc::RTCRtpReceiverPtr > >();
  auto nativeList = native_->getReceivers();
  if (nativeList) {
    for (auto iter = nativeList->begin(); iter != nativeList->end(); ++iter) {
      auto wrapper = RTCRtpReceiver::toWrapper(*iter);
      if (!wrapper) continue;
      resultList->push_back(wrapper);
    }
  }
  return resultList;
}

//------------------------------------------------------------------------------
shared_ptr< PromiseWithHolderPtr< wrapper::org::ortc::RTCRtpSenderPtr > > wrapper::impl::org::ortc::adapter::RTCPeerConnection::addTrack(wrapper::org::ortc::MediaStreamTrackPtr track) noexcept
{
  return toWrapper(native_->addTrack(MediaStreamTrack::toNative(track)));
}

//------------------------------------------------------------------------------
shared_ptr< PromiseWithHolderPtr< wrapper::org::ortc::RTCRtpSenderPtr > > wrapper::impl::org::ortc::adapter::RTCPeerConnection::addTrack(
  wrapper::org::ortc::MediaStreamTrackPtr track,
  wrapper::org::ortc::adapter::RTCMediaStreamTrackConfigurationPtr config
  ) noexcept
{
  auto nativeTrack = MediaStreamTrack::toNative(track);
  auto nativeConfig = RTCMediaStreamTrackConfiguration::toNative(config);
  ZS_ASSERT(nativeConfig);

  return toWrapper(native_->addTrack(nativeTrack, *nativeConfig));
}

//------------------------------------------------------------------------------
shared_ptr< PromiseWithHolderPtr< wrapper::org::ortc::RTCRtpSenderPtr > > wrapper::impl::org::ortc::adapter::RTCPeerConnection::addTrack(
  wrapper::org::ortc::MediaStreamTrackPtr track,
  shared_ptr< list< wrapper::org::ortc::adapter::MediaStreamPtr > > mediaStreams,
  wrapper::org::ortc::adapter::RTCMediaStreamTrackConfigurationPtr config
  ) noexcept
{
  auto nativeTrack = MediaStreamTrack::toNative(track);
  list<::ortc::adapter::IMediaStreamPtr> nativeList;
  if (mediaStreams) {
    for (auto iter = mediaStreams->begin(); iter != mediaStreams->end(); ++iter) {
      auto native = MediaStream::toNative(*iter);
      if (!native) continue;
      nativeList.push_back(native);
    }
  }
  auto nativeConfig = RTCMediaStreamTrackConfiguration::toNative(config);
  ZS_ASSERT(nativeConfig);

  return toWrapper(native_->addTrack(nativeTrack, nativeList, *nativeConfig));
}

//------------------------------------------------------------------------------
void wrapper::impl::org::ortc::adapter::RTCPeerConnection::removeTrack(wrapper::org::ortc::RTCRtpSenderPtr sender) noexcept
{
  native_->removeTrack(RTCRtpSender::toNative(sender));
}

//------------------------------------------------------------------------------
shared_ptr< PromiseWithHolderPtr< wrapper::org::ortc::RTCDataChannelPtr > > wrapper::impl::org::ortc::adapter::RTCPeerConnection::createDataChannel(wrapper::org::ortc::RTCDataChannelParametersPtr parameters) noexcept
{
  auto native = RTCDataChannelParameters::toNative(parameters);
  ZS_ASSERT(!native);
  return toWrapper(native_->createDataChannel(*native));
}

//------------------------------------------------------------------------------
uint64_t wrapper::impl::org::ortc::adapter::RTCPeerConnection::get_objectId() noexcept
{
  return native_->getID();
}

//------------------------------------------------------------------------------
wrapper::org::ortc::adapter::RTCSessionDescriptionPtr wrapper::impl::org::ortc::adapter::RTCPeerConnection::get_localDescription() noexcept
{
  return RTCSessionDescription::toWrapper(native_->localDescription());
}

//------------------------------------------------------------------------------
wrapper::org::ortc::adapter::RTCSessionDescriptionPtr wrapper::impl::org::ortc::adapter::RTCPeerConnection::get_currentDescription() noexcept
{
  return RTCSessionDescription::toWrapper(native_->currentDescription());
}

//------------------------------------------------------------------------------
wrapper::org::ortc::adapter::RTCSessionDescriptionPtr wrapper::impl::org::ortc::adapter::RTCPeerConnection::get_pendingDescription() noexcept
{
  return RTCSessionDescription::toWrapper(native_->pendingDescription());
}

//------------------------------------------------------------------------------
wrapper::org::ortc::adapter::RTCSessionDescriptionPtr wrapper::impl::org::ortc::adapter::RTCPeerConnection::get_remoteDescription() noexcept
{
  return RTCSessionDescription::toWrapper(native_->remoteDescription());
}

//------------------------------------------------------------------------------
wrapper::org::ortc::adapter::RTCSessionDescriptionPtr wrapper::impl::org::ortc::adapter::RTCPeerConnection::get_currentRemoteDescription() noexcept
{
  return RTCSessionDescription::toWrapper(native_->currentRemoteDescription());
}

//------------------------------------------------------------------------------
wrapper::org::ortc::adapter::RTCSessionDescriptionPtr wrapper::impl::org::ortc::adapter::RTCPeerConnection::get_pendingRemoteDescription() noexcept
{
  return RTCSessionDescription::toWrapper(native_->pendingRemoteDescription());
}

//------------------------------------------------------------------------------
wrapper::org::ortc::adapter::RTCSignalingState wrapper::impl::org::ortc::adapter::RTCPeerConnection::get_signalingState() noexcept
{
  return Helper::toWrapper(native_->signalingState());
}

//------------------------------------------------------------------------------
wrapper::org::ortc::RTCIceGathererState wrapper::impl::org::ortc::adapter::RTCPeerConnection::get_iceGatheringState() noexcept
{
  return Helper::toWrapper(native_->iceGatheringState());
}

//------------------------------------------------------------------------------
wrapper::org::ortc::adapter::RTCIceConnectionState wrapper::impl::org::ortc::adapter::RTCPeerConnection::get_iceConnectionState() noexcept
{
  return Helper::toPeerConnectionWrapper(native_->iceConnectionState());
}

//------------------------------------------------------------------------------
wrapper::org::ortc::adapter::RTCPeerConnectionState wrapper::impl::org::ortc::adapter::RTCPeerConnection::get_connectionState() noexcept
{
  return Helper::toWrapper(native_->connectionState());
}

//------------------------------------------------------------------------------
bool wrapper::impl::org::ortc::adapter::RTCPeerConnection::get_canTrickleCandidates() noexcept
{
  return native_->canTrickleCandidates();
}

//------------------------------------------------------------------------------
wrapper::org::ortc::adapter::RTCConfigurationPtr wrapper::impl::org::ortc::adapter::RTCPeerConnection::get_getConfiguration() noexcept
{
  return RTCConfiguration::toWrapper(native_->getConfiguration());
}

//------------------------------------------------------------------------------
void wrapper::impl::org::ortc::adapter::RTCPeerConnection::set_getConfiguration(wrapper::org::ortc::adapter::RTCConfigurationPtr value) noexcept
{
  auto native = RTCConfiguration::toNative(value);
  ZS_ASSERT(native);
  native_->setConfiguration(*native);
}

//------------------------------------------------------------------------------
void wrapper::impl::org::ortc::adapter::RTCPeerConnection::wrapper_onObserverCountChanged(size_t count) noexcept
{
  subscriptionCount_ = count;
  subscribe();
}

//------------------------------------------------------------------------------
void WrapperImplType::onPeerConnectionNegotiationNeeded(IPeerConnectionPtr connection) noexcept
{
  onNegotiationNeeded();
}

//------------------------------------------------------------------------------
void WrapperImplType::onPeerConnectionIceCandidate(
  IPeerConnectionPtr connection,
  ICECandidatePtr candidate,
  const char *url
) noexcept
{
  onIceCandidate(RTCPeerConnectionIceEvent::toWrapper(candidate, String(url)));
}

//------------------------------------------------------------------------------
void WrapperImplType::onPeerConnectionIceCandidateError(
  IPeerConnectionPtr connection,
  ICECandidateErrorEventPtr error
) noexcept
{
  onIceCandidateError(RTCPeerConnectionIceErrorEvent::toWrapper(error));
}

//------------------------------------------------------------------------------
void WrapperImplType::onPeerConnectionSignalingStateChange(
  IPeerConnectionPtr connection,
  ZS_MAYBE_USED() SignalingStates state
) noexcept
{
  ZS_MAYBE_USED(state);
  onSignalingStateChange();
}

//------------------------------------------------------------------------------
void WrapperImplType::onPeerConnectionICEGatheringStateChange(
  IPeerConnectionPtr connection,
  ZS_MAYBE_USED() ICEGatheringStates state
) noexcept
{
  ZS_MAYBE_USED(state);
  onIceGatheringStateChange();
}

//------------------------------------------------------------------------------
void WrapperImplType::onPeerConnectionICEConnectionStateChange(
  IPeerConnectionPtr connection,
  ZS_MAYBE_USED() ICEConnectionStates state
) noexcept
{
  ZS_MAYBE_USED(state);
  onIceConnectionStateChange();
}

//------------------------------------------------------------------------------
void WrapperImplType::onPeerConnectionConnectionStateChange(
  IPeerConnectionPtr connection,
  ZS_MAYBE_USED() PeerConnectionStates state
) noexcept
{
  ZS_MAYBE_USED(state);
  onConnectionStateChange();
}

//------------------------------------------------------------------------------
void WrapperImplType::onPeerConnectionTrack(
  IPeerConnectionPtr connection,
  MediaStreamTrackEventPtr event
) noexcept
{
  onTrack(RTCTrackEvent::toWrapper(event));
}

//------------------------------------------------------------------------------
void WrapperImplType::onPeerConnectionTrackGone(
  IPeerConnectionPtr connection,
  MediaStreamTrackEventPtr event
) noexcept
{
  onTrackGone(RTCTrackEvent::toWrapper(event));
}

//------------------------------------------------------------------------------
void WrapperImplType::onPeerConnectionDataChannel(
  IPeerConnectionPtr connection,
  IDataChannelPtr dataChannel
) noexcept
{
  onDataChannel(RTCDataChannelEvent::toWrapper(dataChannel));
}

//------------------------------------------------------------------------------
WrapperImplTypePtr WrapperImplType::toWrapper(NativeTypePtr track) noexcept
{
  if (!track) return WrapperImplTypePtr();

  auto result = make_shared<WrapperImplType>();
  result->thisWeak_ = result;
  result->native_ = track;
  result->defaultSubscription_ = false;
  result->subscribe();
  return result;
}

//------------------------------------------------------------------------------
NativeTypePtr WrapperImplType::toNative(WrapperTypePtr wrapper) noexcept
{
  if (!wrapper) return NativeTypePtr();
  auto result = std::dynamic_pointer_cast<WrapperImplType>(wrapper);
  if (!result) return NativeTypePtr();
  return result->native_;
}

//------------------------------------------------------------------------------
void WrapperImplType::subscribe() noexcept
{
  if (defaultSubscription_) return;
  if (!native_) return;

  zsLib::AutoLock lock(lock_);
  if (subscriptionCount_ < 1) {
    if (!subscription_) return;
    subscription_->cancel();
    return;
  }
  if (subscription_) return;
  subscription_ = native_->subscribe(thisWeak_.lock());
}

//------------------------------------------------------------------------------
WrapperImplType::WrapperPromiseWithSessionDescriptionPtr WrapperImplType::toWrapper(NativePromiseWithSessionDescriptionPtr promise) noexcept
{
  if (!promise) return WrapperPromiseWithSessionDescriptionPtr();

  auto result = WrapperPromiseWithSessionDescription::create(Helper::getGuiQueue());
  promise->thenClosure([result, promise] {
    if (promise->isRejected()) {
      Helper::reject(promise, result);
      return;
    }
    result->resolve(RTCSessionDescription::toWrapper(promise->value()));
  });
  promise->background();
  return result;
}

//------------------------------------------------------------------------------
WrapperImplType::WrapperPromiseWithSenderPtr WrapperImplType::toWrapper(NativePromiseWithSenderPtr promise) noexcept
{
  if (!promise) return WrapperPromiseWithSenderPtr();

  auto result = WrapperPromiseWithSender::create(Helper::getGuiQueue());
  promise->thenClosure([result, promise] {
    if (promise->isRejected()) {
      Helper::reject(promise, result);
      return;
    }
    result->resolve(RTCRtpSender::toWrapper(promise->value()));
  });
  promise->background();
  return result;
}

//------------------------------------------------------------------------------
WrapperImplType::WrapperPromiseWithDataChannelPtr WrapperImplType::toWrapper(NativePromiseWithDataChannelPtr promise) noexcept
{
  if (!promise) return WrapperPromiseWithDataChannelPtr();

  auto result = WrapperPromiseWithDataChannel::create(Helper::getGuiQueue());
  promise->thenClosure([result, promise] {
    if (promise->isRejected()) {
      Helper::reject(promise, result);
      return;
    }
    result->resolve(RTCDataChannel::toWrapper(promise->value()));
  });
  promise->background();
  return result;
}
