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

#include <ortc/IMediaStreamTrack.h>

namespace ortc
{
  namespace internal
  {
    ZS_DECLARE_INTERACTION_PTR(IMediaStreamTrackChannelDelegate);
    ZS_DECLARE_INTERACTION_PTR(IMediaStreamTrackChannelMediaDelegate);
    ZS_DECLARE_INTERACTION_PTR(IMediaStreamTrackChannelRTPDelegate);

    ZS_DECLARE_INTERACTION_PTR(IMediaStreamTrackChannelForMediaStreamTrack);
    ZS_DECLARE_INTERACTION_PTR(IMediaStreamTrackChannelForMediaStreamTrackSubscriber);
    ZS_DECLARE_INTERACTION_PTR(IMediaStreamTrackChannelForMediaStreamTrackSubscriberMedia);
    ZS_DECLARE_INTERACTION_PTR(IMediaStreamTrackChannelForMediaStreamTrackSubscriberRTP);

    //-------------------------------------------------------------------------
    //-------------------------------------------------------------------------
    //-------------------------------------------------------------------------
    //-------------------------------------------------------------------------
    //
    // IMediaStreamTrackChannelDelegate
    //

    interaction IMediaStreamTrackChannelDelegate
    {
      ZS_DECLARE_TYPEDEF_PTR(IMediaStreamTrackTypes::ImmutableMediaChannelTrace, ImmutableMediaChannelTrace);

      virtual void notifyMediaChannelCancelled(ImmutableMediaChannelTracePtr trace) noexcept = 0;
    };

    //-------------------------------------------------------------------------
    //-------------------------------------------------------------------------
    //-------------------------------------------------------------------------
    //-------------------------------------------------------------------------
    //
    // IMediaStreamTrackChannelMediaDelegate
    //

    interaction IMediaStreamTrackChannelMediaDelegate : public IMediaStreamTrackChannelDelegate
    {
      ZS_DECLARE_TYPEDEF_PTR(IMediaStreamTrackTypes::ImmutableMediaChannelTrace, ImmutableMediaChannelTrace);
      ZS_DECLARE_TYPEDEF_PTR(IMediaStreamTrackTypes::AudioFrame, AudioFrame);
      ZS_DECLARE_TYPEDEF_PTR(IMediaStreamTrackTypes::VideoFrame, VideoFrame);

      virtual void notifyMediaChannelAudioFrame(
                                                ImmutableMediaChannelTracePtr trace,
                                                AudioFramePtr frame
                                                ) noexcept = 0;
      virtual void notifyMediaChannelVideoFrame(
                                                ImmutableMediaChannelTracePtr trace,
                                                AudioFramePtr frame
                                                ) noexcept = 0;
    };

    //-------------------------------------------------------------------------
    //-------------------------------------------------------------------------
    //-------------------------------------------------------------------------
    //-------------------------------------------------------------------------
    //
    // IMediaStreamTrackChannelRTPDelegate
    //

    interaction IMediaStreamTrackChannelRTPDelegate : public IMediaStreamTrackChannelDelegate
    {
      ZS_DECLARE_TYPEDEF_PTR(IMediaStreamTrackTypes::ImmutableMediaChannelTrace, ImmutableMediaChannelTrace);
      ZS_DECLARE_TYPEDEF_PTR(IMediaStreamTrackTypes::AudioFrame, AudioFrame);
      ZS_DECLARE_TYPEDEF_PTR(IMediaStreamTrackTypes::VideoFrame, VideoFrame);

      virtual void notifyMediaChannelRTPPacket(
                                               ImmutableMediaChannelTracePtr trace,
                                               RTPPacketPtr packet
                                               ) noexcept = 0;
      virtual void notifyMediaChannelRTCPPacket(
                                                ImmutableMediaChannelTracePtr trace,
                                                RTPPacketPtr packet
                                                ) noexcept = 0;
    };

    //-------------------------------------------------------------------------
    //-------------------------------------------------------------------------
    //-------------------------------------------------------------------------
    //-------------------------------------------------------------------------
    //
    // IMediaStreamTrackChannelForMediaStreamTrack
    //

    interaction IMediaStreamTrackChannelForMediaStreamTrack
    {
      ZS_DECLARE_TYPEDEF_PTR(IMediaStreamTrackChannelForMediaStreamTrack, ForMediaStreamTrack);

      typedef PUID SubscriberObjectID;
      ZS_DECLARE_TYPEDEF_PTR(IMediaStreamTrackTypes::ImmutableMediaChannelTrace, ImmutableMediaChannelTrace);
      ZS_DECLARE_TYPEDEF_PTR(IMediaStreamTrackTypes::AudioFrame, AudioFrame);
      ZS_DECLARE_TYPEDEF_PTR(IMediaStreamTrackTypes::VideoFrame, VideoFrame);

      static ForMediaStreamTrackPtr create(
                                           size_t timeIndex,
                                           ImmutableMediaChannelTracePtr trace
                                           ) noexcept;

      virtual PUID getID() const noexcept = 0;

      virtual void shutdown() noexcept = 0;

      virtual void notifyAudioFrame(
                                    size_t timeIndex,
                                    ImmutableMediaChannelTracePtr trace,
                                    AudioFramePtr frame
                                    ) noexcept = 0;
      virtual void notifyVideoFrame(
                                    size_t timeIndex,
                                    ImmutableMediaChannelTracePtr trace,
                                    VideoFramePtr frame
                                    ) noexcept = 0;

      virtual void notifyRTPPacket(
                                   size_t timeIndex,
                                   ImmutableMediaChannelTracePtr trace,
                                   RTPPacketPtr packet
                                   ) noexcept = 0;
      virtual void notifyRTCPPacket(
                                    size_t timeIndex,
                                    ImmutableMediaChannelTracePtr trace,
                                    RTPPacketPtr packet
                                    ) noexcept = 0;

      virtual void subscribeComplete() noexcept = 0;

      virtual bool shouldCancel(size_t cleanOlderThanTimeIndex) noexcept = 0;

      virtual void notifyMediaChannelGone(ImmutableMediaChannelTracePtr trace) noexcept = 0;
    };

    //-------------------------------------------------------------------------
    //-------------------------------------------------------------------------
    //-------------------------------------------------------------------------
    //-------------------------------------------------------------------------
    //
    // IMediaStreamTrackChannelForMediaStreamTrackSubscriber
    //

    interaction IMediaStreamTrackChannelForMediaStreamTrackSubscriber
    {
      ZS_DECLARE_TYPEDEF_PTR(IMediaStreamTrackChannelForMediaStreamTrackSubscriber, ForMediaStreamTrackSubscriber);

      typedef PUID SubscriberObjectID;

      virtual void notifyCancelled(SubscriberObjectID subscriberID) noexcept = 0;
    };

    //-------------------------------------------------------------------------
    //-------------------------------------------------------------------------
    //-------------------------------------------------------------------------
    //-------------------------------------------------------------------------
    //
    // IMediaStreamTrackChannelForMediaStreamTrackSubscriberMedia
    //

    interaction IMediaStreamTrackChannelForMediaStreamTrackSubscriberMedia : public IMediaStreamTrackChannelForMediaStreamTrackSubscriber
    {
      ZS_DECLARE_TYPEDEF_PTR(IMediaStreamTrackChannelForMediaStreamTrackSubscriberMedia, ForMediaStreamTrackSubscriberMedia);

      ZS_DECLARE_TYPEDEF_PTR(IMediaStreamTrackTypes::ImmutableMediaChannelTrace, ImmutableMediaChannelTrace);

      virtual void subscribeMedia(
                                  SubscriberObjectID subscriberID,
                                  IMediaStreamTrackChannelMediaDelegatePtr delegate
                                  ) noexcept = 0;
    };

    //-------------------------------------------------------------------------
    //-------------------------------------------------------------------------
    //-------------------------------------------------------------------------
    //-------------------------------------------------------------------------
    //
    // IMediaStreamTrackChannelForMediaStreamTrackSubscriberRTP
    //

    interaction IMediaStreamTrackChannelForMediaStreamTrackSubscriberRTP : public IMediaStreamTrackChannelForMediaStreamTrackSubscriber
    {
      ZS_DECLARE_TYPEDEF_PTR(IMediaStreamTrackChannelForMediaStreamTrackSubscriberRTP, ForMediaStreamTrackSubscriberRTP);

      typedef PUID SubscriberObjectID;
      ZS_DECLARE_TYPEDEF_PTR(IMediaStreamTrackTypes::ImmutableMediaChannelTrace, ImmutableMediaChannelTrace);
      ZS_DECLARE_TYPEDEF_PTR(IRTPTypes::ImmutableParameters, ImmutableParameters);

      virtual void subscribeRTP(
                                SubscriberObjectID subscriberID,
                                ImmutableParametersPtr params,
                                IMediaStreamTrackChannelRTPDelegatePtr delegate
                                ) noexcept = 0;
    };


  } // namespace internal
} // namespace ortc
