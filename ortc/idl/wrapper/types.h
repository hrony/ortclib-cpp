
#pragma once

#include "generated/types.h"

namespace wrapper {
  namespace impl {

    namespace org {
      namespace ortc {
        namespace adapter {

          ZS_DECLARE_STRUCT_PTR(MediaStream);
          ZS_DECLARE_STRUCT_PTR(RTCAnswerOptions);
          ZS_DECLARE_STRUCT_PTR(RTCCapabilityOptions);
          ZS_DECLARE_STRUCT_PTR(RTCConfiguration);
          ZS_DECLARE_STRUCT_PTR(RTCIceCandidate);
          ZS_DECLARE_STRUCT_PTR(RTCMediaStreamTrackConfiguration);
          ZS_DECLARE_STRUCT_PTR(RTCOfferAnswerOptions);
          ZS_DECLARE_STRUCT_PTR(RTCOfferOptions);
          ZS_DECLARE_STRUCT_PTR(RTCPeerConnection);
          ZS_DECLARE_STRUCT_PTR(RTCPeerConnectionIceErrorEvent);
          ZS_DECLARE_STRUCT_PTR(RTCPeerConnectionIceEvent);
          ZS_DECLARE_STRUCT_PTR(RTCSessionDescription);
          ZS_DECLARE_STRUCT_PTR(RTCSessionDescriptionConnectionData);
          ZS_DECLARE_STRUCT_PTR(RTCSessionDescriptionConnectionDataDetails);
          ZS_DECLARE_STRUCT_PTR(RTCSessionDescriptionDescription);
          ZS_DECLARE_STRUCT_PTR(RTCSessionDescriptionDescriptionDetails);
          ZS_DECLARE_STRUCT_PTR(RTCSessionDescriptionMediaLine);
          ZS_DECLARE_STRUCT_PTR(RTCSessionDescriptionMediaLineDetails);
          ZS_DECLARE_STRUCT_PTR(RTCSessionDescriptionRtpMediaLine);
          ZS_DECLARE_STRUCT_PTR(RTCSessionDescriptionRtpSender);
          ZS_DECLARE_STRUCT_PTR(RTCSessionDescriptionRtpSenderDetails);
          ZS_DECLARE_STRUCT_PTR(RTCSessionDescriptionSctpMediaLine);
          ZS_DECLARE_STRUCT_PTR(RTCSessionDescriptionTransport);
          ZS_DECLARE_STRUCT_PTR(RTCSessionDescriptionTransportParameters);
          ZS_DECLARE_STRUCT_PTR(RTCTrackEvent);

        } // namespace adapter

        namespace log {
        } // namespace log

        ZS_DECLARE_STRUCT_PTR(ConstrainBoolean);
        ZS_DECLARE_STRUCT_PTR(ConstrainBooleanParameters);
        ZS_DECLARE_STRUCT_PTR(ConstrainDouble);
        ZS_DECLARE_STRUCT_PTR(ConstrainDoubleRange);
        ZS_DECLARE_STRUCT_PTR(ConstrainLong);
        ZS_DECLARE_STRUCT_PTR(ConstrainLongRange);
        ZS_DECLARE_STRUCT_PTR(ConstrainString);
        ZS_DECLARE_STRUCT_PTR(ConstrainStringParameters);
        ZS_DECLARE_STRUCT_PTR(DoubleRange);
        ZS_DECLARE_STRUCT_PTR(Error);
        ZS_DECLARE_STRUCT_PTR(ErrorEvent);
        ZS_DECLARE_STRUCT_PTR(EventQueue);
        ZS_DECLARE_STRUCT_PTR(Json);
        ZS_DECLARE_STRUCT_PTR(Logger);
        ZS_DECLARE_STRUCT_PTR(LongRange);
        ZS_DECLARE_STRUCT_PTR(MediaControl);
        ZS_DECLARE_STRUCT_PTR(MediaDeviceInfo);
        ZS_DECLARE_STRUCT_PTR(MediaDevices);
        ZS_DECLARE_STRUCT_PTR(MediaSource);
        ZS_DECLARE_STRUCT_PTR(MediaStreamConstraints);
        ZS_DECLARE_STRUCT_PTR(MediaStreamTrack);
        ZS_DECLARE_STRUCT_PTR(MediaTrackCapabilities);
        ZS_DECLARE_STRUCT_PTR(MediaTrackConstraintSet);
        ZS_DECLARE_STRUCT_PTR(MediaTrackConstraints);
        ZS_DECLARE_STRUCT_PTR(MediaTrackSettings);
        ZS_DECLARE_STRUCT_PTR(MediaTrackSupportedConstraints);
        ZS_DECLARE_STRUCT_PTR(OrtcLib);
        ZS_DECLARE_STRUCT_PTR(OverconstrainedError);
        ZS_DECLARE_STRUCT_PTR(OverconstrainedErrorEvent);
        ZS_DECLARE_STRUCT_PTR(RTCCertificate);
        ZS_DECLARE_STRUCT_PTR(RTCCertificateStats);
        ZS_DECLARE_STRUCT_PTR(RTCCodec);
        ZS_DECLARE_STRUCT_PTR(RTCDataChannel);
        ZS_DECLARE_STRUCT_PTR(RTCDataChannelEvent);
        ZS_DECLARE_STRUCT_PTR(RTCDataChannelParameters);
        ZS_DECLARE_STRUCT_PTR(RTCDataChannelStateChangeEvent);
        ZS_DECLARE_STRUCT_PTR(RTCDataChannelStats);
        ZS_DECLARE_STRUCT_PTR(RTCDataTransport);
        ZS_DECLARE_STRUCT_PTR(RTCDtlsCertificateBinary);
        ZS_DECLARE_STRUCT_PTR(RTCDtlsFingerprint);
        ZS_DECLARE_STRUCT_PTR(RTCDtlsParameters);
        ZS_DECLARE_STRUCT_PTR(RTCDtlsTransport);
        ZS_DECLARE_STRUCT_PTR(RTCDtlsTransportStateChangeEvent);
        ZS_DECLARE_STRUCT_PTR(RTCDtlsTransportStats);
        ZS_DECLARE_STRUCT_PTR(RTCDtmfSender);
        ZS_DECLARE_STRUCT_PTR(RTCDtmfToneChangeEvent);
        ZS_DECLARE_STRUCT_PTR(RTCIceCandidate);
        ZS_DECLARE_STRUCT_PTR(RTCIceCandidateAttributes);
        ZS_DECLARE_STRUCT_PTR(RTCIceCandidateComplete);
        ZS_DECLARE_STRUCT_PTR(RTCIceCandidatePair);
        ZS_DECLARE_STRUCT_PTR(RTCIceCandidatePairChangeEvent);
        ZS_DECLARE_STRUCT_PTR(RTCIceCandidatePairStats);
        ZS_DECLARE_STRUCT_PTR(RTCIceGatherInterfacePolicy);
        ZS_DECLARE_STRUCT_PTR(RTCIceGatherOptions);
        ZS_DECLARE_STRUCT_PTR(RTCIceGatherer);
        ZS_DECLARE_STRUCT_PTR(RTCIceGathererCandidate);
        ZS_DECLARE_STRUCT_PTR(RTCIceGathererCandidateCompleteEvent);
        ZS_DECLARE_STRUCT_PTR(RTCIceGathererCandidateEvent);
        ZS_DECLARE_STRUCT_PTR(RTCIceGathererIceErrorEvent);
        ZS_DECLARE_STRUCT_PTR(RTCIceGathererStateChangeEvent);
        ZS_DECLARE_STRUCT_PTR(RTCIceGathererStats);
        ZS_DECLARE_STRUCT_PTR(RTCIceParameters);
        ZS_DECLARE_STRUCT_PTR(RTCIceServer);
        ZS_DECLARE_STRUCT_PTR(RTCIceTransport);
        ZS_DECLARE_STRUCT_PTR(RTCIceTransportController);
        ZS_DECLARE_STRUCT_PTR(RTCIceTransportOptions);
        ZS_DECLARE_STRUCT_PTR(RTCIceTransportStateChangeEvent);
        ZS_DECLARE_STRUCT_PTR(RTCIceTransportStats);
        ZS_DECLARE_STRUCT_PTR(RTCIdentity);
        ZS_DECLARE_STRUCT_PTR(RTCIdentityAssertion);
        ZS_DECLARE_STRUCT_PTR(RTCIdentityError);
        ZS_DECLARE_STRUCT_PTR(RTCIdentityResult);
        ZS_DECLARE_STRUCT_PTR(RTCInboundRtpStreamStats);
        ZS_DECLARE_STRUCT_PTR(RTCMediaStreamStats);
        ZS_DECLARE_STRUCT_PTR(RTCMediaStreamTrackStats);
        ZS_DECLARE_STRUCT_PTR(RTCMessageEvent);
        ZS_DECLARE_STRUCT_PTR(RTCOutboundRtpStreamStats);
        ZS_DECLARE_STRUCT_PTR(RTCRtcpFeedback);
        ZS_DECLARE_STRUCT_PTR(RTCRtcpParameters);
        ZS_DECLARE_STRUCT_PTR(RTCRtcpTransport);
        ZS_DECLARE_STRUCT_PTR(RTCRtpCapabilities);
        ZS_DECLARE_STRUCT_PTR(RTCRtpCodecCapability);
        ZS_DECLARE_STRUCT_PTR(RTCRtpCodecCapabilityOptions);
        ZS_DECLARE_STRUCT_PTR(RTCRtpCodecCapabilityParameters);
        ZS_DECLARE_STRUCT_PTR(RTCRtpCodecParameterSettings);
        ZS_DECLARE_STRUCT_PTR(RTCRtpCodecParameters);
        ZS_DECLARE_STRUCT_PTR(RTCRtpContributingSource);
        ZS_DECLARE_STRUCT_PTR(RTCRtpEncodingParameters);
        ZS_DECLARE_STRUCT_PTR(RTCRtpFecParameters);
        ZS_DECLARE_STRUCT_PTR(RTCRtpFlexFecCodecCapabilityParameters);
        ZS_DECLARE_STRUCT_PTR(RTCRtpFlexFecCodecParameterSettings);
        ZS_DECLARE_STRUCT_PTR(RTCRtpH264CodecCapabilityParameters);
        ZS_DECLARE_STRUCT_PTR(RTCRtpH264CodecParameterSettings);
        ZS_DECLARE_STRUCT_PTR(RTCRtpHeaderExtension);
        ZS_DECLARE_STRUCT_PTR(RTCRtpHeaderExtensionParameters);
        ZS_DECLARE_STRUCT_PTR(RTCRtpListener);
        ZS_DECLARE_STRUCT_PTR(RTCRtpOpusCodecCapabilityOptions);
        ZS_DECLARE_STRUCT_PTR(RTCRtpOpusCodecCapabilityParameters);
        ZS_DECLARE_STRUCT_PTR(RTCRtpOpusCodecParameterSettings);
        ZS_DECLARE_STRUCT_PTR(RTCRtpParameters);
        ZS_DECLARE_STRUCT_PTR(RTCRtpReceiver);
        ZS_DECLARE_STRUCT_PTR(RTCRtpRedCodecParameterSettings);
        ZS_DECLARE_STRUCT_PTR(RTCRtpRtxCodecCapabilityParameters);
        ZS_DECLARE_STRUCT_PTR(RTCRtpRtxCodecParameterSettings);
        ZS_DECLARE_STRUCT_PTR(RTCRtpRtxParameters);
        ZS_DECLARE_STRUCT_PTR(RTCRtpSender);
        ZS_DECLARE_STRUCT_PTR(RTCRtpStreamStats);
        ZS_DECLARE_STRUCT_PTR(RTCRtpTransport);
        ZS_DECLARE_STRUCT_PTR(RTCRtpUnhandledEvent);
        ZS_DECLARE_STRUCT_PTR(RTCRtpVp8CodecCapabilityParameters);
        ZS_DECLARE_STRUCT_PTR(RTCRtpVp8CodecParameterSettings);
        ZS_DECLARE_STRUCT_PTR(RTCSctpCapabilities);
        ZS_DECLARE_STRUCT_PTR(RTCSctpTransport);
        ZS_DECLARE_STRUCT_PTR(RTCSctpTransportListener);
        ZS_DECLARE_STRUCT_PTR(RTCSctpTransportListenerEvent);
        ZS_DECLARE_STRUCT_PTR(RTCSctpTransportStateChangeEvent);
        ZS_DECLARE_STRUCT_PTR(RTCSctpTransportStats);
        ZS_DECLARE_STRUCT_PTR(RTCSrtpSdesCryptoParameters);
        ZS_DECLARE_STRUCT_PTR(RTCSrtpSdesKeyParameters);
        ZS_DECLARE_STRUCT_PTR(RTCSrtpSdesParameters);
        ZS_DECLARE_STRUCT_PTR(RTCSrtpSdesTransport);
        ZS_DECLARE_STRUCT_PTR(RTCSrtpSdesTransportLifetimeRemainingEvent);
        ZS_DECLARE_STRUCT_PTR(RTCSrtpTransportStats);
        ZS_DECLARE_STRUCT_PTR(RTCSsrcConflictEvent);
        ZS_DECLARE_STRUCT_PTR(RTCStats);
        ZS_DECLARE_STRUCT_PTR(RTCStatsProvider);
        ZS_DECLARE_STRUCT_PTR(RTCStatsReport);
        ZS_DECLARE_STRUCT_PTR(RTCStatsTypeSet);
        ZS_DECLARE_STRUCT_PTR(Settings);
        ZS_DECLARE_STRUCT_PTR(StringOrStringList);

      } // namespace ortc
    } // namespace org
  } // namespace impl
} // namespace wrapper

