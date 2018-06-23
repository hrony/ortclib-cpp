// Generated by zsLibEventingTool

#include "pch.h"

#ifndef CPPWINRT_USE_GENERATED_ORG_ORTC_EVENTQUEUEMAKER

#include <wrapper/generated/cppwinrt/cppwinrt_Helpers.h>
#include "Org.Ortc.EventQueueMaker.h"
#include "Org.Ortc.EventQueue.h"

using namespace winrt;

//------------------------------------------------------------------------------
winrt::com_ptr< Org::Ortc::implementation::EventQueueMaker > Org::Ortc::implementation::EventQueueMaker::ToCppWinrtImpl(wrapper::org::ortc::EventQueueMakerPtr value)
{
  if (!value) return nullptr;
  auto result = winrt::make_self<Org::Ortc::implementation::EventQueueMaker>(WrapperCreate{});
  result->native_ = value;
  return result;
}

//------------------------------------------------------------------------------
winrt::com_ptr< Org::Ortc::implementation::EventQueueMaker > Org::Ortc::implementation::EventQueueMaker::ToCppWinrtImpl(Org::Ortc::EventQueueMaker const & value)
{
  winrt::com_ptr< Org::Ortc::implementation::EventQueueMaker > impl {nullptr};
  impl.copy_from(winrt::from_abi<Org::Ortc::implementation::EventQueueMaker>(value));
  return impl;
}

//------------------------------------------------------------------------------
winrt::com_ptr< Org::Ortc::implementation::EventQueueMaker > Org::Ortc::implementation::EventQueueMaker::ToCppWinrtImpl(winrt::com_ptr< Org::Ortc::implementation::EventQueueMaker > const & value)
{
  return value;
}

//------------------------------------------------------------------------------
winrt::com_ptr< Org::Ortc::implementation::EventQueueMaker > Org::Ortc::implementation::EventQueueMaker::ToCppWinrtImpl(Org::Ortc::IEventQueueMaker const & value)
{
  winrt::com_ptr< Org::Ortc::implementation::EventQueueMaker > impl {nullptr};
  impl.copy_from(winrt::from_abi<Org::Ortc::implementation::EventQueueMaker>(value));
  return impl;
}

//------------------------------------------------------------------------------
Org::Ortc::EventQueueMaker Org::Ortc::implementation::EventQueueMaker::ToCppWinrt(wrapper::org::ortc::EventQueueMakerPtr value)
{
  auto result = ToCppWinrtImpl(value);
  return result.as< Org::Ortc::EventQueueMaker >();
}

//------------------------------------------------------------------------------
Org::Ortc::EventQueueMaker Org::Ortc::implementation::EventQueueMaker::ToCppWinrt(Org::Ortc::EventQueueMaker const & value)
{
  return value;
}

//------------------------------------------------------------------------------
Org::Ortc::EventQueueMaker Org::Ortc::implementation::EventQueueMaker::ToCppWinrt(winrt::com_ptr< Org::Ortc::implementation::EventQueueMaker > const & value)
{
  return value.as< Org::Ortc::EventQueueMaker >();
}

//------------------------------------------------------------------------------
Org::Ortc::EventQueueMaker Org::Ortc::implementation::EventQueueMaker::ToCppWinrt(Org::Ortc::IEventQueueMaker const & value)
{
  return value.as< Org::Ortc::EventQueueMaker >();
}

//------------------------------------------------------------------------------
Org::Ortc::IEventQueueMaker Org::Ortc::implementation::EventQueueMaker::ToCppWinrtInterface(wrapper::org::ortc::EventQueueMakerPtr value)
{
  auto result = ToCppWinrtImpl(value);
  return result.as< Org::Ortc::IEventQueueMaker >();
}

//------------------------------------------------------------------------------
Org::Ortc::IEventQueueMaker Org::Ortc::implementation::EventQueueMaker::ToCppWinrtInterface(Org::Ortc::EventQueueMaker const & value)
{
  return value.as< Org::Ortc::EventQueueMaker >();
}

//------------------------------------------------------------------------------
Org::Ortc::IEventQueueMaker Org::Ortc::implementation::EventQueueMaker::ToCppWinrtInterface(winrt::com_ptr< Org::Ortc::implementation::EventQueueMaker > const & value)
{
  return value.as< Org::Ortc::EventQueueMaker >();
}

//------------------------------------------------------------------------------
Org::Ortc::IEventQueueMaker Org::Ortc::implementation::EventQueueMaker::ToCppWinrtInterface(Org::Ortc::IEventQueueMaker const & value)
{
  return value;
}

//------------------------------------------------------------------------------
wrapper::org::ortc::EventQueueMakerPtr Org::Ortc::implementation::EventQueueMaker::FromCppWinrt(winrt::com_ptr< Org::Ortc::implementation::EventQueueMaker > const & value)
{
  if (!value) return wrapper::org::ortc::EventQueueMakerPtr();
  return value->native_;
}

//------------------------------------------------------------------------------
wrapper::org::ortc::EventQueueMakerPtr Org::Ortc::implementation::EventQueueMaker::FromCppWinrt(Org::Ortc::EventQueueMaker const & value)
{
  return FromCppWinrt(ToCppWinrtImpl(value));
}

//------------------------------------------------------------------------------
wrapper::org::ortc::EventQueueMakerPtr Org::Ortc::implementation::EventQueueMaker::FromCppWinrt(wrapper::org::ortc::EventQueueMakerPtr value)
{
  return value;
}

//------------------------------------------------------------------------------
wrapper::org::ortc::EventQueueMakerPtr Org::Ortc::implementation::EventQueueMaker::FromCppWinrt(Org::Ortc::IEventQueueMaker const & value)
{
  return FromCppWinrt(ToCppWinrtImpl(value));
}

//------------------------------------------------------------------------------
Org::Ortc::EventQueueMaker Org::Ortc::implementation::EventQueueMaker::CastFromIEventQueueMaker(Org::Ortc::IEventQueueMaker const & value)
{
  if (!value) return nullptr;
  auto nativeObject = ::Internal::Helper::FromCppWinrt_Org_Ortc_EventQueueMaker(value);  
  if (!nativeObject) return nullptr;
  auto result = std::dynamic_pointer_cast< wrapper::org::ortc::EventQueueMaker >(nativeObject);
  if (!result) return nullptr;
  return ToCppWinrt(result);
}

//------------------------------------------------------------------------------
Org::Ortc::IEventQueue Org::Ortc::implementation::EventQueueMaker::BindQueue(Windows::UI::Core::CoreDispatcher const & queue)
{
  Org::Ortc::IEventQueue result {nullptr};
  result = wrapper::org::ortc::EventQueueMaker::bindQueue(::Internal::Helper::FromCppWinrt(queue));
  return result;
}

//------------------------------------------------------------------------------
Windows::UI::Core::CoreDispatcher Org::Ortc::implementation::EventQueueMaker::ExtractQueue(Org::Ortc::IEventQueue const & queue)
{
  Windows::Foundation::IInspectable result {nullptr};
  result = wrapper::org::ortc::EventQueueMaker::extractQueue(::Internal::Helper::FromCppWinrt_Org_Ortc_EventQueue(queue));
  return result;
}


#endif //ifndef CPPWINRT_USE_GENERATED_ORG_ORTC_EVENTQUEUEMAKER
