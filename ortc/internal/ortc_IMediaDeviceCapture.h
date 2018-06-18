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

#include <ortc/internal/ortc_IMediaDevice.h>

#include <ortc/IMediaStreamTrack.h>

namespace ortc
{
  namespace internal
  {
    ZS_DECLARE_INTERACTION_PTR(IMediaDeviceCaptureForMediaEngine);
    ZS_DECLARE_INTERACTION_PTR(IMediaDeviceCaptureAudioForMediaEngine);
    ZS_DECLARE_INTERACTION_PTR(IMediaDeviceCaptureVideoForMediaEngine);

    ZS_DECLARE_INTERACTION_PTR(IMediaEngineForMediaDevice);
    ZS_DECLARE_INTERACTION_PTR(IMediaEngineForMediaDeviceCapture);
    ZS_DECLARE_INTERACTION_PTR(IMediaEngineForMediaDeviceCaptureAudio);
    ZS_DECLARE_INTERACTION_PTR(IMediaEngineForMediaDeviceCaptureVideo);


    //-------------------------------------------------------------------------
    //-------------------------------------------------------------------------
    //-------------------------------------------------------------------------
    //-------------------------------------------------------------------------
    //
    // IMediaDeviceCapture
    //

    interaction IMediaDeviceCapture : public IMediaDevice
    {
      ZS_DECLARE_TYPEDEF_PTR(IMediaStreamTrackTypes::Kinds, Kinds);
      ZS_DECLARE_TYPEDEF_PTR(IMediaStreamTrackTypes::TrackConstraints, TrackConstraints);

      typedef zsLib::PromiseWithHolderPtr<IMediaDeviceCapturePtr> MediaDeviceCapturePromise;
      ZS_DECLARE_PTR(MediaDeviceCapturePromise);

      static MediaDeviceCapturePromisePtr create(
                                                 MediaDeviceObjectID repaceExistingDeviceObjectID,
                                                 Kinds kind,
                                                 const TrackConstraints &constraints,
                                                 IMediaDeviceCaptureDelegatePtr delegate
                                                 ) noexcept;

      virtual ~IMediaDeviceCapture() noexcept {}
    };

    //-------------------------------------------------------------------------
    //-------------------------------------------------------------------------
    //-------------------------------------------------------------------------
    //-------------------------------------------------------------------------
    //
    // IMediaDeviceCaptureDelegate
    //

    interaction IMediaDeviceCaptureDelegate
    {
      ZS_DECLARE_TYPEDEF_PTR(IMediaStreamTrackTypes::ImmutableMediaChannelTrace, ImmutableMediaChannelTrace);
      ZS_DECLARE_TYPEDEF_PTR(IMediaDevice::States, States);
      ZS_DECLARE_TYPEDEF_PTR(IMediaStreamTrackTypes::AudioFrame, AudioFrame);
      ZS_DECLARE_TYPEDEF_PTR(IMediaStreamTrackTypes::VideoFrame, VideoFrame);

      virtual void notifyMediaDeviceCaptureAudioFrame(
                                                      ImmutableMediaChannelTracePtr trace,
                                                      AudioFramePtr frame
                                                      ) noexcept = 0;
      virtual void notifyMediaDeviceCaptureVideoFrame(
                                                      ImmutableMediaChannelTracePtr trace,
                                                      VideoFramePtr frame
                                                      ) noexcept = 0;
      virtual void onMediaDeviceCaptureStateChanged(
                                                    IMediaDeviceCapturePtr device,
                                                    States state
                                                    ) = 0;
    };

    //---------------------------------------------------------------------------
    //---------------------------------------------------------------------------
    //---------------------------------------------------------------------------
    //---------------------------------------------------------------------------
    //
    // IMediaDeviceCaptureSubscription
    //

    interaction IMediaDeviceCaptureSubscription
    {
      virtual PUID getID() const noexcept = 0;

      virtual void cancel() noexcept = 0;

      virtual void background() noexcept = 0;
    };

    //-------------------------------------------------------------------------
    //-------------------------------------------------------------------------
    //-------------------------------------------------------------------------
    //-------------------------------------------------------------------------
    //
    // IMediaDeviceCaptureAudio
    //

    interaction IMediaDeviceCaptureAudio : public IMediaDeviceCapture
    {
      virtual ~IMediaDeviceCaptureAudio() noexcept {}
    };

    //-------------------------------------------------------------------------
    //-------------------------------------------------------------------------
    //-------------------------------------------------------------------------
    //-------------------------------------------------------------------------
    //
    // IMediaDeviceCaptureVideo
    //

    interaction IMediaDeviceCaptureVideo : public IMediaDeviceCapture
    {
      virtual ~IMediaDeviceCaptureVideo() noexcept {}
    };

    //-----------------------------------------------------------------------
    //-----------------------------------------------------------------------
    //-----------------------------------------------------------------------
    //-----------------------------------------------------------------------
    //
    // IMediaDeviceCaptureForMediaEngine
    //

    interaction IMediaDeviceCaptureForMediaEngine : public IMediaDeviceForMediaEngine
    {
      ZS_DECLARE_TYPEDEF_PTR(IMediaDeviceCaptureForMediaEngine, ForMediaEngine);

      ZS_DECLARE_TYPEDEF_PTR(IMediaDevice::MediaDeviceObjectID, MediaDeviceObjectID);
      ZS_DECLARE_TYPEDEF_PTR(IMediaStreamTrackTypes::TrackConstraints, TrackConstraints);

      typedef zsLib::PromiseWithHolderPtr<IMediaDeviceCapturePtr> MediaDeviceCapturePromise;
      ZS_DECLARE_PTR(MediaDeviceCapturePromise);

      virtual void mediaDeviceCaptureSubscribe(
                                               MediaDeviceCapturePromisePtr promise,
                                               MediaDeviceObjectID repaceExistingDeviceObjectID,
                                               TrackConstraintsPtr constraints,
                                               IMediaDeviceCaptureDelegatePtr delegate
                                               ) noexcept = 0;
    };

    
    //-----------------------------------------------------------------------
    //-----------------------------------------------------------------------
    //-----------------------------------------------------------------------
    //-----------------------------------------------------------------------
    //
    // IMediaDeviceCaptureAudioForMediaEngine
    //

    interaction IMediaDeviceCaptureAudioForMediaEngine : public IMediaDeviceCaptureForMediaEngine
    {
      ZS_DECLARE_TYPEDEF_PTR(IMediaDeviceCaptureAudioForMediaEngine, ForMediaEngine);

      ZS_DECLARE_TYPEDEF_PTR(IMediaEngineForMediaDeviceCaptureAudio, UseMediaEngine);

      static ForMediaEnginePtr create(
                                      UseMediaEnginePtr mediaEngine,
                                      const String &deviceID
                                      ) noexcept;
    };


    //-----------------------------------------------------------------------
    //-----------------------------------------------------------------------
    //-----------------------------------------------------------------------
    //-----------------------------------------------------------------------
    //
    // IMediaDeviceCaptureVideoForMediaEngine
    //

    interaction IMediaDeviceCaptureVideoForMediaEngine : public IMediaDeviceCaptureForMediaEngine
    {
      ZS_DECLARE_TYPEDEF_PTR(IMediaDeviceCaptureVideoForMediaEngine, ForMediaEngine);

      ZS_DECLARE_TYPEDEF_PTR(IMediaEngineForMediaDeviceCaptureVideo, UseMediaEngine);

      static ForMediaEnginePtr create(
                                      UseMediaEnginePtr mediaEngine,
                                      const String &deviceID
                                      ) noexcept;
    };
  }
}

ZS_DECLARE_PROXY_BEGIN(ortc::internal::IMediaDeviceCaptureDelegate)
ZS_DECLARE_PROXY_TYPEDEF(ortc::IMediaStreamTrackTypes::AudioFramePtr, AudioFramePtr)
ZS_DECLARE_PROXY_TYPEDEF(ortc::IMediaStreamTrackTypes::VideoFramePtr, VideoFramePtr)
ZS_DECLARE_PROXY_TYPEDEF(ortc::internal::IMediaDeviceCapturePtr, IMediaDeviceCapturePtr)
ZS_DECLARE_PROXY_TYPEDEF(ortc::IMediaStreamTrackTypes::ImmutableMediaChannelTracePtr, ImmutableMediaChannelTracePtr)
ZS_DECLARE_PROXY_TYPEDEF(ortc::internal::IMediaDevice::States, States)
ZS_DECLARE_PROXY_METHOD_SYNC(notifyMediaDeviceCaptureAudioFrame, ImmutableMediaChannelTracePtr, AudioFramePtr)
ZS_DECLARE_PROXY_METHOD_SYNC(notifyMediaDeviceCaptureVideoFrame, ImmutableMediaChannelTracePtr, VideoFramePtr)
ZS_DECLARE_PROXY_METHOD(onMediaDeviceCaptureStateChanged, IMediaDeviceCapturePtr, States)
ZS_DECLARE_PROXY_END()

ZS_DECLARE_PROXY_SUBSCRIPTIONS_BEGIN(ortc::internal::IMediaDeviceCaptureDelegate, ortc::internal::IMediaDeviceCaptureSubscription)
ZS_DECLARE_PROXY_SUBSCRIPTIONS_TYPEDEF(ortc::IMediaStreamTrackTypes::AudioFramePtr, AudioFramePtr)
ZS_DECLARE_PROXY_SUBSCRIPTIONS_TYPEDEF(ortc::IMediaStreamTrackTypes::VideoFramePtr, VideoFramePtr)
ZS_DECLARE_PROXY_SUBSCRIPTIONS_TYPEDEF(ortc::internal::IMediaDeviceCapturePtr, IMediaDeviceCapturePtr)
ZS_DECLARE_PROXY_SUBSCRIPTIONS_TYPEDEF(ortc::IMediaStreamTrackTypes::ImmutableMediaChannelTracePtr, ImmutableMediaChannelTracePtr)
ZS_DECLARE_PROXY_SUBSCRIPTIONS_TYPEDEF(ortc::internal::IMediaDevice::States, States)
ZS_DECLARE_PROXY_SUBSCRIPTIONS_METHOD_SYNC(notifyMediaDeviceCaptureAudioFrame, ImmutableMediaChannelTracePtr, AudioFramePtr)
ZS_DECLARE_PROXY_SUBSCRIPTIONS_METHOD_SYNC(notifyMediaDeviceCaptureVideoFrame, ImmutableMediaChannelTracePtr, VideoFramePtr)
ZS_DECLARE_PROXY_SUBSCRIPTIONS_METHOD(onMediaDeviceCaptureStateChanged, IMediaDeviceCapturePtr, States)
ZS_DECLARE_PROXY_SUBSCRIPTIONS_END()
