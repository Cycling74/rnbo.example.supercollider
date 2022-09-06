#include "SC_PlugIn.hpp"
#include "RNBO.h"

namespace SimpleSaw {

class RnboSaw : public SCUnit {
public:
    RNBO::CoreObject *rnboObj;
    RnboSaw();

    // Destructor
    ~RnboSaw();

private:
    // Calc function
    void next(int nSamples);

    // Member variables
    RNBO::SampleValue **buf;
};

} // namespace SimpleSaw
