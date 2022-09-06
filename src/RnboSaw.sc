RnboSaw : UGen {
	*ar { arg freq = 440.0;
		^this.multiNew('audio', freq);
	}
}
