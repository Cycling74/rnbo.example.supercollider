#include "SC_PlugIn.hpp"
#include "RnboSaw.hpp"

static InterfaceTable* ft;

namespace SimpleSaw {

RnboSaw::RnboSaw() {
    mCalcFunc = make_calc_function<RnboSaw, &RnboSaw::next>();

    buf = (RNBO::SampleValue **)RTAlloc(mWorld, sizeof(RNBO::SampleValue *) * rnboObj.getNumOutputChannels());
    for (int i = 0; i < rnboObj.getNumOutputChannels(); i++) {
        buf[i] = (RNBO::SampleValue *)RTAlloc(mWorld, sizeof(RNBO::SampleValue *) * 512);
    }

    if (buf == NULL) {
        Print("RnboSaw ERROR: mem alloc failed");
    }

    Print("New RnboSaw!\n");
    next(1);
}

RnboSaw::~RnboSaw() {
    if (buf) {
        RTFree(mWorld, buf);
    }
}

void RnboSaw::next(int nSamples) {
    // const float* input = in(0);
    float* outbuf = out(0);
    RNBO::SampleValue ** input = nullptr;

    // TODO: How does SC get the sample rate and buffer size?
    rnboObj.prepareToProcess(44100, 512);
    rnboObj.process(input, 0, buf, 1, 512);

    for (int i = 0; i < nSamples; ++i) {
        outbuf[i] = static_cast<float>(buf[0][i]); //TODO better conversion?
    }
}

} // namespace SimpleSaw

PluginLoad(RnboSawUGens) {
    // Plugin magic
    ft = inTable;
    registerUnit<SimpleSaw::RnboSaw>(ft, "RnboSaw", false);
}
