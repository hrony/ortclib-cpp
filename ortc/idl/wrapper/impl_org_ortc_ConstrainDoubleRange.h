
#pragma once

#include "types.h"
#include "generated/org_ortc_ConstrainDoubleRange.h"

#include <ortc/IConstraints.h>

namespace wrapper {
  namespace impl {
    namespace org {
      namespace ortc {

        struct ConstrainDoubleRange : public wrapper::org::ortc::ConstrainDoubleRange
        {
          ZS_DECLARE_TYPEDEF_PTR(::ortc::IConstraints::ConstrainDoubleRange, NativeConstrainDoubleRange);
          ConstrainDoubleRangeWeakPtr thisWeak_;

          ConstrainDoubleRange() noexcept;
          virtual ~ConstrainDoubleRange() noexcept;

          // methods ConstrainDoubleRange
          void wrapper_init_org_ortc_ConstrainDoubleRange() noexcept override;
          void wrapper_init_org_ortc_ConstrainDoubleRange(wrapper::org::ortc::ConstrainDoubleRangePtr source) noexcept override;
          void wrapper_init_org_ortc_ConstrainDoubleRange(wrapper::org::ortc::JsonPtr json) noexcept override;
          wrapper::org::ortc::JsonPtr toJson() noexcept override;
          String hash() noexcept override;

          static ConstrainDoubleRangePtr toWrapper(NativeConstrainDoubleRangePtr native) noexcept;
          static ConstrainDoubleRangePtr toWrapper(const NativeConstrainDoubleRange &native) noexcept;
          static NativeConstrainDoubleRangePtr toNative(wrapper::org::ortc::ConstrainDoubleRangePtr wrapper) noexcept;
        };

      } // ortc
    } // org
  } // namespace impl
} // namespace wrapper

