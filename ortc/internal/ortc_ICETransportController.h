/*

 Copyright (c) 2014, Hookflash Inc. / Hookflash Inc.
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

#include <ortc/IICETransportController.h>
#include <ortc/IICETransport.h>

#include <zsLib/MessageQueueAssociator.h>

namespace ortc
{
  namespace internal
  {
    ZS_DECLARE_INTERACTION_PTR(IICETransportControllerForICETransport);

    ZS_DECLARE_INTERACTION_PROXY(ITransportControllerAsyncDelegate);

    ZS_DECLARE_INTERACTION_PTR(IICETransportForICETransportContoller);

    //-------------------------------------------------------------------------
    //-------------------------------------------------------------------------
    //-------------------------------------------------------------------------
    //-------------------------------------------------------------------------
    //
    // IICETransportControllerForICETransport
    //

    interaction IICETransportControllerForICETransport
    {
      ZS_DECLARE_TYPEDEF_PTR(IICETransportControllerForICETransport, ForICETransport);

      static ElementPtr toDebug(ForICETransportPtr controller) noexcept;

      virtual PUID getID() const noexcept = 0;

      virtual PromisePtr notifyWhenUnfrozen(
                                            ICETransportPtr transport,
                                            const String &localFoundation,
                                            const String &remoteFoundation
                                            ) noexcept = 0;

      virtual void notifyDetached(ICETransportPtr transport) noexcept = 0;
    };

    //-------------------------------------------------------------------------
    //-------------------------------------------------------------------------
    //-------------------------------------------------------------------------
    //-------------------------------------------------------------------------
    //
    // ITransportControllerAsyncDelegate
    //

    interaction ITransportControllerAsyncDelegate
    {
      ZS_DECLARE_TYPEDEF_PTR(IICETransportForICETransportContoller, UseICETransport)

      typedef size_t AttachedOrderID;

      virtual void onTransportControllerNotifyWhenUnfrozen(
                                                           PromisePtr promise,
                                                           UseICETransportPtr transport,
                                                           const char *localFoundation,
                                                           const char *remoteFoundation
                                                           ) = 0;

      virtual void onTransportControllerNotifyDetached(
                                                       UseICETransportPtr transport,
                                                       AttachedOrderID detachedOrder
                                                       ) = 0;
    };

    //-------------------------------------------------------------------------
    //-------------------------------------------------------------------------
    //-------------------------------------------------------------------------
    //-------------------------------------------------------------------------
    //
    // ICETransportController
    //
    
    class ICETransportController : public Noop,
                                   public MessageQueueAssociator,
                                   public SharedRecursiveLock,
                                   public IICETransportController,
                                   public IICETransportControllerForICETransport,
                                   public ITransportControllerAsyncDelegate,
                                   public IWakeDelegate
    {
    protected:
      struct make_private {};

    public:
      friend interaction IICETransportController;
      friend interaction IICETransportControllerFactory;
      friend interaction IICETransportControllerForICETransport;

      ZS_DECLARE_TYPEDEF_PTR(IICETransportForICETransportContoller, UseICETransport);

      typedef size_t AttachedOrderID;
      typedef std::pair<AttachedOrderID, UseICETransportPtr> AttachedTransportPair;
      typedef std::list<AttachedTransportPair> TransportList;

    public:
      ICETransportController(
                             const make_private &,
                             IMessageQueuePtr queue
                             ) noexcept;

    protected:
      ICETransportController(Noop) noexcept :
        Noop(true),
        MessageQueueAssociator(IMessageQueuePtr()),
        SharedRecursiveLock(SharedRecursiveLock::create())
      {}

      void init() noexcept;

    public:
      virtual ~ICETransportController() noexcept;

      static ICETransportControllerPtr convert(IICETransportControllerPtr object) noexcept;
      static ICETransportControllerPtr convert(ForICETransportPtr object) noexcept;

    protected:
      //-----------------------------------------------------------------------
      //
      // ICETransportController => IICETransportController
      //

      static ElementPtr toDebug(ICETransportControllerPtr controller) noexcept;

      static ICETransportControllerPtr create() noexcept;

      PUID getID() const noexcept override;

      ICETransportList getTransports() const noexcept override;
      void addTransport(
                        IICETransportPtr transport,
                        Optional<size_t> index = Optional<size_t>()
                        ) noexcept(false) override; // throws InvalidParameters, InvalidStateError

      //-----------------------------------------------------------------------
      //
      // ICETransportController => IStatsProvider
      //

      PromiseWithStatsReportPtr getStats(const StatsTypeSet &stats = StatsTypeSet()) const noexcept override;

      //-----------------------------------------------------------------------
      //
      // ICETransportController => IICETransportControllerForICETransport
      //

      // (duplicate) virtual PUID getID() const noexcept= 0;

      PromisePtr notifyWhenUnfrozen(
                                    ICETransportPtr transport,
                                    const String &localFoundation,
                                    const String &remoteFoundation
                                    ) noexcept override;

      void notifyDetached(ICETransportPtr transport) noexcept override;

      //-----------------------------------------------------------------------
      //
      // ICETransportController => ITransportControllerAsyncDelegate
      //

      void onTransportControllerNotifyWhenUnfrozen(
                                                   PromisePtr promise,
                                                   UseICETransportPtr transport,
                                                   const char *localFoundation,
                                                   const char *remoteFoundation
                                                   ) override;

      void onTransportControllerNotifyDetached(
                                               UseICETransportPtr transport,
                                               AttachedOrderID detachedOrder
                                               ) override;

      //-----------------------------------------------------------------------
      //
      // ICETransportController => IWakeDelegate
      //

      void onWake() override;

    protected:
      //-----------------------------------------------------------------------
      //
      // ICETransportController => (internal)
      //

      Log::Params log(const char *message) const noexcept;
      Log::Params debug(const char *message) const noexcept;
      ElementPtr toDebug() const noexcept;

      void step() noexcept;

      void cancel() noexcept;

    protected:
      //-----------------------------------------------------------------------
      //
      // ICETransportController => (data)
      //

      AutoPUID mID;
      ICETransportControllerWeakPtr mThisWeak;

      TransportList mTransports;

      std::atomic<AttachedOrderID> mAttachOrder {};
    };

    //-------------------------------------------------------------------------
    //-------------------------------------------------------------------------
    //-------------------------------------------------------------------------
    //-------------------------------------------------------------------------
    //
    // IICETransportControllerFactory
    //

    interaction IICETransportControllerFactory
    {
      static IICETransportControllerFactory &singleton() noexcept;

      virtual ICETransportControllerPtr create() noexcept;
    };

    class ICETransportControllerFactory : public IFactory<IICETransportControllerFactory> {};
  }
}

ZS_DECLARE_PROXY_BEGIN(ortc::internal::ITransportControllerAsyncDelegate)
ZS_DECLARE_PROXY_TYPEDEF(zsLib::PromisePtr, PromisePtr)
ZS_DECLARE_PROXY_TYPEDEF(ortc::internal::ITransportControllerAsyncDelegate::UseICETransportPtr, UseICETransportPtr)
ZS_DECLARE_PROXY_TYPEDEF(ortc::internal::ITransportControllerAsyncDelegate::AttachedOrderID, AttachedOrderID)
ZS_DECLARE_PROXY_METHOD(onTransportControllerNotifyWhenUnfrozen, PromisePtr, UseICETransportPtr, const char *, const char *)
ZS_DECLARE_PROXY_METHOD(onTransportControllerNotifyDetached, UseICETransportPtr, AttachedOrderID)
ZS_DECLARE_PROXY_END()
