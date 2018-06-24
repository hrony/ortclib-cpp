/*

 Copyright (c) 2017, Optical Tone Ltd.
 All rights reserved.

 Redistribution and use in source and binary forms, with or without
 modification, are permitted provided that the following conditions are met:

 1. Redistributions of source code must retain the above copyright notice, this
 list of conditions and the following disclaimer.
 2. Redistributions in binary form must reproduce the above copyright notice,
 this list of conditions and the following disclaimer in the documentation
 and/or other materials provided with the distribution.

 THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS "AS IS" AND
 ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE IMPLIED
 WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE ARE
 DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT OWNER OR CONTRIBUTORS BE LIABLE FOR
 ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES
 (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES;
 LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND
 ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT
 (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE OF THIS
 SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.

 The views and conclusions contained in the software and documentation are those
 of the authors and should not be interpreted as representing official policies,
 either expressed or implied, of the FreeBSD Project.
 
 */

#pragma once

#include <ortc/internal/types.h>
#include <ortc/internal/ortc_IRTP.h>

#include <ortc/IMediaStreamTrack.h>

#include <zsLib/Promise.h>

namespace ortc
{
  namespace internal
  {
    ZS_DECLARE_INTERACTION_PTR(IRTPEncoderForMediaEngine);
    ZS_DECLARE_INTERACTION_PTR(IRTPEncoderAudioForMediaEngine);
    ZS_DECLARE_INTERACTION_PTR(IRTPEncoderVideoForMediaEngine);

    ZS_DECLARE_INTERACTION_PTR(IMediaEngineForRTPEncoderAudio);
    ZS_DECLARE_INTERACTION_PTR(IMediaEngineForRTPEncoderVideo);

    ZS_DECLARE_INTERACTION_PROXY(IRTPEncoderAysncDelegate);

    //-----------------------------------------------------------------------
    //-----------------------------------------------------------------------
    //-----------------------------------------------------------------------
    //-----------------------------------------------------------------------
    //
    // IRTPEncoder
    //

    interaction IRTPEncoder : public IRTP
    {
      ZS_DECLARE_TYPEDEF_PTR(IMediaStreamTrackTypes::ImmutableMediaChannelTrace, ImmutableMediaChannelTrace);
      ZS_DECLARE_TYPEDEF_PTR(IMediaStreamTrackTypes::AudioFrame, AudioFrame);
      ZS_DECLARE_TYPEDEF_PTR(IMediaStreamTrackTypes::VideoFrame, VideoFrame);

      virtual void notifyAudioFrame(
                                    ImmutableMediaChannelTracePtr trace,
                                    AudioFramePtr frame
                                    ) noexcept = 0;
      virtual void notifyVideoFrame(
                                    ImmutableMediaChannelTracePtr trace,
                                    VideoFramePtr frame
                                    ) noexcept = 0;

      virtual ~IRTPEncoder() noexcept {}
    };

    //-----------------------------------------------------------------------
    //-----------------------------------------------------------------------
    //-----------------------------------------------------------------------
    //-----------------------------------------------------------------------
    //
    // IRTPEncoderAudio
    //

    interaction IRTPEncoderAudio : public IRTPEncoder
    {
      ZS_DECLARE_TYPEDEF_PTR(IRTPTypes::Parameters, Parameters);
      ZS_DECLARE_TYPEDEF_PTR(zsLib::PromiseWithHolderPtr<IRTPEncoderAudioPtr>, PromiseWithRTPEncoderAudio);

      static PromiseWithRTPEncoderAudioPtr create(
                                                  const Parameters &parameters,
                                                  IRTPEncoderDelegatePtr delegate
                                                  ) noexcept;

      virtual ~IRTPEncoderAudio() noexcept {}
    };

    //-----------------------------------------------------------------------
    //-----------------------------------------------------------------------
    //-----------------------------------------------------------------------
    //-----------------------------------------------------------------------
    //
    // IRTPEncoderVideo
    //

    interaction IRTPEncoderVideo : public IRTPEncoder
    {
      ZS_DECLARE_TYPEDEF_PTR(IRTPTypes::Parameters, Parameters);
      ZS_DECLARE_TYPEDEF_PTR(zsLib::PromiseWithHolderPtr<IRTPEncoderVideoPtr>, PromiseWithRTPEncoderVideo);

      static PromiseWithRTPEncoderVideoPtr create(
                                                  const Parameters &parameters,
                                                  IRTPEncoderDelegatePtr delegate
                                                  ) noexcept;

      virtual ~IRTPEncoderVideo() noexcept {}
    };

    //-------------------------------------------------------------------------
    //-------------------------------------------------------------------------
    //-------------------------------------------------------------------------
    //-------------------------------------------------------------------------
    //
    // IRTPEncoderDelegate
    //

    interaction IRTPEncoderDelegate
    {
      ZS_DECLARE_TYPEDEF_PTR(IMediaStreamTrackTypes::ImmutableMediaChannelTrace, ImmutableMediaChannelTrace);
      ZS_DECLARE_TYPEDEF_PTR(IRTP::States, States);

      virtual void notifyRTPEncoderRTPPacket(
                                             ImmutableMediaChannelTracePtr trace,
                                             RTPPacketPtr packet
                                             ) noexcept = 0;
      virtual void notifyRTPEncoderRTCPPacket(
                                              ImmutableMediaChannelTracePtr trace,
                                              RTCPPacketPtr packet
                                              ) noexcept = 0;

      virtual void onRTPEncoderStateChanged(
                                            IRTPEncoderPtr encoder,
                                            States state
                                            ) = 0;
    };

    //---------------------------------------------------------------------------
    //---------------------------------------------------------------------------
    //---------------------------------------------------------------------------
    //---------------------------------------------------------------------------
    //
    // IRTPEncoderSubscription
    //

    interaction IRTPEncoderSubscription
    {
      virtual PUID getID() const noexcept = 0;

      virtual void cancel() noexcept = 0;

      virtual void background() noexcept = 0;
    };

    //-----------------------------------------------------------------------
    //-----------------------------------------------------------------------
    //-----------------------------------------------------------------------
    //-----------------------------------------------------------------------
    //
    // IRTPEncoderForMediaEngine
    //

    interaction IRTPEncoderForMediaEngine : public IRTPForMediaEngine
    {
      ZS_DECLARE_TYPEDEF_PTR(IRTPEncoderForMediaEngine, ForMediaEngine);

      virtual ~IRTPEncoderForMediaEngine() noexcept {}
    };

    //-----------------------------------------------------------------------
    //-----------------------------------------------------------------------
    //-----------------------------------------------------------------------
    //-----------------------------------------------------------------------
    //
    // IRTPEncoderAudioForMediaEngine
    //

    interaction IRTPEncoderAudioForMediaEngine : public IRTPEncoderForMediaEngine
    {
      ZS_DECLARE_TYPEDEF_PTR(IRTPEncoderAudioForMediaEngine, ForMediaEngine);

      ZS_DECLARE_TYPEDEF_PTR(IRTPTypes::Parameters, Parameters);
      ZS_DECLARE_TYPEDEF_PTR(IMediaEngineForRTPEncoderAudio, UseMediaEngine);

      ZS_DECLARE_TYPEDEF_PTR(zsLib::PromiseWithHolderPtr<IRTPEncoderAudioPtr>, PromiseWithRTPEncoderAudio);

      static ForMediaEnginePtr create(
                                      PromiseWithRTPEncoderAudioPtr promise,
                                      UseMediaEnginePtr mediaEngine,
                                      ParametersPtr parameters,
                                      IRTPEncoderDelegatePtr delegate
                                      ) noexcept;

      virtual ~IRTPEncoderAudioForMediaEngine() noexcept {}
    };

    //-----------------------------------------------------------------------
    //-----------------------------------------------------------------------
    //-----------------------------------------------------------------------
    //-----------------------------------------------------------------------
    //
    // IRTPEncoderVideoForMediaEngine
    //

    interaction IRTPEncoderVideoForMediaEngine : public IRTPEncoderForMediaEngine
    {
      ZS_DECLARE_TYPEDEF_PTR(IRTPEncoderVideoForMediaEngine, ForMediaEngine);

      ZS_DECLARE_TYPEDEF_PTR(IRTPTypes::Parameters, Parameters);
      ZS_DECLARE_TYPEDEF_PTR(IMediaEngineForRTPEncoderVideo, UseMediaEngine);

      ZS_DECLARE_TYPEDEF_PTR(zsLib::PromiseWithHolderPtr<IRTPEncoderVideoPtr>, PromiseWithRTPEncoderVideo);

      static ForMediaEnginePtr create(
                                      PromiseWithRTPEncoderVideoPtr promise,
                                      UseMediaEnginePtr mediaEngine,
                                      ParametersPtr parameters,
                                      IRTPEncoderDelegatePtr delegate
                                      ) noexcept;

      virtual ~IRTPEncoderVideoForMediaEngine() noexcept {}
    };

    //-------------------------------------------------------------------------
    //-------------------------------------------------------------------------
    //-------------------------------------------------------------------------
    //-------------------------------------------------------------------------
    //
    // IRTPEncoderAsyncDelegate
    //

    interaction IRTPEncoderAysncDelegate
    {
      ZS_DECLARE_TYPEDEF_PTR(IMediaStreamTrackTypes::ImmutableMediaChannelTracePtr, ImmutableMediaChannelTracePtr);
      ZS_DECLARE_TYPEDEF_PTR(IMediaStreamTrackTypes::AudioFrame, AudioFrame);
      ZS_DECLARE_TYPEDEF_PTR(IMediaStreamTrackTypes::VideoFrame, VideoFrame);

      virtual void onRTPEncoderAudioFrame(
                                          ImmutableMediaChannelTracePtr trace,
                                          AudioFramePtr frame
                                          ) = 0;
      virtual void onRTPEncoderVideoFrame(
                                          ImmutableMediaChannelTracePtr trace,
                                          VideoFramePtr frame
                                          ) = 0;
    };

  }
}



ZS_DECLARE_PROXY_BEGIN(ortc::internal::IRTPEncoderDelegate)
ZS_DECLARE_PROXY_TYPEDEF(ortc::RTPPacketPtr, RTPPacketPtr)
ZS_DECLARE_PROXY_TYPEDEF(ortc::RTCPPacketPtr, RTCPPacketPtr)
ZS_DECLARE_PROXY_TYPEDEF(ortc::internal::IRTPEncoderPtr, IRTPEncoderPtr)
ZS_DECLARE_PROXY_TYPEDEF(ortc::IMediaStreamTrackTypes::ImmutableMediaChannelTracePtr, ImmutableMediaChannelTracePtr)
ZS_DECLARE_PROXY_TYPEDEF(ortc::internal::IRTP::States, States)
ZS_DECLARE_PROXY_METHOD_SYNC(notifyRTPEncoderRTPPacket, ImmutableMediaChannelTracePtr, RTPPacketPtr)
ZS_DECLARE_PROXY_METHOD_SYNC(notifyRTPEncoderRTCPPacket, ImmutableMediaChannelTracePtr, RTCPPacketPtr)
ZS_DECLARE_PROXY_METHOD(onRTPEncoderStateChanged, IRTPEncoderPtr, States)
ZS_DECLARE_PROXY_END()

ZS_DECLARE_PROXY_SUBSCRIPTIONS_BEGIN(ortc::internal::IRTPEncoderDelegate, ortc::internal::IRTPEncoderSubscription)
ZS_DECLARE_PROXY_SUBSCRIPTIONS_TYPEDEF(ortc::RTPPacketPtr, RTPPacketPtr)
ZS_DECLARE_PROXY_SUBSCRIPTIONS_TYPEDEF(ortc::RTCPPacketPtr, RTCPPacketPtr)
ZS_DECLARE_PROXY_SUBSCRIPTIONS_TYPEDEF(ortc::internal::IRTPEncoderPtr, IRTPEncoderPtr)
ZS_DECLARE_PROXY_SUBSCRIPTIONS_TYPEDEF(ortc::IMediaStreamTrackTypes::ImmutableMediaChannelTracePtr, ImmutableMediaChannelTracePtr)
ZS_DECLARE_PROXY_SUBSCRIPTIONS_TYPEDEF(ortc::internal::IRTP::States, States)
ZS_DECLARE_PROXY_SUBSCRIPTIONS_METHOD_SYNC(notifyRTPEncoderRTPPacket, ImmutableMediaChannelTracePtr, RTPPacketPtr)
ZS_DECLARE_PROXY_SUBSCRIPTIONS_METHOD_SYNC(notifyRTPEncoderRTCPPacket, ImmutableMediaChannelTracePtr, RTCPPacketPtr)
ZS_DECLARE_PROXY_SUBSCRIPTIONS_METHOD(onRTPEncoderStateChanged, IRTPEncoderPtr, States)
ZS_DECLARE_PROXY_SUBSCRIPTIONS_END()

ZS_DECLARE_PROXY_BEGIN(ortc::internal::IRTPEncoderAysncDelegate)
ZS_DECLARE_PROXY_TYPEDEF(ortc::IMediaStreamTrackTypes::ImmutableMediaChannelTracePtr, ImmutableMediaChannelTracePtr)
ZS_DECLARE_PROXY_TYPEDEF(ortc::internal::IRTPEncoderAysncDelegate::AudioFramePtr, AudioFramePtr)
ZS_DECLARE_PROXY_TYPEDEF(ortc::internal::IRTPEncoderAysncDelegate::VideoFramePtr, VideoFramePtr)
ZS_DECLARE_PROXY_METHOD(onRTPEncoderAudioFrame, ImmutableMediaChannelTracePtr, AudioFramePtr)
ZS_DECLARE_PROXY_METHOD(onRTPEncoderVideoFrame, ImmutableMediaChannelTracePtr, VideoFramePtr)
ZS_DECLARE_PROXY_END()
