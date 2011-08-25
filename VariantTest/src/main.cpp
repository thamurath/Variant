

#include <Variant/Variant.hpp>


int main (void)
{
  uint32_t u32(23);
  uint64_t u64(44);


  Utilities::Variant::Variant vu32(u32);
  Utilities::Variant::Variant vu64(u64);

  uint32_t value_u32(0);
  uint64_t value_u64(0);

  vu32.getValue(value_u32);
  vu32.getValue(value_u64);


  value_u32 = 0;
  value_u64 = 0;

  vu64.getValue(value_u32);
  vu64.getValue(value_u64);

  return 0;
}
