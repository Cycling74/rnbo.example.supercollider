#include "SC_PlugIn.hpp"
#include "RNBO.h"

namespace SimpleSaw {

class RnboSaw : public SCUnit {
public:
    RnboSaw();
    ~RnboSaw();

private:
    void next(int nSamples);

    RNBO::SampleValue **buf;
    RNBO::CoreObject rnboObj;
};

} // namespace SimpleSaw
