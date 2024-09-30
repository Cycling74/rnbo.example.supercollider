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


    auto index = rnboObj.getParameterIndexForID("freq");
    if (index < rnboObj.getNumParameters()) {
      float freq = in0(0);
      rnboObj.setParameterValue(index, freq);
    } else {
        Print("RnboSaw ERROR: cannot find freq parameter");
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
    auto bufsize = bufferSize();
    rnboObj.prepareToProcess(sampleRate(), bufsize);
    rnboObj.process(input, 0, buf, 1, bufsize);

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
