/*

 Copyright (c) 2015, Hookflash Inc. / Hookflash Inc.
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

#include <ortc/IRTPSender.h>
#include <ortc/IDTLSTransport.h>
#include <ortc/IICETransport.h>

#include <openpeer/services/IWakeDelegate.h>
#include <zsLib/MessageQueueAssociator.h>
#include <zsLib/Timer.h>

//#define ORTC_SETTING_SCTP_TRANSPORT_MAX_MESSAGE_SIZE "ortc/sctp/max-message-size"

namespace ortc
{
  namespace internal
  {
    ZS_DECLARE_INTERACTION_PTR(IRTPSenderForSettings)
    ZS_DECLARE_INTERACTION_PTR(IRTPSenderForRTPListener)
    ZS_DECLARE_INTERACTION_PTR(IRTPSenderForRTPSenderChannel)
    ZS_DECLARE_INTERACTION_PTR(IRTPSenderForMediaStreamTrack)

    ZS_DECLARE_INTERACTION_PTR(ISecureTransportForRTPSender)
    ZS_DECLARE_INTERACTION_PTR(IRTPListenerForRTPSender)
    ZS_DECLARE_INTERACTION_PTR(IRTPSenderChannelForRTPSender)
    ZS_DECLARE_INTERACTION_PTR(IMediaStreamTrackForRTPSender)

    ZS_DECLARE_INTERACTION_PROXY(IRTPSenderAsyncDelegate)

    //-------------------------------------------------------------------------
    //-------------------------------------------------------------------------
    //-------------------------------------------------------------------------
    //-------------------------------------------------------------------------
    #pragma mark
    #pragma mark IRTPSenderForSettings
    #pragma mark

    interaction IRTPSenderForSettings
    {
      ZS_DECLARE_TYPEDEF_PTR(IRTPSenderForSettings, ForSettings)

      static void applyDefaults();

      virtual ~IRTPSenderForSettings() {}
    };
    
    //-------------------------------------------------------------------------
    //-------------------------------------------------------------------------
    //-------------------------------------------------------------------------
    //-------------------------------------------------------------------------
    #pragma mark
    #pragma mark IRTPSenderForRTPListener
    #pragma mark

    interaction IRTPSenderForRTPListener
    {
      ZS_DECLARE_TYPEDEF_PTR(IRTPSenderForRTPListener, ForRTPListener)

      static ElementPtr toDebug(ForRTPListenerPtr transport);

      virtual PUID getID() const = 0;

      virtual bool handlePacket(
                                IICETypes::Components viaTransport,
                                RTCPPacketPtr packet
                                ) = 0;
    };

    //-------------------------------------------------------------------------
    //-------------------------------------------------------------------------
    //-------------------------------------------------------------------------
    //-------------------------------------------------------------------------
    #pragma mark
    #pragma mark IRTPSenderForRTPSenderChannel
    #pragma mark

    interaction IRTPSenderForRTPSenderChannel
    {
      ZS_DECLARE_TYPEDEF_PTR(IRTPSenderForRTPSenderChannel, ForRTPSenderChannel)

      static ElementPtr toDebug(ForRTPSenderChannelPtr transport);

      virtual PUID getID() const = 0;

      virtual bool sendPacket(RTPPacketPtr packet) = 0;
      virtual bool sendPacket(RTCPPacketPtr packet) = 0;
    };

    //-------------------------------------------------------------------------
    //-------------------------------------------------------------------------
    //-------------------------------------------------------------------------
    //-------------------------------------------------------------------------
    #pragma mark
    #pragma mark IRTPSenderForDTMFSender
    #pragma mark

    interaction IRTPSenderForDTMFSender
    {
      ZS_DECLARE_TYPEDEF_PTR(IRTPSenderForDTMFSender, ForDTMFSender)

      static ElementPtr toDebug(ForDTMFSenderPtr transport);

      virtual PUID getID() const = 0;
    };

    //-------------------------------------------------------------------------
    //-------------------------------------------------------------------------
    //-------------------------------------------------------------------------
    //-------------------------------------------------------------------------
    #pragma mark
    #pragma mark IRTPSenderForMediaStreamTrack
    #pragma mark

    interaction IRTPSenderForMediaStreamTrack
    {
      ZS_DECLARE_TYPEDEF_PTR(IRTPSenderForMediaStreamTrack, ForMediaStreamTrack)

      static ElementPtr toDebug(ForMediaStreamTrackPtr transport);

      virtual PUID getID() const = 0;
    };

    //-------------------------------------------------------------------------
    //-------------------------------------------------------------------------
    //-------------------------------------------------------------------------
    //-------------------------------------------------------------------------
    #pragma mark
    #pragma mark IRTPSenderAsyncDelegate
    #pragma mark

    interaction IRTPSenderAsyncDelegate
    {
      virtual ~IRTPSenderAsyncDelegate() {}
    };

    //-------------------------------------------------------------------------
    //-------------------------------------------------------------------------
    //-------------------------------------------------------------------------
    //-------------------------------------------------------------------------
    #pragma mark
    #pragma mark RTPSender
    #pragma mark
    
    class RTPSender : public Noop,
                      public MessageQueueAssociator,
                      public SharedRecursiveLock,
                      public IRTPSender,
                      public IRTPSenderForSettings,
                      public IRTPSenderForRTPListener,
                      public IRTPSenderForRTPSenderChannel,
                      public IRTPSenderForDTMFSender,
                      public IRTPSenderForMediaStreamTrack,
                      public IWakeDelegate,
                      public zsLib::ITimerDelegate,
                      public IRTPSenderAsyncDelegate
    {
    protected:
      struct make_private {};

    public:
      friend interaction IRTPSender;
      friend interaction IRTPSenderFactory;
      friend interaction IRTPSenderForSettings;
      friend interaction IRTPSenderForRTPListener;
      friend interaction IRTPSenderForRTPSenderChannel;
      friend interaction IRTPSenderForDTMFSender;
      friend interaction IRTPSenderForMediaStreamTrack;

      ZS_DECLARE_TYPEDEF_PTR(ISecureTransportForRTPSender, UseSecureTransport)
      ZS_DECLARE_TYPEDEF_PTR(IRTPListenerForRTPSender, UseListener)
      ZS_DECLARE_TYPEDEF_PTR(IRTPSenderChannelForRTPSender, UseChannel)
      ZS_DECLARE_TYPEDEF_PTR(IMediaStreamTrackForRTPSender, UseMediaStreamTrack)

      enum States
      {
        State_Pending,
        State_Ready,
        State_ShuttingDown,
        State_Shutdown,
      };
      static const char *toString(States state);

    public:
      RTPSender(
                const make_private &,
                IMessageQueuePtr queue,
                IRTPSenderDelegatePtr delegate,
                IMediaStreamTrackPtr track,
                IRTPTransportPtr transport,
                IRTCPTransportPtr rtcpTransport = IRTCPTransportPtr()
                );

    protected:
      RTPSender(Noop) :
        Noop(true),
        MessageQueueAssociator(IMessageQueuePtr()),
        SharedRecursiveLock(SharedRecursiveLock::create())
      {}

      void init();

    public:
      virtual ~RTPSender();

      static RTPSenderPtr convert(IRTPSenderPtr object);
      static RTPSenderPtr convert(ForSettingsPtr object);
      static RTPSenderPtr convert(ForRTPListenerPtr object);
      static RTPSenderPtr convert(ForRTPSenderChannelPtr object);
      static RTPSenderPtr convert(ForDTMFSenderPtr object);
      static RTPSenderPtr convert(ForMediaStreamTrackPtr object);


    protected:
      //-----------------------------------------------------------------------
      #pragma mark
      #pragma mark RTPSender => IStatsProvider
      #pragma mark

      virtual PromiseWithStatsReportPtr getStats() const throw(InvalidStateError) override;

      //-----------------------------------------------------------------------
      #pragma mark
      #pragma mark RTPSender => IRTPSender
      #pragma mark

      static ElementPtr toDebug(RTPSenderPtr receiver);

      static RTPSenderPtr create(
                                 IRTPSenderDelegatePtr delegate,
                                 IMediaStreamTrackPtr track,
                                 IRTPTransportPtr transport,
                                 IRTCPTransportPtr rtcpTransport = IRTCPTransportPtr()
                                 );

      virtual PUID getID() const override {return mID;}

      virtual IRTPSenderSubscriptionPtr subscribe(IRTPSenderDelegatePtr delegate) override;

      virtual IMediaStreamTrackPtr track() const override;
      virtual IRTPTransportPtr transport() const override;
      virtual IRTCPTransportPtr rtcpTransport() const override;

      virtual void setTransport(
                                IRTPTransportPtr transport,
                                IRTCPTransportPtr rtcpTransport = IRTCPTransportPtr()
                                ) override;
      virtual PromisePtr setTrack(IMediaStreamTrackPtr track) override;

      static CapabilitiesPtr getCapabilities(Optional<Kinds> kind);

      virtual void send(const Parameters &parameters) override;
      virtual void stop() override;


      //-----------------------------------------------------------------------
      #pragma mark
      #pragma mark RTPSender => IRTPSenderForRTPListener
      #pragma mark

      // (duplciate) static ElementPtr toDebug(ForRTPListenerPtr transport);

      // (duplicate) virtual PUID getID() const = 0;

      virtual bool handlePacket(
                                IICETypes::Components viaTransport,
                                RTCPPacketPtr packet
                                ) override;

      //-----------------------------------------------------------------------
      #pragma mark
      #pragma mark RTPSender => IRTPSenderForRTPSenderChannel
      #pragma mark

      // (duplciate) static ElementPtr toDebug(ForRTPSenderChannelPtr transport);

      // (duplicate) virtual PUID getID() const = 0;

      virtual bool sendPacket(RTPPacketPtr packet) override;
      virtual bool sendPacket(RTCPPacketPtr packet) override;

      //-----------------------------------------------------------------------
      #pragma mark
      #pragma mark RTPSender => IRTPSenderForMediaStreamTrack
      #pragma mark

      // (duplciate) static ElementPtr toDebug(ForMediaStreamTrackPtr transport);

      // (duplicate) virtual PUID getID() const = 0;

      //-----------------------------------------------------------------------
      #pragma mark
      #pragma mark RTPSender => IRTPSenderForDTMFSender
      #pragma mark

      // (duplciate) static ElementPtr toDebug(ForRTPSenderPtr transport);

      // (duplicate) virtual PUID getID() const = 0;


      //-----------------------------------------------------------------------
      #pragma mark
      #pragma mark RTPSender => IWakeDelegate
      #pragma mark

      virtual void onWake() override;

      //-----------------------------------------------------------------------
      #pragma mark
      #pragma mark RTPSender => ITimerDelegate
      #pragma mark

      virtual void onTimer(TimerPtr timer) override;

      //-----------------------------------------------------------------------
      #pragma mark
      #pragma mark RTPSender => IRTPSenderAsyncDelegate
      #pragma mark

    protected:
      //-----------------------------------------------------------------------
      #pragma mark
      #pragma mark RTPSender => (internal)
      #pragma mark

      Log::Params log(const char *message) const;
      Log::Params debug(const char *message) const;
      virtual ElementPtr toDebug() const;

      bool isShuttingDown() const;
      bool isShutdown() const;

      void step();
      bool stepBogusDoSomething();

      void cancel();

      void setState(States state);
      void setError(WORD error, const char *reason = NULL);

      bool sendPacket(
                      IICETypes::Components packetType,
                      const BYTE *buffer,
                      size_t bufferSizeInBytes
                      );

    protected:
      //-----------------------------------------------------------------------
      #pragma mark
      #pragma mark RTPSender => (data)
      #pragma mark

      AutoPUID mID;
      RTPSenderWeakPtr mThisWeak;
      RTPSenderPtr mGracefulShutdownReference;

      IRTPSenderDelegateSubscriptions mSubscriptions;
      IRTPSenderSubscriptionPtr mDefaultSubscription;

      States mCurrentState {State_Pending};

      WORD mLastError {};
      String mLastErrorReason;

      ParametersPtr mParameters;

      UseListenerPtr mListener;

      UseSecureTransportPtr mRTPTransport;
      UseSecureTransportPtr mRTCPTransport;

      IICETypes::Components mSendRTPOverTransport {IICETypes::Component_RTP};
      IICETypes::Components mSendRTCPOverTransport {IICETypes::Component_RTCP};
      IICETypes::Components mReceiveRTCPOverTransport {IICETypes::Component_RTCP};
    };

    //-------------------------------------------------------------------------
    //-------------------------------------------------------------------------
    //-------------------------------------------------------------------------
    //-------------------------------------------------------------------------
    #pragma mark
    #pragma mark IRTPSenderFactory
    #pragma mark

    interaction IRTPSenderFactory
    {
      typedef IRTPSenderTypes::Kinds Kinds;
      typedef IRTPSenderTypes::CapabilitiesPtr CapabilitiesPtr;

      static IRTPSenderFactory &singleton();

      virtual RTPSenderPtr create(
                                  IRTPSenderDelegatePtr delegate,
                                  IMediaStreamTrackPtr track,
                                  IRTPTransportPtr transport,
                                  IRTCPTransportPtr rtcpTransport = IRTCPTransportPtr()
                                  );

      virtual CapabilitiesPtr getCapabilities(Optional<Kinds> kind);
    };

    class RTPSenderFactory : public IFactory<IRTPSenderFactory> {};
  }
}

ZS_DECLARE_PROXY_BEGIN(ortc::internal::IRTPSenderAsyncDelegate)
//ZS_DECLARE_PROXY_METHOD_0(onWhatever)
ZS_DECLARE_PROXY_END()
