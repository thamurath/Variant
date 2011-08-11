#include "Variant.hpp"

#include "src/VariantTypeBase.hpp"

#include <Common/Nullptr.hpp>

namespace Utilities
{
  Variant::~Variant(void)
  {
    delete m_value;
    m_value = Base::nullptr;
  }
}
