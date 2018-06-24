
#pragma once

#include "types.h"
#include "generated/org_ortc_Error.h"

#include <ortc/types.h>

namespace wrapper {
  namespace impl {
    namespace org {
      namespace ortc {

        struct Error : public wrapper::org::ortc::Error
        {
          ZS_DECLARE_TYPEDEF_PTR(::ortc::ErrorAny, NativeType);
          ZS_DECLARE_TYPEDEF_PTR(Error, WrapperImplType);
          ZS_DECLARE_TYPEDEF_PTR(wrapper::org::ortc::Error, WrapperType);
          ErrorWeakPtr thisWeak_;

          Error() noexcept;
          virtual ~Error() noexcept;
          void wrapper_init_org_ortc_Error() noexcept override;

          static WrapperImplTypePtr toWrapper(NativeTypePtr native) noexcept;
          static WrapperImplTypePtr toWrapper(const NativeType &native) noexcept;
          static NativeTypePtr toNative(WrapperTypePtr wrapper) noexcept;
        };

      } // ortc
    } // org
  } // namespace impl
} // namespace wrapper

