
#include "impl_org_webrtc_AudioOptions.h"



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

//------------------------------------------------------------------------------
wrapper::impl::org::webrtc::AudioOptions::AudioOptions() noexcept
{
}

//------------------------------------------------------------------------------
wrapper::org::webrtc::AudioOptionsPtr wrapper::org::webrtc::AudioOptions::wrapper_create() noexcept
{
  auto pThis = make_shared<wrapper::impl::org::webrtc::AudioOptions>();
  pThis->thisWeak_ = pThis;
  return pThis;
}

//------------------------------------------------------------------------------
wrapper::impl::org::webrtc::AudioOptions::~AudioOptions()
{
}

//------------------------------------------------------------------------------
void wrapper::impl::org::webrtc::AudioOptions::wrapper_init_org_webrtc_AudioOptions() noexcept
{
}


